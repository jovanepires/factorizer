/**
 * Number factorizer
 * @description computes prime factors of a natural number
 * @author Jovane Pires
 * @repository https://github.com/jovanepires/factorizer
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int MAX = 1000000;

int isPrime(int n);
int nextPrime();

/**
 * Fatora um número informado pelo usuário, e exibe a saída
 *
 * @param void
 * @return int
 */
int main() {
    long int num = 0; 
    int i = 0, j = 0, p = 2, lp = 2;
    int result[MAX];
    int primos[MAX];

    // inicializando os vetores
    memset(primos, 0, (sizeof(int) * MAX));
    memset(result, 0, (sizeof(int) * MAX));

    system("clear");
    printf ("--> Digite um número: ");
    scanf ("%ld", &num);

    // carregando o primeiro primo
    primos[i] = p;

    while (num != 1) {
    	if (num % p == 0) {
    	    if (lp != p) {
        		lp = p;
        		i += 1;
        		primos[i] = p; // armazena o número primo usado na fatoração
    	    }

    	    printf("---> %-20ld\t|\t%d\n", num, p);
    	    num = num / p;
    	    result[i] += 1; // incrementa o expoente 
    	} else {
    	    p = nextPrime();
    	}
    }

    // imprime a forma fatorada do número informado
    printf("\n--> ");	
    for (j = 0; j < MAX; j++) {
    	if (result[j] > 0) {
    	    printf( "%d^%d x ", primos[j], result[j]);
    	}
    }
    printf("1\n\n");

    return 0;
}

/**
 * Verifica se um número é primo
 *
 * @param int Número a ser verificado 
 * @return int
 */
int isPrime(int n) {
    int p = 1, i = 0;

    if (n == 2) {
        return 1;
    }

    if (n%2 == 0 || n <= 1) {
        p = 0;
    } else {
        for(i=3; i<=sqrt(n); i+=2){
            if (n % i == 0) {
                p = 0;
            }
        }
    }

    return p;
}

/**
 * Retorna o valor do próximo número primo, \
 * com base no anterior armazenado na variável n 
 *
 * @param void
 * @return int
 */
int nextPrime() {
    static int n = 2;
    n = n + 1;
    if ((n % 2 == 0) && (n != 2)){
        n += 1;
    }
    while (isPrime(n) != 1){
        n += 2;
    }
    return n;
}
