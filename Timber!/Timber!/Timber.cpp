
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
    Cloud1.setPosition(0, 0);
    Cloud2.setPosition(0, 150);
    Cloud3.setPosition(0, 300);
    //Are they on screen?
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    //Their speed.
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;
    bool gamePaused = true;

    //Variable to control time
    sf::Clock clock;
    //game loop
    while (window.isOpen())
    {
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();  //exit game.
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            gamePaused = false;
        }
        /*
        ********************************
            Update the scene
        ********************************/
        if (!gamePaused)
        {
            //Measure time
            sf::Time dt = clock.restart();

            //Speed of the bee.
            if (!beeActive)
            {
                srand((int)time(0) * 10);
                beeSpeed = (rand() % 200) + 200;
                //Bee height;
                float height = (rand() % 500) + 500;
                spriteBee.setPosition(2000, height);
                beeActive = true;
            }
            else {
                //Move the bee;
                spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
                    spriteBee.getPosition().y);
                if (spriteBee.getPosition().x < -100)
                {
                    beeActive = false;
                }
            }

            if (!cloud1Active)
            {
                //Cloud speed
                srand((int)time(0) * 10);
                cloud1Speed = (rand() % 200);

                //Cloud height
                srand((int)time(0) * 10);
                float height = (rand() % 150);
                Cloud1.setPosition(-200, height);
                cloud1Active = true;
            }
            else
            {
                Cloud1.setPosition(Cloud1.getPosition().x
                    + (cloud1Speed * dt.asSeconds()),
                    Cloud1.getPosition().y);
                if (Cloud1.getPosition().x > 1920)
                {
                    cloud1Active = false;
                }

            }
            if (!cloud2Active)
            {
                //Cloud speed
                srand((int)time(0) * 20);
                cloud2Speed = (rand() % 200);

                //Cloud height
                srand((int)time(0) * 20);
                float height = (rand() % 300) - 150;
                Cloud2.setPosition(-200, height);
                cloud2Active = true;
            }
            else
            {
                Cloud2.setPosition(Cloud2.getPosition().x
                    + (cloud2Speed * dt.asSeconds()),
                    Cloud2.getPosition().y);
                if (Cloud2.getPosition().x > 1920)
                {
                    cloud2Active = false;
                }

            }
            if (!cloud3Active)
            {
                //Cloud speed
                srand((int)time(0) * 30);
                cloud3Speed = (rand() % 200);

                //Cloud height
                srand((int)time(0) * 30);
                float height = (rand() % 450) - 150;
                Cloud3.setPosition(-200, height);
                cloud3Active = true;
            }
            else
            {
                Cloud3.setPosition(Cloud3.getPosition().x
                    + (cloud3Speed * dt.asSeconds()),
                    Cloud3.getPosition().y);
                if (Cloud3.getPosition().x > 1920)
                {
                    cloud3Active = false;
                }

            }
        } // end if  not paused
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
