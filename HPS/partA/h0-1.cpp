# include <iostream>

using namespace std;

int main(void){
    int h, m;
    char _;
    while (cin >> h >> _ >> m && (h || m)){
        h = (60 * h + m) % 720;
        m = (6 * m) % 360;
        float res = (h / 2. > m) ? h / 2. - m : m - h / 2.;
        printf("%.03f\n", res > 180 ? 360 - res : res);
    }
}