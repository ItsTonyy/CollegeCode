import cv2
import numpy as np
import matplotlib.pyplot as plt


def calcular_histograma(imagem):
    # calcula o histograma
    hist = cv2.calcHist(
        [imagem],
        [0],
        None,
        [256],
        [0, 256]
    )

    return hist.flatten()


def histograma_normalizado(imagem):
    hist = calcular_histograma(imagem)

    # normaliza o histograma
    return hist / imagem.size


def especificar_histograma(imagem, histograma_desejado):

    # calcula o histograma original
    hist_original = histograma_normalizado(imagem)

    # calcula o acumulado original
    cdf_original = hist_original.cumsum()

    hist_desejado = np.array(
        histograma_desejado,
        dtype=np.float64
    )

    # verifica se existem 256 níveis
    if len(hist_desejado) != 256:
        raise ValueError(
            "O histograma desejado deve possuir 256 valores."
        )

    # normaliza o histograma desejado
    hist_desejado = (
        hist_desejado /
        hist_desejado.sum()
    )

    # calcula o acumulado desejado
    cdf_desejado = hist_desejado.cumsum()

    # cria a tabela de mapeamento
    tabela = np.zeros(256, dtype=np.uint8)

    for nivel in range(256):

        diferencas = np.abs(
            cdf_original[nivel] -
            cdf_desejado
        )

        nivel_destino = np.argmin(diferencas)

        tabela[nivel] = nivel_destino

    # aplica o mapeamento
    imagem_especificada = cv2.LUT(
        imagem,
        tabela
    )

    return (
        imagem_especificada,
        hist_desejado,
        cdf_desejado
    )


def mostrar_resultados(
    imagem,
    imagem_especificada,
    hist_desejado,
    cdf_desejado
):

    hist_original = histograma_normalizado(imagem)

    hist_resultado = histograma_normalizado(
        imagem_especificada
    )

    cdf_original = hist_original.cumsum()
    cdf_resultado = hist_resultado.cumsum()

    niveis = np.arange(256)

    # mostra o histograma especificado
    plt.figure(figsize=(12, 5))

    plt.bar(
        niveis,
        hist_desejado,
        color="blue",
        width=2.0
    )

    plt.title("Histograma especificado normalizado")
    plt.xlabel("Nível de cinza")
    plt.ylabel("Frequência normalizada")
    plt.xlim(0, 255)

    plt.tight_layout()
    plt.show()

    # mostra o histograma acumulado
    plt.figure(figsize=(12, 5))

    plt.plot(
        niveis,
        cdf_desejado,
        color="red"
    )

    plt.title(
        "Histograma especificado normalizado acumulado"
    )

    plt.xlabel("Nível de cinza")
    plt.ylabel("Frequência acumulada")
    plt.xlim(0, 255)
    plt.ylim(0, 1.05)

    plt.grid()

    plt.tight_layout()
    plt.show()

    # mostra antes e depois
    plt.figure(figsize=(12, 5))

    plt.subplot(1, 2, 1)

    plt.imshow(
        imagem,
        cmap="gray"
    )

    plt.title("Antes")
    plt.axis("off")

    plt.subplot(1, 2, 2)

    plt.imshow(
        imagem_especificada,
        cmap="gray"
    )

    plt.title("Depois - histograma especificado")
    plt.axis("off")

    plt.tight_layout()
    plt.show()


def main():

    caminho = "imagens/low-contrast.png"

    imagem = cv2.imread(
        caminho,
        cv2.IMREAD_GRAYSCALE
    )

    if imagem is None:
        print(
            "Erro: não foi possível carregar a imagem."
        )
        return

    # cria 256 níveis de cinza
    niveis = np.arange(256)

    # cria um histograma desejado (formato sino) funcao gaussiana
    centro = 127.5
    desvio = 50

    histograma_desejado = np.exp(
        -((niveis - centro) ** 2) /
        (2 * desvio ** 2)
    )

    # aplica a especificação
    (
        imagem_especificada,
        hist_desejado,
        cdf_desejado
    ) = especificar_histograma(
        imagem,
        histograma_desejado
    )

    # mostra os resultados
    mostrar_resultados(
        imagem,
        imagem_especificada,
        hist_desejado,
        cdf_desejado
    )


if __name__ == "__main__":
    main()
