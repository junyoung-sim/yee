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

	std::vector<long long int> dp(1000001, 0);
	for(int i = 1; i <= 1000000; i++) {
		for(int j = i; j <= 1000000; j += i)
			dp[j] += i;
		dp[i] += dp[i-1];
	}

	int T, N;
	std::cin >> T;

	while(T--) {
		std::cin >> N;
		std::cout << dp[N] << "\n";
	}

	return 0;
}
