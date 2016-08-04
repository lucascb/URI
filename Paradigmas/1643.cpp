/*      Problema 1642 - Converter Quilômetros para Milhas       */

#include <cstdio>

int fib[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711};

int main(int argc, char const *argv[]) {
    int t, n, i, f;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        // Converte n para base fibonacci
        f = 0;
        for (i = 20; i >= 0; i--) {
            if (n / fib[i])
                f |= (1 << i);
            n %= fib[i];
        }
        // Desloca f uma posicao para a direita
        f >>= 1;
        n = 0;
        // Calcular f deslocado na base fibonacci
        for (i = 20; i >= 0; i--) {
            if ((f & (1 << i)) != 0)
                n += fib[i];
        }
        printf("%d\n", n);
    }

    return 0;
}
