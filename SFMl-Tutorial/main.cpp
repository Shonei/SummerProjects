#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "iostream"

using namespace sf;
using namespace std;

int main()
{
    Game game;
    while(game.gameOn())
    {
        game.somethingHappened();
        game.render();
    }

    return 0;
}