#include <iostream>
#include <vector>

int N;
std::vector<int> perm;

void func(int i, int n) {
    perm[i] = n;
    if(i == N-1) {
        for(int k = 0; k < N; k++) {
            std::cout << perm[k];
            if(k != N-1) std::cout << " ";
        }
        std::cout << "\n";
        return;
    }

    for(int k = 1; k <= N; k++) {
        bool valid;
        for(int l = 0; l <= i; l++) {
            valid = (k != perm[l]);
            if(!valid) break;
        }

        if(valid) func(i+1, k);
    }
}

int main()
{
    std::cin >> N;
    perm.resize(N);

    for(int n = 1; n <= N; n++)
        func(0, n);

    return 0;
}
