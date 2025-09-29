#pragma once
#include "gra.h"

class graAI : public gra
{
public:
    graAI();

    // nadpisujemy tylko ruch gracza2
    void ruch_gracz2(float delta) override;
};
