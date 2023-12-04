#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <map>
#include <set>

int lcd(int A, int B) {
    int ans = -RAND_MAX;
    for(int i = 1; i <= std::min(A, B); i++)
        if(A % i == 0 && B % i == 0) ans = std::max(i, ans);
    return ans;
}

int lcm(int A, int B) {
    if(lcd(A, B) == -RAND_MAX)
        return A * B;
    else
        return A * B / lcd(A, B);
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N;
    std::cin >> N;

    int A, B;
    for(int i = 0; i < N; i++) {
        std::cin >> A >> B;
        std::cout << lcm(A, B) << "\n";
    }

    return 0;
}