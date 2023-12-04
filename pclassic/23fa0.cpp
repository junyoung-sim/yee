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

    int T; std::cin >> T;

    while(T--) {
        int k;
        std::cin >> k;
        
        std::string s;
        std::cin >> s;

        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        std::cout << k+1 << "\n";
        std::cout << s + 'a' << "\n";
        std::cout << a + b + c + d << "\n";
    }
	
	return 0;
}
