
import cv2
import numpy as np


def preencher_buraco(imagem, semente):
    altura, largura = imagem.shape

    # A: figura preta; Ac: regiões brancas
    A = imagem < 128
    Ac = np.logical_not(A)

    sy, sx = semente

    if not (0 <= sy < altura and 0 <= sx < largura):
        raise ValueError("Semente fora dos limites da imagem.")

    if not Ac[sy, sx]:
        raise ValueError("A semente deve estar em uma regiao branca.")

    # X0: semente
    X = np.zeros((altura, largura), dtype=bool)
    X[sy, sx] = True
    X0 = X.copy()

    # Guarda o estado de X para cada iteracao
    historico = [X.copy()]

    while True:
        # Dilatacao manual usando B 3x3
        dilatada = np.zeros((altura, largura), dtype=bool)

        for y in range(altura):
            for x in range(largura):
                if X[y, x]:
                    for dy in range(-1, 2):
                        for dx in range(-1, 2):
                            ny = y + dy
                            nx = x + dx

                            if 0 <= ny < altura and 0 <= nx < largura:
                                dilatada[ny, nx] = True

        # Xk = (X anterior dilatado) intersecao Ac
        proximo = np.zeros((altura, largura), dtype=bool)

        for y in range(altura):
            for x in range(largura):
                if dilatada[y, x] and Ac[y, x]:
                    proximo[y, x] = True

        if np.array_equal(proximo, X):
            break

        X = proximo
        historico.append(X.copy())

    total_iteracoes = len(historico) - 1

    # Estado correspondente a 50% das iteracoes
    indice_50 = total_iteracoes // 2
    X_50 = historico[indice_50]

    # Resultado final: uniao A U Xk
    resultado = np.zeros((altura, largura), dtype=np.uint8)

    for y in range(altura):
        for x in range(largura):
            if A[y, x] or X[y, x]:
                resultado[y, x] = 0
            else:
                resultado[y, x] = 255

    print("Total de iteracoes:", total_iteracoes)

    return X0, X_50, X, resultado


def para_visualizacao(matriz):
    # True vira preto; False vira branco
    visualizacao = np.zeros(matriz.shape, dtype=np.uint8)

    for y in range(matriz.shape[0]):
        for x in range(matriz.shape[1]):
            visualizacao[y, x] = 0 if matriz[y, x] else 255

    return visualizacao


def montar_painel(imagens, titulos):
    # Redimensiona as imagens para facilitar a visualizacao conjunta
    miniaturas = []

    for imagem, titulo in zip(imagens, titulos):
        colorida = cv2.cvtColor(imagem, cv2.COLOR_GRAY2BGR)

        # Redimensionamento manual por amostragem de vizinho mais proximo
        nova_altura = 256
        nova_largura = 256
        pequena = np.zeros((nova_altura, nova_largura, 3), dtype=np.uint8)

        for y in range(nova_altura):
            for x in range(nova_largura):
                oy = y * imagem.shape[0] // nova_altura
                ox = x * imagem.shape[1] // nova_largura
                pequena[y, x] = colorida[oy, ox]

        # Faixa branca para o titulo
        quadro = np.full((nova_altura + 35, nova_largura, 3), 255,
                         dtype=np.uint8)
        quadro[35:, :] = pequena

        cv2.putText(
            quadro, titulo, (5, 23),
            cv2.FONT_HERSHEY_SIMPLEX, 0.48, (0, 0, 0), 1
        )

        miniaturas.append(quadro)

    # Junta todas em uma grade 2x2
    linha1 = np.hstack((miniaturas[0], miniaturas[1]))
    linha2 = np.hstack((miniaturas[2], miniaturas[3]))

    painel = np.vstack((linha1, linha2))

    # Quinta imagem: resultado final
    ultima = np.zeros_like(miniaturas[4])
    ultima[:] = 255
    ultima[:] = miniaturas[4]

    # Painel final 3 colunas x 2 linhas
    vazio = np.full_like(miniaturas[0], 255)
    linha3 = np.hstack((miniaturas[4], vazio))

    return np.vstack((linha1, linha2, linha3))


# Leitura da imagem
imagem = cv2.imread("coroa.png", cv2.IMREAD_GRAYSCALE)

if imagem is None:
    raise FileNotFoundError("Imagem nao encontrada.")

print("Dimensoes:", imagem.shape)

# Escolha uma semente dentro do quadrado oco
semente = (256, 256)

X0, X50, Xfinal, resultado = preencher_buraco(imagem, semente)

# Monta as cinco imagens para mostrar juntas
imagens = [
    imagem,
    para_visualizacao(X0),
    para_visualizacao(X50),
    para_visualizacao(Xfinal),
    resultado
]

titulos = [
    "1 - Imagem original",
    "2 - Semente X0",
    "3 - Crescimento em 50%",
    "4 - Dilatacao final Xk",
    "5 - Buraco preenchido"
]

painel = montar_painel(imagens, titulos)

cv2.imshow("Preenchimento de buracos - todas as etapas", painel)
cv2.waitKey(0)
cv2.destroyAllWindows()
