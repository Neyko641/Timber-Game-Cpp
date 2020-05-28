
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    //create screen object
    sf::VideoMode vm(1920, 1080);
    //create & open the video window for the game.
    sf::RenderWindow window(vm, "Timber!!!", sf::Style::Fullscreen);
    sf::Texture textureBackground; //Create a texture to hold the the BG image
    textureBackground.loadFromFile("graphics/background.png"); // load from disk
    sf::Sprite spriteBackground; // create a sprite
    spriteBackground.setTexture(textureBackground); //Attach a texture to the sprite
    spriteBackground.setPosition(0, 0); // set the position of the background.
    //game loop
    while (window.isOpen())
    {
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();  //exit game.
        }
        //clear screen from last frame.
        window.clear();
        //Draw new scene next frame.
        window.draw(spriteBackground);
        //display drawn scene.
        window.display();
            
    }
    return 0;
}
