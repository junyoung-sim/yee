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

    int N, M;
    std::cin >> N >> M;

    std::deque<int> dq;
    for(int i = 1; i <= N; i++)
        dq.push_back(i);

    int ans = 0;
    while(M--) {
        int loc;
        std::cin >> loc;

        int i;
        for(int k = 0; k < dq.size(); k++) {
            if(loc == dq[k]) {
                i = k;
                break;
            }
        }

        if(i <= dq.size() / 2) {
            while(dq.front() != loc) {
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
        }
        else {
            while(dq.front() != loc) {
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
        }
        dq.pop_front();
    }

    std::cout << ans << "\n";

    return 0;
}