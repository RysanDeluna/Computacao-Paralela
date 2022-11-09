#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long int fat(int n);
void taylor(int n, long double *global);

long long int fats[1000000] = {0};

unsigned long long int fat(int n) {
  if (n == 0)
    fats[n] = 1;
  else
    fats[n] = n * fat(n - 1);
  return fats[n];
}

void taylor(int n, long double *global, omp_lock_t trava) {
  long double my_result = 0.0;
  int minha_thread = omp_get_thread_num();
  int thread_count = omp_get_num_threads();

  for (int i = minha_thread; i < n; i += thread_count)
    my_result += 1 / (double)fat(i);

#pragma omp critical
  *global += my_result;
}

int main(int argc, char *argv[]) {
  int thread_count;
  long double global;

  thread_count = strtol(argv[1], NULL, 10);

  fat(50);

#pragma omp parallel num_threads(thread_count)
  long double taylor(50, &global, trava);

  printf("O resultado obtido é: %.33Lf \n", global);
  return 0;
}
