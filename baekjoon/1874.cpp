#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin >> N;

    std::string ans = "";

    std::vector<int> x(N);
    for(int i = 0; i < N; i++)
        std::cin >> x[i];
    
    int max = 0;
    std::stack<int> s;
    for(int i = 0; i < N; i++) {
        if(s.empty() || x[i] > s.top()) {
            for(int k = max+1; k <= x[i]; k++) {
                s.push(k);
                ans += "+\n";
            }
            max = x[i];
        }
        if(x[i] == s.top()) {
            s.pop();
            ans += "-\n";
        }
        else {
            ans = "NO\n";
            break;
        }
    }

    std::cout << ans;

    return 0;
}