/*      Problema 1595 - Humm.. Andar ou Correr.. Eis a Questão
Solução utilizando método guloso O(nlogn)
*/

#include <stdio.h>
#include <algorithm>

int main(int argc, char const *argv[]) {
    int t, s, c, r, i;
    double tempo, vel[400000];

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &s, &c, &r);
        for (i = 0; i < s; i++)
            scanf("%lf", &vel[i]);

        std::sort(vel, vel+s);
        tempo = 0;
        for (i = 0; i < s; i++) {
            if (i < c)
                tempo += (1 / (vel[i] + r));
            else
                tempo += (1 / vel[i]);
        }
        printf("%.2lf\n", tempo);
    }

    return 0;
}
