#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (void)
{
    
    int matriz[300][300];
    int valorusuario,i,j,contido=0;
    
    
    printf("****** Comparador de valores aleátorios de uma matriz com valor informado pelo usuário ******\n");
    printf("\nPor favor informe um valor entre 1 e 300:\n\n");
    scanf("%d", &valorusuario);
    
    if (!(valorusuario > 0 && valorusuario < 300)) {
    printf("Valor inválido!!!");
        exit(0);
    }
    srand(time(NULL));
    
    for (i = 0; i < 300; i++) {
        for (j = 0; j < 300; j++) {
            matriz[i][j] = rand () %299+1;
            printf("%d ", matriz[i][j]);
            }
        printf("\n");

    }
    for (i = 0; i < 300; i++) {
        for (j = 0; j < 300; j++) {
            if (matriz[i][j] == valorusuario) {
                printf("\nO valor esta contido na matriz e esta na posicao [%d][%d]\n", i,j);
                contido = 1;
            }
        }
    }
    if (contido == 0) {
         printf("\nO valor não esta contido na matriz");
    }
    
    
    
    
    return(0);
}
