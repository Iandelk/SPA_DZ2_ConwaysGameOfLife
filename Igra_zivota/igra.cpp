#include "igra.h"
#include <iostream>
#include <ctime>
#include<sstream>



igra::igra()
{
}


igra::~igra()
{
}

void igra::inicijalizacija() {

	font.loadFromFile("transformers.ttf");
	
	generacija = 0;

	srand(time(nullptr));
	for (int i = 0; i < redci; i++)
	{
		for (int j = 0; j < stupci; j++)
		{
			int slucajni_broj = rand() % (max - min + 1) + 1;

		if (slucajni_broj == 4) {
			ploca[i][j] = ziv;
	}
	else {
		ploca[i][j] = mrtav;

			}
		}

	}



}
void igra::provjera_evolucije() {
	kopiranje_polja(ploca, privremena_ploca);
	
	

	for (int i = 0; i < redci; i++)
	{
		for (int j = 0; j < stupci; j++)
		{			
			brojac = 0;
			
			if ((i - 1) >= 0) {
				if (privremena_ploca[i - 1][j] == ziv) {				
				
					brojac++;	
				}
			}
			if ((i + 1) <= redci-1) {
				if (privremena_ploca[i + 1][j] == ziv) {

					brojac++;
				}
			}
			if ((j - 1) >= 0) {
				if (privremena_ploca[i][j - 1] == ziv) {

					brojac++;

				}
			}
			if ((j + 1) <= stupci-1) {
				if (privremena_ploca[i][j + 1] == ziv) {

					brojac++;
			
				}
			}
			if (((i - 1) >= 0) && ((j - 1) >= 0)) {
				if (privremena_ploca[i - 1][j - 1] == ziv) {
			
					brojac++;

				}
			}
			if (((i + 1) <= redci-1) && ((j + 1) <= stupci-1)) {
				if (privremena_ploca[i + 1][j + 1] == ziv) {
		
					brojac++;
		
				}
			}
			if (((i + 1) <= redci-1) && ((j - 1) >= 0)) {
				if (privremena_ploca[i + 1][j - 1] == ziv) {

					brojac++;
			
				}
			}
			if (((i - 1) >= 0) && ((j + 1) <= stupci-1)) {
				if (privremena_ploca[i - 1 ][j + 1] == ziv) {
				
					brojac++;

				}
			
			}
			
			if (privremena_ploca[i][j] == ziv && (brojac == 2 || brojac == 3)) {
				
			}
			else if (privremena_ploca[i][j] == ziv && (brojac < 2 || brojac > 3))
			{
				ploca[i][j] = mrtav;
			}
			else if (privremena_ploca[i][j] == mrtav && brojac == 3)
			{
				ploca[i][j] = ziv;
			}

			

		}
	
		
	}

	
}



void igra::postavljanje_animiranog_polja(float vremenski_razmak, sf::RenderWindow *window) {
	generacija++;
	
	brojGen.setFont(font);
	brojGen.setPosition(190, 0);
	brojGen.setString(to_string(generacija));
	window->draw(brojGen);
	
	sf::RectangleShape organizam(sf::Vector2f(10,10));
	
	sf::Texture organizam_tekstura_ziv;
	sf::Texture organizam_tekstura_mrtav;
	sf::Texture organizam_tekstura_ziv_mrtav;
	sf::Texture organizam_tekstura_mrtav_ziv;
	
	organizam_tekstura_ziv.loadFromFile("zeleni.png");
	organizam_tekstura_mrtav.loadFromFile("ljubicasti.png");
	organizam_tekstura_ziv_mrtav.loadFromFile("crveni.png");
	organizam_tekstura_mrtav_ziv.loadFromFile("zuti.png");
	
	float x = 0;
	float y = 40;

	for (int i = 0; i < redci; i++)
	{
		x = 0;

		for (int j = 0; j < stupci; j++)
		{




			if (ploca[i][j] == ziv && privremena_ploca[i][j] == ziv) {

			animirana_ploca[i][j] = organizam;
			animirana_ploca[i][j].setTexture(&organizam_tekstura_ziv);
			animirana_ploca[i][j].setPosition(x, y);
			window->draw(animirana_ploca[i][j]);
		}

			else if (ploca[i][j] == mrtav && privremena_ploca[i][j] == mrtav) {

			animirana_ploca[i][j] = organizam;
			animirana_ploca[i][j].setTexture(&organizam_tekstura_mrtav);
			animirana_ploca[i][j].setPosition(x, y);

			window->draw(animirana_ploca[i][j]);
		}

			else if (ploca[i][j] == ziv && privremena_ploca[i][j] == mrtav) {

			animirana_ploca[i][j] = organizam;
			animirana_ploca[i][j].setTexture(&organizam_tekstura_ziv_mrtav);
			animirana_ploca[i][j].setPosition(x, y);

			window->draw(animirana_ploca[i][j]);
		}

		

			else if (ploca[i][j] == mrtav && privremena_ploca[i][j] == ziv) {

			animirana_ploca[i][j] = organizam;
			animirana_ploca[i][j].setTexture(&organizam_tekstura_mrtav_ziv);
			animirana_ploca[i][j].setPosition(x, y);

			window->draw(animirana_ploca[i][j]);
		}


		
			x = x + 10.0f;
			

		}
		y = y + 10.0f;
	}

}


void igra::kopiranje_polja(char(&polje_za_kopiranje)[redci][stupci], char(&kopija_polja)[redci][stupci])
{
	for (int i = 0; i < redci; i++)
	{
		for (int j = 0; j < stupci; j++)
		{

			kopija_polja[i][j] = polje_za_kopiranje[i][j];

		}

	}


}

std::string igra::to_string(int broj)
{
	std::stringstream ss;
	ss << broj;
	return ss.str();
}