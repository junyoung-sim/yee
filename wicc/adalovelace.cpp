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

	int n, a, b;
	std::cin >> n >> a >> b;

	int sum = 0, t = 0;
	while(sum < n) {
		if(t > 0) a += (t % b == 0);
		sum += a; t++;
	}

	std::cout << t;
	
	return 0;
}
