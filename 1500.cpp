/*      Problema 1500 - Consultas Horriveis
Solução utilizando Fenwick Tree com range updates e queries
Visto em: https://kartikkukreja.wordpress.com/2013/12/02/range-updates-with-bit-fenwick-tree/
*/

#include <cstdio>
#include <cstring>
#define LSOne(S) (S & (-S))

typedef long long int ll;

ll A[100009], B[100009];
int N;

void update(ll ft[], int i, ll v) {
    for (; i <= N; i += LSOne(i))
        ft[i] += v;
}

// Atualiza em v o intervalo array[a..b]
void update(int a, int b, ll v) {
    update(A, a, v);
    update(A, b+1, -v);
    update(B, a, v * (a-1));
    update(B, b+1, (-v) * b);
}

ll query(ll ft[], int i) {
    ll sum = 0;
    for (; i; i -= LSOne(i)) sum += ft[i];
    return sum;
}

ll query(int b) { return (query(A, b) * b) - query(B, b); }

ll range_query(int a, int b) { return query(b) - query(a-1); }

int main(int argc, char const *argv[]) {
    int t, c, cmd, p, q;
    ll v;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &N, &c);
        memset(A, 0, (N+1) * sizeof(ll));
        memset(B, 0, (N+1) * sizeof(ll));
        while (c--) {
            scanf("%d %d %d", &cmd, &p, &q);
            if (cmd == 0) {
                scanf("%lld", &v);
                update(p, q, v);
            }
            else
                printf("%lld\n", range_query(p, q));
        }
    }

    return 0;
}
