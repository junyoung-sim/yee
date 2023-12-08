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

	int N; std::cin >> N;

	std::vector<int> v(21, 0);
	while(N--) {
		std::string cmd;
		std::cin >> cmd;

		int x;
		if(cmd != "all" && cmd != "empty")
			std::cin >> x;
		
		if(cmd == "add") v[x] = 1;
		else if(cmd == "remove") v[x] = 0;
		else if(cmd == "toggle") v[x] = !v[x];
		else if(cmd == "check")
			std::cout << v[x] << "\n";
		else if(cmd == "all")
			for(int i = 1; i <= 20; i++) v[i] = 1;
		else
			for(int i = 1; i <= 20; i++) v[i] = 0;
	}

	return 0;
}
