//
// Created by Thomas Miller on 6/28/25.
//

#ifndef GUI_H
#define GUI_H

//GUI_H

#include <SFML/Graphics.hpp>
#include "game_state.h"

class GUI {
public:
    std::map<char, sf::Texture*> textures;
    GUI();
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event, Game_State& game);
    void update(const Game_State& game);
private:
    const int TILE_SIZE = 75;

    sf::Texture BB;
    sf::Texture BK;
    sf::Texture BN;
    sf::Texture BP;
    sf::Texture BQ;
    sf::Texture BR;
    sf::Texture WB;
    sf::Texture WK;
    sf::Texture WN;
    sf::Texture WP;
    sf::Texture WQ;
    sf::Texture WR;

};
#endif