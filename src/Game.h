#pragma once
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <string>

class Game {
    Player player;
    Enemy boss;
    std::vector<Enemy> enemies;
    int playerPotions;

    void clearScreen();
    void showScene(const std::string &sceneArt, const std::string &text);
    void battle(Enemy &enemy, const std::string &sceneArt, const std::string &sceneText);
    void showEndScreen(bool victory);
    void startGame();

public:
    Game();
    void mainMenu();
    void resetGame();
};
