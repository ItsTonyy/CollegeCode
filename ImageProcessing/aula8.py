import cv2
import numpy as np

# input de imagem
imagem = cv2.imread("imagem.png", cv2.IMREAD_GRAYSCALE)

altura, largura = imagem.shape

# quadrado de 10x10
tamanho = 10
meio = tamanho // 2

#erosao

erosao = np.zeros_like(imagem)

for y in range(meio, altura - meio):
    for x in range(meio, largura - meio):

        todos_brancos = True

        # percorre o quadrado
        for dy in range(-meio, meio):
            for dx in range(-meio, meio):

                if imagem[y + dy, x + dx] == 0:
                    todos_brancos = False
                    break

            if not todos_brancos:
                break

        if todos_brancos:
            erosao[y, x] = 255

# dilatacao
dilatacao = np.zeros_like(imagem)

for y in range(meio, altura - meio):
    for x in range(meio, largura - meio):

        encontrou_branco = False

        # Percorre o quadrado de 50 x 50
        for dy in range(-meio, meio):
            for dx in range(-meio, meio):

                if erosao[y + dy, x + dx] == 255:
                    encontrou_branco = True
                    break

            if encontrou_branco:
                break

        if encontrou_branco:
            dilatacao[y, x] = 255

# printa as imagens
cv2.imshow("Imagem Original", imagem)
cv2.imshow("Imagem com Erosao", erosao)
cv2.imshow("Imagem Final - Dilatacao", dilatacao)

cv2.waitKey(0)
cv2.destroyAllWindows()