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

int N;
int dp[16];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	dp[0] = 2;
	for(int i = 1; i <= 15; i++)
		dp[i] = dp[i-1] * 2 - 1;
	
	std::cin >> N;
	std::cout << dp[N] * dp[N];
	
	return 0;
}
