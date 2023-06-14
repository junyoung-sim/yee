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

int N, M;

void func(std::vector<int> &v, int i, int n) {
    v[i++] = n;
    if(i == M) {
        for(int &x: v)
            std::cout << x << " ";
        std::cout << "\n";
        return;
    }
    for(int j = n; j <= N; j++) {
        bool exists = false;
        for(int k = 0; k < i; k++) {
            exists = (j == v[k]);
            if(exists) break;
        }
        if(!exists) func(v, i, j);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;

    std::vector<int> v(M);
    for(int n = 1; n <= N; n++)
        func(v, 0, n);

    return 0;
}