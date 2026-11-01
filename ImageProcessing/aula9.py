import cv2
import numpy as np

# Ler imagem em escala de cinza
imagem = cv2.imread("image.png", cv2.IMREAD_GRAYSCALE)

if imagem is None:
    raise ValueError("Erro ao carregar imagem.png")

altura, largura = imagem.shape

# 1. Binarização manual
binaria = np.zeros((altura, largura), dtype=np.uint8)

for y in range(altura):
    for x in range(largura):
        if imagem[y, x] > 127:
            binaria[y, x] = 255

# Elemento estruturante 3x3
# Experimente 5 se quiser fechar espaços maiores
tamanho = 3
meio = tamanho // 2

# 2. DILATAÇÃO manual
dilatacao = np.zeros_like(binaria)

for y in range(altura):
    for x in range(largura):

        encontrou_branco = False

        for dy in range(-meio, meio + 1):
            for dx in range(-meio, meio + 1):

                ny = y + dy
                nx = x + dx

                if 0 <= ny < altura and 0 <= nx < largura:
                    if binaria[ny, nx] == 255:
                        encontrou_branco = True
                        break

            if encontrou_branco:
                break

        if encontrou_branco:
            dilatacao[y, x] = 255

# 3. EROSÃO manual sobre a dilatação
fechamento = np.zeros_like(binaria)

for y in range(altura):
    for x in range(largura):

        todos_brancos = True

        for dy in range(-meio, meio + 1):
            for dx in range(-meio, meio + 1):

                ny = y + dy
                nx = x + dx

                # Fora da imagem é considerado preto
                if not (0 <= ny < altura and 0 <= nx < largura):
                    todos_brancos = False
                    break

                if dilatacao[ny, nx] == 0:
                    todos_brancos = False
                    break

            if not todos_brancos:
                break

        if todos_brancos:
            fechamento[y, x] = 255

# 4. Mostrar resultados
cv2.imshow("Imagem Original", imagem)
cv2.imshow("Fechamento", fechamento)

cv2.waitKey(0)
cv2.destroyAllWindows()