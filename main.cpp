//
// Created by Arthur Yuzeev on 10/18/23.
//

#include <SFML/Graphics.hpp>
#include "game.h"

static sf::RenderWindow window(sf::VideoMode(width, height), "GameOfLife");

extern void app();

sf::RectangleShape getCell(const int i, const int j, sf::Color color) {
    sf::RectangleShape cell(sf::Vector2f(size_cell, size_cell));
    cell.setFillColor(color);
    cell.setPosition(i * size_cell, j * size_cell);
    return cell;
}


void draw(int i, int j, bool live) {
    if (live) {
        window.draw(getCell(i, j, sf::Color::Red));
        return;
    }

    window.draw(getCell(i, j, sf::Color::White));
}

bool flush() {
    if (window.isOpen()) {
        window.display();
        window.clear();
        return true;
    }
    return false;
}

void initGame() {
    window.setFramerateLimit(60);
    srand(time(NULL));
}

void checkClose() {
    sf::Event event{};

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window.close();
            return;
        }
    }
}

int main() {
    initGame();
    app();
    return 0;
}
