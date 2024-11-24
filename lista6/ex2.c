#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char conteudo;
    struct No *esq;
    struct No *dir;
} No;

int valor(char letra);
No *criarNo(char conteudo);
No *montaArvore(const char *posfixa);


int calcula(No *raiz) {

    if (raiz->esq == NULL && raiz->dir == NULL) {
        return valor(raiz->conteudo);
    }

    int esquerdo = calcula(raiz->esq);
    int direito = calcula(raiz->dir);

    switch (raiz->conteudo) {
        case '+': return esquerdo + direito;
        case '-': return esquerdo - direito;
        case '*': return esquerdo * direito;
        case '/': return esquerdo / direito;
        default: return 0;
    }
}

int main() {
    const char posfixa[] = "ab+c*";
    No *arvore = montaArvore(posfixa);

    int resultado = calcula(arvore);
    printf("Resultado: %d\n", resultado);

    return 0;
}

int valor(char letra) {
    if (letra >= 'A' && letra <= 'Z') {
        return letra - 'A' + 1;
    }
    else if (letra >= 'a' && letra <= 'z') {
        return letra - 'a' + 1;
    }
    else {
        return -1; 
    }
}

No *criarNo(char conteudo) {
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