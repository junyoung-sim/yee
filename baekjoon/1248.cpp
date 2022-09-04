#include <iostream>
#include <string>
#include <vector>

int n;
std::string code = "";
std::vector<std::vector<char>> matrix;

std::string seq = "";

int main()
{
    std::cin >> n;
    std::cin >> code;

    matrix.resize(n, std::vector<char>(n));
    int c = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j >= i) matrix[i][j] = code[c++];
        }
    }

    return 0;
}
