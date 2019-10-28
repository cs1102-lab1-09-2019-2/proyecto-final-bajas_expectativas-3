#include "final.h"
int main() {
    entero alto=10;
    entero ancho=10;
    vector<vector<vector<caraccter >>> mapas;
    entero m_eleg;
    menu();
    cin>>m_eleg;
    if(m_eleg==3){
        return 0;
    }
    if(m_eleg==1) {
        leerdatos(mapas);
        cout<<"Selecione el mapa";
        cin>>m-e;
        ruta(m_eleg,mapas);
    }
//ent num = 2;
//do {
//  ruta(10, 10, num, mapa);
//  impr(mapa, 10, 10);
//  num++;
//} while (num<8);
    /*ruta(10, 10, 2, mapa);
    ruta(10, 10, 3, mapa);
    ruta(10, 10, 4, mapa);
    impr(mapa, 10, 10);
*/

    return 0;}