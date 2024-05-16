#ifndef GAME_H
#define GAME_H

#include <bits/stdc++.h>
#include "../Display/display.h"
#include "../Player/player.h"

using namespace std;


class Game {
public:
    Game();
    void initGame(bool by_input = false);
    void fromBoard(vector<vector<int>> &board, vector<vector<int>> &position, int turn, int remain[2]);
    void startGame();
    void endGame();
    bool isEnd();
    int winner();
    int move(int id, int dir, int color);
    int undo(int id, int dir, int color, int original);
    vector<array<int, 2>> expand(int color);

    int n, m;
    vector<vector<int>> position;

    
private:
    Player* players[2];

    int turn;
    int remain[2];
    vector<vector<int>> board;

    static int dx[2][3];
    static int dy[2][3];

    void randomBoard();
    void inputBoard();
    bool isColor(int x, int y, int color);
    bool isRed(int x, int y);
    bool isBlue(int x, int y);
    bool isEmpty(int x, int y);
    bool redSurvice();
    bool blueSurvice();
    void showValidMove();
};

#endif