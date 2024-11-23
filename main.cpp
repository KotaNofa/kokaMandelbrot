#include "ComplexPlane.h"
#include "text.h"


using namespace std;
using namespace sf;

int main()
{
    // Initializing vm and render window
    VideoMode vm(VideoMode::getDesktopMode().width / 2, VideoMode::getDesktopMode().height / 2);
    RenderWindow gameWindow(vm, "MandelbrotSet!!", Style::Default);

    // Initialize Complex Plane;
    ComplexPlane plane(gameWindow.getSize().x, gameWindow.getSize().y);

    // Initialize font and text
    Font bouba;
    if (!bouba.loadFromFile("boubasfont.ttf")) {
        return -1;
    }

    Text startupEcho = createStartupText(bouba, gameWindow.getSize());

    // Loop while window open
    while (gameWindow.isOpen()) {

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

        gameWindow.clear(Color::White);

        gameWindow.draw(startupEcho);



        gameWindow.display();
    }

    return 0;
}
