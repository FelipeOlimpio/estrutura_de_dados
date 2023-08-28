#include <stdio.h>

void menor_maior_array(int array[], int size, int *menor, int *maior) {
    *menor = array[0];
    *maior = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] < *menor) {
            *menor = array[i];
        }
        if (array[i] > *maior) {
            *maior = array[i];
        }
    }
}

int main() {
    int arr[] = {15, 5, 45, 30, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int menor, maior;
    menor_maior_array(arr, size, &menor, &maior);
    printf("Menor: %d\nMaior: %d\n", menor, maior);

    return 0;
}
