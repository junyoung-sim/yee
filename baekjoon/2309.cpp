
#include <iostream>

int main()
{
    unsigned int height[9];
    unsigned int sum = 0;
    for(unsigned int i = 0; i < 9; i++) {
        std::cin >> height[i];
        sum += height[i];
    }

    unsigned extra = sum - 100;
    for(unsigned int i = 0; i < 8; i++) {
        bool fake = false;
        for(unsigned int j = 0; j < 9; j++) {
            if(i != j && height[i] + height[j] == extra) {
                height[i] = 0;
                height[j] = 0;
                fake = true;
                break;
            }
        }

        if(fake) break;
    }

    for(unsigned int i = 0; i < 8; i++) {
        unsigned int min = 100, min_pos = 0;
        for(unsigned int j = i; j < 9; j++) {
            if(height[j] < min) {
                min = height[j];
                min_pos = j;
            }
        }

        unsigned int temp = height[i];
        height[i] = min;
        height[min_pos] = temp;
    }

    for(unsigned int i = 2; i < 9; i++)
        std::cout << height[i] << "\n";

    return 0;
}
