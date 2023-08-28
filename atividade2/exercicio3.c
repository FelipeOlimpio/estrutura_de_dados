#include <stdio.h>
#include <string.h>

int busca_string(char *array[], int size, char *busca) {
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i], busca) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char *arr[] = {"texto", "J", "EDA"};
    int size = sizeof(arr) / sizeof(arr[0]);

    char busca[] = "J";
    int result = busca_string(arr, size, busca);
    printf("Resultado: %d\n", result);

    return 0;
}
