#include <SDL2/SDL.h>
#include "../Screen.h"
#include "BufferIterator.h"
#include <atomic>
#include <thread>

class VirtualScreen: Screen
{


public:
    void init();
    void display();
    void displayPartial();
    void cleanUp();

private:
    int pixelScale = 10;
    int simulatedResolutionWidth = 100;
    int simulatedResolutionHeight = 70;
    int windowWidth;
    int windowHeight;
    void updateWindowResolution();

    SDL_Window* window;
    SDL_Renderer* renderer;

    void initSDL();
    void runWindowAsync();
    void drawGrid(UBYTE* stream);
    void checkInputs();
    SDL_Color boolToColor(bool value);

    std::atomic<UBYTE*> buffer;
    void replaceBuffer(UBYTE* buffer);
    std::thread windowThread;
};
