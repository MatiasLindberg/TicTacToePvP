#include "game.h"

void ResetBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      board[i][j] = 0;
  }
}

bool ClickedOnTile(int x, int y) {
  struct pos a;
  if (x >= 15 && x < 150) {
    a.x = 0;
  } else if (x >= 172 && x < 318) {
    a.x = 1;
  } else if (x >= 330 && x < 465) {
    a.x = 2;
  } else {
    a.x = -1;
  }

  if (y >= 75 && y < 210) {
    a.y = 0;
  } else if (y >= 232 && y < 378) {
    a.y = 1;
  } else if (y >= 390 && y < 525) {
    a.y = 2;
  } else {
    a.y = -1;
  }

  if (a.x == -1 || a.y == -1 || board[a.x][a.y] != 0) {
    return false;
  }

  if (player) {
    board[a.x][a.y] = 1;
  } else {
    board[a.x][a.y] = 2;
  }
  return true;
}

bool CheckForWin() {
  int x;
  if (player) {
    x = 1;
  } else {
    x = 2;
  }

  for (int i = 0; i < 3; i++) {
    if (board[0][i] == x) {
      if (board[1][i] == x && board[2][i] == x) {
        return true;
      }
      if (i == 0 && board[1][1] == x && board[2][2] == x) {
        return true;
      }
      if (i == 2 && board[1][1] == x && board[2][0] == x) {
        return true;
      }
    }
  }

  for (int i = 1; i < 3; i++) {
    if (board[i][0] == x) {
      if (board[i][1] == x && board[i][2] == x) {
        return true;
      }
    }
  }

  return false;
}

bool CheckForTie() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 0) {
        return false;
      }
    }
  }
  return true;
}