from PIL import Image
import matplotlib.pyplot as plt

CAMINHO_IMAGEM = "imagens/feijao_com_arroz.png"

# <1 ele diminui, >1 ele aumenta
CONTRASTE = 2.0
# >0 clareia, <0 escurece
ILUMINACAO = 20


# Aplica a curva de tom
def aplicar_curva(valor, contraste, iluminacao):

    novo_valor = (valor - 128) * contraste + 128
    novo_valor = novo_valor + iluminacao

    if novo_valor < 0:
        novo_valor = 0

    if novo_valor > 255:
        novo_valor = 255

    return int(novo_valor)


# Aplica a curva de tom parabólica
def aplicar_curva_parabolica(valor):

    novo_valor = ((valor / 256) ** 2) * 255

    return int(novo_valor)


# Aplica a curva "estourada"
# 0 -> máximo -> 0 -> máximo
def aplicar_curva_estourada(valor):

    if valor < 85:

        # 0 -> 255
        novo_valor = (valor / 85) * 255

    elif valor < 170:

        # 255 -> 0
        novo_valor = 255 - ((valor - 85) / 85) * 255

    else:

        # 0 -> 255
        novo_valor = ((valor - 170) / 85) * 255

    return int(novo_valor)


# Gera os valores da curva
def gerar_curva(contraste, iluminacao):

    curva = []

    for entrada in range(256):
        saida = aplicar_curva(
            entrada,
            contraste,
            iluminacao
        )

        curva.append(saida)

    return curva


# Gera os valores da curva parabólica
def gerar_curva_parabolica():

    curva = []

    for entrada in range(256):

        saida = aplicar_curva_parabolica(entrada)

        curva.append(saida)

    return curva


# Gera os valores da curva estourada
def gerar_curva_estourada():

    curva = []

    for entrada in range(256):

        saida = aplicar_curva_estourada(entrada)

        curva.append(saida)

    return curva


# modifica a imagem em tons de cinza
def modificar_imagem(imagem, contraste, iluminacao):

    # converte a imagem para tons de cinza
    imagem = imagem.convert("L")

    largura, altura = imagem.size

    # cria uma nova imagem em tons de cinza
    nova_imagem = Image.new(
        "L",
        (largura, altura)
    )

    pixels_originais = imagem.load()
    pixels_novos = nova_imagem.load()

    # Percorre todos os pixels
    for y in range(altura):

        for x in range(largura):

            valor = pixels_originais[x, y]

            # pra cada pixel, aplicamos o contraste e iluminação
            novo_valor = aplicar_curva(
                valor,
                contraste,
                iluminacao
            )

            pixels_novos[x, y] = novo_valor

    return nova_imagem


# Aplica a curva parabólica na imagem
def modificar_imagem_parabolica(imagem):

    imagem = imagem.convert("L")

    largura, altura = imagem.size

    nova_imagem = Image.new(
        "L",
        (largura, altura)
    )

    pixels_originais = imagem.load()
    pixels_novos = nova_imagem.load()

    for y in range(altura):

        for x in range(largura):

            valor = pixels_originais[x, y]

            novo_valor = aplicar_curva_parabolica(valor)

            pixels_novos[x, y] = novo_valor

    return nova_imagem


# Aplica a curva estourada na imagem
def modificar_imagem_estourada(imagem):

    imagem = imagem.convert("L")

    largura, altura = imagem.size

    nova_imagem = Image.new(
        "L",
        (largura, altura)
    )

    pixels_originais = imagem.load()
    pixels_novos = nova_imagem.load()

    for y in range(altura):

        for x in range(largura):

            valor = pixels_originais[x, y]

            novo_valor = aplicar_curva_estourada(valor)

            pixels_novos[x, y] = novo_valor

    return nova_imagem


# Transforma a imagem em negativa
def transformar_negativa(imagem):

    imagem = imagem.convert("L")

    largura, altura = imagem.size

    nova_imagem = Image.new(
        "L",
        (largura, altura)
    )

    pixels_originais = imagem.load()
    pixels_novos = nova_imagem.load()

    for y in range(altura):

        for x in range(largura):

            valor = pixels_originais[x, y]

            novo_valor = 255 - valor

            pixels_novos[x, y] = novo_valor

    return nova_imagem


