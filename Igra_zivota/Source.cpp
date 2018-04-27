#include "igra.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

using namespace std;



int main() {

	int dalje = 1;
	igra igra;
	
	igra.inicijalizacija();
	
	
		sf::RenderWindow window(sf::VideoMode(1340, 940), "Conway's game of life - abstract");

		sf::Music pjesma;
		pjesma.openFromFile("GoL.ogg");
		pjesma.setVolume(25);
		pjesma.play();
		pjesma.setLoop(true);
		
		sf::Font font;
		font.loadFromFile("transformers.ttf");
		
		
		sf::Text text_generacija;
		sf::Text text_restart;
		sf::Text organizam_dead;
		sf::Text organizam_alive;
		
		text_generacija.setFont(font);
		text_generacija.setPosition(10, 0);
		text_generacija.setString("Generacija: ");
		
		organizam_dead.setFont(font);
		organizam_dead.setPosition(900, 10);
		organizam_dead.setCharacterSize(15);
		organizam_dead.setString("Mrtav->Ziv: \tMrtav: ");
		organizam_alive.setFont(font);
		organizam_alive.setCharacterSize(15);
		organizam_alive.setPosition(1130, 10);
		organizam_alive.setString("Ziv->Mrtav: \tZiv: ");
		text_restart.setFont(font);
		text_restart.setPosition(450, 0);
		text_restart.setString("Press SPACE to restart! ");

		sf::Texture organizam_tekstura_ziv;
		sf::Texture organizam_tekstura_mrtav;
		sf::Texture organizam_tekstura_ziv_mrtav;
		sf::Texture organizam_tekstura_mrtav_ziv;

		organizam_tekstura_ziv.loadFromFile("zeleni.png");
		organizam_tekstura_mrtav.loadFromFile("ljubicasti.png");
		organizam_tekstura_ziv_mrtav.loadFromFile("crveni.png");
		organizam_tekstura_mrtav_ziv.loadFromFile("zuti.png");

		sf::RectangleShape organizam_ziv(sf::Vector2f(10, 10));
		sf::RectangleShape organizam_ziv_mrtav(sf::Vector2f(10, 10));
		sf::RectangleShape organizam_mrtav_ziv(sf::Vector2f(10, 10));
		sf::RectangleShape organizam_mrtav(sf::Vector2f(10, 10));

		organizam_ziv.setTexture(&organizam_tekstura_ziv);
		organizam_ziv.setPosition(1295, 15);
		organizam_ziv_mrtav.setTexture(&organizam_tekstura_ziv_mrtav);
		organizam_ziv_mrtav.setPosition(1227, 15);
		organizam_mrtav_ziv.setTexture(&organizam_tekstura_mrtav_ziv);
		organizam_mrtav_ziv.setPosition(995, 15);
		organizam_mrtav.setTexture(&organizam_tekstura_mrtav);
		organizam_mrtav.setPosition(1087, 15);
		
		window.setFramerateLimit(60);


		float vremenski_razmak = 0;
		sf::Clock clock;

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type) {
				case sf::Event::Closed: {
					window.close();
					break;
				}
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Space) {
						igra.inicijalizacija();
					}
					if (event.key.code == sf::Keyboard::Escape) {
						window.close();
					}
				}
			}
			vremenski_razmak = clock.restart().asSeconds();
			window.setFramerateLimit(10);
			igra.provjera_evolucije();
		
			window.clear(sf::Color(41,7,51));
			window.draw(text_generacija);
			window.draw(text_restart);
			window.draw(organizam_alive);
			window.draw(organizam_dead);
			window.draw(organizam_mrtav);
			window.draw(organizam_mrtav_ziv);
			window.draw(organizam_ziv);
			window.draw(organizam_ziv_mrtav);
			igra.postavljanje_animiranog_polja(vremenski_razmak, &window);
			window.display();
		}




	return 0;
}