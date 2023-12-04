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

int gcd(int a, int b) {
	if(a == 0)
		return b;
	return gcd(b%a, a);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;

	int M, N, x, y;
	while(T--) {
		std::cin >> M >> N >> x >> y;
		int MAX = lcm(M, N);
		int ans = -1;
		for(int t = x; t <= MAX; t += M) {
			int yhat = t % N;
			if(yhat == 0) yhat = N;
			if(yhat == y) {
				ans = t;
				break;
			}
		}
		std::cout << ans << "\n";
	}

	return 0;
}
