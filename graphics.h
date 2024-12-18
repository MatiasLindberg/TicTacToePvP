#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* background;
extern SDL_Texture* X;
extern SDL_Texture* O;

extern TTF_Font* font;
extern SDL_Texture* textTexture;
extern SDL_Surface* text;
extern SDL_Color color;

bool InitWindow();
bool InitTextures();
bool InitText();

const SDL_Rect DrawPosition(int x, int y);

#endif