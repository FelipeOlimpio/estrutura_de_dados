// lista.c

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1; 
        }
        atual = atual->proximo;
    }
    return 0; 
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int count = 0;
    No* atual = L;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            count++;
        }
        atual = atual->proximo;
    }
    return count;
}

void lista_imprimir_inversa(No* L) {
    if (L == NULL) {
        return; // Lista vazia
    }

    lista_imprimir_inversa(L->proximo);
    printf("%c ", L->valor);
}

void lista_inserir_no_i(No** L, int i, char valor) {
    if (i < 0) {
        return; 
    }

    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;

    if (i == 0 || *L == NULL) {
        novo->proximo = *L;
        *L = novo;
        return;
    }

    No* atual = *L;
    for (int j = 0; j < i - 1; j++) {
        if (atual->proximo == NULL) {
            free(novo);
            return; 
        }
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

void lista_remover_no_i(No** L, int i) {
    if (i < 0 || *L == NULL) {
        return; 
    }

    if (i == 0) {
        No* temp = *L;
        *L = (*L)->proximo;
        free(temp);
        return;
    }

    No* atual = *L;
    for (int j = 0; j < i - 1; j++) {
        if (atual->proximo == NULL) {
            return; 
        }
        atual = atual->proximo;
    }

    if (atual->proximo == NULL) {
        return; 
    }

    No* temp = atual->proximo;
    atual->proximo = temp->proximo;
    free(temp);
}

void lista_remover_no(No** L, char valor_busca) {
    while (*L != NULL && (*L)->valor == valor_busca) {
        No* temp = *L;
        *L = (*L)->proximo;
        free(temp);
    }

    if (*L == NULL) {
        return; 
    }

    No* atual = *L;
    while (atual->proximo != NULL) {
        if (atual->proximo->valor == valor_busca) {
            No* temp = atual->proximo;
            atual->proximo = temp->proximo;
            free(temp);
        } else {
            atual = atual->proximo;
        }
    }
}

void lista_libera_memoria(No* L) {
    while (L != NULL) {
        No* temp = L;
        L = L->proximo;
        free(temp);
    }
}
