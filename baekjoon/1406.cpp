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

	std::string str;
	std::cin >> str;

	std::stack<char> f;
	std::stack<char> b;

	for(char &ch: str) f.push(ch);

	char cmd, x;
	int N; std::cin >> N;
	while(N--) {
		std::cin >> cmd;
		if(cmd == 'L') {
			if(!f.empty()) {
				b.push(f.top());
				f.pop();
			}
		}
		else if(cmd == 'D') {
			if(!b.empty()) {
				f.push(b.top());
				b.pop();
			}
		}
		else if(cmd == 'B') {
			if(!f.empty())
				f.pop();
		}
		else {
			std::cin >> x;
			f.push(x);
		}
	}

	while(!f.empty()) {
		b.push(f.top());
		f.pop();
	}
	while(!b.empty()) {
		std::cout << b.top();
		b.pop();
	}

	return 0;
}
