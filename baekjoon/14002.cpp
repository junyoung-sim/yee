#include <bits/stdc++.h>
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

    int N; std::cin >> N;

    int v[N];
    for(int i = 0; i < N; i++)
        std::cin >> v[i];
    
    int dp[N];
    int max = 1, argmax = 0;
    for(int i = 0; i < N; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(v[j] < v[i] && dp[j] >= dp[i]) {
                dp[i] = dp[j] + 1;
                if(dp[i] >= max) {
                    max = dp[i];
                    argmax = i;
                }
            }
        }
    }

    std::cout << max << "\n";

    int seq[max], k = max-1;
    for(int i = N-1; i >= 0; i--) {
        if(dp[i] == max) {
            seq[k--] = v[i];
            max--;
        }
    }

    for(int &x: seq) std::cout << x << " ";

    return 0;
}
