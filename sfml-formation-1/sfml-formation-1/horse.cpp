#include "horse.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"

using namespace sf;
using namespace std;

Horse::Horse() {}

Sprite Horse::getHorse()
{
    return horse;
}


void Horse::updateHorsePosition(int x, int y)
{
    horse.setPosition(x, y);
}

void Horse::updateHorseTexture(Texture& texture)
{
    horse.setTexture(texture);

}

void Horse::updateHorseTextureRect(IntRect tile_hero)
{
    horse.setTextureRect(tile_hero);

}

void Horse::updateHorseScale(int scale_x, int scale_y)
{
    horse.setScale(scale_x, scale_y);
}

void Horse::addHeroSprite()
{
    for (auto& tile : horseTiles)
    {
        IntRectHero[tile.first] = IntRect(tile.second.x * 16, tile.second.y * 16, 16, 16);

    }
}

void Horse::dep_player_horse(Player& player)
{
    if (player_horse == true)
    {
        player.update_player_position(horse.getPosition().x, horse.getPosition().y);
    }
}

void Horse::mont_horse(Player& player, Event& event)
{
    Vector2f pos_player;
    pos_player.x = player.recup_position().x;
    pos_player.y = player.recup_position().y;

    if (((pos_player.x - horse.getPosition().x) <= 50.0f && (pos_player.y - horse.getPosition().y) <= 50.0f) && ((pos_player.x - horse.getPosition().x) >= -50.0f && (pos_player.y - horse.getPosition().y) >= -50.0f))
    {
        if (event.type == Event::KeyPressed)
        {
            if (player_horse == true && event.key.code == Keyboard::E)
            {
                player.update_player_position(player.recup_position().x + 10.0f, player.recup_position().y + 10.0f);
            }

            cout << "keyporess" << endl;
            if (event.key.code == Keyboard::E && player_horse == false && key_release_e == false)
            {
                cout << "ok true !!" << endl;
                player_horse = true;
                key_release_e = true;
            }


            
        }
        if (event.type == Event::KeyReleased)
        {
            if (event.key.code == Keyboard::E)
            {
                cout << "marche stp" << endl;
                key_release_e = false;
            }
        }
    }


}