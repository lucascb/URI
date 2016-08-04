/* Problema 2095 - Guerra
Solução gulosa
*/

#include <cstdio>
#include <algorithm>

int main(int argc, char const *argv[]) {
    int s, q_army[100000], n_army[100000], i, j, wins;

    scanf("%d", &s);
    for (i = 0; i < s; i++)
        scanf("%d", &q_army[i]);

    for (i = 0; i < s; i++)
        scanf("%d", &n_army[i]);

    std::sort(q_army, q_army+s);
    std::sort(n_army, n_army+s);

    wins = 0;
    i = j = s-1;
    while (i >= 0 && j >= 0) {
        if (n_army[i] > q_army[j]) {
            wins++;
            i--;
        }
        j--;
    }

    printf("%d\n", wins);

    return 0;
}
