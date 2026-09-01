import cv2
import numpy as np
import matplotlib.pyplot as plt

imagem = cv2.imread("imagens/brasil3.jpg")

# Criando a imagem em tons de cinza
imagemCinza = np.zeros(
    (imagem.shape[0], imagem.shape[1]),
    dtype=np.uint8
)

# Convertendo para tons de cinza pela média dos 3 canais
for i in range(imagem.shape[0]):
    for j in range(imagem.shape[1]):

        imagemCinza[i][j] = (imagem[i][j].sum()/3)

## ** Limiarização** 

cv2.imshow("Imagem Original", imagem)
cv2.imshow("imagem cinza", imagemCinza)

# Faixas encontradas no histograma

# Verde: pico aproximadamente em 30
verde_min = 68
verde_max = 72

# Azul: pico aproximadamente em 45
amarelo_min = 150
amarelo_max = 155

# Amarelo: pico aproximadamente em 158
branco_min = 248
branco_max = 255


# ==========================================
# MÁSCARA VERDE
# ==========================================

mascara_verde = cv2.inRange(
    imagemCinza,
    verde_min,
    verde_max
)

imagem_verde = cv2.bitwise_and(
    imagem,
    imagem,
    mask=mascara_verde
)


# ==========================================
# MÁSCARA branco
# ==========================================

mascara_branco = cv2.inRange(
    imagemCinza,
    branco_min,
    branco_max
)

imagem_branco = cv2.bitwise_and(
    imagem,
    imagem,
    mask=mascara_branco
)


# ==========================================
# MÁSCARA AMARELA
# ==========================================

mascara_amarela = cv2.inRange(
    imagemCinza,
    amarelo_min,
    amarelo_max
)

imagem_amarela = cv2.bitwise_and(
    imagem,
    imagem,
    mask=mascara_amarela
)


# ==========================================
# MOSTRAR AS 3 IMAGENS
# ==========================================

cv2.imshow("Limiarizacao Verde e azul", imagem_verde)
cv2.imshow("Limiarizacao Amarela", imagem_amarela)
cv2.imshow("Limiarizacao Branca", imagem_branco)

## ** Histograma **

histograma = [0] * 256

# Contando os pixels de cada tom de cinza
for i in range(imagemCinza.shape[0]):
    for j in range(imagemCinza.shape[1]):
        histograma[imagemCinza[i][j]] += 1


# Eixo X: tons de cinza de 0 a 255
pixel = list(range(256))

# Criando o gráfico
plt.figure(figsize=(10, 5))

plt.bar(
    pixel,
    histograma,
    color='gray',
    width=1
)

plt.xlabel('Tom de cinza')
plt.ylabel('Quantidade de pixels')
plt.title('Histograma em Tons de Cinza')

plt.xlim(0, 255)

plt.show()

cv2.waitKey(0)
cv2.destroyAllWindows()