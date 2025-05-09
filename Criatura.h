//
// Created by Maria Isabel on 9/05/2025.
//

#ifndef CRIATURA_H
#define CRIATURA_H

#include <vector>
#include <string>
#include <memory>
#include "json.hpp"


using namespace std;
using json = nlohmann::json;


class Criatura {
protected:
    string nombre;
    int edad, energia;

public:
    Criatura(string nom, int ed, int en);

    virtual void actuar() = 0;
    virtual void moverse() = 0;
    virtual void reproducirse(vector<shared_ptr<Criatura>>& nuevas) = 0;
    virtual bool estaViva() const;

    virtual json serializar() const = 0;
    virtual ~Criatura();
};

#endif //CRIATURA_H
