/*      Problema 1851 - Como Treinar Seu Dragão
Solução utilizando Fila de Prioridade
*/

#include <cstdio>
#include <queue>
#include <vector>

typedef unsigned long long int uint64;
struct dragao_t { uint64 c, i, t, f; double r; };
// c: dia de chegada do dragao
// i: dia de inicio do treino
// t: tempo gasto para treinar
// f: multa por cada dia na fila
// r: razao entre t/f

struct compDragao {
    bool operator()(const dragao_t & a, const dragao_t & b) {
        if (a.r != b.r)
            return a.r > b.r;
        else
            return a.c > b.c;
    }
};

int main(int argc, char const *argv[]) {
    uint64 tempo, multa, dia, total;
    std::priority_queue<dragao_t, std::vector<dragao_t>, compDragao> fila;
    dragao_t dr, atual;

    dia = 1; total = 0;
    while (scanf("%llu %llu", &tempo, &multa) != EOF) {
        dr.c = dia;
        dr.i = 0;
        dr.t = tempo;
        dr.f = multa;
        dr.r = tempo / (multa * 1.0);
        fila.push(dr);
        //printf("Dia=%llu \tFila=(%llu, %llu, %llu, %llu, %lf) \t\tTotal=%llu\n", dia, dr.c, dr.i, dr.t, dr.f, dr.r, total);
        if (dia == 1 || dia == atual.t + atual.i) {
            atual = fila.top();
            fila.pop();
            atual.i = dia;
            total += ((dia - atual.c) * atual.f);
            //printf("Dia=%llu \tTreino=(%llu, %llu, %llu, %llu, %lf) \tTotal=%llu\n", dia, atual.c, atual.i, atual.t, atual.f, atual.r, total);
        }
        dia++;
    }

    dia += (atual.t - (dia - atual.i));
    while (!fila.empty()) {
        atual = fila.top();
        fila.pop();
        total += ((dia - atual.c) * atual.f);
        atual.i = dia;
        //printf("Dia=%llu \tTreino=(%llu, %llu, %llu, %llu, %lf) \tTotal=%llu\n", dia, atual.c, atual.i, atual.t, atual.f, atual.r, total);
        dia += atual.t;
    }

    printf("%llu\n", total);
    return 0;
}
