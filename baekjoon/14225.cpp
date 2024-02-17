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

int N;
std::vector<int> v;
std::map<int, bool> valid;

void func(int i, int c, int l, int sum) {
	if(c == l) {
		valid[sum] = true;
		return;
	}
	for(int j = i+1; j < N; j++) func(j, c+1, l, sum+v[j]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	v.resize(N);
	for(int i = 0; i < N; i++)
		std::cin >> v[i];
	
	for(int i = 0; i < N; i++) {
		for(int l = 1; l <= N-i; l++)
			func(i, 1, l, v[i]);
	}

	int sum = 1;
	while(valid[sum]) sum++;

	std::cout << sum << "\n";
	
	return 0;
}
