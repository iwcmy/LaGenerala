#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "rlutil.h"

////////////////////// DECLARACION

void menu(int y, int op, int puntajesv[], int tiradasv[], char jugador1[], char jugador2[],int bp[],int maxpyt[],char jrecord[]);
int cursenter(int y, int op, int puntajesv[], int tiradasv[], char jugador1[], char jugador2[],int bp[],int maxpyt[], char jrecord[]);
void mostraropcion(const char* text, int posx, int posy, bool selected);
void bienvenida(int v[]);
void valordados(int xin, int yin,int v[], int orden);
void cargarAleatorio(int v[], int tam, int limite);
void dados(int vd[]);
void dadosinicio(int vd[]);
char nombrej1(char nombre[],int tam);
int introjuego1(int op, char jugador1[], int ronytir[]);
int interfazjuego1(int op, char jugador1[], int ronytir[], int puntajesv[], int tiradasv[]);
void mostrarbotonesdejuego(const char* text, int posx, int posy, bool sel);
void status(int x);
void ponerCero(int v[], int tam);
void matematica(int vd[], int vectorcombinaciones[], int vpuntajeindividual[]);
void opcionesjuegos(int ny, int vectordiscomb[], int vectorcombinaciones[], int vpuntajeindividual[]);
int introjuego2(int op, char jugador1[], char jugador2[], int ronytir[]);
int interfazjuego2(int op, char jugador1[], char jugador2[], int ronytir[], int puntajesv[], int tiradasv[]);
char nombrej2(char jugador[],int tam);
void pantallaturnos(int i, char siguiente[], char jugador1[], char jugador2[], int tiradasj[], int ind, int puntostotalj[]);

////////////////////// DESARROLLO

void menu(int y, int op, int puntajesv[], int tiradasv[], char jugador1[], char jugador2[], int bp[], int maxpyt[],char jrecord[]){

    do{
        rlutil::setBackgroundColor(0);
        rlutil::setColor(15);
        rlutil::hidecursor();

        rlutil::locate(70,14);
        cout<<"-----------------------------"<<endl;
        mostraropcion("JUEGO NUEVO DE A 1", 75, 15, y==0);
        mostraropcion("JUEGO NUEVO DE A 2", 75, 16, y==1);
        mostraropcion("MOSTRAR PUNTUACION MAS ALTA", 71, 17, y==2);
        mostraropcion("SALIR", 82, 19, y==4);
        rlutil::locate(70,18);
        cout<<"-----------------------------"<<endl;
        rlutil::locate(70,20);
        cout<<"-----------------------------"<<endl;

        switch(rlutil::getkey())
        {
        case 14: //up

            PlaySound(TEXT("mov.wav"),NULL,SND_ASYNC);

            y--;
            if(y==3){
                y--;
            }
            if(y<0){
                y=4;
            }
            break;

        case 15: //down

            PlaySound(TEXT("mov.wav"),NULL,SND_ASYNC);

            y++;
            if(y==3){
                y++;
            }
            if(y>4){
                y=0;
            }
            break;

        case 1: //enter

            PlaySound(TEXT("enter.wav"),NULL,SND_ASYNC);
            op=cursenter(y, op, puntajesv, tiradasv, jugador1, jugador2,bp,maxpyt,jrecord);
            break;
        }

    }while(op!=0);

}

int cursenter(int y, int op, int puntajesv[], int tiradasv[], char jugador1[], char jugador2[], int bp[],int maxpyt[],char jrecord[]){

    int ronytir[2];

 switch(y)
            {
            case 0:
                {

                    op=introjuego1(op, jugador1, ronytir);

                    op=interfazjuego1(op, jugador1, ronytir, puntajesv, tiradasv);
                }
                break;

            case 1:

                    op=introjuego2(op, jugador1, jugador2, ronytir);

                    op=interfazjuego2(op, jugador1, jugador2,  ronytir, puntajesv, tiradasv);

                break;

            case 2:
                {
                int bannombre=-1;

                rlutil::cls();
                rlutil::locate(75,12);
                rlutil::setColor(10);
                cout<<"Tabla de puntaje"<<endl;

                rlutil::locate(63,13);
                rlutil::setColor(15);
                cout<<"-----------------------------------------"<<endl;

                for(int i=0;i<=1;i++){

                    if(bp[0]==0){

                        maxpyt[0]=puntajesv[i];
                        maxpyt[1]=tiradasv[i];
                        bp[0]=1;
                        strcpy(jrecord,jugador1);
                    }
                    else if(puntajesv[i]>=maxpyt[0]){

                        maxpyt[0]=puntajesv[i];
                        maxpyt[1]=tiradasv[i];
                            if(i==0){
                                strcpy(jrecord,jugador1);
                            }
                            else{
                                strcpy(jrecord,jugador2);
                        }
                    }
                    bannombre=0;
                }
                if(maxpyt[1]==0){
                    rlutil::locate(64,16);
                    cout<<"Nombre: xxxxx";
                }
                else if(bannombre==0){
                    rlutil::locate(64,16);
                    cout<<"Nombre: "<<jrecord;
                }
                rlutil::locate(64,18);
                cout<<"Tiradas: "<<maxpyt[1];

                if(maxpyt[0]==123456789){
                    rlutil::locate(64,20);
                    cout<<"Gano por generala servida.";
                }
                else{
                    rlutil::locate(64,20);
                    cout<<"Puntaje: "<<maxpyt[0];
                }

                rlutil::locate(63,23);
                cout<<"-----------------------------------------"<<endl;

                rlutil::locate(64,24);
                system("pause");
                PlaySound(TEXT("enter.wav"),NULL,SND_ASYNC);
                rlutil::cls();
                op=1;
                }
                break;

            case 4:
                system("cls");
                rlutil::locate(72,14);
                cout<<"Gracias por jugar, vuelva prontos."<<endl;
                rlutil::locate(70,18);
                system("pause");
                PlaySound(TEXT("close.wav"),NULL,SND_SYNC);
                rlutil::cls();
                op=0;
                break;
            }

return op;
}

void mostraropcion(const char* text, int posx, int posy, bool selected){

    if(selected){
        rlutil::setBackgroundColor(4);
        rlutil::locate(posx-2, posy);
        cout<<char(175)<<" "<<text<<" "<<char(174)<<endl;
    }
    else{
        rlutil::setBackgroundColor(0);
        rlutil::locate(posx-2, posy);
        cout<<"  "<<text<<"  "<<endl;
    }

    rlutil::setBackgroundColor(0);

}

void bienvenida(int v[]){


        rlutil::locate(71,12);
        rlutil::setColor(10);
        cout<<char(173)<<"Bienvenido a la generala!"<<endl;
        rlutil::locate(55,14);
        rlutil::setColor(7);
        cout<<char(175)<<" Recomendamos jugar con la consola en pantalla completa "<<char(174)<<endl;
        rlutil::locate(64,17);
        rlutil::setColor(7);
        system("pause");
        dadosinicio(v);
        rlutil::hidecursor();
        rlutil::locate(70,45);
        rlutil::setColor(0);
        system("pause");
        system("cls");
}

