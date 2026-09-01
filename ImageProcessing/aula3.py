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

            # pra cada pixel, aplicamos o contraste e iluminação definidas no começo do arquivo
            novo_valor = aplicar_curva(
                valor,
                contraste,
                iluminacao
            )

            pixels_novos[x, y] = novo_valor

    return nova_imagem


# NOVO: transforma a imagem em negativa
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

            # Inverte o valor do pixel
            novo_valor = 255 - valor

            pixels_novos[x, y] = novo_valor

    return nova_imagem


# aplica a curva parabólica na imagem
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

    # cria a imagem negativa
    imagem_negativa = transformar_negativa(
        imagem_original
    )

    # aplica a curva parabólica
    imagem_parabolica = modificar_imagem_parabolica(
        imagem_original
    )

    # Gera a curva
    curva = gerar_curva(
        CONTRASTE,
        ILUMINACAO
    )

    # gera a curva parabólica
    curva_parabolica = gerar_curva_parabolica()

    # Cria a janela com os elementos
    fig, eixos = plt.subplots(
        2,
        3,
        figsize=(18, 10)
    )

    # Mostra a imagem original
    eixos[0, 0].imshow(
        imagem_original,
        cmap="gray",
        vmin=0,
        vmax=255
    )

    eixos[0, 0].set_title("Imagem original")
    eixos[0, 0].axis("off")

    # Mostra a imagem modificada
    eixos[0, 1].imshow(
        imagem_modificada,
        cmap="gray",
        vmin=0,
        vmax=255
    )

    eixos[0, 1].set_title("Imagem modificada")
    eixos[0, 1].axis("off")

    # mostra a imagem negativa
    eixos[0, 2].imshow(
        imagem_negativa,
        cmap="gray",
        vmin=0,
        vmax=255
    )

    eixos[0, 2].set_title("Imagem negativa")
    eixos[0, 2].axis("off")

    # mostra a imagem com curva parabólica
    eixos[1, 0].imshow(
        imagem_parabolica,
        cmap="gray",
        vmin=0,
        vmax=255
    )

    eixos[1, 0].set_title("Curva de tom parabólica")
    eixos[1, 0].axis("off")

    # Mostra a curva original
    eixos[1, 1].plot(
        range(256),
        range(256),
        "--",
        color="gray",
        label="Original"
    )

    # Mostra a curva modificada
    eixos[1, 1].plot(
        range(256),
        curva,
        color="blue",
        label="Modificada"
    )

    eixos[1, 1].set_title("Curva de tom")
    eixos[1, 1].set_xlabel("Entrada")
    eixos[1, 1].set_ylabel("Saída")

    eixos[1, 1].set_xlim(0, 255)
    eixos[1, 1].set_ylim(0, 255)

    eixos[1, 1].grid(True, alpha=0.3)
    eixos[1, 1].legend()

    # mostra a curva parabólica
    eixos[1, 2].plot(
        range(256),
        range(256),
        "--",
        color="gray",
        label="Original"
    )

    eixos[1, 2].plot(
        range(256),
        curva_parabolica,
        color="red",
        label="Parabólica"
    )

    eixos[1, 2].set_title("Curva de tom parabólica")
    eixos[1, 2].set_xlabel("Entrada")
    eixos[1, 2].set_ylabel("Saída")

    eixos[1, 2].set_xlim(0, 255)
    eixos[1, 2].set_ylim(0, 255)

    eixos[1, 2].grid(True, alpha=0.3)
    eixos[1, 2].legend()

    plt.tight_layout()
    plt.show()


if __name__ == "__main__":
    main()