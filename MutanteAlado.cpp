#include "MutanteAlado.h"

MutanteAlado::MutanteAlado(string nom, int ed, int en)
    : Mutante(move(nom), ed, en) {}

void MutanteAlado::moverse() {
    energia -= 1;
}

json MutanteAlado::serializar() const {
    return {
            {"tipo", "MutanteAlado"},
            {"nombre", nombre},
            {"edad", edad},
            {"energia", energia}
    };
}
