#include <stdio.h>

int valor(char ch); 
int eh_operador(char ch);
int eh_letra(char ch);

int calcula_prefixo(char expr[], int *index) {

    char ch = expr[(*index)++];

    if (eh_letra(ch)) {
        return valor(ch);
    }

    if (eh_operador(ch)) {
        int operando1 = calcula_prefixo(expr, index);
        int operando2 = calcula_prefixo(expr, index);

        switch (ch) {
            case '+': return operando1 + operando2;
            case '-': return operando1 - operando2;
            case '*': return operando1 * operando2;
            case '/': return operando1 / operando2;
        }
    }

    return 0; 
}


int main() {
    char expr[] = "-+A*BC/+/-D/EFGH+I"; 
    int index = 0;
    int resultado = calcula_prefixo(expr, &index);
    printf("O resultado da expressão é: %d\n", resultado);

    return 0;
}


int valor(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 1;
    }
    else if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 1;
    }
    else {
        return -1; 
    }
}

int eh_operador(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int eh_letra(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}