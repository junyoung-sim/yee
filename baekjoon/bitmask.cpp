#include <iostream>
#include <vector>

int N;
std::vector<int> mask;

void bitmask(int i, int n) {
    mask[i] = n;
    if(i == mask.size() - 1) {
        for(int &val: mask)
            std::cout << val << " ";
        std::cout << "\n";
        return;
    }

    bitmask(i+1, 0);
    bitmask(i+1, 1);
}

int main()
{
    std::cin >> N;
    mask.resize(N);

    bitmask(0, 0);
    bitmask(0, 1);

    return 0;
}