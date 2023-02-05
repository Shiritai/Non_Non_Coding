# include <iostream>

using namespace std;

int main(void){
    long long n, s, d;
    cin >> n;
    while (n--){
        cin >> s >> d;
        if ((s & 1) == (d & 1) && s >= d)
            cout << ((s + d) >> 1) << ' ' << ((s - d) >> 1) << endl;
        else 
            cout << "impossible\n";
    }
}