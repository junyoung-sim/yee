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

	std::string record;
	std::cin >> record;

	int score = 0, combo = 0;
	for(int i = 0; i < N; i++) {
		if(record[i] == '*') { score += 100 + combo; combo++; }
		if(record[i] == 'o') { score += 50 + combo; combo++; }
		if(record[i] == 'x') { combo = 0; }
	}

	std::cout << score;
	
	return 0;
}
