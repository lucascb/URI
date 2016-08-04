/*      Problema 1451 - Teclado Quebrado        */

#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[]) {
    string text;
    list<char> result;
    list<char>::iterator it;

    text.reserve(100000);

    while (cin >> text) {
        it = result.begin();
        for (string::iterator i = text.begin(); i != text.end(); i++) {
            if (*i == '[')
                it = result.begin();
            else if (*i == ']')
                it = result.end();
            else
                result.insert(it, *i);
        }
        
        for (it = result.begin(); it != result.end(); it++)
            cout << *it;
        cout << '\n';
        result.clear();
    }

    return 0;
}
