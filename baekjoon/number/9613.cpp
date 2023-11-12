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

long long int gcd(long long int a, long long int b) {
	if(a == 0)
		return b;
	return gcd(b%a, a);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T; std::cin >> T;
	while(T--) {
		int N; std::cin >> N;
		long long int v[N];
		for(int i = 0; i < N; i++)
			std::cin >> v[i];

		long long int sum = 0;
		for(int i = 0; i < N-1; i++)
			for(int j = i+1; j < N; j++)
				sum += gcd(v[i], v[j]);
		std::cout << sum << "\n";
	}

	return 0;
}
