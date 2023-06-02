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

    int N, K;
    std::cin >> N >> K;

    std::queue<int> q;
    for(int i = 1; i <= N; i++)
        q.push(i);
    
    std::cout << "<";
    while(q.size() > 0) {
        for(int i = 1; i < K; i++) {
            q.push(q.front());
            q.pop();
        }
        std::cout << q.front();
        if(q.size() > 1)
            std::cout << ", ";
        q.pop();
    } std::cout << ">\n";

    return 0;
}