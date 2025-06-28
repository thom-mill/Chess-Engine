//
// Created by Thomas Miller on 6/28/25.
//

#include "gui.h"
#include <iostream>
GUI::GUI() {
    if(!BB.loadFromFile("textures/BB.png")||
        !BK.loadFromFile("textures/BK.png")||
        !BN.loadFromFile("textures/BN.png")||
        !BP.loadFromFile("textures/BP.png")||
        !BQ.loadFromFile("textures/BQ.png")||
        !BR.loadFromFile("textures/BR.png")||
        !WB.loadFromFile("textures/WB.png")||
        !WK.loadFromFile("textures/WK.png")||
        !WN.loadFromFile("textures/WN.png")||
        !WP.loadFromFile("textures/WP.png")||
        !WQ.loadFromFile("textures/WQ.png")||
        !WR.loadFromFile("textures/WR.png")) {

        std::cerr << "Error loading png" << std::endl;
    }

}

void GUI::draw(sf::RenderWindow& window) {
    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            sf::RectangleShape tile(sf::Vector2f(TILE_SIZE,TILE_SIZE));
            tile.setPosition(col * TILE_SIZE, row * TILE_SIZE);
            if((row + col) % 2 == 0)
                tile.setFillColor(sf::Color::White);
            else
                tile.setFillColor(sf::Color::Black);
            window.draw(tile);
        }
    }

}