#include "game.h"
#include "graphics.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* background = NULL;
SDL_Texture* X = NULL;
SDL_Texture* O = NULL;

TTF_Font* font;
SDL_Texture* textTexture;
SDL_Surface* text;
SDL_Color color;

bool player;

int board[3][3];

void StartNewGame() {
  ResetBoard();
  player = true;
}

void EndGame() {
  TTF_CloseFont(font);
  SDL_DestroyTexture(background);
  SDL_DestroyTexture(X);
  SDL_DestroyTexture(O);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  IMG_Quit();
}

int main(int argc, char* argv[]) {
  if (!InitWindow(window)) {
    EndGame();
    return 0;
  }
  if (!InitTextures()) {
    EndGame();
    return 0;
  }
  if (!InitText()) {
    EndGame();
    return 0;
  }

  StartNewGame();

  SDL_Rect backgroundPosition = {0, 60, 480, 480};
  SDL_Rect textPosition = {130, 5, 240, 50};

  SDL_Event event;
  int running = true;
  while (running) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          running = false;
        case SDL_MOUSEBUTTONDOWN:
          if (event.button.button == SDL_BUTTON_LEFT &&
              ClickedOnTile(event.button.x, event.button.y)) {
            const char* msg;
            if (CheckForWin()) {
              msg = player ? "X won!" : "O won!";
              StartNewGame();
            } else if (CheckForTie()) {
              msg = "Game is a tie!";
              StartNewGame();
            } else {
              player = !player;
              msg = player ? "Place X!" : "Place O!";
            }
            text = TTF_RenderText_Solid(font, msg, color);
            textTexture = SDL_CreateTextureFromSurface(renderer, text);
            SDL_FreeSurface(text);
          }
      }
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL, &backgroundPosition);
    SDL_RenderCopy(renderer, textTexture, NULL, &textPosition);

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == 1) {
          SDL_Rect position = DrawPosition(i, j);
          SDL_RenderCopy(renderer, X, NULL, &position);
        } else if (board[i][j] == 2) {
          SDL_Rect position = DrawPosition(i, j);
          SDL_RenderCopy(renderer, O, NULL, &position);
        }
      }
    }
    SDL_RenderPresent(renderer);
  }

  EndGame();
  return 0;
}
