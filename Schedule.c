/* Programa de soma de múltiplos com diferentes tipos de schedule 
 * By Yure Pablo em 08/04/2019 
 */
#include<stdio.h>
#include <omp.h>

int main(){
    int n,i; //inteiro positivo
    int soma = 0;
    //teste de 100000 com pragma
    /*real	0m7,465s
      user	0m17,073s
      sys	0m0,004s*/

    //teste de 100000 sem pragma
    /*real	0m16,323s
      user	0m16,315s
      sys	0m0,004s*/

    //teste de 100000 com schedule dynamic
    /* real 0m4,327s
       user	0m15,647s
       sys	0m0,008s */
    
    //teste de 100000 com schedule static
    /*real	0m7,266s
    user	0m15,682s
    sys	0m0,000s */
    
    //teste de 100000 com schedule guided
    /*real	0m4,325s
      user	0m15,628s
      sys	0m0,000s*/


    #pragma omp parallel for private(n,i,soma) schedule(static)
    for (n = 1; n <= 100000; n++){
        for (i = 1; i < n; i++){
            if (n%i == 0){
                soma+=i;
            }
        }
      if (soma == n) printf("%d, ",n);
      soma = 0;
    }
}