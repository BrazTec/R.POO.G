#include "Character.h"

Character::Character(const std::string &name, int hp, int damage)
    : name(name), hp(hp), damage(damage) {}

std::string Character::getName() const { return name; }
int Character::getHP() const { return hp; }
void Character::setHP(int val) { hp = val < 0 ? 0 : val; }
int Character::getDamage() const { return damage; }

void Character::printStatus() const {
    std::cout << name << " HP: " << hp << std::endl;
}
