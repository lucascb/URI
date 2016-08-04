/*      Problema 1301 - Produto do Intervalo
Solução utilizando Segment Tree
*/

#include <cstdio>
#define LEFT(P) (P << 1)
#define RIGHT(P) ((P << 1) + 1)
#define MID(L, R) ((L + R) >> 1)

int array[100000], n;
char st[400000];

void build(int p, int L, int R) {
    if (L == R)
        st[p] = array[L];
    else {
        build( LEFT(p), L, MID(L, R) );
        build( RIGHT(p), MID(L, R)+1, R );
        st[p] = st[ LEFT(p) ] * st[ RIGHT(p) ];
    }
}

int getProduct(int p, int i, int j, int L, int R) {
    if (i > R || j < L)
        return 1;
    if (i <= L && j >= R)
        return st[p];
    return getProduct( LEFT(p), i, j, L, MID(L, R) ) *
            getProduct( RIGHT(p), i, j, MID(L, R) + 1, R );
}

// Retorna o produto dos elementos em array[i..j]
int getProduct(int i, int j) { return getProduct(1, i-1, j-1, 0, n-1); }

void update(int p, int i, int L, int R) {
    if (L > i || R < i)
        return;
    if (L == R)
        st[p] = array[L];
    else {
        update( LEFT(p), i, L, MID(L, R) );
        update( RIGHT(p), i, MID(L, R) + 1, R );
        st[p] = st[ LEFT(p) ] * st[ RIGHT(p) ];
    }
}

// Atualiza array[i] = k
void update(int i, int k) {
    if (k == 0) array[i-1] = 0;
    else if (k > 0) array[i-1] = 1;
    else array[i-1] = -1;
    update(1, i-1, 0, n-1);
}

int main(int argc, char const *argv[]) {
    int k, x, y, i, p;
    char t;

    while (scanf("%d %d", &n, &k) != EOF) {
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            if (x == 0) array[i] = 0;
            else if (x > 0) array[i] = 1;
            else array[i] = -1;
        }
        build(1, 0, n-1);
        for (i = 0; i < k; i++) {
            getchar();
            scanf("%c %d %d", &t, &x, &y);
            if (t == 'P') {
                p = getProduct(x, y);
                if (p > 0)
                    printf("+");
                else if (p < 0)
                    printf("-");
                else
                    printf("0");
            }
            else
                update(x, y);
        }
        printf("\n");
    }

    return 0;
}
