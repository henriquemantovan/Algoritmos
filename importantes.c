/*Escreva uma função recursiva com protótipo
   int maximo (int v[], int ini, int fim);
que devolve o maior valor do vetor entre as posições ini e fim. 
Use uma estratégia como a do mergesort (divisão e conquista): divida o vetor ao meio, 
chame a função recursivamente para cada uma das metades, depois "junte" as respostas.*/
int maximo (int v[], int ini, int fim){
   if(ini == fim)
      return v[ini];
   int meio = (ini + fim) / 2;

   int max1 = maximo(v, ini, meio);
   int max2 = maximo(v, meio + 1, fim);

   return (max1 > max2) ? max1 : max2;
}

/*Escreva uma função recursiva busca_ternária com o seguinte protótipo
   int busca_ternaria 
   (int v, int ini, int fim, int x);
Sua função deve devolver 1 se x aparece no vetor, 0 caso contrário. Inspire-se na busca binária. 
Na busca ternária, você deve dividir o vetor em três (em vez de em dois), 
comparar o x com os dois elementos separadores dessas três partes e, ou encontra x, 
ou decide em qual das partes ele pode estar, procurando-o recursivamente nesta parte.*/
int busca_ternaria(int v[], int ini, int fim, int x) {
    if (ini > fim) {
        return 0; // Elemento não encontrado
    }

    // Dividir o array em três partes
    int terco1 = ini + (fim - ini) / 3;
    int terco2 = fim - (fim - ini) / 3;

    if (v[terco1] == x ) {
        return 1; // Elemento encontrado

    if (x < v[terco1]) {
        // Buscar no primeiro terço
        return busca_ternaria(v, ini, terco1 - 1, x);
    } else if (x > v[terco2]) {
        // Buscar no terceiro terço
        return busca_ternaria(v, terco2 + 1, fim, x);
    } else {
        // Buscar no segundo terço
        return busca_ternaria(v, terco1 + 1, terco2 - 1, x);
    }
}

/*Escreva uma função que recebe um vetor com n letras As e Bs e, por meio de trocas, 
move todos os As para o início do vetor. Sua função deve consumir tempo linear 
(proporcional ao tamanho do vetor, ou seja, a n).*/


/*Escreva uma função com protótipo
      void alteraChave (int x, int i, int n, intv[]); 
que recebe um heap em v[1..n] e altera a chave do elemento i para x, 
rearranjando v para que continue um heap
 * Função para alterar a chave do elemento i para x e rearranjar o heap
 * Parâmetros:
 * - x: novo valor para a chave
 * - i: índice do elemento cuja chave será alterada
 * - n: número de elementos no heap
 * - v: array que representa o heap (indexado de 1 a n)
 */
void alteraChave(int x, int i, int n, Maquina v[]) {
    int original = v[i].carga;
    v[i].carga = x;

    if (x > original) {
        // Se a nova chave é maior, precisamos ajustar o heap para cima
        while (i > 0 && v[(i - 1) / 2].carga > v[i].carga) {
            Maquina temp = v[i];
            v[i] = v[(i - 1) / 2];
            v[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    } else if (x < original) {
        // Se a nova chave é menor, precisamos ajustar o heap para baixo
        int left, right, smallest;
        while (1) {
            left = 2 * i + 1;
            right = 2 * i + 2;
            smallest = i;

            if (left < n && v[left].carga < v[smallest].carga) {
                smallest = left;
            }
            if (right < n && v[right].carga < v[smallest].carga) {
                smallest = right;
            }
            if (smallest == i) {
                break;
            }

            Maquina temp = v[i];
            v[i] = v[smallest];
            v[smallest] = temp;
            i = smallest;
        }
    }
}

/*Escreva uma função com protótipo
      void removeHeap (int i, int *n, intv[]); 
que recebe um heap em v[1..*n] e remove o elemento v[i] do heap, rearranjando v para que continue um heap.
 * Função para remover o elemento v[i] do heap e rearranjar o heap
 * Parâmetros:
 * - i: índice do elemento a ser removido
 * - n: ponteiro para o número de elementos no heap
 * - v: array que representa o heap (indexado de 0 a *n-1)
 */
void removeHeap(int i, int *n, Maquina v[]) {
    // Troca o elemento a ser removido com o último elemento do heap
    Maquina temp = v[i];
    v[i] = v[*n - 1];
    v[*n - 1] = temp;

    // Reduz o tamanho do heap
    (*n)--;

    // Ajusta o heap para manter a propriedade de heap
    if (i < *n) {
        int left, right, smallest;
        while (1) {
            left = 2 * i + 1;
            right = 2 * i + 2;
            smallest = i;

            if (left < *n && v[left].carga < v[smallest].carga) {
                smallest = left;
            }
            if (right < *n && v[right].carga < v[smallest].carga) {
                smallest = right;
            }
            if (smallest == i) {
                break;
            }

            Maquina temp = v[i];
            v[i] = v[smallest];
            v[smallest] = temp;
            i = smallest;
        }

        // Ajusta o heap para cima, se necessário
        while (i > 0 && v[(i - 1) / 2].carga > v[i].carga) {
            Maquina temp = v[i];
            v[i] = v[(i - 1) / 2];
            v[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }
}









/*Escreva uma função monta-árvore que recebe uma expressão aritmética com operadores +, -, * e / 
e operandos identificados por uma letra cada um, e devolve uma árvore binária que representa essa expressão, 
conforme o exemplo mostrado em aula.*/

/*Escreva uma função calcula que recebe a árvore que você montou no exercício 1 e devolve o valor da expressão 
nela guardada, supondo que você tem à sua disposição uma rotina valor que, dada uma letra, devolve o valor 
associado àquela letra na expressão. Quanto tempo sua função consome em função do número de nós da árvore?*/
int calcula(Arvore r)
{
   if (r == NULL)
      return 0;
   int valor_esq = calcula(r->esquerda);
   int valor_dir = calcula(r->direita);

   switch (r->valor)
   {
   case '+':
      return valor_esq + valor_dir;
   case '-':
      return valor_esq - valor_dir;
   case '*':
      return valor_esq * valor_dir;
   case '/':
      return valor_esq / valor_dir;
   default:
      return valor(r->valor);
   }
}

/*Escreva uma função posfixa que recebe a árvore que você montou no exercício 1 
e imprime a notação posfixa da expressão nela armazenada.*/

/*Escreva uma função recursiva máximo que recebe uma árvore r não-vazia e 
devolve um apontador para o nó com conteúdo máximo em r.*/

/*Escreva uma função nível que recebe uma ABB r e um elemento x que aparece na árvore r, e devolve o 
nível do nó que contém x em r.*/

/*Escreva a função remoção, que recebe o apontador p para um nó de uma ABB e remove o conteúdo do nó 
apontado por p da ABB, deixando-a uma ABB após a operação.*/








/*Declare um tipo struct celula, com dois campos: chave (int) e Link (apontador para struct celula). 
Usando esse tipo, escreva uma implementação das funções
   int h(int m, int k);

   int busca(Link T[], int m, int k);

   void insere (Link T[], int m, int k);

   void remove (Link T[], int m, int k); 
em que h é é uma função de hash sugerida na aula e a resolução de colisões é por lista encadeada. 
Para escolher o valor de m e a função de hash, considere uma aplicação em que 
vão ser armazenados na tabela de hashing cerca de 1000 inteiros.*/

/*Calcule os vetores ult e alcance, usados nas heurísticas do algoritmo Boyer-Moore, para o padrão abaixo:
      a    b    b    a    b    a    b    b    a    a    b */
      
/*Escreva uma função que tem como parâmetro duas palavras de mesmo comprimento 
e determina se uma é permutação cíclica da outra. Por exemplo, arco e coar são rotações uma da outra.*/








//EPS
void heapify(int indice, int size, Maquina arr[]) {
    int menor = indice;
    int galho_esquerdo = 2 * indice + 1;
    int galho_direito = 2 * indice + 2;

    if (galho_esquerdo < size && arr[galho_esquerdo].carga < arr[menor].carga) {
        menor = galho_esquerdo;
    }

    if (galho_direito < size && arr[galho_direito].carga < arr[menor].carga) {
        menor = galho_direito;
    }

    if (menor != indice) {
        Maquina temp = arr[indice];
        arr[indice] = arr[menor];
        arr[menor] = temp;

        heapify(menor, size, arr);
    }
}

void sortInd(int n, int d[], int id[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (d[id[i]] < d[id[j]]) {
                int temp = id[i];
                id[i] = id[j];
                id[j] = temp;
            }
        }
    }
}