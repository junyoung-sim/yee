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

    std::string A, B;
    std::cin >> A >> B;

    int dp[A.size()+1][B.size()+1];
    for(int i = 0; i < A.size()+1; i++)
        dp[i][0] = 0;
    for(int j = 0; j < B.size()+1; j++)
        dp[0][j] = 0;
    
    for(int i = 1; i < A.size()+1; i++) {
        for(int j = 1; j < B.size()+1; j++) {
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
        }
    }

    std::cout << dp[A.size()][B.size()] << "\n";

    return 0;
}