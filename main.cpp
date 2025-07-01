//
// Created by Thomas Miller on 6/28/25.
//
#include <iostream>
#include "game_state.h"
#include "gui.h"
#include <sfml/Graphics.hpp>
int main() {
    const int WINDOWWIDTH = 830;
    const int WINDOWHEIGHT = 630;

    const sf::Color background_color(64, 64, 64);
    sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "Chess Game");
    Game_State game;
    GUI gui;

    bool keyDown = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed && !keyDown) {
                game.appendChar(event);
                keyDown = true;
            }
            if(event.type == sf::Event::KeyReleased)
                keyDown = false;

        }

        //gui.update(game);

        window.clear(background_color);
        gui.draw(window, game);  // draw everything via GUI
        window.display();
    }
  return 0;
}
