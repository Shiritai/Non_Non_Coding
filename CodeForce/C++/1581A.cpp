# include <iostream>

using namespace std;

int main(){
    int amount;
    cin >> amount;
    for (int _ = 0; _ < amount; ++_){
        long long pa = 1000000007ll, res = 1ll, to;
        cin >> to;
        for (long long i = 3ll; i <= to << 1; ++i){
            res *= i;
            res %= pa;
        }
        cout << res << endl;
    }
}