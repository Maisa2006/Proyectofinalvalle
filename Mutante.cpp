#include "Mutante.h"

Mutante::Mutante(string nom, int ed, int en)
    : Criatura(move(nom), ed, en) {}

void Mutante::actuar() {
    energia -= 1;
    edad++;
}

void Mutante::moverse() {
    energia -= 2;
}

void Mutante::reproducirse(vector<shared_ptr<Criatura>>& nuevas) {
    if (edad > 3 && energia > 15) {
        nuevas.push_back(make_shared<Mutante>(nombre + "_mut", 0, 10));
    }
}

json Mutante::serializar() const {
    return {
            {"tipo", "Mutante"},
            {"nombre", nombre},
            {"edad", edad},
            {"energia", energia}
    };
}
