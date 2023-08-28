#include <stdio.h>

void multiplica_array(int array1[], int array2[], int size, int resultado[]) {
    for (int i = 0; i < size; i++) {
        resultado[i] = array1[i] * array2[i];
    }
}

int main() {
    int arr1[] = {2, 4, 6, 8};
    int arr2[] = {3, 1, 5, 2};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    int resultado[size];
    multiplica_array(arr1, arr2, size, resultado);

    printf("Resultado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
