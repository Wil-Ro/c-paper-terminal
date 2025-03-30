#include "../Structs.h"

class Screen
{
protected:
    int width;
    int height;

public:
    void init();
    void display();
    void displayPartial();
    void cleanUp();
};
