#pragma once
#include "Character.h"
#include <string>

class Enemy : public Character {
    std::string specialName;
    bool preparingSpecial;

public:
    Enemy(const std::string &name, int hp, int damage, const std::string &specialName);

    void attackPlayer(Character &player, bool playerDefending);
    void specialAttack(Character &player, bool playerDefending);
    std::string attackEnemy(Character &target) override;

    bool isPreparingSpecial() const { return preparingSpecial; }
    void setPreparingSpecial(bool val) { preparingSpecial = val; }
    std::string getSpecialName() const { return specialName; }
};
