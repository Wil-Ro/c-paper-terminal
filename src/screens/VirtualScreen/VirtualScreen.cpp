#include "VirtualScreen.h"

void VirtualScreen::initSDL()
{
    SDL_Init(SDL_INIT_VIDEO < 0);

    updateWindowResolution();
    this->window = SDL_CreateWindow("E-Ink Dummy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, 0);

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

    UBYTE* buffer = (UBYTE*)calloc(sizeof(UBYTE), simulatedResolutionHeight*(simulatedResolutionWidth/8));
    replaceBuffer(buffer);

    windowThread = std::thread(&VirtualScreen::runWindowAsync, this);
}

void VirtualScreen::runWindowAsync()
{
    for(;;)
    {
        SDL_RenderClear(this->renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

        this->checkInputs();
        this->drawGrid(this->buffer); //todo unsure on if this is actually threadsafe or not


        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
}

void VirtualScreen::drawGrid(UBYTE* buffer)
{
    BufferIterator* iterator = new BufferIterator(buffer, simulatedResolutionHeight*(simulatedResolutionWidth/8));

    SDL_Rect *rect = new SDL_Rect();
    for (int y = 0; y < windowHeight; y=y+pixelScale)
    {
        for (int x = 0; x < windowWidth; x+=pixelScale)
        {
            SDL_Color color = boolToColor(iterator->next());
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

            rect->x = x;
            rect->y = y;
            rect->w = pixelScale;
            rect->h = pixelScale;
            SDL_RenderFillRect(this->renderer, rect);
        }
    }

    delete rect;
    delete iterator;
}

void VirtualScreen::checkInputs()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                exit(0);
        }
    }
}

void VirtualScreen::updateWindowResolution()
{
    windowWidth = simulatedResolutionWidth * pixelScale;
    windowHeight = simulatedResolutionHeight * pixelScale;
}

SDL_Color VirtualScreen::boolToColor(bool value)
{
    const SDL_Color black = {0, 0, 0, 0};
    const SDL_Color white = {255, 255, 255, 255};
    return value ? white : black;
}

void VirtualScreen::replaceBuffer(UBYTE* buffer)
{
    this->buffer = buffer; //todo does this need to delete the old data?
}


void VirtualScreen::cleanUp()
{

}

void VirtualScreen::init()
{
    this->initSDL();
}

/*
 * literally just use std::thread and make a
 * std::thread thread_obj(method, params)
 */

/*
 UBYTE* data = (UBYTE*)calloc(sizeof(UBYTE), simulatedResolutionHeight*simulatedResolutionWidth/8);
 for (int i=0; i<(simulatedResolutionHeight*simulatedResolutionWidth)/8; i++)
 {
 data[i] = 0b00001;
 }
 */
