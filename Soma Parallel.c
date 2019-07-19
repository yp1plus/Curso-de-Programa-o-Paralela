/* Programa de soma simples com programação paralela utilizando reduction 
 * By Yure Pablo 09/04/2019
*/

#include <stdio.h>
#include <omp.h>

int main(){
    int N;

    scanf("%d", &N);
    int i;
    double soma = 0;
    #pragma omp parallel for private (i) reduction(+:soma)
    for (i = 1; i <= N; i++){
        soma += i;
    }
    printf("%.2f",soma);
    return 0;
    //10^9 com reduction
    /*real	0m6,034s
    user	0m2,841s
    sys	0m0,000s*/
    //10^9 sem reduction
    /*real	0m10,648s
    user	0m2,714s
    sys	0m0,000s*/
}