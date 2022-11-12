#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

int N;
std::vector<int> seq;
int solutions = 0;

void solve(int i, int n, int sum) {
    seq[i] = n;
    sum += n;
    if(sum >= N) {
        solutions += (sum == N);
        return;
    }

    for(int m = 1; m <= 3; m++) {
        if(m != seq[i])
            solve(i+1, m, sum);
    }
}

// by using solve
// n:   1 2 3 4 5 6 7 8  9  10 11 12
// ans: 1 1 3 3 4 8 9 12 21 27 37 58

int main()
{
    std::cin >> T;
    std::vector<int> dynamic = {0, 1, 1, 3, 3};
    std::string ans = "";

    

    return 0;
}