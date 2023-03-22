#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::vector<std::vector<int>> mat(100, std::vector<int>(100,0));

    int N;
    std::cin >> N;

    for(int n = 0; n < N; n++) {
        int r, c;
        std::cin >> c >> r;
        for(int i = r; i < r+10; i++)
            for(int j = c; j < c+10; j++)
                mat[i][j] = 1;
    }

    int area = 0;
    for(int i = 0; i < mat.size(); i++)
        for(int j = 0; j < mat[i].size(); j++)
            area += mat[i][j];
    std::cout << area << "\n";

    return 0;
}