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

void compress(std::vector<std::string> &img, std::string &zip, int N, int r, int c) {
    int sum = 0;
    for(int i = r; i < r + N; i++)
        for(int j = c; j < c + N; j++)
            sum += img[i][j] - '0';
    
    if(sum == 0) { zip += "0"; return; }
    if(sum == N*N) { zip += "1"; return; }

    zip += "(";
    compress(img, zip, N/2, r, c);
    compress(img, zip, N/2, r, c + N/2);
    compress(img, zip, N/2, r + N/2, c);
    compress(img, zip, N/2, r + N/2, c + N/2);
    zip += ")";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::string zip = "";
    std::vector<std::string> img(N);
    for(int i = 0; i < N; i++)
        std::cin >> img[i];
    
    compress(img, zip, N, 0, 0);

    std::cout << zip << "\n";

    return 0;
}