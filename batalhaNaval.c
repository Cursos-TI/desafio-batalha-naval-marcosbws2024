
#include <stdio.h>
#define tam 11

int main() {
	char matriz[tam][tam];
	int i, j;

	// Preenchendo a primeira linha com letras de A a J
	matriz[0][0] = ' ';  // Primeira posiC'C#o C) um espaC'o
	for (j = 1; j < tam; j++) {
		matriz[0][j] = 'A' + (j - 1);  // Letras de A a J
	}

	// Preenchendo a primeira coluna com nC:meros de 1 a 9
	for (i = 1; i < tam; i++) {
		matriz[i][0] = '0' + i;  // NC:meros de 1 a 9 (como caractere)
	}

	// Preenchendo o restante da matriz com '~'
	for (i = 1; i < tam; i++) {
		for (j = 1; j < tam; j++) {
			matriz[i][j] = '~';  // Preenchendo com '0'
		}
	}

//Posicionando o barco na diagonal debaixo para cima linha A10 ate coluna C8
	for(int i =10, j=1; i<tam &&j<tam; i--,j++) {
		if(j<4) {
			matriz[i][j]='3';
		}
	}

//Posicionando na diagonal a partir a linha A1 até a C3
	for(int i=1, j=1; i<tam && j<tam; i++,j++) {
		if(i<4) {
			matriz[i][j]='1';
		}
	}

//Posicionando na diagonal a partir da linha A3 até a C5 
	for(int i=3, j=1; i<tam && j<tam; i++,j++) {
		if(j<4)
			matriz[i][j]='6';
	}



//Posicionando na vertical da linha E8 até E10
	for(int i=8, j=1; j<tam && i<tam; i++,j++) {
		matriz[i][5]='7';
	}

//Posicionando na vertical da linha I8 até I10
	for(int i=8, j=1; j<tam && i<tam; i++,j++) {
		matriz[i][9]='9';
	}

//Posiconando na horizontal a partir da linha E1 até G1 
	for(int i=1, j=5; j<tam && i<tam; i++,j++) {
		if(i<4) {
			matriz[1][j]='8';
		}
	}

//Posicionando na Diagonal a partir da linha I1 ate G3
	for(int i=1, j=9; j<tam && i<tam; i++,j--) {
		if(i<4) {
			matriz[i][j]='5';
		}
	}

//Posicionando na Diagonal a partir da linha J1 ate H4
	for(int i=1, j=10; j<tam && i<tam; i++,j--) {
		if(i<4) {
			matriz[i][j]='4';
		}
	}


//Posiconando na horizontal a partir da linha E5 até G5 
	for(int i=5, j=5; j<tam && i<tam; i++,j++) {
	    if(i<8) {
		matriz[5][j]='2';
	    }
	}



// Imprimindo a matriz desde a posiC'C#o 0 de I e J para pegar a linha numerica e alfabC)tica
	for (i = 0; i < tam; i++) {
		for (j = 0; j < tam; j++) {
			// Se for o nC:mero 10 na primeira coluna, exibe corretamente
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