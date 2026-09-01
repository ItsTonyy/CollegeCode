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

    # imagem original

    hist_original = calcular_histograma(cinza)

    # quantidade total de pixels
    total_pixels = cinza.size

    # histograma normalizado
    hist_normalizado = hist_original / total_pixels

    # histograma acumulado
    hist_acumulado = hist_normalizado.cumsum()


    # equalização do histograma

    # aplica a equalização do histograma usando cv2
    cinza_equalizada = cv2.equalizeHist(cinza)

    # calcula o histograma da imagem equalizada
    hist_equalizado = calcular_histograma(cinza_equalizada)

    # histograma equalizado normalizado
    hist_equalizado_normalizado = hist_equalizado / total_pixels

    # histograma equalizado acumulado
    hist_equalizado_acumulado = hist_equalizado_normalizado.cumsum()

    niveis = range(256)

    plt.figure(figsize=(15, 10))

    # histograma da imagem cinza

    plt.subplot(2, 3, 1)

    plt.bar(
        niveis,
        hist_original,
        width=2.0,
        color="blue"
    )

    plt.title("Histograma Original")
    plt.xlabel("Nível de Cinza")
    plt.ylabel("Quantidade de Pixels")
    plt.xlim(0, 255)

    # histograma normalizado

    plt.subplot(2, 3, 2)

    plt.bar(
        niveis,
        hist_normalizado,
        color="blue"
    )

    plt.title("Histograma Normalizado")
    plt.xlabel("Nível de Cinza")
    plt.ylabel("Frequência")
    plt.xlim(0, 255)

    # histograma acumulado

    plt.subplot(2, 3, 3)

    plt.plot(
        niveis,
        hist_acumulado,
        color="blue"
    )

    plt.title("Histograma Acumulado")
    plt.xlabel("Nível de Cinza")
    plt.ylabel("Frequência Acumulada")
    plt.xlim(0, 255)
    plt.ylim(0, 1.05)

    # histograma da imagem equalizada

    plt.subplot(2, 3, 4)

    plt.bar(
        niveis,
        hist_equalizado,
        width=2.0,
        color="blue"
    )

    plt.title("Histograma Equalizado")
    plt.xlabel("Nível de Cinza")
    plt.ylabel("Quantidade de Pixels")
    plt.xlim(0, 255)

    # Imagem Equalizada

    plt.subplot(2, 3, 5)

    plt.imshow(cinza, cmap="gray")
    plt.title("Imagem Original")
    plt.axis("off")

    plt.subplot(2, 3, 6)

    plt.imshow(cinza_equalizada, cmap="gray")
    plt.title("Imagem Equalizada")
    plt.axis("off")

    plt.tight_layout()
    plt.show()


def main():
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

    cv2.waitKey(0)
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
