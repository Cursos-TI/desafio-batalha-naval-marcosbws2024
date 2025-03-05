#include <stdio.h>
#define tam 11

int main() {
    char matriz[tam][tam];  
    int i, j;

    // Preenchendo a primeira linha com letras de A a J
    matriz[0][0] = ' ';  // Primeira posição é um espaço
    for (j = 1; j < tam; j++) {
        matriz[0][j] = 'A' + (j - 1);  // Letras de A a J
    }

    // Preenchendo a primeira coluna com números de 1 a 9
    for (i = 1; i < tam; i++) {
        matriz[i][0] = '0' + i;  // Números de 1 a 9 (como caractere)
    }

    // Preenchendo o restante da matriz com '0'
    for (i = 1; i < tam; i++) {
        for (j = 1; j < tam; j++) {
            matriz[i][j] = '0';  // Preenchendo com '0'
        }
    }
    
    
//51 valor para Numero 3 
//Com o vetor de char pode usar um numero da tabele asc para representar numero ou letra
matriz [8][3] = '3';
matriz [7][3] = '3';
matriz [6][3] = '3';

matriz [1][3] = '3';
matriz [1][2] = '3';
matriz [1][1] = '3';

matriz [1][7] = 51;
matriz [1][8] = 51;
matriz [1][9] = 51;

matriz [3][7] = 51;
matriz [4][8] = 51;
matriz [5][9] = 51;

matriz [4][1] = 51;
matriz [4][2] = 51;
matriz [4][3] = 51;



    // Imprimindo a matriz desde a posição 0 de I e J para pegar a linha numerica e alfabética
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
          // Se for o número 10 na primeira coluna, exibe corretamente
            if (i == 10 && j == 0) {
                printf("%3s ", "10");
            } else {
                printf("%3c ", matriz[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
