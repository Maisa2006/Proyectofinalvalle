#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include "Mapa.h"
#include "json.hpp"


using namespace std;
using json = nlohmann::json;


int main() {
    srand(time(nullptr));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(3, 8);

    int filas = dist(gen);
    int columnas = dist(gen);

    cout << "Valle Iridiano de " << filas << "x" << columnas << " nodos\n";
    Mapa valle(filas, columnas);
    valle.poblar();

    json historial;

    for (int ciclo = 0; ciclo < 5; ++ciclo) {
        cout << "\nCiclo " << ciclo + 1 << "\n";
        valle.simular();
        valle.mostrar();

        historial["Ciclo " + to_string(ciclo + 1)] = valle.serializar();
    }

    ofstream("../valleIridiano.json") << historial.dump(4);
    cout << "\n Archivo generado: valleIridiano.json\n";

   return 0;
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.