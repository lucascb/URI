/*      Problema 1084 - Apagando e Ganhando     */

#include <cstdio>

int main(int argc, char const *argv[]) {
    int n, d, i, j, cont;
    char num[100001], result[100001];

    while (true) {
        scanf("%d %d", &n, &d);
        if (n == 0 && d == 0)
            break;

        getchar();
        scanf("%s", num);

        j = cont = 0;
        for (i = 0; i < n; i++) {
            while ((j > 0) && (cont < d) && (num[i] > result[j-1])) {
                cont++;
                j--;
            }
            if (j < n-d) {
                result[j] = num[i];
                j++;
            }
        }
        result[j] = '\0';

        printf("%s\n", result);
    }

    return 0;
}
