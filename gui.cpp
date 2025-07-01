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

    numKeys = 0;

    sf::Color darkTiles(10,94,49);
}

void GUI::draw(sf::RenderWindow& window, Game_State& game) {
    //draw tiles
    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            sf::RectangleShape tile(sf::Vector2f(TILE_SIZE,TILE_SIZE));
            tile.setPosition(col * TILE_SIZE + margin, row * TILE_SIZE);
            if((row + col) % 2 == 0)
                tile.setFillColor(sf::Color(240,240,240));
            else
                tile.setFillColor(sf::Color(10,94,49));
            window.draw(tile);
        }
    }
    //draw letters/numbers coordinates
    for(int i = 0; i < 8; i++) {
        sf::Text letter;
        letter.setFont(font);
        letter.setCharacterSize(25);
        char c = 'A' + i;
        letter.setString(std::string(1, c));
        letter.setStyle(sf::Text::Bold);
        letter.setFillColor(sf::Color(240,240,240));
        letter.setPosition(margin + TILE_SIZE / 2.3 + TILE_SIZE * i, SCREENHEIGHT - margin);

        sf::Text digit;
        digit.setFont(font);
        digit.setCharacterSize(25);
        digit.setStyle(sf::Text::Bold);
        digit.setFillColor(sf::Color(240,240,240));
        char d = '8' - i;
        digit.setString(std::string(1, d));
        digit.setPosition(6, margin + TILE_SIZE * i);

        window.draw(letter);
        window.draw(digit);
    }
    //draw pieces according to game_state class
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            char c = game.board[i][j];
            if(c != '.') {
                sf::Sprite piece;
                piece.setTexture(*textures[c]);
                piece.setPosition(j * TILE_SIZE + padding + margin, i * TILE_SIZE + padding);
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
    input_message.setPosition(sf::Vector2f(SCREENWIDTH / 1.24, SCREENHEIGHT / 4.2));
    input_message.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::RectangleShape inputBox;
    inputBox.setSize(sf::Vector2f(150, 25));
    inputBox.setPosition(SCREENWIDTH / 1.27, SCREENHEIGHT / 3.15);
    inputBox.setFillColor(sf::Color(240,240,240));

    window.draw(inputBox);

    //player move
    numKeys = 0;
    if(!game.playerMove.empty()) {
        for(auto bit : game.playerMove) {
            sf::Text digit;
            digit.setFont(font);
            digit.setCharacterSize(characterSize);
            digit.setString(std::string(1,bit));
            digit.setFillColor(sf::Color::Black);
            digit.setPosition(sf::Vector2f(SCREENWIDTH / 1.26 + (numKeys * (characterSize-5)), 200));
            window.draw(digit);

            numKeys++;
        }
    }

    window.draw(input_message);
}

