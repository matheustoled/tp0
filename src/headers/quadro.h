#ifndef QUADRO_H_
#define QUADRO_H_

#define LINHAS 20
#define COLUNAS 80

char quadro[LINHAS][COLUNAS];

void inicializar_quadro();
void imprimir_quadro();
int verificar_posicao(int linha_inicial, int coluna_inicial, int altura_figura, int largura_figura, char figura[altura_figura][largura_figura]);
void desenhar_figura(int linha_inicial, int coluna_inicial, int altura_figura, int largura_figura, char figura[altura_figura][largura_figura]);

#endif