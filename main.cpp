#include "ComplexPlane.h"

using namespace std;
using namespace sf;

int main()
{
    unsigned int vmWidth = VideoMode::getDesktopMode().width / 2;
    unsigned int vmHeight = VideoMode::getDesktopMode().height / 2;

    VideoMode vm(vmWidth, vmHeight);
    RenderWindow gameWindow(vm, "MandelbrotSet!!", Style::Default);

    while (gameWindow.isOpen()) {

        gameWindow.clear(Color::Green);



        gameWindow.display();
    }

    return 0;
}
