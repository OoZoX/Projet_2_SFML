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

        window.clear();
        //window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}