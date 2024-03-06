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

	long long int N, B;
	std::cin >> N >> B;

	std::string converted = "";

	while(N) {
		if(N % B < 10) converted += '0' + (N % B);
		else converted += 'A' + (N % B - 10);
		N /= B;
	}

	std::reverse(converted.begin(), converted.end());
	std::cout << converted;
	
	return 0;
}
