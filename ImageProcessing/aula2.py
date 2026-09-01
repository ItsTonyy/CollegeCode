import cv2
import numpy as np
import matplotlib.pyplot as plt

imagem = cv2.imread("./imagens/ucrania-2cores.jpg")

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

limiar = 120

imagemLimiarizada =  np.zeros(
    (imagem.shape[0], imagem.shape[1]),
    dtype=np.uint8
)

for i in range(imagemCinza.shape[0]):
    for j in range(imagemCinza.shape[1]):

        if imagemCinza[i][j] > limiar:
            imagemLimiarizada[i][j] = imagemCinza[i][j]
        else:
            imagemLimiarizada[i][j] = 255

cv2.imshow("Imagem Limiarizada", imagemLimiarizada)

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