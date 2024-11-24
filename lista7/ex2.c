#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int chave;
    struct celula* prox;
} Celula;

typedef Celula* Link;

int h(int m, int k) {
    return k % m;
}

int busca(Link T[], int m, int k) {
    int indice = h(m, k);
    Link atual = T[indice];
    
    while (atual != NULL) {
        if (atual->chave == k) {
            return 1;  // 
        }
        atual = atual->prox;
    }
    
    return 0; 
}

// Função de inserção
void insere(Link T[], int m, int k) {
//ver se ja existe
    if (busca(T, m, k)) {
        return;  
    }
    
    int indice = h(m, k);
    
    Link novoNo = malloc(sizeof(Celula));
    novoNo->chave = k;
    
    // Insere no início 
    novoNo->prox = T[indice];
    T[indice] = novoNo;
}

void remove(Link T[], int m, int k) {
    int indice = h(m, k);
    Link atual = T[indice];
    Link anterior = NULL;
    
    while (atual != NULL) {
        if (atual->chave == k) {
            // Remove o nó
            if (anterior == NULL) {
                // Remoção do primeiro nó da lista
                T[indice] = atual->prox;
            } else {
                // Remoção de nó do meio ou final
                anterior->prox = atual->prox;
            }
            
            free(atual);
            return;
        }
        
        anterior = atual;
        atual = atual->prox;
    }
}

