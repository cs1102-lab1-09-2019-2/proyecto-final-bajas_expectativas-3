#include "Mapa.h"
int main(){
    cout << " _______  _______  _______  __   __  _______  ___   __    _  ______   _______  ______   "<<"\n";
    cout <<"|       ||   _   ||       ||  | |  ||       ||   | |  |  | ||      | |       ||    _ |  "<<"\n";
    cout <<"|    _  ||  |_|  ||_     _||  |_|  ||    ___||   | |   |_| ||  _    ||    ___||   | ||  "<<"\n";
    cout <<"|   |_| ||       |  |   |  |       ||   |___ |   | |       || | |   ||   |___ |   |_||_ "<<"\n";
    cout <<"|    ___||       |  |   |  |       ||    ___||   | |  _    || |_|   ||    ___||    __  |" <<"\n";
    cout <<"|   |    |   _   |  |   |  |   _   ||   |    |   | | | |   ||       ||   |___ |   |  | |" <<"\n";
    cout <<"|___|    |__| |__|  |___|  |__| |__||___|    |___| |_|  |__||______| |_______||___|  |_|"<<"\n";
    cout <<setfill(' ')<<setw(89) << "" <<"\n";
    cout << "\n";

    cout << setfill('-') << setw(46) <<"MENU";
    cout << setfill('-') << setw(43)<<"-";
    cout << "\n";



    while (true) {
        entero elegido;
        cout << "1 - Seleccionar el mapa.";
        cout << "\n";
        cout << "3 - Salir.";
        cout<<'\n';
        cin>>elegido;
        if (elegido == 6)
            break;
        if(elegido>=1 && elegido<=5) {
            Mapa mapa1(elegido);
            mapa1.Imprimir_Mapa();
            mapa1.Dkjistra();
        }
    }
    return 0;
}
