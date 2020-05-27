
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    //create screen object
    sf::VideoMode vm(1920, 1080);
    //create & open the video window for the game.
    sf::RenderWindow window(vm, "Timber!!!", sf::Style::Fullscreen);
    //game loop
    while (window.isOpen())
    {
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();  //exit game.
        }
        //delete game objects.
        window.clear();
        //Draw game objects.
        window.display();
            
    }
    return 0;
}
