#include "gra.h"
#include "menu.h"

//konstruktor z opcjami okna gry ponga
gra::gra() : window(sf::VideoMode({ 1200,600 }), "okno gry", sf::Style::Close | sf::Style::Titlebar)
{
	parametry_tla();
	parametry_graczy();
	parametry_bramek();
	parametry_pilki();
	velocity_pilki = { 500.f,0 };
	font.openFromFile("Naraka.ttf");
}

//metoda przy uruchamianiu gry
void gra::uruchomienie()
{
	while (window.isOpen()) 
	{
		float deltatime = czas_delta.restart().asSeconds();
		if (deltatime > 0.2f) 
		{
			deltatime = 0.2f;
		}
		obsluga_zdarzen();
		rysowanie_tla();
		rysowanie_gracza1();
		rysowanie_gracza2();
		rysowanie_bramek();
		ruch_gracz1(deltatime);
		ruch_gracz2(deltatime);
		ruch_pilki(deltatime);
		rysowanie_pilki();
		sprawdzanie_gola();
		window.display();
	}
}

//obsluga wydarzen zamykania gry
void gra::obsluga_zdarzen()
{
	while (auto ev = window.pollEvent()) 
	{
		if (ev->is<sf::Event::Closed>()) 
		{
			window.close();
			menu menu;
			menu.uruchomienie_menu();
		}
		else if (auto keypressed = ev->getIf<sf::Event::KeyPressed>()) 
		{
			if (keypressed->scancode == sf::Keyboard::Scancode::Escape) 
			{
				window.close();
				menu menu;
				menu.uruchomienie_menu();
			}
		}


	}
}

//rysowanie tla
void gra::rysowanie_tla()
{
	window.draw(tlo);
}

//parametry do rysowania tla
void gra::parametry_tla()
{
	tlo.setOutlineThickness(10.f);
	tlo.setOutlineColor(sf::Color::Yellow);
	tlo.setPosition(sf::Vector2f(10, 10));
	tlo.setFillColor(sf::Color::Black);
	tlo.setSize(sf::Vector2f(1180, 580));


}

//rysowanie gracza1
void gra::rysowanie_gracza1()
{
	window.draw(gracz1);
}

//rysowanie gracza2
void gra::rysowanie_gracza2()
{
	window.draw(gracz2);
}

//prametry graczy
void gra::parametry_graczy()
{
	gracz1.setFillColor(sf::Color::White);
	gracz1.setSize(sf::Vector2f(20, 100));
	gracz1.setPosition(sf::Vector2f(50, 250));
	gracz2.setFillColor(sf::Color::White);
	gracz2.setSize(sf::Vector2f(20, 100));
	gracz2.setPosition(sf::Vector2f(1100, 250));
}

//parametry bramek
void gra::parametry_bramek()
{
	bramka1.setFillColor(sf::Color::Red);
	bramka1.setPosition(sf::Vector2f(0, 200));
	bramka1.setSize(sf::Vector2f(11, 200));
	bramka2.setFillColor(sf::Color::Red);
	bramka2.setPosition(sf::Vector2f(1189, 200));
	bramka2.setSize(sf::Vector2f(11, 200));
}

//rysowanie bramek
void gra::rysowanie_bramek()
{
	window.draw(bramka1);
	window.draw(bramka2);
}

//obsluga ruchu gracza1
void gra::ruch_gracz1(float delta)
{


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && gracz1.getPosition().y > 10)
	{
			gracz1.move(sf::Vector2f(0, -300 * delta));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && gracz1.getPosition().y + gracz1.getSize().y < 590)
	{
			gracz1.move(sf::Vector2f(0, 300 * delta));
	}

}

//obsluga ruchu gracza2
void gra::ruch_gracz2(float delta)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && gracz2.getPosition().y > 10)
	{
			gracz2.move(sf::Vector2f(0, -300 * delta));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && gracz2.getPosition().y + gracz1.getSize().y < 590)
	{
			gracz2.move(sf::Vector2f(0, 300 * delta));
	}
}

//parametry pilki
void gra::parametry_pilki()
{
	pilka.setFillColor(sf::Color::White);
	pilka.setPosition(sf::Vector2f(595, 295));
	pilka.setRadius(10);
}

