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

	int T;
	std::cin >> T;

	while(T--) {
		int N;
		std::cin >> N;

		int x[N];
		for(int i = 0; i < N; i++) std::cin >> x[i];

		std::vector<int> v(N);
		for(int i = 0; i < N; i++) std::cin >> v[i];

		while(true) {
			std::vector<int> tmp;
			for(int i = 1; i < v.size(); i++) {
				if(v[i-1] <= v[i])
					tmp.push_back(v[i]);
			}
			if(v.size() == tmp.size()) {
				std::cout << v.size() << "\n";
				break;
			}
			v.clear();
			v.swap(tmp);
		}
	}
	
	return 0;
}
