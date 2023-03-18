#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

void read(std::vector<std::vector<int>> &mat) {
    for(int i = 0; i < mat.size(); i++)
        for(int j = 0; j < mat[i].size(); j++)
            std::cin >> mat[i][j];
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M));
    std::vector<std::vector<int>> B(N, std::vector<int>(M));

    read(A);
    read(B);

    for(int i = 0; i < B.size(); i++) {
        for(int j = 0; j < B[i].size(); j++) {
            B[i][j] += A[i][j];
            std::cout << B[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}