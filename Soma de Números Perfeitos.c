/* Programa de soma de múltiplos de um número com a cláusula private
 * By Yure Pablo em 29/04/2019
 */
#include<stdio.h>

#include <omp.h>

int main(){
    int n,i; //inteiro positivo
    int soma = 0;
    //teste de 10^5 com pragma
    /*real	0m7,465s
      user	0m17,073s
      sys	0m0,004s*/

    //teste de 10^5 sem pragma
    /*real	0m16,323s
      user	0m16,315s
      sys	0m0,004s*/

    #pragma omp parallel for private(n,i,soma)
    for (n = 1; n <= 10000; n++){
        for (i = 1; i < n; i++){
            if (n%i == 0){
                soma+=i;
            }
        }
    if (soma == n) printf("%d, ",n);
    soma = 0;
    }
}