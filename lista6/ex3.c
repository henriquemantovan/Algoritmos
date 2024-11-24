#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char conteudo;
    struct No *esq;
    struct No *dir;
} No;

No *novoNo(char conteudo);
No *montaArvore(const char *postfix);


void posfixa(No *raiz) {
    if (raiz != NULL) {
        // Visita recursivamente as subárvores 
        posfixa(raiz->esq);
        posfixa(raiz->dir);

        // Imprime do nó que ta agora
        printf("%c", raiz->conteudo);
    }
}

int main() {
    const char postfix[] = "ab+c*"; 
    No *arvore = montaArvore(postfix);

    printf("Notação pós-fixa da expressão: ");
    posfixa(arvore);

printf("\n");

    return 0;
}

No *novoNo(char conteudo) {
    No *no = (No *)malloc(sizeof(No));
    no->conteudo = conteudo;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

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





