#ifndef MUTANTEALADO_H
#define MUTANTEALADO_H

#include <string>
#include "json.hpp"
#include "Mutante.h"

using namespace std;
using json = nlohmann::json;

class MutanteAlado : public Mutante {
public:
    MutanteAlado(string nom, int ed, int en);
    void moverse() override;
    json serializar() const override;
};

#endif // MUTANTEALADO_H
