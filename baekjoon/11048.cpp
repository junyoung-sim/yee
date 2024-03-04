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

	int N, M;
	std::cin >> N >> M;

	int v[N][M], dp[N][M];

	for(int r = 0; r < N; r++)
		for(int c = 0; c < M; c++) std::cin >> v[r][c];
	
	for(int r = 0; r < N; r++) {
		for(int c = 0; c < M; c++) {
			int sum = -1;
			int dr[3] = {-1, 0, -1};
			int dc[3] = {0, -1, -1};
			for(int n = 0; n < 3; n++) {
				int pr = r+dr[n], pc = c+dc[n];
				if(pr >= 0 && pr < N && pc >= 0 && pc < M) sum = std::max(dp[pr][pc], sum);
			}

			dp[r][c] = v[r][c];
			if(sum != -1) dp[r][c] += sum;
		}
	}
	
	std::cout << dp[N-1][M-1];
	
	return 0;
}
