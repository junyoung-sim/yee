#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::vector<std::string> white(8);
    std::vector<std::string> black(8);

    std::string w = "", b = "";
    for(int c = 0; c < 8; c++) {
        if(c % 2 == 0) {
            w += "W";
            b += "B";
        }
        else {
            w += "B";
            b += "W";
        }
    }

    for(int r = 0; r < 8; r++) {
        if(r % 2 == 0) {
            white[r] = w;
            black[r] = b;
        }
        else {
            white[r] = b;
            black[r] = w;
        }
    }

    int R, C;
    std::cin >> R >> C;

    std::vector<std::string> chess(R);
    for(int r = 0; r < R; r++)
        std::cin >> chess[r];

    int ans = RAND_MAX;
    for(int r = 0; r <= R-8; r++) {
        for(int c = 0; c <= C-8; c++) {
            int w_count = 0, b_count = 0;
            for(int i = r; i < r+8; i++) {
                for(int j = c; j < c+8; j++) {
                    w_count += (chess[i][j] != white[i-r][j-c]);
                    b_count += (chess[i][j] != black[i-r][j-c]);
                }
            }
            ans = std::min(ans, std::min(w_count, b_count));
        }
    }

    std::cout << ans << "\n";

    return 0;
}