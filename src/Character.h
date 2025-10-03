#pragma once
#include <string>
#include <iostream>

class Character {
protected:
    std::string name;
    int hp;
    int damage;

public:
    Character(const std::string &name, int hp = 100, int damage = 10);

    std::string getName() const;
    int getHP() const;
    void setHP(int val);
    int getDamage() const;

    virtual std::string attackEnemy(Character &target) = 0;

    void printStatus() const;
};
