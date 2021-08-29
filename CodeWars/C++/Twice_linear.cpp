# include <iostream>

class DoubleLinear
{
public:
    static int dblLinear(int n);
};

# define L1(x) (((x) << 1) + 1)
# define L2(x) ((x) * 3 + 1)

int DoubleLinear::dblLinear(int n){
    int arr[n];
    arr[0] = 1, arr[1] = 3, arr[2] = 4;
    int cnt = 2, last1 = 1, last2 = 1;
    while (cnt++ < n){
        while (L1(arr[last1]) <= arr[cnt - 1]) ++last1;
        while (L2(arr[last2]) <= arr[cnt - 1]) ++last2;
        int min1 = L1(arr[last1]), min2 = L2(arr[last2]);
        arr[cnt] = min1 < min2 ? min1 : min2;
    }
    return arr[n];
}

int main(void){
    std::cout << DoubleLinear::dblLinear(10) << std::endl;
    std::cout << DoubleLinear::dblLinear(10000) << std::endl;
    std::cout << DoubleLinear::dblLinear(10001) << std::endl;
    std::cout << DoubleLinear::dblLinear(10002) << std::endl;
    std::cout << DoubleLinear::dblLinear(10003) << std::endl;
    std::cout << DoubleLinear::dblLinear(10004) << std::endl;
    std::cout << DoubleLinear::dblLinear(10005) << std::endl;
    std::cout << DoubleLinear::dblLinear(10006) << std::endl;
    std::cout << DoubleLinear::dblLinear(10007) << std::endl;
    std::cout << DoubleLinear::dblLinear(10008) << std::endl;
    std::cout << DoubleLinear::dblLinear(10009) << std::endl;
    std::cout << DoubleLinear::dblLinear(10010) << std::endl;
}