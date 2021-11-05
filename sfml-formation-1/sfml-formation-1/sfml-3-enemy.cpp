/*
Dans cet example, il faudra faire déplacer un ennemi le long d'une série de points configurables.
L'ennemi devra faire une pause d'une durée configurable à chaque arrêt, et faire demi tour selon le même tracé.

La vitesse du monstre doit être configurable.

Vous n'êtes pas obligé d'animer le sprite, mais cela sera un bon bonus.

Afin de bien débugguer, il faudra afficher des petits points représentants l'itinéraire du monstre, avec aussi un tracé.
Il faudra donc utiliser sf::RectangleShape et sf::VertexArray, ainsi que sf::Timer.

Vous devrez donc créer un class enemy{} ou struct enemy{}, avec un constructeur, 
et les méthodes membres update(float delta) et draw(sf::RenderWindow & window).

Lorsque le personnage touche un monstre, la partie se finit avec un message game over en Texte via sf::Text, et le jeu recommence de zéro.
Il faudra vous aider de la fonction Sprite::getGlobalBounds() et FloatRect::intersects()

Vous devrez réutiliser, de préférence, le code de chargement de texte que vous avez écrit dans vos précédents projets.
*/

/*
Annexe: en préparation du projet de physique, vous pouvez commencer a créer une classe vehicle, que le personnage peut rentrer et sortir grace
à la touche entrée.

*/