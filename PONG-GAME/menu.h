#pragma once
#include "gra.h"

class menu
{
public:
	menu();
	void uruchomienie_menu();
	void obsluga_zdarzen_menu();
	void rysowanie_opcji();
	void parametry_opcji();
	void pisanie_opcji_parametry();


private:

	sf::RenderWindow okno_menu;
	sf::RectangleShape plvspl;
	sf::RectangleShape plvsai;
	sf::RectangleShape wyjscie;
	sf::Font fontMenu;
};