//ruch pilki
void gra::ruch_pilki(float delta)
{
	// Ruch pi³ki
	pilka.move(velocity_pilki * delta * 2.f);

	// Dane pomocnicze
	float center_pilki_y = pilka.getPosition().y + pilka.getRadius();
	float center_gracza1_y = gracz1.getPosition().y + gracz1.getSize().y / 2.f;
	float center_gracza2_y = gracz2.getPosition().y + gracz2.getSize().y / 2.f;

	// ---- Kolizja z graczami ----
	if (pilka.getGlobalBounds().findIntersection(gracz1.getGlobalBounds()))
	{
		// ustaw pi³kê tu¿ przy krawêdzi gracza1
		pilka.setPosition(sf::Vector2f(gracz1.getPosition().x + gracz1.getSize().x, pilka.getPosition().y));

		// oblicz odbicie
		float kolizja = center_pilki_y - center_gracza1_y;
		velocity_pilki.x = std::abs(velocity_pilki.x); // zawsze w prawo
		velocity_pilki.y = kolizja * 5.f;
	}
	else if (pilka.getGlobalBounds().findIntersection(gracz2.getGlobalBounds()))
	{
		// ustaw pi³kê tu¿ przy krawêdzi gracza2
		pilka.setPosition(sf::Vector2f(gracz2.getPosition().x - pilka.getRadius() * 2, pilka.getPosition().y));

		// oblicz odbicie
		float kolizja = center_pilki_y - center_gracza2_y;
		velocity_pilki.x = -std::abs(velocity_pilki.x); // zawsze w lewo
		velocity_pilki.y = kolizja * 5.f;
	}

	// ---- Kolizja z sufitem/pod³og¹ ----
	if (pilka.getPosition().y <= 10.f)
	{
		pilka.setPosition(sf::Vector2f(pilka.getPosition().x, 10.f));
		velocity_pilki.y *= -1.f;
	}
	else if (pilka.getPosition().y + pilka.getRadius() * 2 >= 590.f)
	{
		pilka.setPosition(sf::Vector2f(pilka.getPosition().x, 590.f - pilka.getRadius() * 2));
		velocity_pilki.y *= -1.f;
	}
	//boczne sciany
// odbicie od lewej œciany, tylko jeœli NIE jesteœmy w bramce1
	if (pilka.getPosition().x <= 10.f &&
		!bramka1.getGlobalBounds().findIntersection(pilka.getGlobalBounds()))
	{
		pilka.setPosition(sf::Vector2f(10.f, pilka.getPosition().y));
		velocity_pilki.x *= -1.f;
	}
	// odbicie od prawej œciany, tylko jeœli NIE jesteœmy w bramce2
	else if (pilka.getPosition().x + pilka.getRadius() * 2 >= 1190.f &&
		!bramka2.getGlobalBounds().findIntersection(pilka.getGlobalBounds()))
	{
		pilka.setPosition(sf::Vector2f(1190.f - pilka.getRadius() * 2, pilka.getPosition().y));
		velocity_pilki.x *= -1.f;
	}


}

//rysowanie pilki
void gra::rysowanie_pilki()
{
	window.draw(pilka);
}

//wyswietlanie wyniku po strzeleniu gola
void gra::wyswietlanie_wyniku(std::string tekst)
{

	sf::Text score(font);
	score.setFillColor(sf::Color::White);
	score.setCharacterSize(100);
	score.setPosition(sf::Vector2f(200, 50));
	score.setString("Score is " + tekst);
	window.draw(score);
	window.display();
	sf::sleep(sf::seconds(2));
}

//sprawdzanie czy pilka jest w bramce
void gra::sprawdzanie_gola()
{
	
	if (bramka1.getGlobalBounds().findIntersection(pilka.getGlobalBounds())) 
	{
		pilka.setPosition(sf::Vector2f(595, 295));
		gracz1.setPosition(sf::Vector2f(50, 250));
		gracz2.setPosition(sf::Vector2f(1100, 250));
		velocity_pilki = { 500.f,0 };
		punkty_gracz2++;
		std::string wynik = std::to_string(punkty_gracz1) + " : " + std::to_string(punkty_gracz2);
		wyswietlanie_wyniku(wynik);


	}
	else if (bramka2.getGlobalBounds().findIntersection(pilka.getGlobalBounds())) 
	{
		pilka.setPosition(sf::Vector2f(595, 295));
		gracz1.setPosition(sf::Vector2f(50, 250));
		gracz2.setPosition(sf::Vector2f(1100, 250));
		velocity_pilki = { -500.f,0 };
		punkty_gracz1++;
		std::string wynik = std::to_string(punkty_gracz1) + " : " + std::to_string(punkty_gracz2);
		wyswietlanie_wyniku(wynik);
	}
}


