//
// Created by Arthur Yuzeev on 10/18/23.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "game.h"

extern sf::RectangleShape game_map[count_cell][count_cell];

// in this file I also use sf::Color I think it's not drawing method because I need only check type of cell

int getCount(const int i, const int j) {
    if (game_map[i][j].getFillColor() == sf::Color::Red) {
        return 1;
    }
    return 0;
}

int count_neighbors(const int i, const int j) {
    int count = 0;

    for (int k = -1; k < 2; ++k) {
        if (i - 1 >= 0 && j + k >= 0 && j + k < count_cell) {
            count += getCount(i - 1, j + k);
        }
        if (i + 1 < count_cell && j + k >= 0 && j + k < count_cell) {
            count += getCount(i + 1, j + k);
        }
    }

    if (j + 1 < count_cell) {
        count += getCount(i, j + 1);
    }

    if (j - 1 >= 0) {
        count += getCount(i, j - 1);
    }

    return count;
}

// updating gameMap
void app() {
    sf::RectangleShape future_game_map[count_cell][count_cell];
    for (int i = 0; i < count_cell; ++i) {
        for (int j = 0; j < count_cell; ++j) {
            if (game_map[i][j].getFillColor() == sf::Color::Red &&
                (count_neighbors(i, j) < 2 || count_neighbors(i, j) > 3)) {
                future_game_map[i][j] = getCell(i, j, sf::Color::White);
            } else if (game_map[i][j].getFillColor() == sf::Color::White && count_neighbors(i, j) == 3) {
                future_game_map[i][j] = getCell(i, j, sf::Color::Red);
            } else {
                future_game_map[i][j] = game_map[i][j];
            }
            draw(future_game_map[i][j]);
        }
    }
    for (int i = 0; i < count_cell; ++i) {
        for (int j = 0; j < count_cell; ++j) {
            game_map[i][j] = future_game_map[i][j];
        }
    }
}