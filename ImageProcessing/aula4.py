import cv2
import numpy as np
import matplotlib.pyplot as plt


def expansao_histograma(imagem, r1, r2):
    # Converte para escala de cinza
    cinza = cv2.cvtColor(imagem, cv2.COLOR_BGR2GRAY)

    # Cria uma imagem em float para realizar os cálculos
    expandida = np.zeros_like(cinza, dtype=np.float32)

    # Região entre r1 e r2
    mascara = (cinza > r1) & (cinza < r2)

    # Transformação linear
    expandida[mascara] = (
        (cinza[mascara].astype(np.float32) - r1)
        * 255
        / (r2 - r1)
    )

    # Pixels menores ou iguais a r1
    expandida[cinza <= r1] = 0

    # Pixels maiores ou iguais a r2
    expandida[cinza >= r2] = 255

    # Converte para uint8
    expandida = expandida.astype(np.uint8)

    return cinza, expandida


def mostrar_histograma(cinza, r1, r2):
    # Calcula o histograma
    histograma = cv2.calcHist(
        [cinza],
        [0],
        None,
        [256],
        [0, 256]
    )

    plt.figure(figsize=(10, 5))

    plt.plot(
        histograma,
        color="black",
        linewidth=1.5
    )

    # Linha de r1
    plt.axvline(
        r1,
        color="red",
        linestyle="--",
        label=f"r1 = {r1}"
    )

    # Linha de r2
    plt.axvline(
        r2,
        color="blue",
        linestyle="--",
        label=f"r2 = {r2}"
    )

    plt.title("Histograma da Imagem em Escala de Cinza")
    plt.xlabel("Intensidade")
    plt.ylabel("Quantidade de Pixels")

    plt.xlim(0, 255)
    plt.grid(True, alpha=0.3)
    plt.legend()

    plt.show()

def mostrar_histograma_expandida(expandida):

    # Calcula o histograma
    histograma = cv2.calcHist(
        [expandida],
        [0],
        None,
        [256],
        [0, 256]
    )

    plt.figure(figsize=(10, 5))

    plt.plot(
        histograma,
        color="black",
        linewidth=1.5
    )

    plt.title("Histograma da Imagem expandida")
    plt.xlabel("Intensidade")
    plt.ylabel("Quantidade de Pixels")

    plt.xlim(0, 255)
    plt.grid(True, alpha=0.3)
    plt.legend()

    plt.show()


def main():
    caminho = "imagens/man-low-contrast.png"

    # Valores escolhidos observando o histograma
    r1 = 180
    r2 = 250

    # LEITURA DA IMAGEM
    imagem = cv2.imread(caminho)

    if imagem is None:
        print("Erro: não foi possível carregar a imagem.")
        return

    # EXPANSÃO
    cinza, expandida = expansao_histograma(
        imagem,
        r1,
        r2
    )

    # HISTOGRAMA
    mostrar_histograma(
        cinza,
        r1,
        r2
    )

    mostrar_histograma_expandida(
        expandida,
    )

    # MOSTRAR RESULTADO
    cv2.imshow(
        "Imagem Original",
        imagem
    )

    cv2.imshow(
        "Imagem Expandida",
        expandida
    )

    cv2.waitKey(0)
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
