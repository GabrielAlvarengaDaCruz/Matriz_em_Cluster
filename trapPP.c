#include <stdio.h>
#include <string.h>
#include "mpi.h"
main(int argc, char *argv[])
{
        int ret, rank, size, i, tag;
	double tempo_inicial,tempo_final;
	int j, matriz[300][300],contido=0,valorusuario;
        MPI_Status status;
	int a=0;

        ret = MPI_Init(&argc, &argv);

        ret = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        ret = MPI_Comm_size(MPI_COMM_WORLD, &size);

        tag=100;
	tempo_inicial = MPI_Wtime();
        if (rank == 0)
        {


		printf("**** Comparador de valores aleatórios de uma matriz com valor informado pelo usuário ****\n");
		printf("\nPor favor informe um valor entre 1 e 300:\n\n");
		scanf("%d", &valorusuario);

		if(!(valorusuario > 0 && valorusuario < 300)){
			printf("Valor Inválido !!!");
		}
		else{
			srand(time(NULL));	

			for(i = 0; i < 30; i++){
				for(j=0; j < 30; j++){
					
					matriz[i][j] = rand () %301;
					//printf("%d ", matriz[i][j]);// imprime os valores aleatorios da matriz, caso seja necessario verificar
				}
				//printf("\n");
			}		


			ret = MPI_Send(&a, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
			ret = MPI_Send(&a, 1, MPI_INT, 2, tag, MPI_COMM_WORLD);
			ret = MPI_Send(&a, 1, MPI_INT, 3, tag, MPI_COMM_WORLD);


			for(i = 0; i < 50; i++){
				for(j=0; j < 50; j++){
					if(matriz[i][j] == valorusuario){
					printf("\nO valor esta contido na matriz e esta posicao [%d][%d]\n", i,j);
					contido = 1;
					}
				}
			}	


			ret = MPI_Recv(&a, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &status);
			ret = MPI_Recv(&a, 1, MPI_INT, 2, tag, MPI_COMM_WORLD, &status);
			ret = MPI_Recv(&a, 1, MPI_INT, 3, tag, MPI_COMM_WORLD, &status);

			if(contido == 0){
				printf("\n\nO valor nao esta contido na matriz\n\n");	
			}
		}
        }
        else if (rank == 1){
		ret = MPI_Recv(&a, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
		for(i = 50; i < 100; i++){
			for(j=50; j < 100; j++){
				if(matriz[i][j] == valorusuario){
					printf("\nO valor esta contido na matriz e esta posicao [%d][%d]\n", i,j);
					contido = 1;
				}
			}
		}	
		ret = MPI_Send(&a, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
	}
        else if (rank == 2){
		ret = MPI_Recv(&a, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
		for(i = 100; i < 200; i++){
			for(j=100; j < 200; j++){
				if(matriz[i][j] == valorusuario){
					printf("\nO valor esta contido na matriz e esta posicao [%d][%d]\n", i,j);
					contido = 1;
				}
			}
		}
		ret = MPI_Send(&a, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
	}
        else if (rank == 3){
		ret = MPI_Recv(&a, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
		for(i = 200; i < 300; i++){
			for(j=200; j < 300; j++){
				if(matriz[i][j] == valorusuario){
					printf("\nO valor esta contido na matriz e esta posicao [%d][%d]\n", i,j);
					contido = 1;
				}
			}
		}
		ret = MPI_Send(&a, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
	}
	tempo_final = MPI_Wtime() - tempo_inicial;
	printf("%f ", tempo_final);
        ret = MPI_Finalize();
}


