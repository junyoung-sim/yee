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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N; std::cin >> N;

    std::queue<int> q;
    for(int i = 1; i <= N; i++)
        q.push(i);
    
    while(q.size() > 1) {
        q.pop();

        int x = q.front();
        q.pop();
        q.push(x);
    }

    std::cout << q.front() << "\n";

    return 0;
}