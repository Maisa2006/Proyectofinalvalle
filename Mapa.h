#include <vector>
#include <string>
#include <memory>
#include "json.hpp"
#include "Criatura.h"


using namespace std;
using json = nlohmann::json;


class Centella : public Criatura {
public:
    Centella(string nom, int ed, int en) : Criatura(move(nom), ed, en) {}
    void actuar() override { energia -= 2; edad++; }
    void moverse() override { energia -= 1; }
    void reproducirse(vector<shared_ptr<Criatura>>& nuevas) override {
        if (energia > 10)
            nuevas.push_back(make_shared<Centella>(nombre + "_hijo", 0, 5));
    }
    json serializar() const override {
        return {{"tipo", "Centella"}, {"nombre", nombre}, {"edad", edad}, {"energia", energia}};
    }
};
