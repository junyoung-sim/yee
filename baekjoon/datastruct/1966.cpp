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

    int T;
    std::cin >> T;

    int N, M;
    for(int t = 1; t <= T; t++) {
        std::cin >> N >> M;

        std::priority_queue<int> p; // descending order queue
        std::queue<std::pair<int, int>> q;

        for(int i = 0; i < N; i++) {
            int x; std::cin >> x;
            p.push(x);
            q.push({i, x});
        }

        int ans = 0;
        while(!q.empty()) {
            int loc = q.front().first;
            int val = q.front().second;
            q.pop();

            if(val == p.top()) { // item has max priority over others
                p.pop();
                ans++;
                if(loc == M) { // check if initial location of that item is M
                    std::cout << ans << "\n";
                    break;
                }
            }
            else q.push({loc, val});
        }
    }

    return 0;
}