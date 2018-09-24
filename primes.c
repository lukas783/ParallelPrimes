#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

int main(int argc, char*argv[]) {
    if(argc != 2) {
        printf("Invalid number of arguments.\nUsage: %s max_prime\n\
Where 'max_prime' is the largest prime number to check\n\n", argv[0]);
        return 1;
    }

    long long i;

    int max_prime = atoi(argv[1]);
    int* prime_array = malloc(sizeof(int)*max_prime);
    memset(prime_array, 0, sizeof(int)*max_prime);
    prime_array[0] = 1;
    prime_array[1] = 1;
    int thread_count = omp_get_num_procs();
    #pragma omp parallel for num_threads(thread_count) private(i)
    for(i = 2; i < max_prime; i++) {
        for(int p = 2; max_prime > p*i; p++) {
            prime_array[p*i] = 1;
        }
    }
    /*
    for(int i = 2; i < max_prime; i++) {
        if(prime_array[i] == 0) {
            printf("%d, ", i);
        }
    }*/
    printf("\n\n");

    free(prime_array);
    return 0;
}