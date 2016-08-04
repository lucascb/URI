/*      Problema 1661 - Comércio de Vinhos na Gergóvia */

#include <cstdio>
#define ABS(x) ((x >= 0) ? x : -x)

int main(int argc, char const *argv[]) {
    int n, i, aux;
    long long int qtde, t;

    while (true) {
        scanf("%d", &n);
        if (n == 0)
            break;

        scanf("%lld", &qtde);
        t = 0;
        for (i = 1; i < n; i++) {
            scanf("%d", &aux);
            t += ABS(qtde);
            qtde += aux;
        }
        printf("%lld\n", t);
    }

    return 0;
}
