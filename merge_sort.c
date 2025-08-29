#include <stdio.h>
#include <stdlib.h>

/*
    Ejercicio: Implementación de Merge Sort

    Descripción:
    Se reciben n arreglos lineales, cada uno de tamaño n.
    El programa debe combinarlos en un solo arreglo de tamaño n*n
    y ordenarlo en orden creciente usando Merge Sort.

    Entrada:
    - Un número entero n
    - n arreglos de tamaño n (n*n enteros en total)
 

    Salida:
    - Un solo arreglo de tamaño n*n con los elementos ordenados en orden creciente

    Ejemplo:

    Input:
    3
    3 1 5
    2 9 4
    8 7 6

    Output:
    1 2 3 4 5 6 7 8 9
*/


// ---- Prototipos ----
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int n, int r);

// ----Funcion Merge
//Para unir los arreglos y ordenarlos
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int nl = m - l + 1;
    int nr = r - m;

    // Creamos arreglos temporales para la parte derecha e izq
    int *L = (int *)malloc(nl * sizeof(int));
    int *R = (int *)malloc(nr * sizeof(int));

    // Copiamos los datos al arreglo temporal izquierdo
    for (i = 0; i < nl; i++)
        L[i] = arr[l + i];

    // Copiamos los datos al arreglo temporal derecho
    for (j = 0; j < nr; j++)
        R[j] = arr[m + 1 + j];

    


    // Volvemos a inicializar los indices
    i = 0; 
    j = 0; 
    k = l; 

    // Vamos insertando los datos de manera ordenada
    while (i < nl && j < nr) {
        // Si el elemento de indice i del arreglo izq es menor, lo insertamos primero
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        // Si el elemento de indice j del arreglo Derecho es menor, lo insertamos primero
        else {
            arr[k] = R[j];
            j++;
        }
        //Avanzamos la posicion en el arreglo original
        k++;
    }


    //Si la condicion del while linea 65 no se cumple, y aun tenemos elementos en el arreglo izq, los insertamos
    while (i < nl) {
        arr[k] = L[i];
        i++;
        k++;
    }

    //Si la condicion del while linea 65 no se cumple, y aun tenemos elementos en el arreglo dere   , los insertamos
    while (j < nr) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Aqui liberamos la memoria que utilizamos para los arreglos dinamicos que serian temporales
    free(L);
    free(R);
}

// ----Funcion Merge Sort
// Esta servira para separar en arreglos mas pequeños como arbol binario
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Aqui obtenemos la mitad
        int m = l + (r - l) / 2;

        // Mandamos a dividir cada mitad
        // Mit izq
        mergeSort(arr, l, m);

        // Mit derecha
        mergeSort(arr, m + 1, r);

        // Usamos la funcion merge para combinar los arreglos y ordenarlos
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    printf("Ingresa el numero de arreglos: ");
    scanf("%d", &n);  // Leer el número de arreglos, recordando que sera como una matriz cuadrada
    
    
    //El numero total de elementos, sale de multiplicar el numero de arreglos al cuadrado, ya que es como si fuera una matriz cuadrada
    int total = n * n;
    //Creamos el arreglo dinamico
    int *arr = (int *)malloc(total * sizeof(int));

    // Leer n arreglos de tamaño n
    for (int i = 0; i < total; i++) {
        printf("Ingresa el elemento de indice [%d] del arreglo a agregar: ", i);
        scanf("%d", &arr[i]);
    }

    // Ordenar usando merge sort
    mergeSort(arr, 0, total - 1);

    // Imprimir el arreglo ordenado
    for (int i = 0; i < total; i++) {
        printf("[%d] ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
