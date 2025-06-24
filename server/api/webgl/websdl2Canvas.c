#include <GLES2/gl2.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_opengles2.h>
#include <SDL2/SDL_video.h>

const char *APP_TITLE = "Bmb";
const int SCREEN_WIDTH = 540;
const int SCREEN_HEIGHT = 432;

const SDL_Window *window = NULL;
const SDL_GLContext *context = NULL;

void renderFrame() {
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_GL_SwapWindow(window);
}

int main() {
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("%s\r", SDL_GetError());
    return 1;
  }

  window = SDL_CreateWindow(
      APP_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
      SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  if (!window) {
    SDL_Quit();
    return 1;
  }

  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);
  SDL_Quit();
}