//
// Created by Maria Isabel on 9/05/2025.
//

#include "Criatura.h"

Criatura::Criatura(string nom, int ed, int en): nombre(std::move(nom)), edad(ed), energia(en) {}

bool Criatura::estaViva() const { return energia > 0; }

Criatura::~Criatura() = default;
