//
// Created by Thomas Miller on 6/28/25.
//
#include "game_state.h"

#include <iostream>
#include <regex>


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

void Game_State::updateBoard(std::string& move) {
    int startRow = 7 - (move[1] - '1');
    int startCol = move[0] - 'a';
    int endRow = 7 - (move[4] - '1');
    int endCol = move[3] - 'a';

    board[endRow][endCol] = board[startRow][startCol];
    board[startRow][startCol] = '.';
    round++;
}

void Game_State::appendChar(sf::Event& event) {
    sf::Keyboard::Key key = event.key.code;
    if (key >= sf::Keyboard::A && key <= sf::Keyboard::Z) {
        char c = 'A' + (key - sf::Keyboard::A);
        playerMove.push_back(std::tolower(c));
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
    else if(key == sf::Keyboard::Enter && !playerMove.empty()) {
        std::string move;
        for(char c : playerMove) {
            move += c;
        }
        playerMove.clear();
        if(validateMove(move))
            updateBoard(move);
    }
}

bool Game_State::validateMove(std::string& move) {
    if(move.length() != 5) return false;

    std::regex movePattern("^[a-h][1-8].{1}[a-h][1-8]$");

    if(!std::regex_match(move, movePattern)) {
        std::cerr << "Input move in the following format: a1-b2" << std::endl;
        return false;
    }
    //transfer char to iterable row and col
    int startRow = 7 - (move[1] - '1');
    int startCol = move[0] - 'a';
    int endRow = 7 - (move[4] - '1');
    int endCol = move[3] - 'a';

    bool whiteToMove = (round % 2 == 1) ? true : false;

    std::cout << startRow << ":" << startCol << std::endl;
    std::cout << endRow << ":" << endCol << std::endl;

    std::regex upper("^[A-Z]");
    std::regex lower("^[a-z]");

    char movePiece = board[startRow][startCol];
    //if else logic
    if(whiteToMove) {
        if(movePiece >= 'A' && movePiece <= 'Z') {
            return validateHelper(movePiece, startRow, startCol, endRow, endCol, whiteToMove);
        }
        return false;
    }
    if(movePiece >= 'a' && movePiece <= 'z') {
        return validateHelper(movePiece, startRow, startCol, endRow, endCol, whiteToMove);
    }
    return false;

}

bool Game_State::validateHelper(char movePiece, int row, int col, int endRow, int endCol, bool whiteToMove) {
    //======================================
    //============PAWN LOGIC================
    //======================================
    if(movePiece == 'P' && whiteToMove) {
        if(row - endRow == 1) {
            if(col == endCol && board[endRow][endCol] == '.') {
                return true;
            }
            if(abs(col-endCol) == 1 && board[endRow][endCol] >= 'a' && board[endRow][endCol] <= 'z') {
                return true;
            }
            return false;
        }
        if(row - endRow == 2 && row == 6) {
            if(col == endCol && board[endRow][endCol] == '.') {
                return true;
            }
        }
        return false;
    }
    if(movePiece == 'p' && !whiteToMove) {
        if(endRow - row == 1) {
            if(col == endCol && board[endRow][endCol] == '.') {
                return true;
            }
            if(abs(col-endCol) == 1 && board[endRow][endCol] >= 'A' && board[endRow][endCol] <= 'Z') {
                return true;
            }
            return false;
        }
        if(endRow - row == 2 && row == 1) {
            if(col == endCol && board[endRow][endCol] == '.') {
                return true;
            }
        }
        return false;
    }
    //======================================
    //============KNIGHT LOGIC==============
    //======================================
    if(movePiece == 'N' && whiteToMove) {
        if(abs(row - endRow) == 1 && abs(col - endCol) == 2 || abs(row - endRow) == 2 && abs(col - endCol) == 1) {
            if(board[endRow][endCol] == '.' || (board[endRow][endCol] >= 'a' && board[endRow][endCol] <= 'z'))
                return true;
        }
        return false;

    }
    if(movePiece == 'n' && !whiteToMove) {
        if(abs(row - endRow) == 1 && abs(col - endCol) == 2 || abs(row - endRow) == 2 && abs(col - endCol) == 1) {
            if(board[endRow][endCol] == '.' || (board[endRow][endCol] >= 'A' && board[endRow][endCol] <= 'Z'))
                return true;
        }
        return false;
    }
    //======================================
    //============BISHOP LOGIC==============
    //======================================
    if(movePiece == 'B' && whiteToMove) {
        if(abs(row-endRow) == abs(col-endCol) && (board[endRow][endCol] == '.' || (board[endRow][endCol] >= 'a' && board[endRow][endCol] <= 'z'))) {
            int dx, dy;
            if(endRow > row && endCol > col) {
                dx = 1;
                dy = 1;
            }
            else if(endRow > row) {
                dx = -1;
                dy = 1;
            }
            else if(endCol > col) {
                dx = 1;
                dy = -1;
            }
            else {
                dx = -1;
                dy = -1;
            }
            

        }
    }
    if(movePiece == 'b' && !whiteToMove) {
        if(abs(row-endRow) == abs(col-endCol) && (board[endRow][endCol] == '.' || (board[endRow][endCol] >= 'A' && board[endRow][endCol] <= 'Z'))) {

        }
    }
    //======================================
    //==============ROOK LOGIC==============
    //======================================
    if(movePiece == 'R' && whiteToMove) {
        if(endRow == row && (board[endRow][endCol] == '.' || (board[endRow][endCol] >= 'a' && board[endRow][endCol] <= 'z'))) {
            int toRight = (endCol > col) ? 1 : -1;
            for(int i = col + toRight; abs(i-endCol) >= 1; i += (1*toRight)) {
                if(board[row][i] != '.')
                    return false;
            }
            return true;
        }
        if(endCol == col && (board[endRow][endCol] == '.' || (board[endRow][endCol] >= 'a' && board[endRow][endCol] <= 'z'))) {
            int toDown = (endRow > row) ? 1 : -1;
            for(int i = row + toDown; abs(i-endRow) >= 1; i += (1*toDown)) {
                if(board[i][col] != '.')
                    return false;
            }
            return true;
        }
    }
    if(movePiece == 'r' && !whiteToMove) {
        if(endRow == row && (board[endRow][endCol] == '.' || (board[endRow][endCol] >= 'A' && board[endRow][endCol] <= 'Z'))) {
            int toRight = (endCol > col) ? 1 : -1;
            for(int i = col + toRight; abs(i-endCol) >= 1; i += (1*toRight)) {
                if(board[row][i] != '.')
                    return false;
            }
            return true;
        }
        if(endCol == col && (board[endRow][endCol] == '.' || (board[endRow][endCol] >= 'A' && board[endRow][endCol] <= 'Z'))) {
            int toDown = (endRow > row) ? 1 : -1;
            for(int i = row + toDown; abs(i-endRow) >= 1; i += (1*toDown)) {
                if(board[i][col] != '.')
                    return false;
            }
            return true;
        }
    }

    return false;
}