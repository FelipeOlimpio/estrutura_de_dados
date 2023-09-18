#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = "arq_palavras_ordenado.txt";

    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Erro ao abrir arquivo de entrada");
        return 1;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Erro ao criar arquivo de saída");
        fclose(inputFile);
        return 1;
    }

    // Lê as palavras do arquivo de entrada e armazena em um array
    char **words = NULL;
    int numWords = 0;
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), inputFile)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove o caractere de nova linha
        words = (char **)realloc(words, (numWords + 1) * sizeof(char *));
        words[numWords] = strdup(buffer);
        numWords++;
    }

    // Ordena as palavras usando o algoritmo de bubble sort
    bubbleSort(words, numWords);

    // Escreve as palavras ordenadas no arquivo de saída
    for (int i = 0; i < numWords; i++) {
        fprintf(outputFile, "%s\n", words[i]);
        free(words[i]);
    }

    free(words);

    fclose(inputFile);
    fclose(outputFile);

    printf("Arquivo ordenado com sucesso em %s\n", outputFileName);

    return 0;
}
