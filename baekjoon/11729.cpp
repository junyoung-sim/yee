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

std::vector<std::pair<int, int>> seq; 

void hanoi(int n, int from, int aux, int to) {
    if(n == 0) return;

    hanoi(n - 1, from, to, aux);

    seq.push_back({from, to});
    
    hanoi(n - 1, aux, from, to);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N; std::cin >> N;

    hanoi(N, 1, 2, 3);

    std::cout << seq.size() << "\n";
    for(auto &x: seq)
        std::cout << x.first << " " << x.second << "\n";

    return 0;
}