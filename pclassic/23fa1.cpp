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
	
	int T; std::cin >> T;
	while(T--) {
		int n, k;
		std::cin >> n >> k;

		int sum = n + k;

		int ndigits = 0;
		while(n != 0) {
			n /= 10;
			ndigits++;
		}

		int sdigits = 0;
		while(sum != 0) {
			sum /= 10;
			sdigits++;
		}

		std::cout << (sdigits > ndigits ? "YES" : "NO") << "\n";
	}

	return 0;
}
