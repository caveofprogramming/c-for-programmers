#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"

int* gFrameBuffer;
SDL_Window* gSDLWindow;
SDL_Renderer* gSDLRenderer;
SDL_Texture* gSDLTexture;
static int gDone;
const int WINDOW_WIDTH = 1920 / 2;
const int WINDOW_HEIGHT = 1080 / 2;

bool update()
{
  printf("Updating.\n");
  SDL_Event e;
  if (SDL_PollEvent(&e))
  {
    if (e.type == SDL_EVENT_QUIT)
    {
      return false;
    }
    if (e.type == SDL_EVENT_KEY_UP && e.key.key == SDLK_ESCAPE)
    {
      return false;
    }
  }

  char* pix;
  int pitch;
  
  printf("Locking.\n");
  SDL_LockTexture(gSDLTexture, NULL, (void**)&pix, &pitch);

  printf("Memcpy.\n");
  for (int i = 0, sp = 0, dp = 0; i < WINDOW_HEIGHT; i++, dp += WINDOW_WIDTH, sp += pitch)
    memcpy(pix + sp, gFrameBuffer + dp, WINDOW_WIDTH * 4);

  printf("Unlock.\n");
  SDL_UnlockTexture(gSDLTexture);  
  SDL_RenderTexture(gSDLRenderer, gSDLTexture, NULL, NULL);
  SDL_RenderPresent(gSDLRenderer);
  SDL_Delay(1);
  return true;
}

void render(Uint64 aTicks)
{
  for (int i = 0, c = 0; i < WINDOW_HEIGHT; i++)
  {
    for (int j = 0; j < WINDOW_WIDTH; j++, c++)
    {
      gFrameBuffer[c] = (int)(i * i + j * j + aTicks) | 0xff000000;
    }
  }
}

void loop()
{
  if (!update())
  {
    printf("Stopping.\n");
    gDone = 1;
  }
  else
  {
    printf("Render.\n");
    render(SDL_GetTicks());
  }
}

int main(int argc, char** argv)
{
  printf("Starting.\n");
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
  {
    return -1;
  }

  printf("Video OK.\n");
  gFrameBuffer = malloc(WINDOW_WIDTH * WINDOW_HEIGHT);
  gSDLWindow = SDL_CreateWindow("SDL3 window", WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  gSDLRenderer = SDL_CreateRenderer(gSDLWindow, NULL);
  gSDLTexture = SDL_CreateTexture(gSDLRenderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);

  if (!gFrameBuffer || !gSDLWindow || !gSDLRenderer || !gSDLTexture)
    return -1;

  gDone = 0;

  printf("Looping\n");

  while (!gDone)
  {
    loop();
  }

  printf("Terminating.\n");

  SDL_DestroyTexture(gSDLTexture);
  SDL_DestroyRenderer(gSDLRenderer);
  SDL_DestroyWindow(gSDLWindow);
  SDL_Quit();
  free(gFrameBuffer);

  return 0;
}

