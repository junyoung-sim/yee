#include <iostream>
#include <vector>
#include <string>

int N;
std::vector<int> given;
std::vector<int> perm;

void func(int n, int i) {
    perm[n] = i;
    if(n == N-1) {
        for(int &val: perm)
            std::cout << val << " ";
        std::cout << "\n";
        return;
    }

    for(int k = 1; k <= N; k++) {
        bool valid;
        for(int m = 0; m <= n; m++) {
            valid = (k != perm[m]);
            if(!valid) break;
        }

        if(valid) func(n+1, k);
    }
}


int main(int argc, char *argv[])
{
    std::cin >> N;
    given.resize(N);
    perm.resize(N);
    for(int i = 0; i < N; i++)
        std::cin >> given[i];

    for(int i = 1; i <= N; i++)
        func(0, i);

    return 0;
}
