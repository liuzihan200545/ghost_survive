#include "core/game.h"

int main(int, char**) {

    auto& game = Game::get_instance();
    game.init("Ghost Escape",1280,720);
    game.run();

    return 0;
}