#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

bool solve(std::string str) {
    bool fit = true;
    std::vector<int> alphabet(26, 0);
    for(int i = 0; i < str.length(); i++) {
        if(alphabet[str[i] - 'a'] == 0)
            alphabet[str[i] - 'a'] = 1;
        else {
            fit = (str[i] == str[i-1]);
            if(!fit) break;
        }
    }
    return fit;
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int ans = 0;
    std::string str;

    for(int i = 0; i < N; i++) {
        std::cin >> str;
        ans += solve(str);
    }
    
    std::cout << ans << "\n";

    return 0;
}