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
    void draw(sf::RenderWindow& window, Game_State& game);
    void handleEvent(const sf::Event& event, Game_State& game, sf::RenderWindow& window);
    void update(const Game_State& game);
private:
    int numKeys;
    const int SCREENWIDTH = 830;
    const int SCREENHEIGHT = 630;
    const int characterSize = 15;
    const int TILE_SIZE = 75;
    const int padding = 8;
    const int margin = 30;
    sf::Font font;

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