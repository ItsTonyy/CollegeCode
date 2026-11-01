import numpy as np

# Imagem original A: 0 = preto, 1 = branco
A = np.array([
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 1, 1, 1, 1, 1, 0, 0],
    [0, 1, 1, 1, 1, 1, 1, 0, 0],
    [0, 1, 1, 1, 1, 1, 1, 0, 0],
    [0, 1, 1, 1, 1, 1, 1, 0, 0],
    [0, 1, 1, 1, 1, 1, 1, 0, 0],
    [0, 1, 1, 1, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0]
], dtype=np.uint8)

# Elemento estruturante B: 5x5
B = np.array([
    [1, 0, 0, 0, 1],
    [0, 1, 1, 1, 0],
    [0, 1, 1, 1, 0],
    [0, 1, 1, 1, 0],
    [1, 0, 0, 0, 1]
], dtype=np.uint8)

altura, largura = A.shape
hb, wb = B.shape
meio_y = hb // 2
meio_x = wb // 2

# Erosão manual de A por B
erosao = np.zeros_like(A)

for y in range(meio_y, altura - meio_y):
    for x in range(meio_x, largura - meio_x):

        corresponde = True

        for dy in range(hb):
            for dx in range(wb):

                # Verificar apenas as posições ativas de B
                if B[dy, dx] == 1:

                    ny = y + dy - meio_y
                    nx = x + dx - meio_x

                    if A[ny, nx] == 0:
                        corresponde = False
                        break

            if not corresponde:
                break

        if corresponde:
            erosao[y, x] = 1

print("Imagem original A:")
print(A)

print("\nElemento estruturante B:")
print(B)

print("\nResultado da erosão A por B:")
print(erosao)