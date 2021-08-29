# include <string>
# include <vector>
# include <iostream>
# include <unordered_set>
# include <algorithm>

std::vector<std::string> permutations(std::string s) {
    std::unordered_set<std::string> st;
    sort(s.begin(), s.end());
    do {
        st.insert(s);
    } while (std::next_permutation(s.begin(), s.end()));
    return std::vector<std::string> (st.begin(), st.end());
}

int main(void){
    std::string str = "123456";
    str[2] = 'E';
    // std::cout << str << std::endl;
    auto v = permutations("abc");
    for_each(v.begin(), v.end(), [](auto & str){ std::cout << str << std::endl; });
}