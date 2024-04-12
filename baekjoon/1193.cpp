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

	int X;
	std::cin >> X;

	int i = 0;
	int x = 0;
	while(x < X) x += ++i;

	int a = (i % 2 ? 1 : i);
	int b = (i % 2 ? i : 1);
	while(x > X) {
		a += (i % 2 ? 1 : -1);
		b += (i % 2 ? -1 : 1);
		x--;
	}

	std::cout << a << "/" << b;
	
	return 0;
}
