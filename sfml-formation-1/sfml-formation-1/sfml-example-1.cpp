/*

#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    Texture texture;
    //texture.loadFromFile("ghost.png");
    texture.loadFromFile("foresttiles2-t.png");
    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(4, 4);
    sprite.setTextureRect(IntRect(Vector2i(20,24),Vector2i(30,33)));
    // https://imgur.com/a/vVmZnXt

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        for ()

        window.clear();
        //window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
*/
#include <SFML/Graphics.hpp>

using namespace sf;

enum Keys { UP, DOWN, LEFT, RIGHT, SPACE, KEY_MAX };
bool activeKeys[KEY_MAX] = { false };



int main()
{
    float vit = 0.1f;

    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    sf::RectangleShape rectangle(sf::Vector2f(50, 20));
    rectangle.setFillColor(sf::Color::Red);
    shape.setFillColor(sf::Color::Green);

    rectangle.setPosition(0, 0);

    Texture texture;
    texture.loadFromFile("ghost.png");


    Sprite sprite;
    sprite.setTexture(texture);

    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }


            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Q)
                {
                    activeKeys[LEFT] = true;
                }


                if (event.key.code == sf::Keyboard::Z)
                {
                    activeKeys[UP] = true;
                }



                if (event.key.code == sf::Keyboard::S)
                {
                    activeKeys[DOWN] = true;
                }


                if (event.key.code == sf::Keyboard::D)
                {
                    activeKeys[RIGHT] = true;
                }

            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Q) { activeKeys[LEFT] = false; }
                if (event.key.code == sf::Keyboard::Z) { activeKeys[UP] = false; }
                if (event.key.code == sf::Keyboard::S) { activeKeys[DOWN] = false; }
                if (event.key.code == sf::Keyboard::D) { activeKeys[RIGHT] = false; }
            }
        }

        if (activeKeys[UP]) { sprite.move(0, -vit); }
        if (activeKeys[UP] == false) { sprite.move(0, 0); }

        if (activeKeys[LEFT]) { sprite.move(-vit, 0); }
        if (activeKeys[LEFT] == false) { sprite.move(0, 0); }

        if (activeKeys[RIGHT]) { sprite.move(vit, 0); }
        if (activeKeys[RIGHT] == false) { sprite.move(0, 0); }

        if (activeKeys[DOWN]) { sprite.move(0, vit); }
        if (activeKeys[DOWN] == false) { sprite.move(0, 0); }

        if (activeKeys[UP] && activeKeys[LEFT])
        {
            sprite.move(vit * 0.29, vit * 0.29);
        }
        if (activeKeys[UP] && activeKeys[RIGHT])// 848.53
        {
            sprite.move(-vit * 0.29, vit * 0.29); //0.71
        }
        if (activeKeys[DOWN] && activeKeys[LEFT])
        {
            sprite.move(vit * 0.29, -vit * 0.29);
        }
        if (activeKeys[DOWN] && activeKeys[RIGHT])
        {
            sprite.move(-vit * 0.29, -vit * 0.29);
        }

        if (sprite.getPosition().x <= 0)
        {
            sprite.setPosition(0, sprite.getPosition().y);
        }
        if (sprite.getPosition().x >= 590)
        {
            sprite.setPosition(590, sprite.getPosition().y);
        }

        if (sprite.getPosition().y <= 0) {
            sprite.setPosition(sprite.getPosition().x, 0);

        }
        if (sprite.getPosition().y >= 580) {
            sprite.setPosition(sprite.getPosition().x, 580);
        }


        window.clear();

        window.draw(sprite);
        window.display();






    }





    return 0;
}
