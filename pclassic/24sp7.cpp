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

	int p[N+1];
	for(int i = 1; i <= N; i++) std::cin >> p[i];

	int b[N+1];
	for(int i = 1; i <= N; i++) b[i] = 0;
	for(int i = 1; i <= N; i++) {
		b[i] = p[i] - p[(i % N) + 1];
		std::cout << b[i] << " ";
	}


	
	return 0;
}
