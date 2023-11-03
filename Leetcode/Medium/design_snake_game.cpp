// Design a Snake game that is played on a device with screen size height x width. Play the game online if you are not familiar with the game.
// The snake is initially positioned at the top left corner (0, o) with a length of 1 unit.
// You are given an array food where food[il = (ri, ci) is the row and
// column position of a piece of food that the snake can eat. When a snake eats a piece of food, its length and the game's score both increase by 1.
// Each piece of food appears one by one on the screen, meaning the second piece of food will not appear until the snake eats the first piece of food.
// When a piece of food appears on the screen, it is guaranteed that it will not appear on a block occupied by the snake.
// The game is over if the snake goes out of bounds (hits a wall) or if its head occupies a space that its body occupies after moving (ie. a snake of length
// 4 cannot run into itself).
// 만약에 음식을 다 먹어치웠는데 이동은 남아있으면 어떻게 되는거지..? > 상세조건 보려면 리트코드 결제 필요함

#include <bits/stdc++.h>
using namespace std;
// 문제에서 주어지는 조건 3가지
int w = 2, h = 3;
vector<vector<int>> food = {{0, 1}, {1, 1}};
string s[5] = {"R", "D", "R", "U", "L"};

int sy, sx, score;
vector<int> ret;
int main(){
    for(int i = 0; i < sizeof(s); i++){
        if(s[i] == "R") sx++;
        else if(s[i] == "L") sx--;
        else if(s[i] == "U") sy--;
        else if(s[i] == "D") sy++;

        // 이동한 위치가 경계 밖이면 -1 
        if(sy < 0 || sx < 0 || sy >= w || sx >= h) ret.push_back(-1);

        // 이동한 위치에 음식이 있으면 score++;
        if(sy == food[i][0] && sx == food[i][1]){
            ret.push_back(++score);
        }
    }
    for(int i : ret) cout << i << "\n";
    return 0;
}