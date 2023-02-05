# include <iostream>
# define _ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(void){ _
    int n, num, cur;
    cin >> n;
    while (n--){
        cin >> num;
        cur = num >> 1;
        while (cur < num){
            int tmp = 0, gen = cur;
            while (gen){
                tmp += gen % 10;
                gen /= 10;
            }
            if (cur + tmp == num)
                break;
            ++cur;
        }
        cout << (cur != num ? cur : 0) << '\n';
    }
}