#include "graphics.h"

bool InitWindow() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  window = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 480, 540, SDL_WINDOW_SHOWN);

  if (!window) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return false;
  }
  return true;
}

bool InitTextures() {
  if (IMG_Init(IMG_INIT_PNG) == 0) {
    printf("SDL_image could not initialize! SDL_image Error: %s\n",
           IMG_GetError());
    return false;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  background = IMG_LoadTexture(renderer, "Grid.png");
  if (!background) {
    printf("Failed to load texture! SDL_image Error: %s\n", IMG_GetError());
    return false;
  }

  X = IMG_LoadTexture(renderer, "X.png");
  if (!X) {
    printf("Failed to load texture! SDL_image Error: %s\n", IMG_GetError());
    return false;
  }

  O = IMG_LoadTexture(renderer, "O.png");
  if (!O) {
    printf("Failed to load texture! SDL_image Error: %s\n", IMG_GetError());
    return false;
  }

  return true;
}

bool InitText() {
  if (TTF_Init() == -1) {
    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    return false;
  }
  font = TTF_OpenFont("OpenSans.ttf", 40);
  if (!font) {
    printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
    return false;
  }

  color.r = 255;
  color.g = 255;
  color.b = 255;

  text = TTF_RenderText_Solid(font, "Place X!", color);
  if (!text) {
    printf("Unable to create text surface! SDL_ttf Error: %s\n",
           TTF_GetError());
    return false;
  }
  textTexture = SDL_CreateTextureFromSurface(renderer, text);
  SDL_FreeSurface(text);
  if (!textTexture) {
    return false;
  }
  return true;
}

const SDL_Rect DrawPosition(int x, int y) {
  int px, py;

  if (x == 0) {
    px = 15;
  } else if (x == 1) {
    px = 172;
  } else if (x == 2) {
    px = 330;
  }

  if (y == 0) {
    py = 75;
  } else if (y == 1) {
    py = 232;
  } else if (y == 2) {
    py = 390;
  }

  SDL_Rect position = {px, py, 135, 135};
  return position;
}