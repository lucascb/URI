/*      Problema 1112 - Schweisen
Solução utilizando FenwickTree 2D
Visto em: https://www.quora.com/How-do-I-implement-a-2D-binary-indexed-tree-for-range-update-and-range-query-operations
*/

#include <cstdio>
#include <algorithm>

class FenwickTree2D {
private:
    int bit[1001][1001];
    int n;
    int m;
public:
    void construct(int size_x, int size_y) {
        n = size_x;
        m = size_y;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++)
                bit[i][j] = 0;
        }
    }
    void update(int x, int y, int val) {
        int z;
        x++; y++;
        for (; x <= n; x += (x & (-x))) {
            for (z = y; z <= m; z += (z & (-z)))
                bit[x][z] += val;
        }
    }
    // Pega a soma da posicao (0, 0) ate (x, y)
    int get_sum(int x, int y) {
        int z, sum = 0;
        for (; x > 0; x -= (x & (-x))) {
            for (z = y; z > 0; z -= (z & (-z)))
                sum += bit[x][z];
        }
        return sum;
    }
    // Pega a soma no retangulo formado por (x1, y1) e (x2, y2)
    int get_sum(int x1, int y1, int x2, int y2) {
        x1++; y1++; x2++; y2++;
        return get_sum(x2, y2) - get_sum(x2, y1-1) - get_sum(x1-1, y2) + get_sum(x1-1, y1-1);
    }
};

int main(int argc, char const *argv[]) {
    int x, y, p, q, i, j, k, l;
    char t;
    FenwickTree2D ft;

    while (true) {
        scanf("%d %d %d", &x, &y, &p);
        if (x == 0 && y == 0 && p == 0)
            break;
        ft.construct(x, y);
        scanf("%d", &q);
        while (q--) {
            getchar();
            scanf("%c", &t);
            if (t == 'A') {
                scanf("%d %d %d", &i, &j, &k);
                ft.update(j, k, i);
            }
            else {
                scanf("%d %d %d %d", &i, &j, &k, &l);
                if (i > k) std::swap(i, k);
                if (j > l) std::swap(j, l);
                printf("%d\n", ft.get_sum(i, j, k, l) * p);
            }
        }
        printf("\n");
    }

    return 0;
}
