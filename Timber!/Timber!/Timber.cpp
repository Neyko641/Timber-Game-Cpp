
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    //create screen object
    sf::VideoMode vm(1920, 1080);
    //create & open the video window for the game.
    sf::RenderWindow window(vm, "Timber!!!",sf::Style::Fullscreen);
    sf::Texture textureBackground; //Create a texture to hold the the BG image
    textureBackground.loadFromFile("graphics/background.png"); // load from disk
    sf::Sprite spriteBackground; // create a sprite
    spriteBackground.setTexture(textureBackground); //Attach a texture to the sprite
    spriteBackground.setPosition(0, 0); // set the position of the background.

    // Make a tree sprite
    sf::Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    sf::Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);
    
    //Bee object
    sf::Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");
    sf::Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 600);
    //Is it actively moving?
    bool beeActive = false;
    float beeSpeed = 0.0f;

    //Make 3 clouds;
    sf::Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");
    sf::Sprite Cloud1;
    sf::Sprite Cloud2;
    sf::Sprite Cloud3;
    Cloud1.setTexture(textureCloud);
    Cloud2.setTexture(textureCloud);
    Cloud3.setTexture(textureCloud);
    Cloud1.setPosition(250, 0);
    Cloud2.setPosition(500, 300);
    Cloud3.setPosition(1200, 150);
    //Are they on screen?
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    //Their speed.
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;
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
        window.draw(Cloud1);
        window.draw(Cloud2);
        window.draw(Cloud3);
        window.draw(spriteTree);
        window.draw(spriteBee);
        //display drawn scene.
        window.display();
            
    }
    return 0;
}
