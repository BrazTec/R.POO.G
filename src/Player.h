#pragma once
#include "Character.h"

class Player : public Character {
public:
    Player(const std::string &name);

    std::string attackEnemy(Character &target) override;
    void heal(int amount);
};
