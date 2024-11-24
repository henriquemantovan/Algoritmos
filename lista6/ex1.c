#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char conteudo;
    struct No *esq;
    struct No *dir;
} No;

No *criarNo(char conteudo);
void inOrdem(No *raiz);
void preOrdem(No *raiz);

No *montaArvore(const char *posfixa) {
    No *pilha[100]; 
    int topo = -1;

    for (int i = 0; posfixa[i] != '\0'; i++) {
        No *novo = criarNo(posfixa[i]);

        // Monta sub-árvores se for operador
        if (posfixa[i] == '+' || posfixa[i] == '-' || posfixa[i] == '*' || posfixa[i] == '/') {
            
            // Desempilha os nós da esquerda e da direita e coloca como filhos
            novo->dir = pilha[topo--]; 
            novo->esq = pilha[topo--]; 
        }
        
        pilha[++topo] = novo;
    }
    
    // Retorna a raiz da árvore
    return pilha[topo];
}


int main() {
    const char posfixa[] = "ab+c*";
    No *arvore = montaArvore(posfixa);

    printf("Pre-ordem: ");
    preOrdem(arvore);
    printf("\n");

    printf("In-ordem: ");
    inOrdem(arvore);
    printf("\n");

    return 0;
}

No *criarNo(char conteudo) {
    No *no = (No *)malloc(sizeof(No));
    no->conteudo = conteudo;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

void inOrdem(No *raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esq);
        printf("%c ", raiz->conteudo);
        inOrdem(raiz->dir);
    }
}

void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%c ", raiz->conteudo);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}
