#ifndef NODO_H
#define NODO_H

#include <vector>
#include <string>
#include <memory>
#include "json.hpp"
#include "Volador.h"
#include "Criatura.h"
#include "Regenerador.h"

using namespace std;
using json = nlohmann::json;

class Nodo {
    vector<shared_ptr<Criatura>> criaturas;
    int recursos;

public:
    Nodo(int r = 10);

    void agregar(shared_ptr<Criatura> c);
    shared_ptr<Criatura> retirarUna();
    void simular();
    json serializar() const;
    int cantidadCriaturas() const;
};

#endif // NODO_H
