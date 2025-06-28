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
    if(!font.loadFromFile("fonts/arial.ttf"))
        std::cerr << "Error loading font" << std::endl;

    textures['R'] = &WR;
    textures['N'] = &WN;
    textures['B'] = &WB;
    textures['K'] = &WK;
    textures['Q'] = &WQ;
    textures['P'] = &WP;

    textures['r'] = &BR;
    textures['n'] = &BN;
    textures['b'] = &BB;
    textures['k'] = &BK;
    textures['q'] = &BQ;
    textures['p'] = &BP;

}

void GUI::draw(sf::RenderWindow& window, Game_State& game) {
    //draw tiles
    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            sf::RectangleShape tile(sf::Vector2f(TILE_SIZE,TILE_SIZE));
            tile.setPosition(col * TILE_SIZE, row * TILE_SIZE);
            if((row + col) % 2 == 0)
                tile.setFillColor(sf::Color::White);
            else
                tile.setFillColor(sf::Color::Cyan);
            window.draw(tile);
        }
    }
    //draw pieces according to game_state class
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            char c = game.board[i][j];
            if(c != '.') {
                sf::Sprite piece;
                piece.setTexture(*textures[c]);
                piece.setPosition(j * TILE_SIZE + padding, i * TILE_SIZE + padding);
                window.draw(piece);
            }
        }
    }
    //input box
    sf::Text input_message;
    input_message.setFont(font);
    input_message.setCharacterSize(20);
    input_message.setFillColor(sf::Color::White);
    input_message.setString("Input move");
    input_message.setPosition(sf::Vector2f(640, 150));
    input_message.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::RectangleShape inputBox;
    inputBox.setSize(sf::Vector2f(150, 25));
    inputBox.setPosition(625, 200);
    inputBox.setFillColor(sf::Color::White);

    window.draw(input_message);
    window.draw(inputBox);


}