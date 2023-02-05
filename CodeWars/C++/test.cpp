# include <iostream>
# include <string>
# include <unordered_map>
# include <map>

void printBinary(int target) {
    // 若還沒印出過 1，則保持 false
    // 印出第一個 1 後就保持 true
    // 用來幫助我們迴避印出冗余的 0
    bool printed_one = false;

    // 遮罩是一個最高位為 1 的整數
    // 可以透過 AND 位元運算來取得目標數字的最高位
    // 宣告的修飾多了 const 表示此數字不可更改
    const int mask = 0x80000000;

    for (int i = 0; i < 32; ++i) { // 當 target 不等於 0
        // 若最高位為 1，則此 bool 值為 1，否則為 0
        bool current_bit = (target & mask) != 0;
        if (current_bit || printed_one) {
            std::cout << current_bit;
            printed_one = true;
        }
        target = target << 1; // 算數左移
    }
    std::cout << std::endl;
}

void printBinaryElegant(int target) {
    bool printed_one = false;
    const int mask = 0x80000000;

    for (int _ = 0; _ < 32; ++_) {
        bool current_bit = target & mask;
        if ((printed_one = current_bit | printed_one))
            std::cout << current_bit;
        target <<= 1;
    }
    std::cout << std::endl;
}

int absWithoutBranching(int number) {
    const int mask = number >> 31;
    return (mask + number) ^ mask;
}

int main(void){
    // int target; // 目標數字
    // std::cin >> target;
    // int a = 1, b = -1;
    // a ^= b ^= a ^= b;
    // std::cout << a << ", " << b << std::endl;

    // std::cout << (int) 0x80000001 << std::endl;
    // std::cout << absWithoutBranching(0x80000001) << std::endl;

    // 無順序的字典
    std::unordered_map<int, std::string> ump;
    // 有順序的字典
    std::map<int, std::string> mp;

    // 插入資料至無順序的字典
    ump[1] = "Meow";
    ump[2] = "Eroiko";
    // 插入資料至有順序的字典
    mp[1] = "Meow";
    mp[2] = "Eroiko";

    // 印出無序字典的資料，順序不定
    for (auto &p: ump) {
        std::cout << p.first << ", " 
            << p.second << std::endl;
    }
    // 印出有序字典的資料，一定是「Eroiko, 2」先於「Meow, 1」
    for (auto &p: mp) {
        std::cout << p.first << ", " 
            << p.second << std::endl;
    }
}