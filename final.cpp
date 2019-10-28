
#include "final.h"
void menu(){
    cout << " ___  ___  ___  _   _  ___  _   _    _  ___   ___  __   "<<"\n";
    cout <<"|       ||   _   ||       ||  | |  ||       ||   | |  |  | ||      | |       ||    _ |  "<<"\n";
    cout << "|    _  ||  ||  ||     ||  ||  ||    _||   | |   || ||  _    ||    __||   | ||  "<<"\n";
    cout << "|   || ||       |  |   |  |       ||   |_ |   | |       || | |   ||   |_ |   |||_ "<<"\n";
    cout <<"|    _||       |  |   |  |       ||    _||   | |  _    || ||   ||    _||    _  |" <<"\n";
    cout << "|   |    |   _   |  |   |  |   _   ||   |    |   | | | |   ||       ||   |_ |   |  | |" <<"\n";
    cout << "|_|    |_| ||  |_|  || |||_|    |_| ||  |_||__| |__||_|  |_|"<<"\n";
    cout <<setfill('')<<setw(89) << "" <<"\n";
    cout << "\n";

    cout << setfill('-') << setw(46) <<"MENU";
    cout << setfill('-') << setw(43)<<"-";
    cout << "\n";
    cout << "1 - Seleccionar el mapa.";
    cout << "\n";
    /*cout << "2 - Iniciar simulación con mapa aleatorio.";
    cout << "\n";*/
    cout << "3 - Salir.";
    return;
}
entero maximo(vector<entero> x){
    entero max=x[0];
    entero indice=0;
    for (int i = 1; i < x.size(); ++i) {
        if(max<x[i]){
            max=x[i];
            indice=i;
        }
    }
    return indice;
}
void leerdatos(vector<vector<vector<caraccter >>> &mapas){
    ifstream archivo;
    cadena cadena;
    vector<caraccter> columnas;
    vector<vector<caraccter >> filas;
    entero i=0;
    archivo.open("mapas.txt",ios::in);
    while (!archivo.eof){
        getline(archivo,cadena);
        while(i<10) {
            for (int j = 0; j < cadena.size(); ++j) {
                if (isdigit(cadena[j] || cadena[j] == 'X' || cadena[j] == 'F')) {
                    columnas.emplace_back(cadena[j]);
                    i++;
                }
            }
            filas.emplace_back(columnas);
            columnas.clear();
        }
        mapas.emplace_back(filas);
        filas.clear();
    }
}
void ruta(entero m_elegido,vector<vector<vector<caraccter >>> &mapas){
    vector<vector<caraccter>> mapa_e = mapa[m_elegido];
    entero x,y,suma=0,indice;
    vector<entero> sumas;
    for (int i = 0; i < mapa_e.size(); ++i) {
        for (int j = 0; j < mapa_e[i].size() ; ++j) {
            if(mapa_e[i][j]=='X'){
                x=i;
                y=j;
                break;
            }
        }
    }
    vector<entero> coordenadas;
    vector<vector<entero>> rutas;
    entero x1=x,y1=y;
    while(true){
        if(mapa_e[x1+1][y1]== 'F'){
            break;
        }
        if(mapa_e[x1][y1+1]=='F'){
            break;
        }
        if(mapa_e[x1][y1+1]=='0'){
            y1++;
            coordenadas.emplace_back(x1);
            coordenadas.emplace_back(y1;)
            if(mapa_e[x1][y1+1]=='0'){
                y1++;
                coordenadas.emplace_back(x1);
                coordenadas.emplace_back(y1;)

            }
            if(mapa_e[x1][y1+1]=='1'){
                x1++;
            }
            if(mapa_e[x1+1][y1]=='0'){
                x1++;
                coordenadas.emplace_back(x1);
                coordenadas.emplace_back(y1);
            }

        }
        if(mapa_e[x1][y1+1]=='1'){
            x1++;
        }
        if(mapa_e[x1+1][y1]=='0'){
            x1++;
            coordenadas.emplace_back(x1);
            coordenadas.emplace_back(y1);
            if(mapa_e[x1][y1+1]=='0'){
                y1++;
                coordenadas.emplace_back(x1);
                coordenadas.emplace_back(y1;)

            }
            if(mapa_e[x1][y1+1]=='1'){
                x1++;
            }
            if(mapa_e[x1+1][y1]=='0'){
                x1++;
                coordenadas.emplace_back(x1);
                coordenadas.emplace_back(y1);
            }

        }
    }
    for (int k = 0; k <rutas.size ; ++k) {
        suma=0;
        for (int i = 0; i < rutas[i].size; i=i+2) {
            suma++;
        }
        sumas.emplace_back(suma);
    }
    indice=maximo(sumas);
    for (int l = 0; l < rutas[indice].size ; l=l+2) {
        mapa_e[rutas[indice][l]][rutas[indice][l+1]]='&';
    }
    impr(mapa_el[indice],10,10);
}
/*void ruta(entero alto, entero ancho, entero num, vector<vector<caracter >> mapa){
    entero a=0; entero b=0;
    do{
        for (entero i=a;i<alto; i++){
            for (entero j=b;j<ancho; j++){
                a=i;b=j;
                if (mapa[i][j]==num){
                    if (mapa[i-1][j]==0){if (i-1>=0){mapa[i-1][j]=num+1;}}
                    if (mapa[i+1][j]==0){if(i+1<10){mapa[i+1][j]=num+1;}}
                    if (mapa[i][j-1]==0){if (j-1>=0){mapa[i][j-1]=num+1;}}
                    if (mapa[i][j+1]==0){if(j+1<10){mapa[i][j+1]=num+1;}}

                }}}}while(a!=alto-1 && b!= ancho-1);}


*/
void impr(vector<vector<caracter>> mapa, entero alto, entero ancho){
    for (entero i=0;i<alto; i++){
        for (entero j=0;j<ancho; j++){
            cout << " " << mapa[i][j] << " ";
        }cout << "\n";}
    return;
}
