/* Programa para calcular a quantidade de números perfeitos com programação paralela
 * By Yure Pablo em 29/04/2019
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX 700

//max_threads = omp_get_max_threads(); número máximo de threads que será criado por padrão
//num_procs = omp_get_num_procs(); número de processadores (núcleos)
//num_threads = omp_get_num_threads(); Número atual de threads
//thread_num = omp_get_thread_num(); Obtém o número da thread (atual)
// in_parallel = omp_in_parallel(); retorna 1 se estiver no bloco paralelo; retorna 0 se estiver em um bloco sequencial;
// wtime = omp_get_wtime(); Coleta um valor que represente a quantidade de segundos passados desde o valor inicial do relógio;

int main(int argc,char **argv) {
    int i, j;
    int quant_num_perfeitos=0; //Armazenada a quantidade de números perfeitos encontrados
    int num_perfeitos[10]; //Vetor para armazenar os números perfeitos
    int soma;

    /*Torna variáveis críticas privadas para evitar choques de valores */
    #pragma omp parallel for private (i,j,soma) schedule (guided) num_threads(4)
    for (i = 1; i < MAX; i++){
        soma = 0;
        #pragma omp parallel for private (j) num_threads(4)
        for (j = 1; j < i; j++){
            if(i%j == 0){
                soma += j;
            }
        }
        if (soma == i){
            /*Estabelece pontos críticos para serem executados separadamente */
            #pragma omp critical
            {
                num_perfeitos[quant_num_perfeitos]=i;
                quant_num_perfeitos++;
            }
        
        }
    }
    
    printf("Quantidade de nrs perfeitos = %d \n", quant_num_perfeitos);
    
    for(i=0;i<quant_num_perfeitos;i++){
        printf("%d ",num_perfeitos[i]);
    }
    printf("\n");
    return 0;
}
