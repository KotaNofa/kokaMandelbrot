#include "ComplexPlane.h"

using namespace std;
using namespace sf;

int main()
{
    // Setting window size
    unsigned int vmWidth = VideoMode::getDesktopMode().width / 2;
    unsigned int vmHeight = VideoMode::getDesktopMode().height / 2;

    // Initializing vm and render window
    VideoMode vm(vmWidth, vmHeight);
    RenderWindow gameWindow(vm, "MandelbrotSet!!", Style::Default);

    // Loop while window open
    while (gameWindow.isOpen()) {

        gameWindow.clear(Color::Green);

        /*******************
            HANDLE INPUT
        *******************/

        // TODO: handling input

        /*************
            UPDATE
        *************/

        // TODO: update loop

        /************
            DRAW
        ************/

        // TODO: rest of the drawing

        gameWindow.display();
    }

    return 0;
}
