
import cv2
import numpy as np


def extrair_fronteira(imagem):
    # Converte para escala de cinza para identificar a figura preta
    cinza = np.mean(imagem, axis=2) if imagem.ndim == 3 else imagem

    # Máscara interna: True representa a figura preta
    A = cinza < 128

    altura, largura = A.shape

    # Elemento estruturante B: quadrado 3x3
    # Erosão: um pixel permanece se todos os 9 pixels
    # da vizinhança pertencerem à figura.
    A_padded = np.pad(
        A, pad_width=1, mode="constant", constant_values=False
    )

    erodida = np.ones_like(A, dtype=bool)

    for dy in range(3):
        for dx in range(3):
            erodida &= A_padded[
                dy:dy + altura,
                dx:dx + largura
            ]

    # β(A) = A - (A ⊖ B)
    fronteira = A & ~erodida

    # Imagem final: fundo branco e contorno preto
    resultado = np.full((altura, largura), 255, dtype=np.uint8)
    resultado[fronteira] = 0

    return resultado


# Abre a imagem
imagem = cv2.imread("imagem1.png")

if imagem is None:
    raise FileNotFoundError("Não foi possível abrir a imagem.")

# Extrai a fronteira
resultado = extrair_fronteira(imagem)

# Exibe o resultado
cv2.imshow("Imagem original", imagem)
cv2.imshow("Fronteira da figura", resultado)

cv2.waitKey(0)
cv2.destroyAllWindows()
