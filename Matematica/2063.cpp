/*      Problema 2063 - Caçando Digletts */

#include <cstdio>

// Maximo divisor comum
int gcd(int a, int b) {
    int t;

    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Minimo multiplo comum
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main(int argc, char const *argv[]) {
    int n, buracos[1000], profundidades[1000], visitados[1000], i, j, k, aux;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &buracos[i]);
        visitados[i] = 0;
        profundidades[i] = 1;
    }

    k = 0;
    for (i = 0; i < n; i++) {
        if (!visitados[i]) {
            //printf("%d ", buracos[i]);
            j = buracos[i]-1;
            aux = 1;
            while (j != i) {
                //printf("%d ", buracos[j]);
                visitados[j] = 1;
                j = buracos[j]-1;
                aux++;
            }
            //printf("= %d\n", aux);
            visitados[i] = 1;
            profundidades[k] = aux;
            k++;
        }
    }

    /*
    for (i = 0; i < k; i++)
        printf("%d ", profundidades[i]);
    printf("\n");
    //*/

    aux = profundidades[0];
    for (i = 1; i < k; i++) {
        aux = lcm(aux, profundidades[i]);
    }
    printf("%d\n", aux);

    return 0;
}
