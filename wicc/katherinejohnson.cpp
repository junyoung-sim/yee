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

	std::string A = "42";

	for(int n = 2; n <= N; n++) {
		std::vector<int> count;
		for(int k = 0; k < A.size(); k++) {
			if(k == 0 || k > 0 && A[k-1] != A[k]) count.push_back(1);
			if(k > 0 && A[k-1] == A[k]) count.back()++;
		}

		std::string B = "";
		for(int k = 0; k < A.size(); k++)
			if(k == 0 || k > 0 && A[k] != B.back()) B += A[k];

		for(int &x: count) B += std::to_string(x);

		A = B;
	}

	std::cout << A;
	
	return 0;
}
