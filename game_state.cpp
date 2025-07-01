//
// Created by Thomas Miller on 6/28/25.
//
#include "game_state.h"

#include <iostream>


Game_State::Game_State() {
    board =
        {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.',},
        {'.', '.', '.', '.', '.', '.', '.', '.',},
        {'.', '.', '.', '.', '.', '.', '.', '.',},
        {'.', '.', '.', '.', '.', '.', '.', '.',},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
        };
    round = 1;
}

void Game_State::appendChar(sf::Event& event) {
    sf::Keyboard::Key key = event.key.code;
    if (key >= sf::Keyboard::A && key <= sf::Keyboard::Z) {
        char c = 'A' + (key - sf::Keyboard::A);
        playerMove.push_back(c);
    }
    else if(key >= sf::Keyboard::Num1 && key <= sf::Keyboard::Num8) {
        char c = '1' + (key - sf::Keyboard::Num1);
        playerMove.push_back(c);
    }
    else if(key == sf::Keyboard::Hyphen) {
        char c = '-' + (key - sf::Keyboard::Hyphen);
        playerMove.push_back(c);
    }
    else if(key == sf::Keyboard::Backspace && !playerMove.empty()) {
        playerMove.pop_back();
    }
}