//
// Created by Maria Isabel on 9/05/2025.
//

#include "Mapa.h"

Centella::Centella(string nom, int ed, int en): Criatura(move(nom), ed, en) {}

void Centella::actuar() { energia -= 2; edad++; }

void Centella::moverse() { energia -= 1; }

void Centella::reproducirse(vector<shared_ptr<Criatura>> &nuevas) {
}

json Centella::serializar() const {
}
