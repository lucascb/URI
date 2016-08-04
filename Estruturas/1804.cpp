/*      Problema 1804 - Precisa-se de Matemáticos em Marte
Solução utilizando Fenwick Tree
Visto em: http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
*/

#include <cstdio>
#include <vector>

class FenwickTree {
private:
    std::vector<int> ft;
public:
    void create(int n) {
        ft.assign(n+1, 0);
    }
    int getSum(int i) {
        int sum = 0;
        //i -= (i & (-i));
        while (i > 0) {
            sum += ft[i];
            i -= (i & (-i));
        }
        return sum;
    }
    void adjust(int i, int v) {
        while (i < (int) ft.size()) {
            ft[i] += v;
            i += (i & (-i));
        }
    }
    /*
    void print() {
        for (int i = 1; i < (int) ft.size(); i++)
            printf("%d ", ft[i]);
        printf("\n");
    }
    //*/
};

int main(int argc, char const *argv[]) {
    int n, i, v, buggies[100000];
    char c;
    FenwickTree ft;

    scanf("%d", &n);

    ft.create(n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &v);
        buggies[i-1] = v;
        ft.adjust(i, v);
    }

    //ft.print();

    getchar();
    while (scanf("%c %d", &c, &i) != EOF) {
        if (c == 'a') {
            //printf("%c %d\n", c, i);
            ft.adjust(i, -buggies[i-1]);
            //ft.print();
        }
        else
            printf("%d\n", (i > 1) ? ft.getSum(i-1) : 0);
        getchar();
    }

    return 0;
}
