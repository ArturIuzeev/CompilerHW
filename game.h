//
// Created by Arthur Yuzeev on 10/18/23.
//

#ifndef GAMEOFLIFE_GAME_H
#define GAMEOFLIFE_GAME_H

const int width = 1000;
const int height = 1000;
const int size_cell = 15;
const int count_cell = width/size_cell;

void draw(const sf::RectangleShape& cell);
sf::RectangleShape getCell(int i, int j, sf::Color color);

#endif //GAMEOFLIFE_GAME_H
