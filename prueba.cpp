#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using ent=int;

void ruta(ent alto, ent ancho, ent num,int mapa[10][10]){
  
  for (ent i=0;i<alto; i++){
  for (ent j=0;j<ancho; j++){
    if (mapa[i][j]==num){
          if (mapa[i-1][j]==0){if (i-1>=0){mapa[i-1][j]=num+1;}}
          if (mapa[i+1][j]==0){if(i+1<10){mapa[i+1][j]=num+1;}}
          if (mapa[i][j-1]==0){if (j-1>=0){mapa[i][j-1]=num+1;}}
          if (mapa[i][j+1]==0){if(j+1<10){mapa[i][j+1]=num+1;}}
          
  }}}}



void impr(int mapa[10][10], ent alto, ent ancho){
  for (ent i=0;i<alto; i++){
  for (ent j=0;j<ancho; j++){
    cout << setw(5) << mapa[i][j] << " ";
  }cout << "\n";}
  return;
}

int main() {
ent alto=10;
ent ancho=10;
int mapa[10][10] =
{
{0,0,0,0,0,0,0,0,1,0},
{0,1,0,1,1,0,1,0,0,1},
{0,1,0,0,0,0,0,0,0,1},
{0,1,0,1,1,0,0,1,0,1},
{0,1,1,0,0,0,1,1,0,0},
{0,0,0,0,1,0,1,1,0,2},
{0,0,0,0,1,0,0,0,0,0},
{0,1,0,1,0,0,0,1,0,1},
{0,0,1,0,0,0,1,0,0,1},
{100,1,0,1,1,0,1,0,0,0}
};

impr(mapa, 10, 10);
ent num = 2;
do {
  ruta(10, 10, num, mapa);
  impr(mapa, 10, 10);
  cout << "\n";
  num++;
} while (num<100);


return 0;}
