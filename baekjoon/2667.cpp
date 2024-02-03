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

	std::string str;
	std::vector<std::vector<int>> graph(N, std::vector<int>(N,0));
	std::vector<std::vector<int>> visit(N, std::vector<int>(N,0));
	for(int i = 0; i < N; i++) {
		std::cin >> str;

	}
	
	return 0;
}
