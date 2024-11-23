#include "text.h"
#include "ComplexPlane.h"

sf::Text createStartupText(const sf::Font& font, const sf::Vector2u& windowSize) {
    sf::Text startupEcho;
    startupEcho.setString("Successfully Opened");
    startupEcho.setFont(font);
    startupEcho.setFillColor(sf::Color::Black);
    startupEcho.setCharacterSize(windowSize.y / 24);
    startupEcho.setPosition(windowSize.y / 24, windowSize.y / 24);
    return startupEcho;
}
