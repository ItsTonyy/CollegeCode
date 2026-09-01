import cv2
import numpy
import matplotlib.pyplot as plt
 
# Leitura da imagem
imagem = cv2.imread('ucrania-2cores.jpg')
 
# Largura, altura e canais
print('Largura em pixels: ', end='')
print(imagem.shape[1])
 
print('Altura em pixels: ', end='')
print(imagem.shape[0])
 
print('Qtde de canais:', end='')
print(imagem.shape[2])
 
# Mostra a imagem original
cv2.imshow("Imagem Original", imagem)
cv2.imwrite("saida.jpg", imagem)
 
# Criando as matrizes vazias para os canais de cores
canalBlue = numpy.zeros((imagem.shape[0], imagem.shape[1], imagem.shape[2]), dtype=numpy.uint8)
canalGreen = numpy.zeros((imagem.shape[0], imagem.shape[1], imagem.shape[2]), dtype=numpy.uint8)
canalRed = numpy.zeros((imagem.shape[0], imagem.shape[1], imagem.shape[2]), dtype=numpy.uint8)
 
# Criando a matriz de zeros (apenas 2 dimensões) para os tons de cinza
imagemCinza = numpy.zeros((imagem.shape[0], imagem.shape[1]), dtype=numpy.uint8)
 
# Transformando a matriz para tons de cinza manualmente
for i in range(imagem.shape[0]):
    for j in range(imagem.shape[1]):
        # Extrai os valores de B, G e R do pixel
        b, g, r = imagem[i][j]
        
        # Converte para int antes de somar para que o valor não passe do limite de 255 do uint8
        media = (int(b) + int(g) + int(r)) // 3
        
        # Atribui a média ao pixel correspondente
        imagemCinza[i][j] = media
 
# Atribuindo os canais individuais
canalBlue[:,:,0] = imagem[:,:,0]
canalGreen[:,:,1] = imagem[:,:,1]
canalRed[:,:,2] = imagem[:,:,2]
 
# Exibindo os resultados
cv2.imshow("canal Blue", canalBlue)
cv2.imshow("canal Green", canalGreen)
cv2.imshow("canal Red", canalRed)
cv2.imshow("canal Cinza", imagemCinza)
 
cv2.waitKey(0) # Espera pressionar qualquer tecla



import matplotlib.pyplot as plt
 
# Cria uma lista com 256 posições (todas zeradas) para guardar a contagem
histograma = 256 * [0]
 
# Varre a imagem cinza e, para cada pixel, adiciona +1 na posição correspondente ao seu tom
for i in range(imagemCinza.shape[0]):
    for j in range(imagemCinza.shape[1]):
        tom_do_pixel = imagemCinza[i][j]
        histograma[tom_do_pixel] += 1
 
 
# vai criar o eixo x
pixel = 256 * [0]
for i in range(256):
    pixel[i] = i
 
# nome do eixo x
plt.xlabel('Pixel')
 
# nome do eixo y
plt.ylabel('Quantidade')
 
# Título do gráfico
plt.title('Histograma da Imagem em Tons de Cinza')
 
# Cria o gráfico de barras
plt.bar(pixel, histograma, color='gray')
 
# Mostra o gráfico na tela
plt.show()


print(imagem)