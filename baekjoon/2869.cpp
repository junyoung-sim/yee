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

	int A, B, V;
	std::cin >> A;
	std::cin >> B;
	std::cin >> V;

	std::cout << (V - B - 1)  / (A - B) + 1;
	
	return 0;
}
