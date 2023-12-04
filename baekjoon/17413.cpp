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

void empty(std::stack<char> &s) {
	while(!s.empty()) {
		std::cout << s.top();
		s.pop();
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string str;
	std::cin >> std::ws;
	std::getline(std::cin, str);

	bool tag = false;
	std::stack<char> s;
	for(int i = 0; i < str.length(); i++) {
		if(!tag) tag = (str[i] == '<');
		if(tag) {
			if(str[i] == '<') empty(s);
			std::cout << str[i];
			tag = (str[i] != '>');
			continue;
		}

		if(str[i] != ' ') s.push(str[i]);
		if(str[i] == ' ' || i == str.length() - 1) {
			empty(s);
			if(str[i] == ' ') std::cout << " ";
		}
	}

	return 0;
}
