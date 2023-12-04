
#include <iostream>
#include <string>
#include <vector>

unsigned int algo(std::vector<std::vector<char>> &candy, unsigned int i, unsigned int j, unsigned int p1, unsigned int p2) {
    char this_candy = candy[i][j];
    char that_candy = candy[p1][p2];
    candy[i][j] = that_candy;
    candy[p1][p2] = this_candy;

    unsigned int max_run = 0;
    unsigned int run = 1;

    for(unsigned int r = 0; r < candy.size(); r++) {
        for(unsigned int c = 1; c < candy[r].size(); c++) {
            if(candy[r][c] == candy[r][c-1]) run++;
            else {
                max_run = std::max(run, max_run);
                run = 1;
            }
        }

        max_run = std::max(run, max_run);
        run = 1;
    }

    run = 1;
    for(unsigned int c = 0; c < candy[0].size(); c++) {
        for(unsigned int r = 1; r < candy.size(); r++) {
            if(candy[r][c] == candy[r-1][c]) run++;
            else {
                max_run = std::max(run, max_run);
                run = 1;
            }
        }

        max_run = std::max(run, max_run);
        run = 1;
    }

    candy[i][j] = this_candy;
    candy[p1][p2] = that_candy;

    return max_run;
}

int main()
{
    unsigned int N;
    std::cin >> N;

    std::vector<std::vector<char>> candy;
    for(unsigned int i = 0; i < N; i++) {
        std::string line;
        std::cin >> line;

        std::vector<char> candy_line;
        for(unsigned int k = 0; k < N; k++)
            candy_line.push_back(line[k]);
        candy.push_back(candy_line);

        std::vector<char>().swap(candy_line);
    }

    unsigned int max_candy = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char this_candy = candy[i][j];
            if(i-1 >= 0 && candy[i-1][j] != this_candy) max_candy = std::max(algo(candy,i,j,i-1,j), max_candy);
            if(j+1 < N && candy[i][j+1] != this_candy) max_candy = std::max(algo(candy,i,j,i,j+1), max_candy);
            if(i+1 < N && candy[i+1][j] != this_candy) max_candy = std::max(algo(candy,i,j,i+1,j), max_candy);
            if(j-1 >= 0 && candy[i][j-1] != this_candy) max_candy = std::max(algo(candy,i,j,i,j-1), max_candy);
        }
    }

    std::cout << max_candy << "\n";

    std::vector<std::vector<char>>().swap(candy);

    return 0;
}
