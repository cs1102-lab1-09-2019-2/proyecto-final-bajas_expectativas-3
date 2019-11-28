#include "Mapa.h"
int main(){
    cout << " ___  ___  ___  _   _  ___  _   _    _  ___   ___  __   "<<"\n";
    cout <<"|       ||   _   ||       ||  | |  ||       ||   | |  |  | ||      | |       ||    _ |  "<<"\n";
    cout << "|    _  ||  ||  ||     ||  ||  ||    _||   | |   || ||  _    ||    __||   | ||  "<<"\n";
    cout << "|   || ||       |  |   |  |       ||   |_ |   | |       || | |   ||   |_ |   |||_ "<<"\n";
    cout <<"|    _||       |  |   |  |       ||    _||   | |  _    || ||   ||    _||    _  |" <<"\n";
    cout << "|   |    |   _   |  |   |  |   _   ||   |    |   | | | |   ||       ||   |_ |   |  | |" <<"\n";
    cout << "|_|    |_| ||  |_|  || |||_|    |_| ||  |_||__| |__||_|  |_|"<<"\n";
    cout <<setfill(' ')<<setw(89) << "" <<"\n";
    cout << "\n";

    cout << setfill('-') << setw(46) <<"MENU";
    cout << setfill('-') << setw(43)<<"-";
    cout << "\n";

    entero elegido;
    cout << "1 - Seleccionar el mapa.";
    cout << "\n";
    cout << "3 - Salir.";
    cout<<'\n';
    cin>>elegido;

    if(elegido==3)
        return 0;
    Mapa mapa1(elegido);
    mapa1.Imprimir_Mapa();
    mapa1.Dkjistra();

    return 0;
}
