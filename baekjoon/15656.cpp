#include <iostream>
#include <vector>
#include <string>

int N, M;
std::vector<int> num;

void func(std::string seq, int N, int M) {
    if(seq.length() == M) {
        for(int i = 0; i < M; i++) {
            std::cout << num[seq[i] - '0'];
            if(i != M - 1) std::cout << " ";
        }
        std::cout << "\n";
        return;
    }

    for(int n = 0; n < N; n++)
        func(seq + std::to_string(n), N, M);
}

int main()
{
    std::cin >> N >> M;
    num.resize(N);
    for(int i = 0; i < N; i++) std::cin >> num[i];

    for(int i = 0; i < N-1; i++) {
        int min_pos = i;
        for(int j = i; j < N; j++) {
            if(num[j] < num[min_pos])
                min_pos = j;
        }
        std::swap(num[i], num[min_pos]);
    }

    for(int n = 0; n < N; n++)
        func(std::to_string(n), N, M);

    return 0;
}


