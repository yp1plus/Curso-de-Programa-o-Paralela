/* Soma de vetores com manipulação de variáveis da omp 
 * By Yure Pablo em 29/04/2019
 */
#include <stdio.h>
#include <omp.h>

#define N 1000
#define TH 10

int main(){
    int i = 0; //índice
    long long int soma[TH] = {0},sum = 0;
    
    /*const int indiceThread = omp_get_thread_num();
    const int num_threads = omp_get_num_threads();
    long long int loop_inicial = N/num_threads*indiceThread;
    long long int loop_final = N/num_threads * (indiceThread+1);*/

    #pragma omp parallel num_threads(TH) private(i)
    for (i = (N/TH)*(omp_get_thread_num()); i < (N/TH)*(omp_get_thread_num()+1); i++){
        soma[omp_get_thread_num()]+=i;
    }

    for (i = 0; i < TH; i++){
        sum+=soma[i];
    }

    printf("%lld\n", sum);
    return 0;
}