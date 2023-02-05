#include <climits>
#include <iostream>
 
using namespace std;
 
int main(void) {
    ios::sync_with_stdio(false);
    int n, sz;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &sz);
        int LOCAL_MAX = 1;
        while (sz > LOCAL_MAX)
            LOCAL_MAX = (LOCAL_MAX << 1) | 1;
        LOCAL_MAX = (LOCAL_MAX << 1) | 1;
        int res = LOCAL_MAX;
        int up_seek = sz + 1;
        for (int i = sz; i > 2; --i) {
            int local_i = i;
            if (!(res ^ i)) {
                while (!(res ^ up_seek))
                    ++up_seek;
                local_i = up_seek;
            }
            printf("%d ", local_i);
            res = res ^ local_i;
        }
        printf("%d %d\n", LOCAL_MAX, res);
    }
}

/* 
1, 3, 5, 7, 9
0, 2, 4, 6, res

*    2 ^ 4 ^ 6 ^ 8 ^ res = 1 ^ 3 ^ 5 ^ 7 ^ 9
*    res_gp ^ res = other_gp
*    res_gp ^ res_gp ^ res = res_gp ^ other_gp
*    0 ^ res = res_gp ^  other_gp
*    res = res_gp ^  other_gp

*    res ^ res = res ^ res_gp ^  other_gp
*    0 = res ^ res_gp ^  other_gp

 */