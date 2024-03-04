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

	int N;
	std::cin >> N;

	int v[N];
	for(int i = 0; i < N; i++) std::cin >> v[i];

	int dp[N];
	dp[0] = 0;

	for(int i = 1; i < N; i++) {
		dp[i] = RAND_MAX;
		for(int j = 0; j < i; j++)
			if(i - j <= v[j] && dp[j] < dp[i]) dp[i] = dp[j] + 1;
	}

	std::cout << (dp[N-1] == RAND_MAX ? -1 : dp[N-1]);
	
	return 0;
}
