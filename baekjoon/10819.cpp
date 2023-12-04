#include <iostream>
#include <vector>

int N;
std::vector<int> num;
std::vector<int> seq;

int ans = -10000;

void func(int pos, int i) {
    seq[pos] = i;
    if(pos == N-1) {
        int diff_sum = 0;
        for(int k = 0; k < N-1; k++)
            diff_sum += abs(num[seq[k]] - num[seq[k+1]]);
        ans = std::max(diff_sum, ans);
        return;
    }

    for(int k = 0; k < N; k++) {
        bool valid;
        for(int t = 0; t <= pos; t++) {
            valid = (k != seq[t]);
            if(!valid) break;
        }

        if(valid) func(pos+1, k);
    }
}

int main()
{
    std::cin >> N;
    num.resize(N);
    seq.resize(N);

    for(int i = 0; i < N; i++) std::cin >> num[i];

    for(int i = 0; i < N; i++)
        func(0, i);

    std::cout << ans << "\n";

    return 0;
}
