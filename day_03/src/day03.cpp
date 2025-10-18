#include "day03.hpp"
#include <set>

int solve_part_1(std::vector<std::string> input) { 
    int x = 0;
    int y = 0;
    std::set<std::pair<int,int>> visited{std::make_pair(0,0)};
    for (const auto& line : input)   {
        for (const char& dir : line) {
            const auto cord = update_x_y_coordinate(dir,x,y);
            visited.insert(std::make_pair(x,y));
        }
    }
    return visited.size();
}

std::pair<int,int> update_x_y_coordinate(const char dir, int& x, int& y) {
        switch (dir)
        {
        case '^':
            y++;
            break;
        case 'v':
            y--;
            break;
        case '<':
            x--;
            break;
        case '>':
            x++;
            break;
        default:
            break;
        }
        return std::make_pair(x,y);
}

int solve_part_2(const std::vector<std::string> input) { 

    int santa_x = 0;
    int santa_y = 0;
    int robo_santa_x = 0;
    int robo_santa_y = 0;
    int move = 0;
    std::set<std::pair<int,int>> visited{std::make_pair(0,0)};
    for (const char& dir : input[0]) {
        if (move % 2 == 0) {
            const auto cord = update_x_y_coordinate(dir,santa_x,santa_y);
            visited.insert(std::make_pair(santa_x, santa_y));
        } else {
            const auto cord = update_x_y_coordinate(dir,robo_santa_x,robo_santa_y);
            visited.insert(std::make_pair(robo_santa_x, robo_santa_y));
        }
        move++;
    }
    return visited.size();
 }
