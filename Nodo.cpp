#include "Nodo.h"
#include <algorithm>

Nodo::Nodo(int r) : recursos(r) {}

void Nodo::agregar(shared_ptr<Criatura> c) {
    criaturas.push_back(c);
}

shared_ptr<Criatura> Nodo::retirarUna() {
    if (criaturas.empty()) return nullptr;
    auto c = criaturas.back();
    criaturas.pop_back();
    return c;
}

void Nodo::simular() {
    vector<shared_ptr<Criatura>> nuevas;
    for (auto& c : criaturas) {
        c->actuar();
        c->moverse();
        if (recursos >= 20) {
            if (auto reg = dynamic_pointer_cast<Regenerador>(c)) {
                reg->regenerar();
            }
        }
        if (recursos >= 10)
            c->reproducirse(nuevas);
    }

    for (auto& c : nuevas)
        criaturas.push_back(c);

    criaturas.erase(remove_if(criaturas.begin(), criaturas.end(),
                              [](const shared_ptr<Criatura>& c) {
                                  return !c->estaViva();
                              }),
                    criaturas.end());
}

json Nodo::serializar() const {
    json j;
    j["recursos"] = recursos;
    for (const auto& c : criaturas)
        j["criaturas"].push_back(c->serializar());
    return j;
}

int Nodo::cantidadCriaturas() const {
    return criaturas.size();
}
