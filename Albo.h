#ifndef ALBO_H
#define ALBO_H

#include <vector>
#include <string>
#include <memory>
#include "json.hpp"
#include "Volador.h"
#include "Criatura.h"
#include "Regenerador.h"


using namespace std;
using json = nlohmann::json;


class Albo : public Criatura, public Volador, public Regenerador {
public:
    Albo(string nom, int ed, int en) : Criatura(move(nom), ed, en) {}
    void actuar() override { energia--; edad++; if (edad % 2 == 0) regenerar(); }
    void moverse() override { volar(); energia -= 1; }
    void reproducirse(vector<shared_ptr<Criatura>>& nuevas) override {
        if (energia > 20)
            nuevas.push_back(make_shared<Albo>(nombre + "_eco", 0, 10));
    }
    void volar() override { energia -= 1; }
    void regenerar() override { energia += 2; }
    json serializar() const override {
        return {{"tipo", "Albo"}, {"nombre", nombre}, {"edad", edad}, {"energia", energia}};
    }
};


#endif//ALBO_H
