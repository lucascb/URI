/*      Problema 1303 - Spurs Rocks      */

#include <cstdio>
#include <algorithm>

typedef struct team {
    int id;
    int score;
    int pts_made;
    int pts_received;
} team_t;

bool sortTeams(const team_t & a, const team_t & b) {
    double avg_a = (a.pts_received > 0) ? (a.pts_made / (a.pts_received * 1.0)) : a.pts_made;
    double avg_b = (b.pts_received > 0) ? (b.pts_made / (b.pts_received * 1.0)) : b.pts_made;

    if (a.score != b.score)
        return a.score > b.score;
    else if (avg_a != avg_b)
        return avg_a > avg_b;
    else if (a.pts_made != b.pts_made)
        return a.pts_made > b.pts_made;
    else
        return a.id < b.id;
}

int main(int argc, char const *argv[]) {
    team_t league[100];
    int n, x, y, z, w, inst;

    inst = 1;
    while (true) {
        scanf("%d", &n);
        if (n == 0)
            break;

        for (int i = 0; i < n; i++) {
            league[i].id = i+1;
            league[i].score = league[i].pts_made = league[i].pts_received = 0;
        }

        for (int i = 0; i < (n*(n-1))/2; i++) {
            scanf("%d %d %d %d", &x, &y, &z, &w);
            league[x-1].pts_made += y;
            league[x-1].pts_received += w;
            league[z-1].pts_made += w;
            league[z-1].pts_received += y;
            if (y > w) {
                league[x-1].score += 2;
                league[z-1].score++;
            }
            else {
                league[z-1].score += 2;
                league[x-1].score++;
            }
        }

        /*
        printf("\n");
        for (int i = 0; i < n; i++)
            printf("%d %d %d %d %lf\n", league[i].id, league[i].score, league[i].pts_made, league[i].pts_received, league[i].pts_made / (league[i].pts_received * 1.0));
        //*/

        std::sort(league, league+n, sortTeams);
        if (inst > 1) printf("\n");
        printf("Instancia %d\n", inst++);
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", league[i].id);
        }
        printf("\n");
    }

    return 0;
}
