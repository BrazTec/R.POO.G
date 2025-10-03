#include "Enemy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Enemy::Enemy(const std::string &name, int hp, int damage, const std::string &specialName)
    : Character(name, hp, damage), specialName(specialName), preparingSpecial(false) {}

// ----------------- ataque -----------------
void Enemy::attackPlayer(Character &player, bool playerDefending) {
    int actualDamage = damage;
    if(playerDefending) {
        actualDamage = static_cast<int>(damage * 0.5);
    }
    player.setHP(player.getHP() - actualDamage);
    std::cout << "\033[31m\n"<< name << " atacou e causou " << actualDamage << " de dano!\n"<<"\033[0m";
}

void Enemy::specialAttack(Character &player, bool playerDefending) {
    int actualDamage = damage * 2;
    if(playerDefending) {
        actualDamage = static_cast<int>(actualDamage * 0.01);
    }
    player.setHP(player.getHP() - actualDamage);
    std::cout << "\033[31m\n"<< name << " usou " << specialName << " e causou " << actualDamage << " de dano!\n"<<"\033[0m";
    preparingSpecial = false;
}

std::string Enemy::attackEnemy(Character &target) {
    int actualDamage = damage;
    target.setHP(target.getHP() - actualDamage);
    return name + " sofreu " + std::to_string(actualDamage) + " de dano!";
}