void valordados(int xin, int yin,int v[], int orden){
    int xini, yini;
    xini=xin;
        switch(v[orden]){
    case 1:
        yini=yin;
        for(int a=0;a<10;a++){
            for(int b=0;b<20;b++){
                if(a==4 && b==8){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==9){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==10){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==11){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==8){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==9){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==10){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==11){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else{
                   rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    cout<<(char)219;
                }
                xini++;
            }
        xini=xin;
        yini=yini+1;
        }
    break;
    case 2:
        yini=yin;
        for(int a=0;a<10;a++){
            for(int b=0;b<20;b++){
                if(a==2 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else{
                   rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    cout<<(char)219;
                }
                xini++;
            }
        xini=xin;
        yini=yini+1;
        }
    break;
    case 3:
        yini=yin;
        for(int a=0;a<10;a++){
            for(int b=0;b<20;b++){
                if(a==2 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==8){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==9){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==10){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==11){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==8){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==9){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==10){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==11){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else{
                   rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    cout<<(char)219;
                }
                xini++;
            }
        xini=xin;
        yini=yini+1;
        }
    break;
    case 4:
        yini=yin;
        for(int a=0;a<10;a++){
            for(int b=0;b<20;b++){
                if(a==2 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else{
                   rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    cout<<(char)219;
                }
                xini++;
            }
        xini=xin;
        yini=yini+1;
        }
    break;
    case 5:
        yini=yin;
        for(int a=0;a<10;a++){
            for(int b=0;b<20;b++){
                if(a==2 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==8){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==9){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==10){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==11){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==8){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==9){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==10){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==11){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else{
                   rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    cout<<(char)219;
                }
                xini++;
            }
        xini=xin;
        yini=yini+1;
        }
    break;
    case 6:
        yini=yin;
        for(int a=0;a<10;a++){
            for(int b=0;b<20;b++){
                if(a==2 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==2 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==1 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==8 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==7 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==14){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==15){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==16){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==17){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==4 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==2){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==3){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==4){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else if(a==5 && b==5){
                    rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::BLACK);
                    cout<<(char)219;
                }
                else{
                   rlutil::locate(xini,yini);
                    rlutil::setColor(rlutil::COLOR::WHITE);
                    cout<<(char)219;
                }
                xini++;
            }
        xini=xin;
        yini=yini+1;
        }
    break;
        }
    }

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}

void dados(int vd[]){
    cargarAleatorio(vd, 5, 6);
    valordados(33,14,vd, 0);
    valordados(53,27,vd, 1);
    valordados(73,14,vd, 2);
    valordados(93,27,vd, 3);
    valordados(113,14,vd, 4);
}

void dadosinicio(int vd[]){
    cargarAleatorio(vd, 5, 6);
    valordados(33,20,vd, 0);
    valordados(53,33,vd, 1);
    valordados(73,20,vd, 2);
    valordados(93,33,vd, 3);
    valordados(113,20,vd, 4);
}

char nombrej1(char jugador1[],int tam){

    cout<<"Ingrese nombre del jugador : "<<endl;
    rlutil::locate(81,16);
    cin>>jugador1;
    cout<<endl;

}

int introjuego1(int op, char jugador1[], int ronytir[]){

    int c=0, rondas, tiradas;

        for(int i=1;i<=4;i++){

        system("cls");
        rlutil::locate(70,6);
        rlutil::setColor(10);
        cout<<char(173)<<"Bienvenido al modo 1 jugador!"<<endl;
            if(c==0){
                c++;
                rlutil::locate(72,14);
                rlutil::setColor(15);
                nombrej1(jugador1,21);
                PlaySound(TEXT("enter.wav"),NULL,SND_ASYNC);
            }
            else if(c==1){
                c++;
                rlutil::locate(70,14);
                rlutil::setColor(15);
                cout<<"Ingrese la cantidad de rondas: ";
                cin>>rondas;
                ronytir[0]=rondas;
                PlaySound(TEXT("enter.wav"),NULL,SND_ASYNC);
            }
            else if(c==2){
                c++;
                rlutil::locate(70,14);
                rlutil::setColor(15);
                cout<<"Ingrese la cantidad de tiradas: ";
                cin>>tiradas;
                ronytir[1]=tiradas;
                PlaySound(TEXT("enter.wav"),NULL,SND_ASYNC);
            }
            else if(c==3){
                rlutil::locate(68,16);
                rlutil::setColor(15);
                system("pause");
                rlutil::cls();
                op=0;
            }
        }

return op;
}

int interfazjuego1(int op, char jugador1[], int ronytir[], int puntajesv[], int tiradasv[]){

    int puntostotal=0;
    int puntparcial=0;
    int tiradas=0;
    int vdjuego1[5];
    int ubi2=1, x=0, b1=0, b2=0, b3=0, b4=0, b5=0;
    int vectorcombinaciones[10];
    int vpuntajeindividual[10];
    int vectordiscomb[10];
    ponerCero(vectordiscomb, 10);
    int ny=0;
    int bys=0;
    int vectordadosanalizables[5];
    ponerCero(vectordadosanalizables, 5);
    int contdispo=0;
    int generalaservida=0;

    for(int i=1;i<=ronytir[0];i++){


    int seleccionados[5];
    ponerCero(seleccionados, 5);

    system("cls");
    rlutil::locate(33,2);
    cout<<"Turno de ";
    cout<<jugador1;
    rlutil::locate(33,3);
    cout<<"Ronda N"<<char(167)<<i;
    rlutil::locate(120,2);
    cout<<"Puntaje total ";
    rlutil::locate(121,3);
    cout<<puntostotal<<"  puntos";
    rlutil::locate(32,4);
    cout<<"------------------------------------------------------------------------------------------------------";

        puntparcial=0;

        int j=1;

        if(contdispo==9){
            i=ronytir[0];
        }

        do{

            ubi2=1;
            tiradas++;


    rlutil::locate(33,5);
    cout<<"Tirada N"<<char(167)<<j;
    rlutil::locate(114,5);
    cout<<"Tiradas totales: "<<tiradas;
    rlutil::locate(32,6);
    cout<<"------------------------------------------------------------------------------------------------------";
    rlutil::locate(33,7);
    cout<<"Presione Enter para seleccionar si desea MANTENER o CAMBIAR el dado.";

    rlutil::locate(33,9);
    rlutil::setColor(12);
    cout<<char(219);
    rlutil::locate(34,9);
    rlutil::setColor(12);
    cout<<char(219);
    rlutil::locate(36,9);
    rlutil::setColor(15);
    cout<<"El color rojo significa CAMBIAR.";

    rlutil::locate(33,11);
    rlutil::setColor(10);
    cout<<char(219);
    rlutil::locate(34,11);
    rlutil::setColor(10);
    cout<<char(219);
    rlutil::locate(36,11);
    rlutil::setColor(15);
    cout<<"El color verde significa MANTENER.";

    rlutil::locate(12,25);
    rlutil::setColor(15);
    cout<<"CONTROLES";
    rlutil::locate(14,27);
    cout<<char(17);
    rlutil::locate(15,27);
    cout<<" Y ";
    rlutil::locate(18,27);
    cout<<char(16);
    rlutil::locate(4,28);
    cout<<"Desplazamiento entre dados";
    rlutil::locate(14,30);
    cout<<char(30);
    rlutil::locate(15,30);
    cout<<" Y ";
    rlutil::locate(18,30);
    cout<<char(31);
    rlutil::locate(10,31);
    cout<<"Desplazamiento";
    rlutil::locate(7,32);
    cout<<"entre combinaciones";



    if(j==1){
        dados(vdjuego1);

        for(int p=0;p<=4;p++){

            vectordadosanalizables[p]=vdjuego1[p];
        }
    }
    else{

        cargarAleatorio(vdjuego1, 5, 6);

        for(int h=0;h<=4;h++){

            if(seleccionados[h]==1){

                switch (h)
                {
                case 0:
                    valordados(33,14,vdjuego1, 0);
                    vectordadosanalizables[0]=vdjuego1[0];
                    break;
                case 1:
                    valordados(53,27,vdjuego1, 1);
                    vectordadosanalizables[1]=vdjuego1[1];
                    break;
                case 2:
                    valordados(73,14,vdjuego1, 2);
                    vectordadosanalizables[2]=vdjuego1[2];
                    break;
                case 3:
                    valordados(93,27,vdjuego1, 3);
                    vectordadosanalizables[3]=vdjuego1[3];
                    break;
                case 4:
                    valordados(113,14,vdjuego1, 4);
                    vectordadosanalizables[4]=vdjuego1[4];
                    break;
                }
            }
        }
    }

        ponerCero(vpuntajeindividual, 10);
        ponerCero(vectorcombinaciones, 10);

        matematica(vectordadosanalizables, vectorcombinaciones, vpuntajeindividual);


    do{
        status(x);

        rlutil::locate(137,25);
        cout<<"LISTA DE COMBINACIONES"<<endl;

        opcionesjuegos(ny, vectordiscomb, vectorcombinaciones, vpuntajeindividual);

        int key=rlutil::getkey();

            PlaySound(TEXT("mov.wav"),NULL,SND_ASYNC);

            switch(key){
        case 15: ///abajo
            x=97;
            if(bys==0){
                bys=1;
                ny=2;
            }
            else if(ny==11){
                ny+=3;
            }
            else if(ny>=14){
                ny=2;
            }
            else{
                ny++;
            }
            break;
        case 14: ///arriba
            if(ny==2){
                x=0;
                ny=0;
                bys=0;
            }
            else if(ny==14){
               ny-=3;
            }
            else{
                ny--;
            }
            break;
        case 17: ///derecha
            {
            int cd=1;
            if(cd%2!=0){
            ny=ny+13;
            x=x+20;
            }
            else{
            ny=ny-13;
            x=x+20;
            }
            if(x>80){
                ny=0;
                x=0;
            }
            cd++;
            }
            if(x>97){
                bys=0;
                x=0;
                ny=0;
            }
            break;
        case 16: ///izquierda
            {
            int ci=1;
            if(ci%2!=0){
            ny=ny+13;
            x=x-20;
            }
            else{
            ny=ny-13;
            x=x-20;
            }
            if(x<0){
                ny=0;
                x=80;
            }
            ci++;
            }
            if(x==77){
                bys=0;
                x=0;
                ny=0;
            }
            break;
        case 1:
            {
                PlaySound(TEXT("select.wav"),NULL,SND_ASYNC);

            switch(x){
        case 0:
        {
        if(b1==0){
            seleccionados[0]=1;
            b1=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(42,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(43,27);
            cout<<(char)219;
        }
        else{
            seleccionados[0]=0;
            b1=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(42,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(43,27);
            cout<<(char)219;
        }
        }
            break;
        case 20:
        {
        if(b2==0){
            seleccionados[1]=1;
            b2=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(62,40);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(63,40);
            cout<<(char)219;
        }
        else{
            seleccionados[1]=0;
            b2=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(62,40);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(63,40);
            cout<<(char)219;
        }
        }
            break;
        case 40:
        {
        if(b3==0){
            seleccionados[2]=1;
            b3=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(82,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(83,27);
            cout<<(char)219;
        }
        else{
            seleccionados[2]=0;
            b3=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(82,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(83,27);
            cout<<(char)219;
        }
        }
            break;
        case 60:
        {
        if(b4==0){
            seleccionados[3]=1;
            b4=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(102,40);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(103,40);
            cout<<(char)219;
        }
        else{
            seleccionados[3]=0;
            b4=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(102,40);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(103,40);
            cout<<(char)219;
        }
        }
            break;
        case 80:
        {
        if(b5==0){
            seleccionados[4]=1;
            b5=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(122,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(123,27);
            cout<<(char)219;
        }
        else{
            seleccionados[4]=0;
            b5=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(122,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(123,27);
            cout<<(char)219;
        }
        }
            break;
        case 97:
            switch(ny){
            case 2:
                if(vectordiscomb[0]==0){
                    ubi2=0;
                    j=ronytir[1];
                    puntparcial+=vpuntajeindividual[0];
                    vectordiscomb[0]=1;
                    contdispo++;
                }
                break;
            case 3:
                if(vectordiscomb[1]==0){
                    ubi2=0;
                    j=ronytir[1];
                    puntparcial+=vpuntajeindividual[1];
                    vectordiscomb[1]=1;
                    contdispo++;
                }
                break;
            case 4:
                if(vectordiscomb[2]==0){
                    ubi2=0;
                    j=ronytir[1];
                    puntparcial+=vpuntajeindividual[2];
                    vectordiscomb[2]=1;
                    contdispo++;
                }
                break;
            case 5:
                if(vectordiscomb[3]==0){
                    ubi2=0;
                    j=ronytir[1];
                    puntparcial+=vpuntajeindividual[3];
                    vectordiscomb[3]=1;
                    contdispo++;
                }
                break;
            case 6:
                if(vectordiscomb[4]==0){
                    ubi2=0;
                    j=ronytir[1];
                    puntparcial+=vpuntajeindividual[4];
                    vectordiscomb[4]=1;
                    contdispo++;
                }
                break;
            case 7:
                if(vectordiscomb[5]==0){
                    ubi2=0;
                    j=ronytir[1];
                    puntparcial+=vpuntajeindividual[5];
                    vectordiscomb[5]=1;
                    contdispo++;
                }
                break;
            case 8:
                if(vectordiscomb[6]==0){
                    ubi2=0;
                    j=ronytir[1];
                    puntparcial+=vpuntajeindividual[6];
                    vectordiscomb[6]=1;
                    contdispo++;
                }
                break;
            case 9:
                if(vectordiscomb[7]==0){
                    ubi2=0;
                    j=ronytir[1];
                    puntparcial+=vpuntajeindividual[7];
                    vectordiscomb[7]=1;
                    contdispo++;
                }
                break;
            case 10:
                if(vectordiscomb[8]==0){
                    ubi2=0;
                    j=ronytir[1];
                    puntparcial+=vpuntajeindividual[8];
                    vectordiscomb[8]=1;
                    contdispo++;
                }
                break;
            case 11:
                if(vectordiscomb[9]==0){
                    ubi2=0;
                    puntparcial+=vpuntajeindividual[9];
                    vectordiscomb[9]=1;
                    contdispo++;
                    if(j!=1){
                        j=ronytir[1];
                    }
                }
                break;
            case 14:
                if(j==ronytir[1]){
                    ubi2=1;
                    rlutil::locate(133,41);
                    cout<<"Seleccione un juego para continuar";
                }
                else{
                 ubi2=0;
                }
                break;
            }
            break;
        }
            }
            break;
        }


    }while(ubi2!=0);


    if(puntparcial==50 && j==1){

        generalaservida=1;

        if(generalaservida==1){
           puntparcial=123456789;
            i=ronytir[0];
            j=ronytir[1];
        }

    }

        j++;
        bys=0;
        }while(ronytir[1]>=j);
        puntostotal+=puntparcial;
    }

    tiradasv[0]=tiradas;
    puntajesv[0]=puntostotal;

    op=1;

    system("cls");

    PlaySound(TEXT("claps.wav"),NULL,SND_ASYNC);

    rlutil::locate(79,12);
    rlutil::setColor(10);
    cout<<char(173)<<"Fin del juego!";

    rlutil::locate(63,13);
    rlutil::setColor(15);
    cout<<"----------------------------------------------";

    rlutil::locate(64,16);
    cout<<"Jugador 1: "<<jugador1;

    rlutil::locate(64,18);
    cout<<"Cantidad de tiradas: "<<tiradasv[0];

    if(puntajesv[0]>=123456789){
       rlutil::locate(64,20);
        cout<<"Ganador por generala servida";

        puntajesv[0]=123456789;
    }
    else{
       rlutil::locate(64,20);
        cout<<"Puntaje total acumulado: "<<puntajesv[0];
    }

    rlutil::locate(63,23);
    cout<<"----------------------------------------------";

    rlutil::locate(67,24);
    system("pause");
    PlaySound(TEXT("enter.wav"),NULL,SND_ASYNC);
    system("cls");

return op;
}

void mostrarbotonesdejuego(const char* text, int posx, int posy, bool sel){
    if(sel){
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::locate(posx,posy);
            cout<<" "<<(char)175<<"  "<<text;
        }
        else{
            rlutil::setColor(rlutil::COLOR::WHITE);
            rlutil::locate(posx,posy);
            cout<<"    "<<text;
        }
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void status(int x){
    mostrarbotonesdejuego("ESTADO ", 36, 25, x==0);
    mostrarbotonesdejuego("ESTADO ", 56, 38, x==20);
    mostrarbotonesdejuego("ESTADO ", 76, 25, x==40);
    mostrarbotonesdejuego("ESTADO ", 96, 38, x==60);
    mostrarbotonesdejuego("ESTADO ", 116, 25, x==80);
}

void ponerCero(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=0;
    }
}

void matematica(int vd[], int vectorcombinaciones[],int vpuntajeindividual[]){
    int vcn[6], ord, cf=0, b=0, mc, mul, pos, aux, vno[5];
    ponerCero(vcn,6);
    ponerCero(vno,5);
    for(int i=0;i<=4;i++){
        for(int j=1;j<=6;j++){
            if(vd[i]==j){
                vcn[j-1]++;
            }
        }
    }
    for(int i=0;i<=4;i++){
        vno[i]=vd[i];
    }
    for (int h=0;h<=4;h++) {
        pos = h;
        aux = vno[h];
        while (pos>0 && vno[pos-1]>aux) {
            vno[pos] = vno[pos-1];
            pos = pos-1;
        }
        vno[pos] = aux;
    }
    for (int i=0;i<=4;i++) {
        if (i==0) {
            ord = 1;
        } else {
            if (vno[i-1]==vno[i]-1) {
                ord = ord+1;
            }
        }
    }

    for(int i=0;i<=5;i++){
        for(int j=4;j<=5;j++){
            if(vcn[i]==j){
                if(j==4){
                    vectorcombinaciones[8]++;
                    vpuntajeindividual[8]=40;
                }
                else{
                    vectorcombinaciones[9]++;
                    vpuntajeindividual[9]=50;
                }
            }
        }
        if(vcn[i]==2 && b==0){
            cf++;
            b=1;
        }
        else if(vcn[i]==3){
            cf++;
        }
    }
    if(cf==2){
        vectorcombinaciones[7]++;
        vpuntajeindividual[7]=30;
    }
    if(ord==5){
        vectorcombinaciones[6]++;
        vpuntajeindividual[6]=25;
    }
        for(int i=0;i<=5;i++){
                mc=vcn[i];
                mul=i+1;
                vpuntajeindividual[i]=mc*mul;

                if(vpuntajeindividual[i]!=0){

                    vectorcombinaciones[i]++;
                }
        }

}

void opcionesjuegos(int ny, int vectordiscomb[], int vectorcombinaciones[], int vpuntajeindividual[]){

    for(int k=0;k<=9;k++){

           if(vectordiscomb[k]==0){

                if(vectorcombinaciones[k]>0){

                    switch (k)
                    {
                    case 0:

                        mostrarbotonesdejuego("Juego de 1: ",133,27,ny==2);
                        cout<<vpuntajeindividual[0];
                        cout<<" punto/s  ";

                        break;
                    case 1:

                        mostrarbotonesdejuego("Juego de 2: ",133,28,ny==3);
                        cout<<vpuntajeindividual[1];
                        cout<<" puntos  ";

                        break;
                    case 2:

                        mostrarbotonesdejuego("Juego de 3: ",133,29,ny==4);
                        cout<<vpuntajeindividual[2];
                        cout<<" puntos  ";

                        break;
                    case 3:

                        mostrarbotonesdejuego("Juego de 4: ",133,30,ny==5);
                        cout<<vpuntajeindividual[3];
                        cout<<" puntos  ";

                        break;
                    case 4:

                        mostrarbotonesdejuego("Juego de 5: ",133,31,ny==6);
                        cout<<vpuntajeindividual[4];
                        cout<<" puntos  ";

                        break;
                    case 5:

                        mostrarbotonesdejuego("Juego de 6: ",133,32,ny==7);
                        cout<<vpuntajeindividual[5];
                        cout<<" puntos  ";

                        break;
                    case 6:

                        mostrarbotonesdejuego("Escalera: ",133,33,ny==8);
                        cout<<"25 puntos";

                        break;
                    case 7:

                        mostrarbotonesdejuego("Full: ",133,34,ny==9);
                        cout<<"30 puntos";

                        break;
                    case 8:

                        mostrarbotonesdejuego("Poker: ",133,35,ny==10);
                        cout<<"40 puntos";

                        break;
                    case 9:

                        mostrarbotonesdejuego("Generala: ",133,36,ny==11);
                        cout<<"50 puntos";

                        break;
                    }
                }
                else{

                    switch (k)
                    {
                    case 0:

                        mostrarbotonesdejuego("Juego de 1: ",133,27,ny==2);
                        cout<<"0 puntos  ";

                        break;
                    case 1:

                        mostrarbotonesdejuego("Juego de 2: ",133,28,ny==3);
                        cout<<"0 puntos  ";

                        break;
                    case 2:

                        mostrarbotonesdejuego("Juego de 3: ",133,29,ny==4);
                        cout<<"0 puntos  ";

                        break;
                    case 3:

                        mostrarbotonesdejuego("Juego de 4: ",133,30,ny==5);
                        cout<<"0 puntos  ";

                        break;
                    case 4:

                        mostrarbotonesdejuego("Juego de 5: ",133,31,ny==6);
                        cout<<"0 puntos  ";

                        break;
                    case 5:

                        mostrarbotonesdejuego("Juego de 6: ",133,32,ny==7);
                        cout<<"0 puntos  ";

                        break;
                    case 6:

                        mostrarbotonesdejuego("Escalera: ",133,33,ny==8);
                        cout<<"0 puntos  ";

                        break;
                    case 7:

                        mostrarbotonesdejuego("Full: ",133,34,ny==9);
                        cout<<"0 puntos  ";

                        break;
                    case 8:

                        mostrarbotonesdejuego("Poker: ",133,35,ny==10);
                        cout<<"0 puntos  ";

                        break;
                    case 9:

                        mostrarbotonesdejuego("Generala: ",133,36,ny==11);
                        cout<<"0 puntos  ";

                        break;
                    }
                }
            }
            else{

                switch (k)
                    {
                    case 0:

                        mostrarbotonesdejuego("Juego de 1 ya seleccionado",133,27,ny==2);

                        break;
                    case 1:

                        mostrarbotonesdejuego("Juego de 2 ya seleccionado",133,28,ny==3);

                        break;
                    case 2:

                        mostrarbotonesdejuego("Juego de 3 ya seleccionado",133,29,ny==4);

                        break;
                    case 3:

                        mostrarbotonesdejuego("Juego de 4 ya seleccionado",133,30,ny==5);

                        break;
                    case 4:

                        mostrarbotonesdejuego("Juego de 5 ya seleccionado",133,31,ny==6);

                        break;
                    case 5:

                        mostrarbotonesdejuego("Juego de 6 ya seleccionado",133,32,ny==7);

                        break;
                    case 6:

                        mostrarbotonesdejuego("Escalera ya seleccionada",133,33,ny==8);

                        break;
                    case 7:

                        mostrarbotonesdejuego("Full ya seleccionado",133,34,ny==9);

                        break;
                    case 8:

                        mostrarbotonesdejuego("Poker ya seleccionado",133,35,ny==10);

                        break;
                    case 9:

                        mostrarbotonesdejuego("Generala ya seleccionada",133,36,ny==11);

                        break;
                    }
            }
        }

        mostrarbotonesdejuego("VOLVER A TIRAR",133,39,ny==14);
}

int introjuego2(int op, char jugador1[], char jugador2[], int ronytir[]){

    int c=0, rondas, tiradas;

        for(int i=1;i<=4;i++){

        system("cls");
        rlutil::locate(69,6);
        rlutil::setColor(10);
        cout<<char(173)<<"Bienvenido al modo de 2 jugadores!"<<endl;
            if(c==0){
                c++;
                rlutil::locate(73,14);
                rlutil::setColor(15);
                nombrej2(jugador1,21);
                PlaySound(TEXT("enter.wav"),NULL,SND_ASYNC);
            }
            else if(c==1){
                c++;
                rlutil::locate(73,14);
                rlutil::setColor(15);
                nombrej2(jugador2,21);
                PlaySound(TEXT("enter.wav"),NULL,SND_ASYNC);
            }
            else if(c==2){
                c++;
                rlutil::locate(71,14);
                rlutil::setColor(15);
                cout<<"Ingrese la cantidad de rondas: ";
                cin>>rondas;
                ronytir[0]=rondas;
                PlaySound(TEXT("enter.wav"),NULL,SND_ASYNC);
            }
            else if(c==3){
                c++;
                rlutil::locate(71,14);
                rlutil::setColor(15);
                cout<<"Ingrese la cantidad de tiradas: ";
                cin>>tiradas;
                ronytir[1]=tiradas;
                PlaySound(TEXT("enter.wav"),NULL,SND_ASYNC);
            }
            else if(c==4){
                rlutil::locate(68,16);
                rlutil::setColor(15);
                system("pause");
                rlutil::cls();
                op=0;
            }
        }

return op;
}

int interfazjuego2(int op, char jugador1[], char jugador2[], int ronytir[], int puntajesv[], int tiradasv[]){

    int puntostotalj[2];
    ponerCero(puntostotalj, 2);
    int puntparcial[2];
    ponerCero(puntparcial, 2);
    int tiradasj[2];
    ponerCero(tiradasj, 2);
    int vdjuego1[5];
    int vdjuego2[5];
    int ubi1=1, ubi2=1, x=0, b1=0, b2=0, b3=0, b4=0, b5=0;
    int f1=0, f2=0, f3=0, f4=0, f5=0;
    int vectorcombinaciones1[10];
    int vectorcombinaciones2[10];
    int vpuntajeindividual1[10];
    int vpuntajeindividual2[10];
    int vectordiscomb1[10];
    int vectordiscomb2[10];
    ponerCero(vectordiscomb1, 10);
    ponerCero(vectordiscomb2, 10);
    int ny=0;
    int bys1=0;
    int bys2=0;
    int vectordadosanalizables1[5];
    int vectordadosanalizables2[5];
    ponerCero(vectordadosanalizables1, 5);
    ponerCero(vectordadosanalizables2, 5);
    int contdispo1=0;
    int contdispo2=0;
    int gservida[2];
    ponerCero(gservida, 2);
    int cuentags=0;

    int turno=1;

    for(int i=1;i<=ronytir[0];i++){

    int seleccionados[5];
    ponerCero(seleccionados, 5);
    ponerCero(puntparcial, 2);

    system("cls");

    int j1=1;
    int j2=1;


        if(contdispo2==9){
        i=ronytir[0];
        }

    do
    {
       rlutil::locate(33,2);
        cout<<"Turno de ";
        cout<<jugador1;
        rlutil::locate(33,3);
        cout<<"Ronda N"<<char(167)<<i;
        rlutil::locate(120,2);
        cout<<"Puntaje total ";
        rlutil::locate(121,3);
        cout<<puntostotalj[0]<<"  puntos";

        rlutil::locate(32,4);
        cout<<"------------------------------------------------------------------------------------------------------";

        do{

            ubi1=1;
            tiradasj[0]++;


    rlutil::locate(33,5);
    cout<<"Tirada N"<<char(167)<<j1;
    rlutil::locate(114,5);
    cout<<"Tiradas totales: "<<tiradasj[0];
    rlutil::locate(32,6);
    cout<<"------------------------------------------------------------------------------------------------------";
    rlutil::locate(33,7);
    cout<<"Presione Enter para seleccionar si desea MANTENER o CAMBIAR el dado.";

    rlutil::locate(33,9);
    rlutil::setColor(12);
    cout<<char(219);
    rlutil::locate(34,9);
    rlutil::setColor(12);
    cout<<char(219);
    rlutil::locate(36,9);
    rlutil::setColor(15);
    cout<<"El color rojo significa CAMBIAR.";

    rlutil::locate(33,11);
    rlutil::setColor(10);
    cout<<char(219);
    rlutil::locate(34,11);
    rlutil::setColor(10);
    cout<<char(219);
    rlutil::locate(36,11);
    rlutil::setColor(15);
    cout<<"El color verde significa MANTENER.";

    rlutil::locate(12,25);
    rlutil::setColor(15);
    cout<<"CONTROLES";
    rlutil::locate(14,27);
    cout<<char(17);
    rlutil::locate(15,27);
    cout<<" Y ";
    rlutil::locate(18,27);
    cout<<char(16);
    rlutil::locate(4,28);
    cout<<"Desplazamiento entre dados";
    rlutil::locate(14,30);
    cout<<char(30);
    rlutil::locate(15,30);
    cout<<" Y ";
    rlutil::locate(18,30);
    cout<<char(31);
    rlutil::locate(10,31);
    cout<<"Desplazamiento";
    rlutil::locate(7,32);
    cout<<"entre combinaciones";



    if(j1==1){
        dados(vdjuego1);

        for(int p=0;p<=4;p++){

            vectordadosanalizables1[p]=vdjuego1[p];
        }
    }
    else{

        cargarAleatorio(vdjuego1, 5, 6);

        for(int h=0;h<=4;h++){

            if(seleccionados[h]==1){

                switch (h)
                {
                case 0:
                    valordados(33,14,vdjuego1, 0);
                    vectordadosanalizables1[0]=vdjuego1[0];
                    break;
                case 1:
                    valordados(53,27,vdjuego1, 1);
                    vectordadosanalizables1[1]=vdjuego1[1];
                    break;
                case 2:
                    valordados(73,14,vdjuego1, 2);
                    vectordadosanalizables1[2]=vdjuego1[2];
                    break;
                case 3:
                    valordados(93,27,vdjuego1, 3);
                    vectordadosanalizables1[3]=vdjuego1[3];
                    break;
                case 4:
                    valordados(113,14,vdjuego1, 4);
                    vectordadosanalizables1[4]=vdjuego1[4];
                    break;
                }
            }
        }
    }

        ponerCero(vpuntajeindividual1, 10);
        ponerCero(vectorcombinaciones1, 10);

        matematica(vectordadosanalizables1, vectorcombinaciones1, vpuntajeindividual1);


    do{
        status(x);

        rlutil::locate(137,25);
        cout<<"LISTA DE COMBINACIONES"<<endl;

        opcionesjuegos(ny, vectordiscomb1, vectorcombinaciones1, vpuntajeindividual1);

        int key=rlutil::getkey();

            PlaySound(TEXT("mov.wav"),NULL,SND_ASYNC);

            switch(key){
        case 15: ///abajo
            x=97;
            if(bys1==0){
                bys1=1;
                ny=2;
            }
            else if(ny==11){
                ny+=3;
            }
            else if(ny>=14){
                ny=2;
            }
            else{
                ny++;
            }
            break;
        case 14: ///arriba
            if(ny==2){
                x=0;
                ny=0;
                bys1=0;
            }
            else if(ny==14){
               ny-=3;
            }
            else{
                ny--;
            }
            break;
        case 17: ///derecha
            {
            int cd=1;
            if(cd%2!=0){
            ny=ny+13;
            x=x+20;
            }
            else{
            ny=ny-13;
            x=x+20;
            }
            if(x>80){
                ny=0;
                x=0;
            }
            cd++;
            }
            if(x>97){
                bys1=0;
                x=0;
                ny=0;
            }
            break;
        case 16: ///izquierda
            {
            int ci=1;
            if(ci%2!=0){
            ny=ny+13;
            x=x-20;
            }
            else{
            ny=ny-13;
            x=x-20;
            }
            if(x<0){
                ny=0;
                x=80;
            }
            ci++;
            }
            if(x==77){
                bys1=0;
                x=0;
                ny=0;
            }
            break;
        case 1:
            {
                PlaySound(TEXT("select.wav"),NULL,SND_ASYNC);

            switch(x){
        case 0:
        {
        if(b1==0){
            seleccionados[0]=1;
            b1=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(42,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(43,27);
            cout<<(char)219;
        }
        else{
            seleccionados[0]=0;
            b1=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(42,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(43,27);
            cout<<(char)219;
        }
        }
            break;
        case 20:
        {
        if(b2==0){
            seleccionados[1]=1;
            b2=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(62,40);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(63,40);
            cout<<(char)219;
        }
        else{
            seleccionados[1]=0;
            b2=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(62,40);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(63,40);
            cout<<(char)219;
        }
        }
            break;
        case 40:
        {
        if(b3==0){
            seleccionados[2]=1;
            b3=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(82,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(83,27);
            cout<<(char)219;
        }
        else{
            seleccionados[2]=0;
            b3=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(82,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(83,27);
            cout<<(char)219;
        }
        }
            break;
        case 60:
        {
        if(b4==0){
            seleccionados[3]=1;
            b4=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(102,40);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(103,40);
            cout<<(char)219;
        }
        else{
            seleccionados[3]=0;
            b4=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(102,40);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(103,40);
            cout<<(char)219;
        }
        }
            break;
        case 80:
        {
        if(b5==0){
            seleccionados[4]=1;
            b5=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(122,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(123,27);
            cout<<(char)219;
        }
        else{
            seleccionados[4]=0;
            b5=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(122,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(123,27);
            cout<<(char)219;
        }
        }
            break;
        case 97:
            switch(ny){
            case 2:
                if(vectordiscomb1[0]==0){
                    ubi1=0;
                    j1=ronytir[1];
                    puntparcial[0]+=vpuntajeindividual1[0];
                    vectordiscomb1[0]=1;
                    contdispo1++;
                }
                break;
            case 3:
                if(vectordiscomb1[1]==0){
                    ubi1=0;
                    j1=ronytir[1];
                    puntparcial[0]+=vpuntajeindividual1[1];
                    vectordiscomb1[1]=1;
                    contdispo1++;
                }
                break;
            case 4:
                if(vectordiscomb1[2]==0){
                    ubi1=0;
                    j1=ronytir[1];
                    puntparcial[0]+=vpuntajeindividual1[2];
                    vectordiscomb1[2]=1;
                    contdispo1++;
                }
                break;
            case 5:
                if(vectordiscomb1[3]==0){
                    ubi1=0;
                    j1=ronytir[1];
                    puntparcial[0]+=vpuntajeindividual1[3];
                    vectordiscomb1[3]=1;
                    contdispo1++;
                }
                break;
            case 6:
                if(vectordiscomb1[4]==0){
                    ubi1=0;
                    j1=ronytir[1];
                    puntparcial[0]+=vpuntajeindividual1[4];
                    vectordiscomb1[4]=1;
                    contdispo1++;
                }
                break;
            case 7:
                if(vectordiscomb1[5]==0){
                    ubi1=0;
                    j1=ronytir[1];
                    puntparcial[0]+=vpuntajeindividual1[5];
                    vectordiscomb1[5]=1;
                    contdispo1++;
                }
                break;
            case 8:
                if(vectordiscomb1[6]==0){
                    ubi1=0;
                    j1=ronytir[1];
                    puntparcial[0]+=vpuntajeindividual1[6];
                    vectordiscomb1[6]=1;
                    contdispo1++;
                }
                break;
            case 9:
                if(vectordiscomb1[7]==0){
                    ubi1=0;
                    j1=ronytir[1];
                    puntparcial[0]+=vpuntajeindividual1[7];
                    vectordiscomb1[7]=1;
                    contdispo1++;
                }
                break;
            case 10:
                if(vectordiscomb1[8]==0){
                    ubi1=0;
                    j1=ronytir[1];
                    puntparcial[0]+=vpuntajeindividual1[8];
                    vectordiscomb1[8]=1;
                    contdispo1++;
                }
                break;
            case 11:
                if(vectordiscomb1[9]==0){
                    ubi1=0;
                    puntparcial[0]+=vpuntajeindividual1[9];
                    vectordiscomb1[9]=1;
                    contdispo1++;
                    if(j1!=1){
                        j1=ronytir[1];
                    }
                }
                break;
            case 14:
                if(j1==ronytir[1]){
                    ubi1=1;
                    rlutil::locate(133,41);
                    cout<<"Seleccione un juego para continuar";
                }
                else{
                 ubi1=0;
                }
                break;
            }
            break;
        }
            }
            break;
        }


    }while(ubi1!=0);

        if(puntparcial[0]==50 && j1==1){
        gservida[0]=1;
        j1=ronytir[1];
        }

        j1++;
        bys1=0;
        }while(ronytir[1]>=j1);

        turno=2;

    }while(turno!=2);

    /////////////////FIN DEL TURNO JUGADOR 1


    ponerCero(seleccionados, 5);
    x=0;
    ny=0;
    system("cls");

    puntostotalj[0]+=puntparcial[0];


    pantallaturnos(i, jugador2, jugador1, jugador2, tiradasj, 1, puntostotalj);

    system("cls");

    do
    {
       rlutil::locate(33,2);
        cout<<"Turno de ";
        cout<<jugador2;
        rlutil::locate(33,3);
        cout<<"Ronda N"<<char(167)<<i;
        rlutil::locate(120,2);
        cout<<"Puntaje total ";
        rlutil::locate(121,3);
        cout<<puntostotalj[1]<<"  puntos";

        rlutil::locate(32,4);
        cout<<"------------------------------------------------------------------------------------------------------";

        do{

            ubi2=1;
            tiradasj[1]++;


    rlutil::locate(33,5);
    cout<<"Tirada N"<<char(167)<<j2;
    rlutil::locate(114,5);
    cout<<"Tiradas totales: "<<tiradasj[1];
    rlutil::locate(32,6);
    cout<<"------------------------------------------------------------------------------------------------------";
    rlutil::locate(33,7);
    cout<<"Presione Enter para seleccionar si desea MANTENER o CAMBIAR el dado.";

    rlutil::locate(33,9);
    rlutil::setColor(12);
    cout<<char(219);
    rlutil::locate(34,9);
    rlutil::setColor(12);
    cout<<char(219);
    rlutil::locate(36,9);
    rlutil::setColor(15);
    cout<<"El color rojo significa CAMBIAR.";

    rlutil::locate(33,11);
    rlutil::setColor(10);
    cout<<char(219);
    rlutil::locate(34,11);
    rlutil::setColor(10);
    cout<<char(219);
    rlutil::locate(36,11);
    rlutil::setColor(15);
    cout<<"El color verde significa MANTENER.";

    rlutil::locate(12,25);
    rlutil::setColor(15);
    cout<<"CONTROLES";
    rlutil::locate(14,27);
    cout<<char(17);
    rlutil::locate(15,27);
    cout<<" Y ";
    rlutil::locate(18,27);
    cout<<char(16);
    rlutil::locate(4,28);
    cout<<"Desplazamiento entre dados";
    rlutil::locate(14,30);
    cout<<char(30);
    rlutil::locate(15,30);
    cout<<" Y ";
    rlutil::locate(18,30);
    cout<<char(31);
    rlutil::locate(10,31);
    cout<<"Desplazamiento";
    rlutil::locate(7,32);
    cout<<"entre combinaciones";



    if(j2==1){
        dados(vdjuego2);

        for(int p=0;p<=4;p++){

            vectordadosanalizables2[p]=vdjuego2[p];
        }
    }
    else{

        cargarAleatorio(vdjuego2, 5, 6);

        for(int h=0;h<=4;h++){

            if(seleccionados[h]==1){

                switch (h)
                {
                case 0:
                    valordados(33,14,vdjuego2, 0);
                    vectordadosanalizables2[0]=vdjuego2[0];
                    break;
                case 1:
                    valordados(53,27,vdjuego2, 1);
                    vectordadosanalizables2[1]=vdjuego2[1];
                    break;
                case 2:
                    valordados(73,14,vdjuego2, 2);
                    vectordadosanalizables2[2]=vdjuego2[2];
                    break;
                case 3:
                    valordados(93,27,vdjuego2, 3);
                    vectordadosanalizables2[3]=vdjuego2[3];
                    break;
                case 4:
                    valordados(113,14,vdjuego2, 4);
                    vectordadosanalizables2[4]=vdjuego2[4];
                    break;
                }
            }
        }
    }

        ponerCero(vpuntajeindividual2, 10);
        ponerCero(vectorcombinaciones2, 10);

        matematica(vectordadosanalizables2, vectorcombinaciones2, vpuntajeindividual2);


    do{
        status(x);

        rlutil::locate(137,25);
        cout<<"LISTA DE COMBINACIONES"<<endl;

        opcionesjuegos(ny, vectordiscomb2, vectorcombinaciones2, vpuntajeindividual2);

        int key=rlutil::getkey();

            PlaySound(TEXT("mov.wav"),NULL,SND_ASYNC);

            switch(key){
        case 15: ///abajo
            x=97;
            if(bys2==0){
                bys2=1;
                ny=2;
            }
            else if(ny==11){
                ny+=3;
            }
            else if(ny>=14){
                ny=2;
            }
            else{
                ny++;
            }
            break;
        case 14: ///arriba
            if(ny==2){
                x=0;
                ny=0;
                bys2=0;
            }
            else if(ny==14){
               ny-=3;
            }
            else{
                ny--;
            }
            break;
        case 17: ///derecha
            {
            int cd=1;
            if(cd%2!=0){
            ny=ny+13;
            x=x+20;
            }
            else{
            ny=ny-13;
            x=x+20;
            }
            if(x>80){
                ny=0;
                x=0;
            }
            cd++;
            }
            if(x>97){
                bys2=0;
                x=0;
                ny=0;
            }
            break;
        case 16: ///izquierda
            {
            int ci=1;
            if(ci%2!=0){
            ny=ny+13;
            x=x-20;
            }
            else{
            ny=ny-13;
            x=x-20;
            }
            if(x<0){
                ny=0;
                x=80;
            }
            ci++;
            }
            if(x==77){
                bys2=0;
                x=0;
                ny=0;
            }
            break;
        case 1:
            {
                PlaySound(TEXT("select.wav"),NULL,SND_ASYNC);

            switch(x){
        case 0:
        {
        if(f1==0){
            seleccionados[0]=1;
            f1=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(42,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(43,27);
            cout<<(char)219;
        }
        else{
            seleccionados[0]=0;
            f1=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(42,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(43,27);
            cout<<(char)219;
        }
        }
            break;
        case 20:
        {
        if(f2==0){
            seleccionados[1]=1;
            f2=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(62,40);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(63,40);
            cout<<(char)219;
        }
        else{
            seleccionados[1]=0;
            f2=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(62,40);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(63,40);
            cout<<(char)219;
        }
        }
            break;
        case 40:
        {
        if(f3==0){
            seleccionados[2]=1;
            f3=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(82,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(83,27);
            cout<<(char)219;
        }
        else{
            seleccionados[2]=0;
            f3=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(82,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(83,27);
            cout<<(char)219;
        }
        }
            break;
        case 60:
        {
        if(f4==0){
            seleccionados[3]=1;
            f4=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(102,40);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(103,40);
            cout<<(char)219;
        }
        else{
            seleccionados[3]=0;
            f4=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(102,40);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(103,40);
            cout<<(char)219;
        }
        }
            break;
        case 80:
        {
        if(f5==0){
            seleccionados[4]=1;
            f5=1;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(122,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTRED);
            rlutil::locate(123,27);
            cout<<(char)219;
        }
        else{
            seleccionados[4]=0;
            f5=0;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(122,27);
            cout<<(char)219;
            rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
            rlutil::locate(123,27);
            cout<<(char)219;
        }
        }
            break;
        case 97:
            switch(ny){
            case 2:
                if(vectordiscomb2[0]==0){
                    ubi2=0;
                    j2=ronytir[1];
                    puntparcial[1]+=vpuntajeindividual2[0];
                    vectordiscomb2[0]=1;
                    contdispo2++;
                }
                break;
            case 3:
                if(vectordiscomb2[1]==0){
                    ubi2=0;
                    j2=ronytir[1];
                    puntparcial[1]+=vpuntajeindividual2[1];
                    vectordiscomb2[1]=1;
                    contdispo2++;
                }
                break;
            case 4:
                if(vectordiscomb2[2]==0){
                    ubi2=0;
                    j2=ronytir[1];
                    puntparcial[1]+=vpuntajeindividual2[2];
                    vectordiscomb2[2]=1;
                    contdispo2++;
                }
                break;
            case 5:
                if(vectordiscomb2[3]==0){
                    ubi2=0;
                    j2=ronytir[1];
                    puntparcial[1]+=vpuntajeindividual2[3];
                    vectordiscomb2[3]=1;
                    contdispo2++;
                }
                break;
            case 6:
                if(vectordiscomb2[4]==0){
                    ubi2=0;
                    j2=ronytir[1];
                    puntparcial[1]+=vpuntajeindividual2[4];
                    vectordiscomb2[4]=1;
                    contdispo2++;
                }
                break;
            case 7:
                if(vectordiscomb2[5]==0){
                    ubi2=0;
                    j2=ronytir[1];
                    puntparcial[1]+=vpuntajeindividual2[5];
                    vectordiscomb2[5]=1;
                    contdispo2++;
                }
                break;
            case 8:
                if(vectordiscomb2[6]==0){
                    ubi2=0;
                    j2=ronytir[1];
                    puntparcial[1]+=vpuntajeindividual2[6];
                    vectordiscomb2[6]=1;
                    contdispo2++;
                }
                break;
            case 9:
                if(vectordiscomb2[7]==0){
                    ubi2=0;
                    j2=ronytir[1];
                    puntparcial[1]+=vpuntajeindividual2[7];
                    vectordiscomb2[7]=1;
                    contdispo2++;
                }
                break;
            case 10:
                if(vectordiscomb2[8]==0){
                    ubi2=0;
                    j2=ronytir[1];
                    puntparcial[1]+=vpuntajeindividual2[8];
                    vectordiscomb2[8]=1;
                    contdispo2++;
                }
                break;
            case 11:
                if(vectordiscomb2[9]==0){
                    ubi2=0;
                    puntparcial[1]+=vpuntajeindividual2[9];
                    vectordiscomb2[9]=1;
                    contdispo2++;
                    if(j2!=1){
                        j2=ronytir[1];
                    }
                }
                break;
            case 14:
                if(j2==ronytir[1]){
                    ubi2=1;
                    rlutil::locate(133,41);
                    cout<<"Seleccione un juego para continuar";
                }
                else{
                 ubi2=0;
                }
                break;
            }
            break;
        }
            }
            break;
        }


    }while(ubi2!=0);

        if(puntparcial[1]==50 && j2==1){
        gservida[1]=1;
        j2=ronytir[1];
        }

        j2++;
        bys2=0;
        }while(ronytir[1]>=j2);

        turno=1;

    }while(turno!=1);

    /////////////////FIN DEL TURNO JUGADOR 2


    x=0;
    ny=0;
    system("cls");

    puntostotalj[1]+=puntparcial[1];


    for(int g=0;g<=1;g++){

        if(gservida[g]==1){

            cuentags++;
        }

    }
    if(cuentags==1){
        i=ronytir[0];
    }


    if(i!=ronytir[0]){
        pantallaturnos(i, jugador1, jugador1, jugador2, tiradasj, 0, puntostotalj);
    }
}

    op=1;

    system("cls");

    PlaySound(TEXT("claps.wav"),NULL,SND_ASYNC);

    rlutil::locate(79,12);
    rlutil::setColor(10);
    cout<<char(173)<<"Fin del juego!";

    rlutil::locate(63,13);
    rlutil::setColor(15);
    cout<<"----------------------------------------------";

    if(puntostotalj[0]>puntostotalj[1] && gservida[0]==1){
        rlutil::locate(64,16);
        cout<<"Ganador: "<<jugador1;

        rlutil::locate(64,18);
        cout<<"Cantidad de tiradas: "<<tiradasj[0];

        rlutil::locate(64,20);
        cout<<"Ganador por generala servida";
    }
    else if(puntostotalj[1]>puntostotalj[0] && gservida[1]==1){
        rlutil::locate(64,16);
        cout<<"Ganador: "<<jugador2;

        rlutil::locate(64,18);
        cout<<"Cantidad de tiradas: "<<tiradasj[1];

        rlutil::locate(64,20);
        cout<<"Ganador por generala servida";
    }
    else if(puntostotalj[0]>puntostotalj[1]){
        rlutil::locate(64,16);
        cout<<"Ganador: "<<jugador1;

        rlutil::locate(64,18);
        cout<<"Cantidad de tiradas: "<<tiradasj[0];

        rlutil::locate(64,20);
        cout<<"Puntaje total acumulado: "<<puntostotalj[0];
    }
    else if(puntostotalj[1]>puntostotalj[0]){
        rlutil::locate(64,16);
        cout<<"Ganador: "<<jugador2;

        rlutil::locate(64,18);
        cout<<"Cantidad de tiradas: "<<tiradasj[1];

        rlutil::locate(64,20);
        cout<<"Puntaje total acumulado: "<<puntostotalj[1];
    }
    else if(puntostotalj[0]==puntostotalj[1]){
        rlutil::locate(64,18);
        cout<<"Empataron";

        rlutil::locate(64,16);
        cout<<"Felicitaciones a los dos";

        rlutil::locate(64,20);
        cout<<"Puntaje obtenido por los dos jugadores: "<<puntostotalj[1];
    }

    rlutil::locate(63,23);
    cout<<"----------------------------------------------";

    if(gservida[0]==1 && gservida[1]==0){
        puntostotalj[0]=123456789;
    }
    else if(gservida[1]==1 && gservida[0]==0){
        puntostotalj[1]=123456789;
    }

     for(int p=0;p<=1;p++){
        puntajesv[p]=puntostotalj[p];
        tiradasv[p]=tiradasj[p];
    }


    rlutil::locate(67,24);
    system("pause");
    PlaySound(TEXT("enter.wav"),NULL,SND_ASYNC);
    system("cls");

return op;
}

char nombrej2(char jugador[],int tam){

    cout<<"Ingrese nombre del jugador : "<<endl;
    rlutil::locate(84,16);
    cin>>jugador;
    cout<<endl;

}

void pantallaturnos(int i, char siguiente[], char jugador1[], char jugador2[], int tiradasj[], int ind, int puntostotalj[]){

    rlutil::locate(76,12);\
    rlutil::setColor(10);
    cout<<char(173)<<"Fin del turno!";

    rlutil::locate(63,13);
    rlutil::setColor(15);
    cout<<"-----------------------------------------"<<endl;

    rlutil::locate(64,15);
    cout<<"Ronda N"<<char(167)<<i;
    rlutil::locate(64,16);
    cout<<"Proximo turno: "<<siguiente;
    rlutil::locate(64,17);
    cout<<"Lanzamientos: "<<tiradasj[ind];
    rlutil::locate(64,19);
    cout<<"Puntaje "<<jugador1<<": "<<puntostotalj[0];
    rlutil::locate(64,20);
    cout<<"Puntaje "<<jugador2<<": "<<puntostotalj[1];

    rlutil::locate(63,23);
    rlutil::setColor(15);
    cout<<"-----------------------------------------"<<endl;

    rlutil::locate(64,24);
    system("pause");
    PlaySound(TEXT("enter.wav"),NULL,SND_ASYNC);

}

#endif // FUNCIONES_H_INCLUDED
