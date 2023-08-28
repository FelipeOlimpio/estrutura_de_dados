#include <stdio.h>
#include <stdlib.h>

// Função para verificar se um número é primo
int isPrime(int num) {
    if (num <= 1)
        return 0;
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }
    
    int num = atoi(argv[1]);
    
    if (isPrime(num)) {
        printf("1 - O numero %d eh primo.\n", num);
    } else {
        printf("0 - O numero %d nao eh primo.\n", num);
    }
    
    return 0;
}
// gcc -o verifica_numero_primo verifica_numero_primo.c
// execute o programa, passando o número como argumento, verifica_numero_primo 123111
