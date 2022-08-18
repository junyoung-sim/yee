
#include <cstdlib>
#include <iostream>

int main()
{
    int N; std::cin >> N;
    int num_of_bad_keys; std::cin >> num_of_bad_keys;

    int bad_keys[num_of_bad_keys];
    for(int i = 0; i < num_of_bad_keys; i++) std::cin >> bad_keys[i];

    int best = abs(N-100);
    for(int i = 0; i <= 1000000; i++) {
        std::string channel = std::to_string(i);
        bool accessible = true;
        for(int k = 0; k < channel.length(); k++) {
            for(int &bad: bad_keys) {
                accessible = channel[k] - '0' != bad;
                if(!accessible) break;
            }

            if(!accessible) break;
        }

        if(accessible) {
            int clicks = channel.length() + abs(i-N);
            best = std::min(clicks, best);
        }
    }

    std::cout << best << "\n";

    return 0;
}
