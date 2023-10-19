//
// Created by Arthur Yuzeev on 10/18/23.
//

#include "game.h"

int count_neighbors(const int i, const int j, const bool *game_map) {
    int count = 0;

    for (int k = -1; k < 2; ++k) {
        if (i - 1 >= 0 && j + k >= 0 && j + k < count_cell) {
            count += game_map[(i - 1) * count_cell + (j + k)];
        }
        if (i + 1 < count_cell && j + k >= 0 && j + k < count_cell) {
            count += game_map[(i + 1) * count_cell + (j + k)];
        }
    }

    if (j + 1 < count_cell) {
        count += game_map[i * count_cell + (j + 1)];
    }

    if (j - 1 >= 0) {
        count += game_map[i * count_cell + (j - 1)];
    }
    return count;
}

void updateGameMap(bool *game_map) {
    bool future_game_map[count_cell * count_cell];
    for (bool &i: future_game_map) {
        i = false;
    }

    for (int i = 0; i < count_cell; ++i) {
        for (int j = 0; j < count_cell; ++j) {
            if (game_map[i * count_cell + j] &&
                (count_neighbors(i, j, game_map) < 2 || count_neighbors(i, j, game_map) > 3)) {
                future_game_map[i * count_cell + j] = false;
            } else if (!game_map[i * count_cell + j] && count_neighbors(i, j, game_map) == 3) {
                future_game_map[i * count_cell + j] = true;
            } else {
                future_game_map[i * count_cell + j] = game_map[i * count_cell + j];
            }
            draw(i, j, future_game_map[i * count_cell + j]);
        }
    }

    for (int i = 0; i < count_cell; ++i) {
        for (int j = 0; j < count_cell; ++j) {
            game_map[i * count_cell + j] = future_game_map[i * count_cell + j];
        }
    }
}

void app() {
    bool game_map[count_cell * count_cell];
    for (bool &i: game_map) {
        i = false;
    }

    for (int i = 0; i < count_cell; ++i) {
        for (int j = 0; j < count_cell; ++j) {
            if (rand() % 2 == 0) {
                game_map[i * count_cell + j] = true;
            }
            draw(i, j, game_map[i * count_cell + j]);
        }
    }
    flush();

    while (1) {
        checkClose();
        updateGameMap(game_map);
        if (!flush()) {
            return;
        }
    }
}