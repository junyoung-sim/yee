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

#define MAX 40000

int N;
int M;

int w[30];
bool dp[MAX+1];
bool tmp[MAX+1];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	for(int i = 0; i < N; i++) std::cin >> w[i];

	dp[0] = true;
	for(int i = 0; i < N; i++) {
		tmp[0] = true;
		for(int j = 0; j <= MAX; j++) {
			if(dp[j]) {
				if(j + w[i] <= MAX)
					tmp[j + w[i]] = true;
				tmp[abs(j - w[i])] = true;
			}
		}
		for(int j = 0; j <= MAX; j++) dp[j] = tmp[j];
	}

	std::cin >> M;
	while(M--) {
		int m;
		std::cin >> m;
		std::cout << (dp[m] ? "Y" : "N") << " ";
	}
	
	return 0;
}