#ifndef REGENERADOR_H
#define REGENERADOR_H

#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class Regenerador {
public:
    virtual void regenerar() = 0;
    virtual ~Regenerador() = default;
};

#endif // REGENERADOR_H
