#include <iostream>
#include <vector>

int N, S;
std::vector<int> num;
std::vector<int> seq;
int ans = 0;

void func(int i, int n) {
    seq[i] = n;
    int sum = 0;
    for(int k = 0; k <= i; k++) {
        sum += num[seq[k]];
    }
    ans += (sum == S);

    for(int k = seq[i] + 1; k < N; k++)
        func(i+1, k);
}

int main()
{
    std::cin >> N >> S;
    num.resize(N);
    seq.resize(N);

    for(int n = 0; n < N; n++)
        std::cin >> num[n];

    for(int n = 0; n < N; n++)
        func(0, n);

    std::cout << ans << "\n";

    return 0;
}