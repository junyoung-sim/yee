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
	for(int i = 0; i < N; i++) std::cin >> v[i];

	int dp[N], ans = 1;
	for(int i = 0; i < N; i++) {
		dp[i] = 1;
		for(int k = 0; k <= i; k++) {
			if(v[k] > v[i] && dp[k] + 1 > dp[i])
				dp[i] = dp[k] + 1;
		}
		ans = std::max(dp[i], ans);
	}

	std::cout << ans << "\n";
	
	return 0;
}
