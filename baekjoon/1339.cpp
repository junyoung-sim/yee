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

bool cmp(int a, int b) { return a > b; }

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::string str;
	std::vector<int> alphabet(26, 0);

	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> str;
		int dec = 1;
		for(int k = str.length() - 1; k >= 0; k--) {
			alphabet[str[k] - 'A'] += dec;
			dec *= 10;
		}
	}
	
	std::sort(alphabet.begin(), alphabet.end(), cmp);

	int ans = 0;
	for(int i = 0; i < 10; i++)
		ans += alphabet[i] * (9-i);
	std::cout << ans << "\n";

	return 0;
}
