//
// Created by Thomas Miller on 6/28/25.
//

#ifndef GAME_STATE_H
#define GAME_STATE_H

//GAME_STATE_H

#include <vector>
#include <stack>
#include <SFML/Graphics.hpp>

class Game_State {
public:
  std::vector<std::vector<char>> board;
  std::vector<char> playerMove;
  int round;
  Game_State();

  void appendChar(sf::Event& event);






};
#endif
