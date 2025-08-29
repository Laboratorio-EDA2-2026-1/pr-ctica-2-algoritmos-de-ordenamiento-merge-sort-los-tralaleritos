def matralaleritos(matriz):
    lista = [num for colum in matriz for num in colum]
    return lista

def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mitad = len(arr) // 2
    izquierda = arr[:mitad]
    derecha = arr[mitad:]

    izquierda = merge_sort(izquierda)
    derecha = merge_sort(derecha)

    return merge(izquierda, derecha)

def merge(left, right):
    merged_list = []
    i = 0  
    j = 0 

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            merged_list.append(left[i])
            i += 1
        else:
            merged_list.append(right[j])
            j += 1

    while i < len(left):
        merged_list.append(left[i])
        i += 1

    while j < len(right):
        merged_list.append(right[j])
        j += 1

    return merged_list
 
n = int(input("Ingrese el numero de filas: "))
m = int(input("Ingrese el numero de columnas: "))

matriz = []
for i in range(n):
    fila  = []
    for j in range(m):
        num = int(input(f"Ingrese el valor de la posicion [{i}] [{j}]:"))
        fila.append(num)
    matriz.append(fila)


lista = matralaleritos(matriz)
print(merge_sort(lista))

