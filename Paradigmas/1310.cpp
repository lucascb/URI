/*      Problema 1310 - Lucro
Solução utilizando PD, algoritmo de Kadane em O(n)
Visto em: https://pt.wikipedia.org/wiki/Sublista_contígua_de_soma_máxima
*/

#include <stdio.h>
#define MAX(a, b) ((a >= b) ? a : b)

// Algoritmo de Kadane para Maior Subsequencia Continua
int main(int argc, char const *argv[]) {
    int n, custoPorDia, receita, custoAteAgora, custoAteAqui;

    while (scanf("%d", &n) != EOF) {
        scanf("%d", &custoPorDia);
        custoAteAqui = custoAteAgora = 0;
        while (n--) {
            scanf("%d", &receita);
            custoAteAqui = MAX(0, custoAteAqui + receita - custoPorDia);
            custoAteAgora = MAX(custoAteAgora, custoAteAqui);
        }
        printf("%d\n", custoAteAgora);
    }

    return 0;
}
