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

void cantor(std::string &str, int i, int j) {
    if(i != j) {
        int L = (j-i+1)/3;
        for(int k = i+L; k < j-L+1; k++)
            str[k] = ' ';
        cantor(str, i, i+L-1);
        cantor(str, j-L+1, j);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    while(std::cin >> N) {
        std::string str = "";
        while(str.length() < pow(3, N))
            str += "-";
        cantor(str, 0, str.length()-1);
        std::cout << str << "\n";
    }

    return 0;
}