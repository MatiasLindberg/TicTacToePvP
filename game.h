#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

extern int board[3][3];
extern bool player;

struct pos {
  int x;
  int y;
};

void ResetBoard();
bool ClickedOnTile(int x, int y);
bool CheckForWin();
bool CheckForTie();

#endif