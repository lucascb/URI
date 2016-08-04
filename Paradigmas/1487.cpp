/*      Problema 1487 - Six Flags
Solução utilizando PD, algoritmo da mochila com repetição
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 1000000

int N, duracao[100], pontuacao[100], table[1000][1000];

// Algoritmo da mochila com repeticao
int knapsack(int i, int t) {
    if (t < 0)
        return -INF;
    if (i == N || t == 0)
        return 0;
    if (table[i][t] != -1)
        return table[i][t];
    return table[i][t] = std::max(pontuacao[i] + knapsack(i, t-duracao[i]),
                                    knapsack(i+1, t));
}

int main(int argc, char const *argv[]) {
    int t, i, c = 1;

    while (true) {
        scanf("%d %d", &N, &t);
        if (N == 0 && t == 0)
            break;
        for (i = 0; i < N; i++)
            scanf("%d %d", &duracao[i], &pontuacao[i]);
        memset(table, -1, sizeof table);
        printf("Instancia %d\n%d\n\n", c++, knapsack(0, t));
    }

    return 0;
}
