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
	
	int i = 1;
	int c = 1;

	if(N == 1) { std::cout << 1; return 0; }

	while(i+6*c < N) {
		i = i+6*c;
		c++;
	}

	std::cout << c+1;
	
	return 0;
}
