#include <iostream>
#include <vector>
#include <string>

int N;
std::vector<std::string> con;

std::vector<int> seq;
std::vector<int> max_seq;
std::vector<int> min_seq;

std::string max_ans = "";
std::string min_ans = "";

void func(int i, int n) {
    seq[i] = n;

    bool valid = true;
    if(i > 0) {
        for(int c = 0; c < i; c++) {
            valid = (con[c] == "<" ? seq[c] < seq[c+1] : seq[c] > seq[c+1]);
            if(!valid) break;
        }
    }

    if(valid && i == N) {
        bool is_max = false, is_min = false;
        for(int k = 0; k < seq.size(); k++) {
            if(seq[k] != max_seq[k]) {
                is_max = (seq[k] > max_seq[k]);
                break;
            }
        }
        for(int k = 0; k < seq.size(); k++) {
            if(seq[k] != min_seq[k]) {
                is_min = (seq[k] < min_seq[k]);
                break;
            }
        }

        std::string val = "";
        for(int &_n: seq)
            val += std::to_string(_n);

        if(is_max) {
            max_ans = val;
            for(int k = 0; k < seq.size(); k++)
                max_seq[k] = seq[k];
        }
        if(is_min) {
            min_ans = val;
            for(int k = 0; k < seq.size(); k++)
                min_seq[k] = seq[k];
        }

        return;
    }
    else if(valid && i != N) {
        for(int _n = 0; _n <= 9; _n++) {
            for(int k = 0; k <= i; k++) {
                valid = (_n != seq[k]);
                if(!valid) break;
            }

            if(valid) func(i+1, _n);
        }

        return;
    }
    else
        return;
}

int main()
{
    std::cin >> N;
    con.resize(N);
    seq.resize(N+1);
    max_seq.resize(N+1, -1);
    min_seq.resize(N+1, 10);

    for(int i = 0; i < N; i++) std::cin >> con[i];

    for(int n = 0; n <= 9; n++)
       func(0, n);

    std::cout << max_ans << "\n";
    std::cout << min_ans << "\n";

    return 0;
}
