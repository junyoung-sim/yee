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

#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3

int N;
std::vector<int> v;
std::vector<int> op(4); // +, -, x, /

int max = -RAND_MAX;
int min = RAND_MAX;

void func(int t, int ans) {
    if(t == N-1) {
        max = std::max(ans, max);
        min = std::min(ans, min);
        return;
    }

    for(int i = ADD; i <= DIV; i++) {
        if(op[i]) {
            op[i]--;
            if(i == ADD) func(t+1, ans+v[t+1]);
            if(i == SUB) func(t+1, ans-v[t+1]);
            if(i == MUL) func(t+1, ans*v[t+1]);
            if(i == DIV) func(t+1, ans/v[t+1]);
            op[i]++;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;
    v.resize(N);

    for(int i = 0; i < N; i++)
        std::cin >> v[i];
    
    for(int i = ADD; i <= DIV; i++)
        std::cin >> op[i];

    func(0, v[0]);

    std::cout << max << "\n";
    std::cout << min << "\n";

    return 0;
}