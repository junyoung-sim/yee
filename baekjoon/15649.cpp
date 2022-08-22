#include <iostream>
#include <string>

std::string func(int i, std::string seq, int N, int M) {
    if(seq.length() == M)
        return seq;

    std::string out = "";
    for(int k = 1; k <= N; k++) {
        bool valid = true;
        for(char ch: seq) {
            valid = ch - '0' != k;
            if(!valid) break;
        }

        if(valid)
            out += func(i, seq + std::to_string(k), N, M);
    }

    return out;
}

int main()
{
    int N, M; std::cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        std::string seq = func(i, std::to_string(i), N, M);
        for(int k = 0; k < seq.length(); k++) {
            std::cout << seq[k];
            if((k + 1) % M == 0) std::cout << "\n";
            else std::cout << " ";
        }
    }

    return 0;
}
