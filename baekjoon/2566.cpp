#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::vector<std::vector<int>> v(9, std::vector<int>(9));

    int max_val = -RAND_MAX;
    int row = -1, col = -1;

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            std::cin >> v[i][j];
            if(v[i][j] > max_val) {
                max_val = v[i][j];
                row = i;
                col = j;
            }
        }
    }

    std::cout << max_val << "\n";
    std::cout << row+1 << " " << col+1 << "\n";

    return 0;
}