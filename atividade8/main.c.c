// main.c
#include <stdio.h>
#include "lista.h"

int main() {
    No* lista = NULL;

    // Inserção de elementos
    lista_inserir_no_i(&lista, 0, 'A');
    lista_inserir_no_i(&lista, 1, 'B');
    lista_inserir_no_i(&lista, 2, 'A');
    lista_inserir_no_i(&lista, 3, 'C');
    lista_inserir_no_i(&lista, 4, 'A');
    lista_inserir_no_i(&lista, 5, 'D');

    // Verificar existência de valor
    if (lista_verificar_existencia(lista, 'C')) {
        printf("O valor 'C' existe na lista.\n");
    } else {
        printf("O valor 'C' não existe na lista.\n");
    }

    // Verificar quantidade de ocorrências
    int ocorrencias = lista_verificar_ocorrencias(lista, 'A');
    printf("O valor 'A' ocorre %d vezes na lista.\n", ocorrencias);

    // Imprimir lista na ordem inversa
    printf("Lista na ordem inversa: ");
    lista_imprimir_inversa(lista);
    printf("\n");

    
    lista_remover_no_i(&lista, 2);

    
    lista_remover_no(&lista, 'A');

    
    No* atual = lista;
    printf("Lista após remoções: ");
    while (atual != NULL) {
        printf("%c ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");

   
    lista_libera_memoria(lista);

    return 0;
}
