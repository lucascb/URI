/*      Problema 1424 - Problema Fácil de Rujia Liu? */

#include <cstdio>
#include <map>
#include <vector>

typedef std::vector<int> vi_t;

int main(int argc, char const *argv[]) {
    int n, m, k, v, i;
    std::map<int, vi_t> num;
    std::map<int, vi_t>::iterator it;

    while (scanf("%d %d", &n, &m) != EOF) {
        for (i = 1; i <= n; i++) {
            scanf("%d", &k);
            it = num.find(k);
            if (it == num.end()) {
                num.insert(std::make_pair(k, vi_t()));
                num[k].push_back(i);
            }
            else {
                it->second.push_back(i);
            }
        }
        /*
        for (it = num.begin(); it != num.end(); it++) {
            printf("%d= ", it->first);
            for (i = 0; i < it->second.size(); i++) {
                printf("%d ", it->second[i]);
            }
            printf("\n");
        }
        //*/

        for (i = 0; i < m; i++) {
            scanf("%d %d", &k, &v);
            it = num.find(v);
            if (it == num.end() || k > it->second.size())
                printf("0\n");
            else
                printf("%d\n", it->second[k-1]);
        }
        num.clear();
    }

    return 0;
}
