#ifndef VOLADOR_H
#define VOLADOR_H

#include "json.hpp"

using namespace std;
using json = nlohmann::json;


class Volador {
public:
    virtual void volar() = 0;
    virtual ~Volador() = default;
};


#endif //VOLADOR_H
