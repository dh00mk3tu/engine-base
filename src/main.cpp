#include <iostream>
// #include <unistd.h>
// #include <dirent.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;


// Util Functions

// #elif defined RUNNING_LINUX 

class Game {
    public: 
        // sf::RenderWindow window(VideoMode(600,400), "Test");
        
        // sf::CircleShape player(150);
        // player.setFillColor(sf::Color::Blue);
        // player.setPosition(10,20);

        // Game(const Game&) = delete;
        // Game& operator = (const Game&) = delete;
        Game() : window(sf::VideoMode(800, 600),"Test"), player(150) {
            player.setFillColor(sf::Color::Blue);
            player.setPosition(10, 20);
        }

        void run() {
            while(window.isOpen()){
                processEvents();
                // update();
                render();
            }
        }
    private: 
        void processEvents() {
            sf::Event event;
            while(window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
                    window.close();
                else 
                    render();
            }

        }
        // void update();
        void render() {
            window.clear();
            window.draw(player);
            window.display();
        }

    sf::RenderWindow window;
    sf::CircleShape player;

};


int main() {
    Game game;
    game.run();


    return 0;
}