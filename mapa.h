//
// Created by abomzo on 25/11/2019.
//

#ifndef PROYECTOFINAL_MAPA_H
#define PROYECTOFINAL_MAPA_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
using nat = size_t;
using cadena=string;
using mapas = vector<vector<vector<char >>>;
using mapa = vector<vector<bool >>;
class Mapa {
private:
    mapa map;
    pair<nat, nat> inicio;
    pair<nat, nat> final;
    int m;
public:
    Mapa(int _m) : m(_m) {
        ifstream archivo;
        archivo.open("/home/linux/POO/debuggin/mapas.txt");
        if (!archivo.is_open()) exit(-1);
        vector<vector<bool >> obstaculos;
        int c = 0;
        for (string line; getline(archivo, line); c++) {
            if (c < (11 * (m - 1))) continue;
            if (c >= (11 * (m))) break;

            vector<bool> particion;
            string res;
            stringstream ss(line);
            for (nat pos = 0; getline(ss, res, ' '); pos++) {
                if (res.empty()) {
                    pos--;
                    continue;
                }

                if (res == "1") {
                    particion.emplace_back(true);
                    continue;
                } else particion.emplace_back(false);
                if (res == "F") final = {pos, c - 11 * (m - 1)};
                if (res == "X") inicio = {pos, c - 11 * (m - 1)};
            }
            obstaculos.emplace_back(particion);

        }
        map = obstaculos;
        archivo.close();
    }

    void Imprimir_Mapa() {
        for (nat i = 0; i < map.size(); ++i) {
            for (nat j = 0; j < map[i].size(); ++j) {
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};

#endif //PROYECTOFINAL_MAPA_H
