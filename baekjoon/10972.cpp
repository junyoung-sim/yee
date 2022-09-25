#include <iostream>
#include <vector>

int N;
std::vector<int> seq;

int main()
{
    std::cin >> N;
    seq.resize(N);
    for(int i = 0; i < N; i++) std::cin >> seq[i];

    int pivot = -1;
    for(int i = N-1; i >= 1; i--) {
        if(seq[i-1] < seq[i]) {
            pivot = i-1;
            break;
        }
    }

    if(pivot == -1)
        std::cout << "-1\n";
    else {
        int swap_pos = N-1;
        for(int i = N-1; i > pivot; i--) {
            if(seq[swap_pos] < seq[pivot]) {
                if(seq[i] > seq[pivot])
                    swap_pos = i;
            }
            else {
                if(seq[i] > seq[pivot] && seq[i] < seq[swap_pos])
                    swap_pos = i;
            }
        }
        std::swap(seq[pivot], seq[swap_pos]);

        int lower = pivot+1, upper = N-1;
        while(lower < upper)
            std::swap(seq[lower++], seq[upper--]);

        for(int i = 0; i < N; i++) {
            std::cout << seq[i];
            if(i != N-1) std::cout << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
