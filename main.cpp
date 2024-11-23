#include "ComplexPlane.h"

using namespace std;
using namespace sf;

int main()
{
    // Initializing vm and render window
    VideoMode vm(VideoMode::getDesktopMode().width / 2, VideoMode::getDesktopMode().height / 2);
    RenderWindow gameWindow(vm, "MandelbrotSet!!", Style::Default);
    Font bouba;
    if (!bouba.loadFromFile("boubasfont.ttf")) {
        return -1;
    }


    // Loop while window open
    while (gameWindow.isOpen()) {

        gameWindow.clear(Color::White);

        /*******************
            HANDLE INPUT
        *******************/

        Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                gameWindow.close();
            }
            // TODO: rest of the handling input
        }

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
