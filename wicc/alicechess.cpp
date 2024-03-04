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

	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	if(x1 != x2 && y1 == y2 || x1 == x2 && y1 != y2 || abs(x1-x2) == abs(y1-y2) ||
	   abs(x1-x2) == 2 && abs(y1-y2) == 1 || abs(x1-x2) == 1 && abs(y1-y2) == 2) std::cout << "YES";
	else std::cout << "NO";
	
	return 0;
}
