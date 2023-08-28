#include <stdio.h>

int soma_array(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = soma_array(arr, size);
    printf("Soma: %d\n", result);

    return 0;
}
