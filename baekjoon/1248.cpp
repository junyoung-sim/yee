#include <iostream>
#include <string>
#include <vector>

int N;
std::string sign;
std::vector<std::vector<int>> sign_matrix;
std::vector<int> code;

bool func(int n, int i) {
    code[n] = i;

    bool valid = false;
    for(int j = 0; j <= n; j++) {
        int sum = 0;
        for(int k = j; k <= n; k++) {
            sum += code[k];
            if(sign_matrix[j][k] == '-') valid = (sum < 0);
            else if(sign_matrix[j][k] == '+') valid = (sum > 0);
            else valid = (sum == 0);

            if(!valid) break;
        }

        if(!valid) break;
    }

    if(valid && n == N-1)
        return true;
    else if(valid && n != N-1) {
        for(int k = -10; k <= 10; k++) {
            valid = func(n+1, k);
            if(valid) break;
        }

        return valid;
    }
    else
        return false;
}

int main()
{
    std::cin >> N;
    std::cin >> sign;

    int k = 0;
    sign_matrix.resize(N, std::vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(j >= i)
                sign_matrix[i][j] = sign[k++];
            else
                sign_matrix[i][j] = -1;
        }
    }

    code.resize(N);

    for(int i = -10; i <= 10; i++) {
        bool valid = func(0, i);
        if(valid) break;
    }

    for(int i = 0; i < code.size(); i++) {
        std::cout << code[i];
        if(i != code.size() - 1) std::cout << " ";
        else std::cout << "\n";
    }

    return 0;
}
