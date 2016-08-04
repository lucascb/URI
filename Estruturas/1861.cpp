/*      Problema 1861 - O Hall dos Assassinos     */

#include <iostream>
#include <map>

using namespace std;


struct person {
    unsigned int kills;
    bool dead;
};

int main(int argc, char const *argv[]) {
    map<string, person> murders;
    map<string, person>::iterator it;
    string killer, killed;
    person p;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> killer >> killed) {
        // Assassino
        it = murders.find(killer);
        if (it == murders.end()) {
            p.kills = 1;
            p.dead = false;
            murders.insert(make_pair(killer, p));
        }
        else
            it->second.kills++;
        // Assasinado
        it = murders.find(killed);
        if (it == murders.end()) {
            p.kills = 0;
            p.dead = true;
            murders.insert(make_pair(killed, p));
        }
        else
            it->second.dead = true;
    }

    cout << "HALL OF MURDERERS\n";
    for (it = murders.begin(); it != murders.end(); it++) {
        if (!it->second.dead)
            cout << it->first << ' ' << it->second.kills << '\n';
    }

    return 0;
}
