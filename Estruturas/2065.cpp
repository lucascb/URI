/*      Problema 2065 - Fila do Supermercado
Solução utilizando Fila de Prioridade
*/

#include <cstdio>
#include <queue>
#include <vector>

typedef struct func { int id; int at; int t; } func_t;

struct compareFunc {
    bool operator()(const func_t & a, const func_t & b) {
        if (a.t != b.t)
            return a.t > b.t;
        else
            return a.id > b.id;
    }
};

int main(int argc, char const *argv[]) {
    std::priority_queue<func_t, std::vector<func_t>, compareFunc> caixas;
    int n, m, i, j, t;
    func_t f;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d", &f.at);
        f.id = i;
        f.t = 0;
        caixas.push(f);
    }

    //printf("\n");
    t = 0;
    for (i = 0; i < m; i++) {
        scanf("%d", &j);
        f = caixas.top();
        caixas.pop();
        f.t += (f.at * j);
        if (f.t > t) t = f.t;
        caixas.push(f);
    }
    //printf("id=%d at=%d f=%d\n", f.id, f.at, f.t);
    /*
    while (!caixas.empty()) {
        f = caixas.top();
        //printf("\nid=%d at=%d f=%d\n", f.id, f.at, f.t);
        caixas.pop();
    }
    //*/

    printf("%d\n", t);

    return 0;
}
