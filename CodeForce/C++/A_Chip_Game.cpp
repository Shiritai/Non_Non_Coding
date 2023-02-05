#include <iostream>

using namespace std;

int main(void) {
    int cases, m, n;
    cin >> cases;
    while (cases--) {
        cin >> m >> n;
        cout << (((m + n) & 1) ? "Burenka\n" : "Tonya\n");
    }
}