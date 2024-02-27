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

	int N, M, R;
	std::cin >> N;
	std::cin >> M;
	std::cin >> R;

	std::vector<std::vector<int>> v(N, std::vector<int>(M));
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++) std::cin >> v[i][j];
	
	
	
	return 0;
}
