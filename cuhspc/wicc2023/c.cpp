#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int loop = 0;
    int seg = 0;

    int N;
    std::cin >> N;

    std::vector<int> nums(N+1);
    for(int i = 1; i <= N; i++)
        std::cin >> nums[i];

    for(int i = 1; i <= N; i++) {
        int j = nums[i];
        while(j != -1 && nums[j] != i) {
            std::cout << i << " " << j << "\n";
            j = nums[j];
        }
        loop += (nums[j] == i);
        seg += (j == -1);
    }

    if(loop == 3 && seg == 1) std::cout << "Y\n";
    else std::cout << "N\n";

    return 0;
}