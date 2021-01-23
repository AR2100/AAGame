#include <unistd.h>
#include <limits.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

std::string getWorkingDirectory() {
    char buffer[PATH_MAX];
    getcwd(buffer, sizeof(buffer));
    std::string temp = buffer;
    return temp.substr(0, temp.length() - 6);
}

int main()
{
    // get the file location of the image
    std::string dir = getWorkingDirectory();

    std::string tilePNG = dir + "/images/GameTile.png";
    std::string bunnyPNG = dir + "/images/PurpleBunny.png";

    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "SFML Demo!");

    //clock starts counting as soon as it's created
    sf::Clock clock;

    sf::Event event;

    sf::Texture bunnyTexture;
    sf::Sprite bunny;

    bunnyTexture.loadFromFile(bunnyPNG.c_str());
    bunny = sf::Sprite(bunnyTexture);
    bunny.setPosition(200.0, 200.0);

    int tileVert = 10;
    int tileHori = 8;

    sf::Texture textureTileArr[tileHori][tileVert];
    sf::Sprite spriteTileArr[tileHori][tileVert];

    float xVal = 0.0f;
    float yVal = 0.0f;

    for (int i = 0; i < tileHori; i++) {
        for (int j = 0; j < tileVert; j++) {
            textureTileArr[i][j].loadFromFile(tilePNG.c_str());
            spriteTileArr[i][j] = sf::Sprite(textureTileArr[i][j]);
            spriteTileArr[i][j].setPosition(xVal, yVal);

            xVal += 64;
        }
        xVal = 0.0f;
        yVal += 64;
    }

    /*
    sf::Texture texture;
    texture.loadFromFile(dir.c_str());
    sf::Sprite mySprite(texture);
    mySprite.setPosition(200.0f, 200.0f);

    sf::CircleShape circleShape(50);
    circleShape.setFillColor(sf::Color::Blue);
    circleShape.setOrigin(circleShape.getRadius(), circleShape.getRadius());

    circleShape.setPosition(100.0f, 100.0f);
    */

    while (renderWindow.isOpen()) {
        //check for all events that happened since last frame
        while (renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed) {
                renderWindow.close();
            }
        }
        /*
        std::cout << "Time since prev frame (microseconds): " <<
            clock.getElapsedTime().asMicroseconds() << std::endl;
        */

        //restarts the clock
        clock.restart();

        renderWindow.clear();
        //renderWindow.draw(circleShape);
        //renderWindow.draw(mySprite);

        for (int i = 0; i < tileHori; i++) {
            for (int j = 0; j < tileVert; j++) {
                renderWindow.draw(spriteTileArr[i][j]);
            }
        }

        renderWindow.draw(bunny);

        renderWindow.display();
    }

}
