import cv2
import numpy as np

# 1. Abrir a imagem original
imagem = cv2.imread("imagem3.PNG")

if imagem is None:
    raise FileNotFoundError("Erro ao abrir a imagem.")

# 2. Converter para escala de cinza e binarizar
cinza = cv2.cvtColor(imagem, cv2.COLOR_BGR2GRAY)

_, binaria = cv2.threshold(
    cinza, 100, 255, cv2.THRESH_BINARY_INV
)

# Hit-or-Miss trabalha com valores 0 e 1
binaria01 = (binaria > 0).astype(np.uint8)

# 3. Criar imagem de saída totalmente branca
resultado = np.full(
    binaria.shape, 255, dtype=np.uint8
)

# 4. Procurar quadrados na imagem inteira
for lado in range(18, 26):

    # Kernel quadrado preenchido, com fundo branco ao redor
    kernel = np.zeros(
        (lado + 2, lado + 2), dtype=np.int8
    )

    kernel[1:-1, 1:-1] = 1
    kernel[0, :] = -1
    kernel[-1, :] = -1
    kernel[:, 0] = -1
    kernel[:, -1] = -1

    deteccoes = cv2.morphologyEx(
        binaria01,
        cv2.MORPH_HITMISS,
        kernel
    )

    # Obter as posições encontradas
    ys, xs = np.where(deteccoes == 1)

    for x, y in zip(xs, ys):
        x0 = x - lado // 2
        y0 = y - lado // 2

        # Garantir que o quadrado fique dentro da imagem
        if (x0 >= 0 and y0 >= 0 and
            x0 + lado <= resultado.shape[1] and
            y0 + lado <= resultado.shape[0]):

            resultado[y0:y0 + lado, x0:x0 + lado] = 0

# 5. Mostrar as imagens
cv2.imshow("Imagem binaria completa", binaria)
cv2.imshow("Somente quadrados", resultado)

cv2.waitKey(0)
cv2.destroyAllWindows()