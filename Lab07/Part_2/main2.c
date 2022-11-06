
#include <stdio.h>
#include <stdlib.h>
#include <omp.h> 
#include <math.h>
#define e 2.7182818

void Trap (double a, double b, int n, double* global_result_p, omp_lock_t trava);
double f (double x);


int main(int argc, char* argv[]){
    omp_lock_t trava;
    double global_result = 0.0;
    double a, b;
    int n;
    int thread_count;

    thread_count = strtol(argv[1], NULL, 10);
    a = 0;
    b = 5;
    n = 1000000;
    //printf("Enter a, b, and n\n");
    //scanf("%lf %lf %d", &a, &b, &n);
  #  pragma omp parallel num_threads(thread_count)
    Trap (a, b, n, &global_result, trava);

    printf("With n = %d, trapezoids, our estimate\n", n);
    printf("of the integral from %f to %f = %.14e\n", a, b, global_result);

    
    return 0;
}

void Trap (double a, double b, int n, double* global_result_p, omp_lock_t trava) {
    omp_init_lock(&trava);
    double h, x, my_result;
    double local_a, local_b;
    int i, local_n;
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    h = (b-a) / n;
    // Definição das variáveis locais
    local_n = n/thread_count;
    local_a = a + my_rank * local_n * h;
    local_b = local_a + local_n * h;
    // Cálculo do trapézio local
    my_result = (f(local_a) + f(local_b)) / 2.0;
    // Se move pela curva da função
    # pragma omp parallel for 
    /*for (i = 1; i <= local_n - 1; i++)
    {
        x = local_a + i * h;
        my_result += f(x);
    }*/
    my_result = my_result * h;
    if (my_result < 0) my_result *= -1;  // O valor da área não pode ser negativo
    
    omp_set_lock(&trava);
    *global_result_p += my_result;
    omp_unset_lock(&trava);
}

double f (double x) { return cos(pow(e, -x)); }
