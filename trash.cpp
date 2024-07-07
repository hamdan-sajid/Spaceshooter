#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bullet Example");
    sf::RectangleShape bullet(sf::Vector2f(5, 20)); // Create a bullet rectangle shape
    bullet.setFillColor(sf::Color::White); // Set bullet color to white
    bullet.setPosition(window.getSize().x / 2, window.getSize().y); // Set bullet initial position to center bottom of window
    float bulletSpeed = 10.0f; // Set bullet speed
    bool bulletFired = false; // Set initial bullet fired status to false

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                bulletFired = true; // Set bullet fired status to true
            }
        }

        if (bulletFired)
        {
            bullet.move(0, -bulletSpeed); // Move bullet upwards
            if (bullet.getPosition().y < 0) // Check if bullet is out of bounds
            {
                bulletFired = false; // Set bullet fired status to false
                bullet.setPosition(window.getSize().x / 2, window.getSize().y); // Reset bullet position to center bottom of window
            }
        }

        window.clear();
        window.draw(bullet);
        window.display();
    }

    return 0;
}
