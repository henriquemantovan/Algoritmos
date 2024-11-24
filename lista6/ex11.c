#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct celula {
    int chave;
    int conteudo;
    struct celula *esq;
    struct celula *dir;
} No;


int nivelRecursivo(No* r, int x) {
    //Tempo consumido: O(altura da arvore)
    //Pior caso: O(n)

    if (r == NULL) {
        return -1;  // Elemento nao encontrado
    }
    
    // Ver se elemento ta na raiz
    if (r->chave == x) {
        return 0; 
    }
    
    // Busca na subárvore esquerda ou direita
    if (x < r->chave) {
        int nivel = nivelRecursivo(r->esq, x);
        if (nivel != -1) {
            return nivel + 1;  
        }
    }
    else {
        int nivel = nivelRecursivo(r->dir, x);
        if (nivel != -1) {
            return nivel + 1;  
        }
    }
    
    // Elemento nao encontrado
    return -1;
}

int nivelNaoRecursivo(No* r, int x) {
    int nivel = 0;
    
    while (r != NULL) {

        if (r->chave == x) {
            return nivel;
        }
        
        // Vai para a subárvore 
        if (x < r->chave) {
            r = r->esq;
        } else {
            r = r->dir;
        }
        
        nivel++;
    }
    
    // Elemento nao encontrado
    return -1;
}

// Funções auxiliares para criação da árvore (igual ao exemplo anterior)
No *criarNo(int chave, int conteudo, No *esq, No *dir) {
    No *novo = malloc(sizeof(No));
    novo->chave = chave;
    novo->conteudo = conteudo;
    novo->esq = esq;
    novo->dir = dir;
    return novo;
}

//Função main para testar as demais funções
int main() {
    No* raiz = NULL;
    
    // Construir uma árvore de exemplo
    raiz = criarNo(25, 0, NULL, NULL);
    raiz->esq = criarNo(15, 0, NULL, NULL);
    raiz->dir = criarNo(35, 0, NULL, NULL);
    raiz->esq->esq = criarNo(10, 0, NULL, NULL);
    raiz->esq->dir = criarNo(20, 0, NULL, NULL);
    raiz->dir->esq = criarNo(30, 0, NULL, NULL);
    raiz->dir->dir = criarNo(40, 0, NULL, NULL);
    
    // Testar níveis de alguns elementos
    int elementos[] = {25, 15, 10, 40};
    int numElementos = sizeof(elementos) / sizeof(elementos[0]);
    
    printf("Testando funções de Nivel:\n");
    for (int i = 0; i < numElementos; i++) {
        int x = elementos[i];
        printf("Elemento %d:\n", x);
        printf("  Nivel Recursivo: %d\n", nivelRecursivo(raiz, x));
        printf("  Nivel nao-Recursivo: %d\n", nivelNaoRecursivo(raiz, x));
    }
    
    // Testar elemento que nao existe
    printf("\nElemento nao existente (50):\n");
    printf("  Nivel Recursivo: %d\n", nivelRecursivo(raiz, 50));
    printf("  Nivel nao-Recursivo: %d\n", nivelNaoRecursivo(raiz, 50));
    
    return 0;
}