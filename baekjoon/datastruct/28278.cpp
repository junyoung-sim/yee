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

	std::stack<int> s;
	while(N--) {
		int cmd, x;
		std::cin >> cmd;

		if(cmd == 1) {
			std::cin >> x;
			s.push(x);
		}
		else if(cmd == 2) {
			if(s.empty()) std::cout << "-1\n";
			else {
				std::cout << s.top() << "\n";
				s.pop();
			}
		}
		else if(cmd == 3)
			std::cout << s.size() << "\n";
		else if(cmd == 4)
			std::cout << s.empty() << "\n";
		else {
			if(s.empty()) std::cout << "-1\n";
			else std::cout << s.top() << "\n";
		}
	}

	return 0;
}
