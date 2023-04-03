#include <iostream>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

#include "funciones.h"
#include "rlutil.h"

int main(){
    int op=1, y=0;
    int v[5];
    int puntajesv[2];
    int tiradasv[2];
    int bp[1];
    int maxpyt[2];
    ponerCero(maxpyt, 2);
    ponerCero(bp, 1);
    ponerCero(puntajesv, 2);
    ponerCero(tiradasv, 2);
    char jugador1[21];
    char jugador2[21];
    char jrecord[21];

        bienvenida(v);

        menu(y, op, puntajesv, tiradasv, jugador1, jugador2,bp,maxpyt,jrecord);

cout<<endl;
return 0;
}
