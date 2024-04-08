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

	std::vector<int> a(N);
	for(int i = 0; i < N; i++) std::cin >> a[i];

	double max_value = *std::max_element(a.begin(), a.end());
	double min_value = *std::min_element(a.begin(), a.end());

	int ans = 0;
	for(int i = 0; i < N; i++)
		ans += std::max(abs(a[i] - max_value), abs(a[i] - min_value));

	std::cout << ans;
	
	return 0;
}
