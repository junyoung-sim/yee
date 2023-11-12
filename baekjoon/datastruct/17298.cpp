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

	int A[N];
	for(int i = 0; i < N; i++)
		std::cin >> A[i];

	int NGE[N];
	std::stack<int> s;
	for(int i = N-1; i >= 0; i--) {
		while(!s.empty() && s.top() <= A[i]) s.pop();
		if(s.empty()) NGE[i] = -1;
		else NGE[i] = s.top();
		s.push(A[i]);
	}

	for(int &ans: NGE)
		std::cout << ans << " ";

	return 0;
}
