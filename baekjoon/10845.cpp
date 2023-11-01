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

	std::queue<int> q;

	std::string cmd;
	int N; std::cin >> N;
	while(N--) {
		std::cin >> cmd;
		if(cmd == "size")
			std::cout << q.size() << "\n";
		else if(cmd == "empty")
			std::cout << q.empty() << "\n";
		else if(cmd == "pop") {
			if(q.empty()) std::cout << "-1\n";
			else {
				std::cout << q.front() << "\n";
				q.pop();
			}
		}
		else if(cmd == "front") {
			if(q.empty()) std::cout << "-1\n";
			else std::cout << q.front() << "\n";
		}
		else if(cmd == "back") {
			if(q.empty()) std::cout << "-1\n";
			else std::cout << q.back() << "\n";
		}
		else {
			int x; std::cin >> x;
			q.push(x);
		}
	}

	return 0;
}
