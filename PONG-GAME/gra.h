#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>
class gra
{
public:
	gra();
	virtual ~gra() = default;
	void uruchomienie();
	void obsluga_zdarzen();
	void rysowanie_tla();
	void parametry_tla();
	void rysowanie_gracza1();
	void rysowanie_gracza2();
	void parametry_graczy();
	void parametry_bramek();
	void rysowanie_bramek();
	void ruch_gracz1(float delta);
	virtual void ruch_gracz2(float delta);
	void parametry_pilki();
	void ruch_pilki(float delta);
	void rysowanie_pilki();
	void wyswietlanie_wyniku(std::string tekst);
	void sprawdzanie_gola();
	sf::Font font;
	sf::RenderWindow window;
	sf::Clock czas_delta;
	sf::RectangleShape tlo;
	sf::RectangleShape gracz1;
	sf::RectangleShape gracz2;
	sf::RectangleShape bramka1;
	sf::RectangleShape bramka2;
	sf::CircleShape pilka;
	sf::Vector2f velocity_pilki;
	sf::Vector2f zmiana_pol;

	int punkty_gracz1 = 0;
	int punkty_gracz2 = 0;
};