def main():

    imagem_original = Image.open(CAMINHO_IMAGEM)

    # Converte para tons de cinza
    imagem_original = imagem_original.convert("L")

    # Modifica a imagem
    imagem_modificada = modificar_imagem(
        imagem_original,
        CONTRASTE,
        ILUMINACAO
    )

    # Imagem negativa
    imagem_negativa = transformar_negativa(
        imagem_original
    )

    # Imagem com curva parabólica
    imagem_parabolica = modificar_imagem_parabolica(
        imagem_original
    )

    # imagem com curva estourada
    imagem_estourada = modificar_imagem_estourada(
        imagem_original
    )

    # Gera a curva
    curva = gerar_curva(
        CONTRASTE,
        ILUMINACAO
    )

    # Gera a curva parabólica
    curva_parabolica = gerar_curva_parabolica()

    # gera a curva estourada
    curva_estourada = gerar_curva_estourada()

    # histogama da imagem parabolica

    histograma_parabolica = imagem_parabolica.histogram()

    # Histograma da imagem estourada

    histograma_estourada = imagem_estourada.histogram()

    # Cria a janela
    fig, eixos = plt.subplots(
        3,
        3,
        figsize=(18, 15)
    )

    # Imagem original
    eixos[0, 0].imshow(
        imagem_original,
        cmap="gray",
        vmin=0,
        vmax=255
    )

    eixos[0, 0].set_title("Imagem original")
    eixos[0, 0].axis("off")


    # Imagem modificada
    eixos[0, 1].imshow(
        imagem_modificada,
        cmap="gray",
        vmin=0,
        vmax=255
    )

    eixos[0, 1].set_title("Imagem modificada")
    eixos[0, 1].axis("off")


    # Imagem negativa
    eixos[0, 2].imshow(
        imagem_negativa,
        cmap="gray",
        vmin=0,
        vmax=255
    )

    eixos[0, 2].set_title("Imagem negativa")
    eixos[0, 2].axis("off")


    # Imagem parabólica
    eixos[1, 0].imshow(
        imagem_parabolica,
        cmap="gray",
        vmin=0,
        vmax=255
    )

    eixos[1, 0].set_title("Imagem - Curva parabólica")
    eixos[1, 0].axis("off")


    # Curva parabólica
    eixos[1, 1].plot(
        range(256),
        range(256),
        "--",
        color="gray",
        label="Original"
    )

    eixos[1, 1].plot(
        range(256),
        curva_parabolica,
        color="red",
        label="Parabólica"
    )

    eixos[1, 1].set_title("Curva de tom parabólica")
    eixos[1, 1].set_xlabel("Entrada")
    eixos[1, 1].set_ylabel("Saída")

    eixos[1, 1].set_xlim(0, 255)
    eixos[1, 1].set_ylim(0, 255)

    eixos[1, 1].grid(True, alpha=0.3)
    eixos[1, 1].legend()


    # Histograma da imagem parabólica
    eixos[1, 2].bar(
        range(256),
        histograma_parabolica,
        color="red",
        width=1
    )

    eixos[1, 2].set_title("Histograma - Curva parabólica")
    eixos[1, 2].set_xlabel("Intensidade")
    eixos[1, 2].set_ylabel("Quantidade de pixels")

    eixos[1, 2].set_xlim(0, 255)

    # Imagem estourada
    eixos[2, 0].imshow(
        imagem_estourada,
        cmap="gray",
        vmin=0,
        vmax=255
    )

    eixos[2, 0].set_title("Imagem - Curva estourada")
    eixos[2, 0].axis("off")


    # Curva estourada
    eixos[2, 1].plot(
        range(256),
        range(256),
        "--",
        color="gray",
        label="Original"
    )

    eixos[2, 1].plot(
        range(256),
        curva_estourada,
        color="purple",
        label="Estourada"
    )

    eixos[2, 1].set_title("Curva de tom estourada")
    eixos[2, 1].set_xlabel("Entrada")
    eixos[2, 1].set_ylabel("Saída")

    eixos[2, 1].set_xlim(0, 255)
    eixos[2, 1].set_ylim(0, 255)

    eixos[2, 1].grid(True, alpha=0.3)
    eixos[2, 1].legend()


    # Histograma da imagem estourada
    eixos[2, 2].bar(
        range(256),
        histograma_estourada,
        color="purple",
        width=1
    )

    eixos[2, 2].set_title("Histograma - Curva estourada")
    eixos[2, 2].set_xlabel("Intensidade")
    eixos[2, 2].set_ylabel("Quantidade de pixels")

    eixos[2, 2].set_xlim(0, 255)


    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    main()