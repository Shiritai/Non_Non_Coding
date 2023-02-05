# include <iostream>
# include <string.h>
# define _ ios::sync_with_stdio(false);cin.tie(0);
# define LIMIT 101

using namespace std;

int main(void){ _
    char master[LIMIT], driven[LIMIT];
    while (cin >> master >> driven){
        const int m_sz = strlen(master), d_sz = strlen(driven);
        int j;
        for (j = 0; j <= m_sz - d_sz; ++j){
            int k;
            for (k = 0; k < d_sz; ++k)
                if (master[j + k] - '0' + driven[k] - '0' > 3)
                    break;
            if (k == d_sz){
                cout << m_sz << endl;
                break;
            }
        }
        if (j <= m_sz - d_sz)
            continue;
        int i;
        for (i = 1; i < d_sz; ++i){
            int k;
            for (k = 0; k < d_sz - i; ++k)
                if (master[k] - '0' + driven[k + i] - '0' > 3)
                    break;
            if (k == d_sz - i){
                cout << m_sz + i << endl;
                break;
            }
        }
        if (i == d_sz){
            for (i = 1; i < d_sz; ++i){
                int k;
                for (k = 0; k < d_sz - i; ++k)
                    if (master[m_sz - d_sz - 1 + k] - '0' + driven[k] - '0' > 3)
                        break;
                if (k == d_sz - i){
                    cout << m_sz + i << endl;
                    break;
                }
            }
        }
        if (i == d_sz)
            cout << m_sz + i << endl;
    }
}