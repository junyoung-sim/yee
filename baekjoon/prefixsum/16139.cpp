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
#include <queue>
#include <deque>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string str;
    std::cin >> str;

    int v[26][str.length()+1];
    for(char x = 'a'; x <= 'z'; x++) {
        v[x-'a'][0] = 0;
        for(int i = 1; i <= str.length(); i++)
            v[x-'a'][i] = v[x-'a'][i-1] + (str[i-1] == x);
    }

    int N; std::cin >> N;
    while(N--) {
        char x; int a, b;
        std::cin >> x >> a >> b;
        std::cout << v[x-'a'][b+1] - v[x-'a'][a] << "\n";
    }

    return 0;
}