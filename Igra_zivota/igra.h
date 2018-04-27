#pragma once
#include<string.h>
#include<SFML\Graphics.hpp>

class igra
{

private:
	static const int redci=90;
	static const int stupci=134;

	char ploca [redci][stupci];
	char privremena_ploca[redci][stupci];
	sf::RectangleShape  animirana_ploca[redci][stupci];
	sf::Text brojGen;
	sf::Font font;
	char ziv = 'x';
	char mrtav = '.';
	int max = 4;
	int min = 1;
	int brojac = 0;
	int generacija = 0;
	int broj;
	std::string to_string(int broj);
	void kopiranje_polja(char(&polje_za_kopiranje)[redci][stupci], char(&kopija_polja)[redci][stupci]);

	

	

public:
	igra();
	~igra();
	void inicijalizacija();
	void provjera_evolucije();
	void postavljanje_animiranog_polja(float vremenski_razmak , sf::RenderWindow *window);


	
	
};

