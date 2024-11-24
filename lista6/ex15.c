#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int chave;
    int conteudo;
    struct celula *pai;
    struct celula *esq;
    struct celula *dir;
} No;

No* remocao(No* p) {

    // No sem filhos
    if (p->esq == NULL && p->dir == NULL) {
        if (p->pai == NULL) return NULL; 
        
        if (p->pai->esq == p)
            p->pai->esq = NULL;
        else
            p->pai->dir = NULL;
        
        return p->pai;
    }
    
    // Nó com um filho
    if (p->esq == NULL || p->dir == NULL) {
        No* filho = (p->esq != NULL) ? p->esq : p->dir;
        
        if (p->pai == NULL) { 
            filho->pai = NULL;
            return filho;
        }
        
        filho->pai = p->pai;
        if (p->pai->esq == p)
            p->pai->esq = filho;
        else
            p->pai->dir = filho;
        
        return filho;
    }
    
    // Nó com dois filhos
    // Encontra o sucessor (menor elemento da subárvore direita)
    No* sucessor = p->dir;
    while (sucessor->esq != NULL) {
        sucessor = sucessor->esq;
    }
    
    // Troca o conteúdo do nó com o sucessor
    int temp = p->chave;
    p->chave = sucessor->chave;
    sucessor->chave = temp;
    
    // Remove o sucessor
    return remocao(sucessor);
}

