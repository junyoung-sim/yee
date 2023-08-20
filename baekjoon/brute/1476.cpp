
#include <iostream>

int main()
{
    unsigned int E, S, M;
    std::cin >> E >> S >> M;

    unsigned int year = 1;
    unsigned int e = 1, s = 1, m = 1;

    while(true) {
        if(e == E && s == S && m == M) break;

        e++; if(e > 15) e = 1;
        s++; if(s > 28) s = 1;
        m++; if(m > 19) m = 1;

        year++;
    }

    std::cout << year << "\n";

    return 0;
}
