# include <vector>
# include <iostream>
using namespace std;

int main(void){
    // vector<int> tmp;
    // auto i = tmp.rbegin();
    int len = 5, k = 11;
    cout << (((k % len) + len) % len) << endl;
}