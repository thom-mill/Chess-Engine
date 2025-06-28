//
// Created by Thomas Miller on 6/28/25.
//
#include <iostream>
#include "game_state.h"
#include "gui.h"
#include <sfml/Graphics.hpp>
int main() {
    const int WINDOWWIDTH = 800;
    const int WINDOWHEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "Chess Game");
    Game_State game;
    GUI gui;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Optional: pass events to GUI for processing
            //gui.handleEvent(event, game);
        }

        //gui.update(game);

        window.clear();
        gui.draw(window);  // draw everything via GUI
        window.display();
    }
  return 0;
}
