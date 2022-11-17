#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 4

int pideNum();
void rellenaMatrizAleatorio(int m[][N]);
void buscaMatriz(int m[][N],int num);
void imprimeMatriz(int m[][N]);
void imprimeResultado(int fila, int colu);

int main() {
    int matriz[N][N],num;
    rellenaMatrizAleatorio(matriz);
    imprimeMatriz(matriz);
    num=pideNum();
    buscaMatriz(matriz,num);
    return 0;
}

void rellenaMatrizAleatorio(int m[][N]){
    srand(time(NULL));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            m[i][j]=rand()%10;
        }
    }
}

int pideNum(){
    int num;
    printf("\nIntroduzca el valor que desea buscar en la matriz (1-9): ");
    scanf("%d",&num);
    fflush(stdin);
    while (num<0 || num>9){
        printf("Numero invalido\nIntroduzca el valor que desea buscar en la matriz (1-9): ");
        scanf("%d",&num);
        fflush(stdin);
    }
    return num;
}

void buscaMatriz(int m[][N],int num){
    int hayUno=0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (m[i][j]==num){
                imprimeResultado(i,j);
                hayUno=1;
            }
        }
    }
    if (hayUno==0)
        printf("El elemento %d no se encuentra en la matriz",num);
}

void imprimeMatriz(int m[][N]){
    printf("\n|-------|-------|-------|-------|\n");
    for (int i = 0; i < N; ++i) {
        printf("|");
        for (int j = 0; j < N; ++j) {
            printf("%4d   |",m[i][j]);
        }
        printf("\n|-------|-------|-------|-------|\n");
    }
}

void imprimeResultado(int fila, int colu){
    printf("\nEl elemento se encuentra en la fila %d y columna %d de la matriz.",fila+1,colu+1);
}