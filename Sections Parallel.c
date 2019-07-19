/* Programa para cálculos de área, perímetro e diagonal com seções paralelas
 * By Yure Pablo em 29/04/2019 
*/
#include <stdio.h>
#include <omp.h>
#include <math.h>

float area(int base, int altura){
    return base*altura;
}

float perimetro(int base, int altura){
    return 2*base+2*altura;
}

float diagonal(int base, int altura){
    return sqrt(base*base+altura*altura);
}

int main(){
    int N = 0;
    scanf("%d",&N);
    float base[N];
    float altura[N];

    for (int i = 0; i < N; i++){
        scanf("%f %f",&base[i],&altura[i]);
        #pragma omp parallel
        {
            #pragma omp sections
            {
                #pragma omp section
                {
                    printf("Área: %f\n",area(base[i],altura[i]));
                }
                #pragma omp section
                {
                    printf("Perímetro: %f\n", perimetro(base[i],altura[i]));
                }
                #pragma omp section
                {
                    printf("Diagonal: %f\n", diagonal(base[i],altura[i]));
                }
            }
        }
        
    }

}