//
// Created by Arthur Yuzeev on 10/18/23.
//

#include <SFML/Graphics.hpp>
#include "game.h"

extern void app();

sf::RenderWindow window(sf::VideoMode(width, height), "GameOfLife");
sf::RectangleShape game_map[count_cell][count_cell];
sf::Event event{};

void runGame() {
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window.close();

        }

        window.clear();
        app();
        window.display();
    }
}

sf::RectangleShape getCell(const int i, const int j, sf::Color color) {
    sf::RectangleShape cell(sf::Vector2f(size_cell, size_cell));
    cell.setFillColor(color);
    cell.setPosition(i * size_cell, j * size_cell);
    return cell;
}

void draw(const sf::RectangleShape &cell) {
    window.draw(cell);
}

// Why we divide on 2 (I don't know why not)
void init() {
    window.setFramerateLimit(60);
    if (window.isOpen()) {
        for (int i = 0; i < count_cell; ++i) {
            for (int j = 0; j < count_cell; ++j) {
                if (rand() % 2 == 0) {
                    game_map[i][j] = getCell(i, j, sf::Color::Red);
                } else {
                    game_map[i][j] = getCell(i, j, sf::Color::White);
                }
                draw(game_map[i][j]);
            }
        }
        window.display();
    }
}

int main() {
    init();
    runGame();
    return 0;
}