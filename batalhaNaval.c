#include <stdio.h>
#include <stdlib.h>

/***********************************Definição das Constantes*************************/
#define TAM 11    //define o tamanho do tavbuleiro.
#define GEO '3'    //define o numero que ser usado para desenhar as formas Geometricas 
#define DESTAB '.' //define a figura que preecher no tabuleiro tirando a guia numerica e alfabetica 


//Cria todo o tabeleiro, mas ainda nC#o preenche as formas numericas e alfabeticas
void criandoTabuleiro(char tab[TAM][TAM]) {
	int i, j;
	// Inicializando matriz, comeC'a do zero pois preenche tudo
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			tab[i][j] = DESTAB;
		}
	}
}

//Cria a primeira linha fazendo a guia de posiC'C#o de coluna em ordem alfabC)tica
void criarGuiaAlfabetica(char tab[TAM][TAM]) {
	int j;
	tab[0][0] = ' '; // Canto superior esquerdo com campo vazio
	for (j = 1; j < TAM; j++) {//comeC'a a preencher iniciando em o j em 1 por que o 0 deve ficar vazio
		tab[0][j] = 'A' + (j - 1); //incia o preenchimento da odem alfabetica
	}
}


//Cria a primeira coluna para guiar a posiC'C#o em ordem numerica.
void criarGuiaNumerica(char tab[TAM][TAM]) {
	int i;
	for (i = 1; i < TAM; i++) {
		if (i < 10)
			tab[i][0] = '0' + i; //esse formato escreve apenas de 0 a 9
		else
			tab[i][0] = 'X'; // Marcador temporC!rio para o numeros que passam de 9
	}

}
// FunC'C#o para desenhar um losango Normal e Simples, pois o Tetraedro C) Formado pro 5 losangulos
void desenhaLosango(char tab[TAM][TAM], int xPosicaoLosango, int yPosicaoLosango, int tamanhoLosango) {
	int meio = tamanhoLosango / 2;
	int i, largura;

	for (i = -meio; i <= meio; i++) {
        //Para desenha as formas geometricas usamos numeros negativos e possitivos, mas para calcular i positivamente converte o numero negativo em positivo com abs(i)
		largura = meio - abs(i);
		//Desenha a primera parte do do losangulo ^
		if (xPosicaoLosango - largura >= 0 && xPosicaoLosango - largura < TAM && yPosicaoLosango + i >= 0 && yPosicaoLosango + i < TAM)
			tab[yPosicaoLosango + i][xPosicaoLosango - largura] = GEO;
		//desenha a segunda parte do losangulo v
		if (yPosicaoLosango + largura >= 0 && xPosicaoLosango + largura < TAM && yPosicaoLosango + i >= 0 && yPosicaoLosango + i < TAM)
			tab[yPosicaoLosango + i][xPosicaoLosango + largura] = GEO;
	}
}

// FunC'C#o para desenhar uma cruz
void desenhaCruz(char tab[TAM][TAM], int x, int y, int tamanho) {
	int i;
	for (i = -tamanho / 2; i <= tamanho / 2; i++) {
		if (y + i >= 0 && y + i < TAM) tab[y + i][x] = GEO; // Desenha a Linha vertical
		if (x + i >= 0 && x + i < TAM) tab[y][x + i] = GEO; // Desenha a Linha horizontal
	}
}

// FunC'C#o para desenhar um cone
void desenhaCone(char tab[TAM][TAM], int x, int y, int altura) {
	int i, j;
	for (i = 0; i < altura; i++) { //desenha as linhas 
		for (j = -i; j <= i; j++) {//desenha as colunas
			if (x + j >= 0 && x + j < TAM && y + i >= 0 && y + i < TAM)
				tab[y + i][x + j] = GEO;
		}
	}
}


//desenhando o tabuleiro completo com as figuras Geometricas
void imprimirTabuleiroCompleto(char tab[TAM][TAM]) {
	int i, j;

	// Imprimindo a matriz
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			if (i == 0 && j > 0) {
				printf("%3c ", 'A' + (j - 1)); // Letras na primeira linha
			} else if (j == 0 && i > 0) {
				printf("%3d ", i); // Numeros na primeira coluna
			} else {
				printf("%3c ", tab[i][j]);//desenho completo da matriz com as figuras 
			}
		}
		printf("\n");
	}
}



int main() {
	char tab[TAM][TAM];
	int i, j;

	// Inicializando matriz
	criandoTabuleiro(tab);

	// Preenchendo a primeira linha com letras de A a Z
	criarGuiaAlfabetica(tab);

	// Preenchendo a primeira coluna com nC:meros
	criarGuiaNumerica(tab);
	// Desenhando a Cruz
	desenhaCruz(tab, 8, 4, 5);

	// Desenhando o Cone
	desenhaCone(tab, 3, 8, 2);

	// Desenhando o Tetraedro com losangos
	
	//desloca todos os losangulos que formam o tetradro juntos
	int deslocX = -3, deslocY = -3;
	//define a quantidade caracteres que serão usados por lado para desenhar o losangulo
	int tamanhoOcta = 1;
	int distancia = tamanhoOcta / 2 + 1;
	int xPosicao = (TAM / 2) + deslocX;
	int yPosicao = (TAM / 2) + deslocY;

	//Cria os losangulos um dentro do outro para formar o Tetraedro.
	desenhaLosango(tab, xPosicao, yPosicao - distancia, tamanhoOcta);
	desenhaLosango(tab, xPosicao, yPosicao, tamanhoOcta);
	desenhaLosango(tab, xPosicao, yPosicao + distancia, tamanhoOcta);
	desenhaLosango(tab, xPosicao + distancia, yPosicao, tamanhoOcta);
	desenhaLosango(tab, xPosicao - distancia, yPosicao, tamanhoOcta);

	imprimirTabuleiroCompleto(tab);

	return 0;
}
