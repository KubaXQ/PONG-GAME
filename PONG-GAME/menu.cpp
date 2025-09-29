#include "menu.h"
#include "gra.h"
#include "graAI.h"
// konstruktor okna i jego opcje
menu::menu() :okno_menu(sf::VideoMode({ 800,800 }), "MENU", sf::Style::Close | sf::Style::Titlebar)
{
	parametry_opcji();
	fontMenu.openFromFile("Naraka.ttf");

}

//obs³uga okna
void menu::uruchomienie_menu()
{
	while (okno_menu.isOpen()) 
	{

		obsluga_zdarzen_menu();
		rysowanie_opcji();
		pisanie_opcji_parametry();
		okno_menu.display();


	}
}

//obs³uga klikania przycisków
void menu::obsluga_zdarzen_menu()
{
	while (auto ev = okno_menu.pollEvent()) 
	{
		if (ev->is<sf::Event::Closed>())
		{
			okno_menu.close();
		}
		else if (auto keypressed = ev->getIf<sf::Event::KeyPressed>()) 
		{
			if (keypressed->scancode == sf::Keyboard::Scancode::Escape) 
			{
				okno_menu.close();
			}
		}
		if (auto klikniecie = ev->getIf<sf::Event::MouseButtonPressed>()) 
		{
			float mx = sf::Mouse::getPosition(okno_menu).x;
			float my = sf::Mouse::getPosition(okno_menu).y;
			sf::Vector2f pos_myszy(mx, my);
			if (plvspl.getGlobalBounds().contains(pos_myszy)) 
			{
				okno_menu.close();
				gra gra;
				gra.uruchomienie();

			}
			else if (plvsai.getGlobalBounds().contains(pos_myszy)) 
			{
				okno_menu.close();
				graAI graAI;       // <-- typ musi byæ graAI
				graAI.uruchomienie();
			}
			else if (wyjscie.getGlobalBounds().contains(pos_myszy)) 
			{
				okno_menu.close();
			}

		}


	}

}

//rysowanie wyboru trybu
void menu::rysowanie_opcji()
{

	okno_menu.draw(plvspl);
	okno_menu.draw(plvsai);
	okno_menu.draw(wyjscie);
}


//parametry okienek trybu
void menu::parametry_opcji()
{
	plvspl.setSize(sf::Vector2f(600, 200));
	plvspl.setOutlineThickness(10);
	plvspl.setOutlineColor(sf::Color::White);
	plvspl.setPosition(sf::Vector2f(100, 50));
	plvspl.setFillColor(sf::Color::Black);

	plvsai.setSize(sf::Vector2f(600, 200));
	plvsai.setOutlineThickness(10);
	plvsai.setOutlineColor(sf::Color::White);
	plvsai.setPosition(sf::Vector2f(100, 300));
	plvsai.setFillColor(sf::Color::Black);

	wyjscie.setSize(sf::Vector2f(600, 200));
	wyjscie.setOutlineThickness(10);
	wyjscie.setOutlineColor(sf::Color::White);
	wyjscie.setPosition(sf::Vector2f(100, 550));
	wyjscie.setFillColor(sf::Color::Black);

}


//parametry tekstu trybów
void menu::pisanie_opcji_parametry()
{
	sf::Text pltxt(fontMenu);
	sf::Text plAi(fontMenu);
	sf::Text wyjscie(fontMenu);

	pltxt.setFillColor(sf::Color::White);
	pltxt.setString("PvP");
	pltxt.setPosition(sf::Vector2f(300, 90));
	pltxt.setCharacterSize(100);

	plAi.setFillColor(sf::Color::White);
	plAi.setString("PvE");
	plAi.setPosition(sf::Vector2f(290, 330));
	plAi.setCharacterSize(100);

	wyjscie.setFillColor(sf::Color::White);
	wyjscie.setString("EXIT");
	wyjscie.setPosition(sf::Vector2f(260, 580));
	wyjscie.setCharacterSize(100);

	okno_menu.draw(pltxt);
	okno_menu.draw(plAi);
	okno_menu.draw(wyjscie);

}



