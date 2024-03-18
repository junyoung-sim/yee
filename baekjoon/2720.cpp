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

int T, C;
int v[4] = {25, 10, 5, 1};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;

	while(T--) {
		std::cin >> C;
		for(int &x: v) {
			std::cout << C / x << " ";
			C %= x;
		}
		std::cout << "\n";
	}
	
	return 0;
}
