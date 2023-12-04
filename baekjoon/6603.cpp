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

void solve(std::vector<int> &v, std::vector<int> &lotto, int i, int k) {
	lotto[k] = v[i];
	if(k == 5) {
		for(int &x: lotto)
			std::cout << x << " ";
		std::cout << "\n";
		return;
	}

	if(i == v.size()) return;

	for(int j = i+1; j < v.size(); j++)
		solve(v, lotto, j, k+1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	while(std::cin >> N && N) {
		std::vector<int> v(N), lotto(6);
		for(int i = 0; i < N; i++)
			std::cin >> v[i];

		for(int i = 0; i <= v.size() - 6; i++)
			solve(v, lotto, i, 0);
		std::cout << "\n";
	}

	return 0;
}
