#include "graAI.h"

graAI::graAI() : gra()
{
    // konstruktor taki sam jak w bazowej klasie
}

void graAI::ruch_gracz2(float delta)
{
    float center_pilki_y = pilka.getPosition().y + pilka.getRadius();
    float center_pilki_x = pilka.getPosition().x + pilka.getRadius();
    float center_gracza2_y = gracz2.getPosition().y + gracz2.getSize().y / 2.f;
    float center_gracza2_x = gracz2.getPosition().x + gracz2.getSize().x / 2.f;

    float predkosc_AI = 150; // zmieñ dla trudnoœci
    float margines = 5.f;      // ¿eby nie drga³

    if (center_gracza2_y < center_pilki_y && gracz2.getPosition().y + gracz2.getSize().y < 590 && center_gracza2_x - center_pilki_x > 50)
    {
            gracz2.move(sf::Vector2f(0, predkosc_AI * delta));
    }
    else if (center_gracza2_y > center_pilki_y + margines && gracz2.getPosition().y > 10 && center_gracza2_x - center_pilki_x > 50)
    {
            gracz2.move(sf::Vector2f(0, -predkosc_AI * delta));
    }
}
