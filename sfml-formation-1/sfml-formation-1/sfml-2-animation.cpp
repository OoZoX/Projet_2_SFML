#include <SFML/Graphics.hpp>
using namespace sf;
/*
Dans cet example, vous allez devoir animer un personnage lors de son déplacement.
Toujours en utilisant Sprite::setTextureRect(), vous devrez alterner entre plusieurs sous régions de la texture fournie, à une fréquence adaptée.

Vous pouvez soit utiliser un sf::Timer avec Timer::getElapsedTime(), soit utiliser un accumulateur en float, sachant que SFML
peut verrouiller la fréquence d'affichage à 60.

Il faudra également choisir la texture appropriée en fonction de la direction de mouvement du personnage.
Il faudra penser à remettre la texture du héros dans son état de repos lorsque le personnage s'arrête.

En exercice supplémentaire, vous pouvez faire tourner une épée en demi cercle autour du personnage.

// https://imgur.com/a/vVmZnXt

*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    // limite les FPS à 60
    window.setFramerateLimit(60);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}