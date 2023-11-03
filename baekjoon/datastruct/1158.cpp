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

	int N, K;
	std::cin >> N >> K;

	std::queue<int> q;
	for(int n = 1; n <= N; n++) q.push(n);

	std::vector<int> ans;
	while(!q.empty()) {
		for(int k = 1; k <= K-1; k++) {
			q.push(q.front());
			q.pop();
		}
		ans.push_back(q.front());
		q.pop();
	}

	std::cout << "<";
	for(int i = 0; i < ans.size(); i++) {
		std::cout << ans[i];
		if(i != ans.size() - 1) std::cout << ", ";
	}
	std::cout << ">\n";

	return 0;
}
