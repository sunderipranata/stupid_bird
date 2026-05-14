/*
A SIMPLE GAME
CODED BY SUNDERI PRANATA
UMN - COMPUTER ENGINEERING 2013
STUDENT NUMBER : 13110210010
------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------DEADBIRD HEADER FILE-----------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <conio2.h>
#include <windows.h>


#define PUTIH 8*15
#define COKLAT 5*15
#define HITAM 0
#define KUNING 15*15
#define MERAH 13*15
#define BG 15*12



using namespace std;
void deadbird(int x){ 
    int i,j;
    int deadbird[12][13]={
                    0,0,0,0,0,0,1,1,0,0,0,0,0,
                    0,0,0,0,0,0,1,1,0,0,0,0,0,
                    0,0,2,2,2,2,2,4,5,4,0,0,0,
                    0,0,2,2,2,2,2,5,4,5,0,0,0,
                    0,0,2,2,2,2,2,4,5,4,0,0,0,
                    0,0,2,2,2,2,2,2,2,2,1,1,0,
                    0,0,3,3,3,3,3,1,1,2,1,1,0,
                    0,0,3,3,3,3,3,1,1,2,1,0,0,
                    1,1,3,3,3,3,3,2,2,2,1,1,0,
                    1,1,3,3,3,3,3,2,2,2,1,1,0,
                    1,1,2,3,3,3,2,2,2,2,0,0,0,
                    1,1,2,2,2,2,2,2,2,2,0,0,0};
    gotoxy(x,10);      
    for (i=0;i<12;i++){
        for(j=0;j<13;j++){
            if (deadbird[i][j]==0) {textcolor(BG); cout<<" ";}
            else 
            if (deadbird[i][j]==1) {textcolor(MERAH); cout<<" ";}
            else 
            if (deadbird[i][j]==2) {textcolor(KUNING); cout<<" ";}
            else 
            if (deadbird[i][j]==3) {textcolor(COKLAT); cout<<" ";}
            else 
            if (deadbird[i][j]==4) {textcolor(HITAM); cout<<" ";}
            else 
            if (deadbird[i][j]==5) {textcolor(PUTIH); cout<<" ";}
        }
        gotoxy(x,11+i);
    }
}
