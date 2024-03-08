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

	int dp[46];
	dp[0] = 0;
	dp[1] = 1;

	for(int i = 2; i <= 45; i++)
		dp[i] = dp[i-2] + dp[i-1];
	
	std::cout << dp[N];
	
	return 0;
}
