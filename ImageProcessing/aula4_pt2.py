import cv2
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

    # transforma de matriz para vetor
    hist = hist.flatten()

    return hist


def mostrar_histogramas(cinza):

    # calcula o histograma
    hist_original = calcular_histograma(cinza)

    # quantidade total de pixels
    total_pixels = cinza.size

    # calcula o histograma normalizado
    hist_normalizado = hist_original / total_pixels

    # calcula o histograma acumulado (cumsum do numPy através do array de hist)
    hist_acumulado = hist_normalizado.cumsum()

    niveis = range(256)

    # histograma original
    plt.figure(figsize=(12, 5))

    plt.bar(
        niveis,
        hist_original,
        width=1.0,
        color="black"
    )

    plt.title("Histograma Original")
    plt.xlabel("Nível de Cinza")
    plt.ylabel("Quantidade de Pixels")
    plt.xlim(0, 255)

    plt.tight_layout()
    plt.show()

    # histograma normalizado
    plt.figure(figsize=(12, 5))

    plt.plot(
        niveis,
        hist_normalizado,
        color="black"
    )

    plt.title("Histograma Normalizado")
    plt.xlabel("Nível de Cinza")
    plt.ylabel("Frequência")
    plt.xlim(0, 255)

    plt.tight_layout()
    plt.show()

    # histograma acumulado
    plt.figure(figsize=(12, 5))

    plt.plot(
        niveis,
        hist_acumulado,
        color="black"
    )

    plt.title("Histograma Acumulado")
    plt.xlabel("Nível de Cinza")
    plt.ylabel("Frequência Acumulada")
    plt.xlim(0, 255)
    plt.ylim(0, 1.05)

    plt.tight_layout()
    plt.show()


def main():

    # caminho da imagem
    caminho = "imagens/mulher-low-contrast.png"

    imagem = cv2.imread(caminho)

    if imagem is None:
        print("Erro: não foi possível carregar a imagem.")
        return

    # converte para escala de cinza
    cinza = cv2.cvtColor(
        imagem,
        cv2.COLOR_BGR2GRAY
    )

    # mostra os histogramas
    mostrar_histogramas(cinza)

    print("Histograma da imagem")

    cv2.waitKey(0)
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
