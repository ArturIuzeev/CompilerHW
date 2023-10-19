//
// Created by Arthur Yuzeev on 10/18/23.
//

#ifndef GAMEOFLIFE_GAME_H
#define GAMEOFLIFE_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>

constexpr int width = 1000;
constexpr int height = 1000;
constexpr int size_cell = 10;
constexpr int count_cell = width / size_cell;

void draw(int i, int j, bool live);
void flush();
void checkClose();
#endif //GAMEOFLIFE_GAME_H
