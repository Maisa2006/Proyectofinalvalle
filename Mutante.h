#ifndef MUTANTE_H
#define MUTANTE_H

#include <vector>
#include <string>
#include <memory>
#include "json.hpp"
#include "Criatura.h"

using namespace std;
using json = nlohmann::json;

class Mutante : public Criatura {
public:
    Mutante(string nom, int ed, int en);
    void actuar() override;
    void moverse() override;
    void reproducirse(vector<shared_ptr<Criatura>>& nuevas) override;
    json serializar() const override;
};

#endif // MUTANTE_H
