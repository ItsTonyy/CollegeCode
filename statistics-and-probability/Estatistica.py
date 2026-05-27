import re
import unicodedata
from pathlib import Path

import kagglehub
import pandas as pd


DATASET_HANDLE = "datahackers/state-of-data-brazil-20242025"
SOURCE_FILE = "Final Dataset - State of Data 2024 - Kaggle - df_survey_2024.csv"
OUTPUT_FILE = Path("state_of_data_brazil_2024_2025_limpo.csv")


def normalize_column_name(column_name):
    normalized = unicodedata.normalize("NFKD", str(column_name).strip())
    normalized = "".join(
        char for char in normalized if not unicodedata.combining(char)
    )
    normalized = normalized.lower()
    normalized = re.sub(r"\s+", "_", normalized)
    normalized = re.sub(r"_+", "_", normalized).strip("_")
    return normalized or "coluna"


def make_unique_column_names(column_names):
    seen = set()
    unique_names = []

    for column_name in column_names:
        base_name = normalize_column_name(column_name)
        unique_name = base_name
        suffix = 2

        while unique_name in seen:
            unique_name = f"{base_name}_{suffix}"
            suffix += 1

        seen.add(unique_name)
        unique_names.append(unique_name)

    return unique_names


def clean_dataset(df):
    summary = {
        "original_rows": len(df),
        "original_columns": len(df.columns),
    }

    df = df.replace(r"^\s*$", pd.NA, regex=True)

    rows_before = len(df)
    df = df.dropna(how="all")
    summary["empty_rows_removed"] = rows_before - len(df)

    rows_before = len(df)
    df = df.drop_duplicates()
    summary["duplicate_rows_removed"] = rows_before - len(df)

    columns_before = len(df.columns)
    df = df.dropna(axis="columns", how="all")
    summary["empty_columns_removed"] = columns_before - len(df.columns)

    single_value_columns = [
        column for column in df.columns if df[column].nunique(dropna=False) == 1
    ]
    df = df.drop(columns=single_value_columns)
    summary["single_value_columns_removed"] = len(single_value_columns)

    df.columns = make_unique_column_names(df.columns)
    summary["final_rows"] = len(df)
    summary["final_columns"] = len(df.columns)

    return df, summary


def main():
    dataset_path = Path(kagglehub.dataset_download(DATASET_HANDLE))
    source_path = dataset_path / SOURCE_FILE

    df = pd.read_csv(source_path, dtype="string", low_memory=False)
    clean_df, summary = clean_dataset(df)
    clean_df.to_csv(OUTPUT_FILE, index=False, encoding="utf-8-sig")

    print("Limpeza concluida.")
    print(f"Arquivo original: {source_path}")
    print(f"Arquivo limpo: {OUTPUT_FILE.resolve()}")
    print(f"Linhas originais: {summary['original_rows']}")
    print(f"Colunas originais: {summary['original_columns']}")
    print(
        "Linhas completamente vazias removidas: "
        f"{summary['empty_rows_removed']}"
    )
    print(f"Linhas duplicadas removidas: {summary['duplicate_rows_removed']}")
    print(
        "Colunas completamente vazias removidas: "
        f"{summary['empty_columns_removed']}"
    )
    print(
        "Colunas com um unico valor removidas: "
        f"{summary['single_value_columns_removed']}"
    )
    print(f"Linhas finais: {summary['final_rows']}")
    print(f"Colunas finais: {summary['final_columns']}")


if __name__ == "__main__":
    main()
