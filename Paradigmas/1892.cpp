/*      Problema 1892 - Calouro Vence Veterano?
Solução utilizando MergeSort para contar o numero de inversoes
Visto em: https://www.ime.usp.br/~cris/aulas/11_1_338/slides/aula3.pdf
*/

#include <cstdio>
#include <cstring>

typedef unsigned long long int ulli;

char A[400000][11], B[400000][11];

ulli merge_count(int p, int q, int r) {
    int i, j, k;
    ulli c;

    for (i = p; i <= q; i++)
        strcpy(B[i], A[i]);

    for (j = q+1; j <= r; j++)
        strcpy(B[r+q+1-j], A[j]);

    i = p;
    j = r;
    c = 0;

    for (k = p; k <= r; k++) {
        if (strcmp(B[i], B[j]) <= 0) {
            strcpy(A[k], B[i]);
            i++;
        }
        else {
            strcpy(A[k], B[j]);
            j--;
            c += (q-i+1);
        }
    }

    return c;
}

ulli sort_count(int p, int r) {
    if (p >= r)
        return 0;
    int q = (p + r) / 2;
    return sort_count(p, q) + sort_count(q+1, r) + merge_count(p, q, r);
}

int main(int argc, char const *argv[]) {
    int n, i;

    while (scanf("%d", &n) != EOF) {
        getchar();
        for (i = 0; i < n; i++)
            scanf("%s", A[i]);

        printf("%llu\n", sort_count(0, n-1));
    }

    return 0;
}
