#include "screens/VirtualScreen/VirtualScreen.h"
#include <stdio.h>

#include <chrono>
#include <thread>


int main(int argc, char** args)
{
    VirtualScreen *vScreen = new VirtualScreen();
    vScreen->init();

    while(1){
        printf("%d\n", vScreen->debug);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }


    return 0;
}
