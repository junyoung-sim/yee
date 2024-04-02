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

#define MAX 10001

int T;
int N;
int M;

int v[21];
int dp[MAX]; // dp[i] = k; there exists "k" ways to make "i"

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;

	while(T--) {
		std::cin >> N;
		for(int i = 1; i <= N; i++) std::cin >> v[i];
		std::cin >> M;

		dp[0] = 1;
		for(int i = 1; i <= MAX; i++) dp[i] = 0;

		for(int i = 1; i <= N; i++) {
			for(int j = v[i]; j <= M; j++)
				dp[j] += dp[j - v[i]];
		}

		std::cout << dp[M] << "\n";
	}
	
	return 0;
}
