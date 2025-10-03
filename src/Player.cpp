#include "Player.h"

Player::Player(const std::string &name) : Character(name, 100, 10) {}

std::string Player::attackEnemy(Character &target) {
    target.setHP(target.getHP() - damage);
    return name + " atacou " + target.getName() + " causando " + std::to_string(damage) + " de dano!";
}

void Player::heal(int amount) {
    setHP(getHP() + amount);
}
