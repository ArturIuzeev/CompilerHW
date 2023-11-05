//
// Created by Arthur Yuzeev on 10/18/23.
//

#ifndef GAMEOFLIFE_GAME_H
#define GAMEOFLIFE_GAME_H


constexpr unsigned int width = 1000;
constexpr unsigned int height = 1000;
constexpr unsigned int size_cell = 10;
constexpr unsigned int count_cell = width / size_cell;

void draw(unsigned int i, unsigned int j, bool live);
bool flush();
void checkClose();

#endif //GAMEOFLIFE_GAME_H
