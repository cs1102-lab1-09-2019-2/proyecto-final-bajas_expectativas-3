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
/*using mapas = vector<vector<vector<char >>>;*/
using mapa = vector<vector<bool >>;
class Mapa{
private:
    mapa map;
    pair<nat, nat> inicio;
    pair<nat, nat> final;
    int m;
public:
    Mapa(int _m):  m(_m){
        ifstream archivo;
        archivo.open("/home/linux/POO/debuggin/mapas.txt");
        if(!archivo.is_open()) exit(-1);
        vector<vector<bool >> obstaculos;
        int c=0;
        for( string line; getline(archivo,line); c++){
            if (c<(11*(m-1))) continue;
            if(c>=(11*(m))) break;

            vector<bool> particion;
            string res;
            stringstream ss(line);
            for(nat pos = 0; getline(ss,res,' '); pos++) {
                if (res.empty()) {pos--; continue;}

                if (res == "1") {
                    particion.emplace_back(true);
                    continue;
                }
                else particion.emplace_back(false);
                if (res == "F")  final = {pos, c - 11*(m-1)};
                if (res == "X")  inicio = {pos, c - 11*(m-1)};
            }
            obstaculos.emplace_back(particion);

        }
        map=obstaculos;
        archivo.close();
    }
    void Imprimir_Mapa(){
        for (nat i = 0; i < map.size() ; ++i) {
            for (nat j = 0; j < map[i].size(); ++j) {
                cout<<map[i][j]<<' ';
            }
            cout << '\n';
        }
    }
    /*void AStar(){

    }*/
    void Dkjistra(){
        auto visitado = map;
        vector<vector<nat>> grid(10,vector<nat> (10,0));
        vector<vector<char>> camino(10,vector<char> (10,'.'));
        for (nat i = 0; i < map.size() ; ++i) {
            for (nat j = 0; j < map[i].size(); ++j) {
                if (map[i][j] == true) camino[i][j] = '#';
            }
        }


        vector<pair<int,int>> vecinos = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<pair<nat,nat>> cola;
        pair<nat,nat> actual = inicio;
        int npasos = 1;
        cola.emplace_back(inicio);
        while(!cola.empty()){
            vector<pair<nat,nat>> cola2;
            for(auto & item: cola){
                try {
                    actual={item.first,item.second};
                    if(grid.at(actual.second).at(actual.first)==0)
                        grid[actual.second][actual.first] = npasos;
                    if (final == actual)
                        goto construir;

                    for (auto vecino : vecinos) {
                        try {
                            pair<nat, nat> spotVecino = {actual.first + vecino.first, actual.second + vecino.second};
                            if (!visitado.at(spotVecino.second).at(spotVecino.first)) {
                                visitado[spotVecino.second][spotVecino.first] = true;
                                cola2.emplace_back(spotVecino);
                            } else continue;
                        } catch (exception &) {continue;}
                    }
                } catch (exception&){continue;}
            }
            npasos++;
            cola = cola2;
        }
        return;
        construir:

        for (; npasos >= 1; ) {
            camino[actual.second][actual.first] = '=';
            if (npasos == 1) break;
            for(auto vecino : vecinos) {
                pair<nat, nat> adyacente = {actual.first + vecino.first, actual.second + vecino.second};
                try {
                    if (grid.at(adyacente.second).at(adyacente.first) == npasos - 1) {
                        actual = adyacente;
                        npasos--;
                        break;
                    }
                } catch (exception &) { continue; }
            }
        }

        for (const auto& linea : camino) {
            for (const auto& item : linea) cout << item << ' ';
            cout << '\n';
        }

    }
};#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
using nat = size_t;
using cadena=string;
/*using mapas = vector<vector<vector<char >>>;*/
using mapa = vector<vector<bool >>;
class Mapa{
private:
    mapa map;
    pair<nat, nat> inicio;
    pair<nat, nat> final;
    int m;
public:
    Mapa(int _m):  m(_m){
        ifstream archivo;
        archivo.open("/home/linux/POO/debuggin/mapas.txt");
        if(!archivo.is_open()) exit(-1);
        vector<vector<bool >> obstaculos;
        int c=0;
        for( string line; getline(archivo,line); c++){
            if (c<(11*(m-1))) continue;
            if(c>=(11*(m))) break;

            vector<bool> particion;
            string res;
            stringstream ss(line);
            for(nat pos = 0; getline(ss,res,' '); pos++) {
                if (res.empty()) {pos--; continue;}

                if (res == "1") {
                    particion.emplace_back(true);
                    continue;
                }
                else particion.emplace_back(false);
                if (res == "F")  final = {pos, c - 11*(m-1)};
                if (res == "X")  inicio = {pos, c - 11*(m-1)};
            }
            obstaculos.emplace_back(particion);

        }
        map=obstaculos;
        archivo.close();
    }
    void Imprimir_Mapa(){
        for (nat i = 0; i < map.size() ; ++i) {
            for (nat j = 0; j < map[i].size(); ++j) {
                cout<<map[i][j]<<' ';
            }
            cout << '\n';
        }
    }
    /*void AStar(){

    }*/
    void Dkjistra(){
        auto visitado = map;
        vector<vector<nat>> grid(10,vector<nat> (10,0));
        vector<vector<char>> camino(10,vector<char> (10,'.'));
        for (nat i = 0; i < map.size() ; ++i) {
            for (nat j = 0; j < map[i].size(); ++j) {
                if (map[i][j] == true) camino[i][j] = '#';
            }
        }


        vector<pair<int,int>> vecinos = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<pair<nat,nat>> cola;
        pair<nat,nat> actual = inicio;
        int npasos = 1;
        cola.emplace_back(inicio);
        while(!cola.empty()){
            vector<pair<nat,nat>> cola2;
            for(auto & item: cola){
                try {
                    actual={item.first,item.second};
                    if(grid.at(actual.second).at(actual.first)==0)
                        grid[actual.second][actual.first] = npasos;
                    if (final == actual)
                        goto construir;

                    for (auto vecino : vecinos) {
                        try {
                            pair<nat, nat> spotVecino = {actual.first + vecino.first, actual.second + vecino.second};
                            if (!visitado.at(spotVecino.second).at(spotVecino.first)) {
                                visitado[spotVecino.second][spotVecino.first] = true;
                                cola2.emplace_back(spotVecino);
                            } else continue;
                        } catch (exception &) {continue;}
                    }
                } catch (exception&){continue;}
            }
            npasos++;
            cola = cola2;
        }
        return;
        construir:

        for (; npasos >= 1; ) {
            camino[actual.second][actual.first] = '=';
            if (npasos == 1) break;
            for(auto vecino : vecinos) {
                pair<nat, nat> adyacente = {actual.first + vecino.first, actual.second + vecino.second};
                try {
                    if (grid.at(adyacente.second).at(adyacente.first) == npasos - 1) {
                        actual = adyacente;
                        npasos--;
                        break;
                    }
                } catch (exception &) { continue; }
            }
        }

        for (const auto& linea : camino) {
            for (const auto& item : linea) cout << item << ' ';
            cout << '\n';
        }

    }
};
