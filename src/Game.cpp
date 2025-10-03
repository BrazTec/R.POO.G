#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <ctime>

// --- Artes ASCII ---

std::string playerArt = R"(
   __O__
  / | | \
    | |
    / \
)";

std::string goblinArt = R"(
  (o_o)
 /(   )\
  || ||
)";

std::string orcArt = R"(
   .----.
  ( o  o )
  (  --  )
  /| || |\
   | || |
   |_||_|
)";

std::string trollArt = R"(
   .-"""-.
  /       \
 |  (o o)  |
 |   ___   |
  \ (___) /
   |  |  |
   |  |  |
   |__|__|
)";

std::string skeletonArt = R"(
  .-"``"-.
  ( 0  0  )
   \_==_/
    /  \
)";

std::string bossArt = R"(
   .-"``"-.
  /  .--.  \
 |  (o  o)  |
 |   .--.   |
  \  '--'  /
   / |  | \
  /  |  |  \
 '--'    '--'
)";

// --- Cutscenes ---
std::string forestArt = R"(
       /\        /\        /\        /\
      /  \      /  \      /  \      /  \
     / /\ \    / /\ \    / /\ \    / /\ \
    /_/  \_\  /_/  \_\  /_/  \_\  /_/  \_\
      ||||      ||||      ||||      ||||
      ||||      ||||      ||||      ||||
)";

std::string fieldArt = R"(
   /\    /\   /\    /\   /\    /\   /\    /\
  /  \  /  \ /  \  /  \ /  \  /  \ /  \  /  \
 ||||  |||| ||||  |||| ||||  |||| ||||  ||||
 ||||  |||| ||||  |||| ||||  |||| ||||  ||||
)";

std::string caveArt = R"(
     ____    ____
    /    \__/    \
   /              \
  /  /\        /\  \
 /__/  \______/  \__\
)";

std::string ruinsArt = R"(
   ___      ___      ___      ___      ___
  |   |    |   |    |   |    |   |    |   |
  | x |    |   |    | x |    |   |    | x |
  |___|    |___|    |___|    |___|    |___|
   ||       ||       ||       ||       ||
   ||       ||       ||       ||       ||
  /||\     /||\     /||\     /||\     /||\
 /_||_\   /_||_\   /_||_\   /_||_\   /_||_\
   /\        /\        /\        /\       /\
  /  \      /  \      /  \      /  \     /  \
  (~~)      (~~)      (~~)      (~~)     (~~)
)";

std::string castleArt = R"(
     /\      /\      /\
    /  \____/  \____/  \
   /                    \
  /      /\      /\      \
 /______/  \____/  \______\
)";

// ----------------- Métodos Game -----------------
void Game::clearScreen() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

void Game::showScene(const std::string &sceneArt, const std::string &text) {
    clearScreen();
    std::cout << sceneArt << "\n\n";
    std::cout << text << "\n";
    std::cout << "\nPressione Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// ----------------- Reset e fim de jogo -----------------
void Game::resetGame() {
    player.setHP(100);
    playerPotions = 3;

    enemies.clear();
    enemies.push_back(Enemy("Goblin", 30, 8, "Golpe Furtivo"));
    enemies.push_back(Enemy("Orc", 40, 10, "Machadada Brutal"));
    enemies.push_back(Enemy("Troll", 50, 12, "Pisada Tremor"));
    enemies.push_back(Enemy("Skeleton", 30, 10, "Lâmina Fantasma"));

    boss.setHP(80);
    boss.setPreparingSpecial(false);
}

void Game::showEndScreen(bool victory) {
    clearScreen();
    if(victory) {
        std::cout << R"(==============================
       VOCÊ VENCEU O JOGO!
       Parabéns, Herói!
==============================)";
    } else {
        std::cout << R"(==============================
       FIM DE JOGO
   Você foi derrotado pelo Necromante
==============================)";
    }

    int choice;
    std::cout << "\n\n1. Voltar ao menu principal\n2. Sair\nEscolha: ";
    std::cin >> choice;
    if(choice == 1) { resetGame(); mainMenu(); }
    else std::cout << "Saindo do jogo...\n";
}

// ----------------- Construtor -----------------
Game::Game() : player("Herói"), boss("Necromante", 80, 15, "Rajada Mortal") {
    srand(time(0));
    resetGame();
}

// ----------------- Menu principal -----------------
void Game::mainMenu() {
    clearScreen();
    std::cout << "\n\n\n\033[34m"<< R"(
                ,-.----.       ,----..       ,----..
,-.----.        \    /  \     /   /   \     /   /   \     ,----..
\    /  \       |   :    \   /   .     :   /   .     :   /   /   \
;   :    \      |   |  .\ : .   /   ;.  \ .   /   ;.  \ |   :     :
|   | .\ :      .   :  |: |.   ;   /  ` ;.   ;   /  ` ; .   |  ;. /
.   : |: |      |   |   \ :;   |  ; \ ; |;   |  ; \ ; | .   ; /--`
|   |  \ :      |   : .   /|   :  | ; | '|   :  | ; | ' ;   | ;  __
|   : .  /      ;   | |`-' .   |  ' ' ' :.   |  ' ' ' : |   : |.' .'
;   | |  \      |   | ;    '   ;  \; /  |'   ;  \; /  | .   | '_.' :
|   | ;\  \     :   ' |     \   \  ',  /  \   \  ',  /  '   ; : \  |
:   ' | \.'___  :   : :      ;   :    /    ;   :    /___'   | '/  .
:   : :-' /  .\ |   | :       \   \ .'      \   \ .'/  .\   :    /
|   |.'   \  ; |`---'.|        `---`         `---`  \  ; \   \ .'
`---'      `--"   `---`                              `--" `---`
)";
    std::cout <<"\033[0m\n" << "\n1. Jogar\n2. Sair\n3. Créditos\nEscolha: ";
    int choice; std::cin >> choice;

    if(choice == 1) {
        showScene(R"(
O mundo está em perigo! O herói deve enfrentar criaturas sombrias
e derrotar o Necromante para restaurar a paz!
)", "A aventura começa...\n\n\n");
        startGame();
    } else if(choice == 3) {
        clearScreen();  // limpa a tela antes de mostrar os créditos
        std::cout << "\n\n           Obrigado por jogar!\n\n\n";
        std::cout << "Eduardo Braz de Oliveira\nGihad Mohamad Mourad\nJonatas Lopes de Sousa";
        std::cout << "\n\n\nPressione Enter para voltar ao menu...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpa buffer
        std::cin.get(); // espera o Enter
        mainMenu(); // volta ao menu principal
    } else {
        std::cout << "Saindo do jogo...\n";
    }
}

// ----------------- StartGame -----------------
void Game::startGame() {
    battle(enemies[0], forestArt, "Você entra na floresta sombria. Um Goblin surge!");
    if(player.getHP() <= 0) { showEndScreen(false); return; }

    battle(enemies[1], fieldArt, "Você atravessa um campo rochoso. Um Orc aparece!");
    if(player.getHP() <= 0) { showEndScreen(false); return; }

    battle(enemies[2], caveArt, "Você adentra a caverna escura. Um Troll o aguarda!");
    if(player.getHP() <= 0) { showEndScreen(false); return; }

    battle(enemies[3], ruinsArt, "Você chega ao cemitério antigo. Um Esqueleto aparece!");
    if(player.getHP() <= 0) { showEndScreen(false); return; }

    battle(boss, castleArt, "Finalmente, você chega ao castelo do Necromante!");
    if(player.getHP() > 0) showEndScreen(true);
    else showEndScreen(false);
}

void Game::battle(Enemy &enemy, const std::string &sceneArt, const std::string &sceneText) {
    showScene(sceneArt, sceneText);

    std::string enemyArt;
    if(enemy.getName() == "Goblin") enemyArt = goblinArt;
    else if(enemy.getName() == "Orc") enemyArt = orcArt;
    else if(enemy.getName() == "Troll") enemyArt = trollArt;
    else if(enemy.getName() == "Skeleton") enemyArt = skeletonArt;
    else enemyArt = bossArt;

    bool playerDefending = false;
    std::string lastAction = "";

    while(enemy.getHP() > 0 && player.getHP() > 0) {
        clearScreen();
        std::cout << "\033[32m"<< "====================================\n"<<"\033[0m\n";
        std::cout << "Você: " << player.getName() << "   HP: " << player.getHP() << "   Poções: " << playerPotions << "\n";
        std::cout << playerArt << "\n\n";
        std::cout << enemy.getName() << "   HP: " << enemy.getHP() << "\n";
        std::cout << enemyArt << "\n";
        std::cout << "\033[32m"<< "====================================\n"<<"\033[0m";

        if(!lastAction.empty()) {
            std::cout << "\033[34m"<< lastAction << "\n"<<"\033[0m\n";
            lastAction = "";
        }

        std::cout << "Escolha sua ação:\n1. Atacar\n2. Defender\n3. Usar poção de cura (+25 HP)\nEscolha: ";
        int choice; std::cin >> choice;

        if(choice == 1) lastAction = player.attackEnemy(enemy);
        else if(choice == 2) {
            lastAction = "Você se prepara para se defender!";
            playerDefending = true;
        } else if(choice == 3) {
            if(playerPotions > 0) {
                player.heal(25); // poção agora cura 25 HP
                playerPotions--;
                lastAction = "Você usou uma poção e recuperou 25 de HP!";
            } else lastAction = "Você não tem poções!";
        }

        // Turno do inimigo
        if(enemy.isPreparingSpecial()) {
            enemy.specialAttack(player, playerDefending);
        } else {
            if(rand() % 4 == 0) {
                enemy.setPreparingSpecial(true);
                lastAction += "\033[31m\n" + enemy.getName() + " está se preparando para usar " + enemy.getSpecialName() + "!\033[0m";
            } else {
                enemy.attackPlayer(player, playerDefending);
            }
        }

        playerDefending = false;
        std::cout << "\n\n\nPressione Enter para continuar...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }


    if(player.getHP() > 0) {
        player.heal(20);
        std::cout << "Você recuperou 20 de HP após a batalha!\n";
    }

    clearScreen();
    if(player.getHP() > 0) {
        std::cout << "Você derrotou " << enemy.getName() << "!\n";
    } else {
        std::cout << "Você foi derrotado por " << enemy.getName() << "!\n";
    }
}





















































