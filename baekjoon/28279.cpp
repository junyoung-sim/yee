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

int N, cmd, x;
std::deque<int> dq;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	while(N--) {
		std::cin >> cmd;
		if(cmd == 1 || cmd == 2)
			std::cin >> x;
		
		if(cmd == 1) dq.push_front(x);
		else if(cmd == 2) dq.push_back(x);
		else if(cmd == 3) {
			std::cout << (dq.empty() ? -1 : dq.front()) << "\n";
			if(!dq.empty())
				dq.pop_front();
		}
		else if(cmd == 4) {
			std::cout << (dq.empty() ? -1 : dq.back()) << "\n";
			if(!dq.empty())
				dq.pop_back();
		}
		else if(cmd == 5) std::cout << dq.size() << "\n";
		else if(cmd == 6) std::cout << dq.empty() << "\n";
		else if(cmd == 7) std::cout << (dq.empty() ? -1 : dq.front()) << "\n";
		else std::cout << (dq.empty() ? -1 : dq.back()) << "\n";
	}
	
	return 0;
}
