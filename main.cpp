#include "ComplexPlane.h"


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

    Text startupEcho;
    startupEcho.setString("Successfully Opened");
    startupEcho.setFont(bouba);
    startupEcho.setFillColor(sf::Color::Black);
    startupEcho.setCharacterSize(gameWindow.getSize().y / 24);
    startupEcho.setPosition(gameWindow.getSize().y / 24, gameWindow.getSize().y / 24);

    Event event;

    // Loop while window open
    while (gameWindow.isOpen()) {

        /*******************
            HANDLE INPUT
        *******************/

        while (gameWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                gameWindow.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    plane.zoomIn();
                    plane.setCenter({ event.mouseButton.x, event.mouseButton.y });
                }
                else if (event.mouseButton.button == Mouse::Right)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    plane.zoomOut();
                    plane.setCenter({ event.mouseButton.x, event.mouseButton.y });
                }
            }
            if (event.type == Event::MouseMoved) {
                plane.setMouseLocation({ event.mouseMove.x, event.mouseMove.y });
                std::cout << event.mouseMove.x << " ";
                std::cout << event.mouseMove.y << endl;
                
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    gameWindow.close();
                }
            }
        }

        /*************
            UPDATE
        *************/

        plane.updateRender();

        plane.loadText(startupEcho);

        /************
            DRAW
        ************/

        gameWindow.clear(Color::White);

        plane.draw(gameWindow, RenderStates::Default);

        gameWindow.draw(startupEcho);

        gameWindow.display();
    }

    return 0;
}
