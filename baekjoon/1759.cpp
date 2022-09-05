#include <iostream>
#include <vector>
#include <string>

int L, C;
std::vector<char> letters;

void func(int i, std::string pw) {
    if(pw.length() == L) {
        int v = 0, c = 0;
        for(char &ch: pw) {
            v += (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
            c += (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u');
        }

        if(v >= 1 && c >= 2)
            std::cout << pw << "\n";

        return;
    }

    for(int k = i+1; k < C; k++)
        func(k, pw + letters[k]);
}

int main()
{
    std::cin >> L >> C;
    letters.resize(C);
    for(int i = 0; i < C; i++)
        std::cin >> letters[i];

    for(int i = 0; i < C; i++) {
        int min_pos = i;
        for(int j = i; j < C; j++) {
            if(letters[j] < letters[min_pos])
                min_pos = j;
        }
        std::swap(letters[i], letters[min_pos]);
    }

    for(int i = 0; i < C; i++) {
        std::string pw(1, letters[i]);
        func(i, pw);
    }

    return 0;
}
