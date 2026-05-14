/*
A SIMPLE GAME
CODED BY SUNDERI PRANATA
UMN - COMPUTER ENGINEERING 2013
STUDENT NUMBER : 13110210010
------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------TITLE HEADER FILE--------------------------------------------------------------------
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


      
//void drawbird(){
void judul(){ 
    
    bool S[5][5]={1,1,1,1,1,
                  1,0,0,0,0,
                  1,1,1,1,1,
                  0,0,0,0,1,
                  1,1,1,1,1};
    bool T[5][5]={1,1,1,1,1,
                  0,0,1,0,0,
                  0,0,1,0,0,
                  0,0,1,0,0,
                  0,0,1,0,0};
    bool U[5][5]={1,0,0,0,1,
                  1,0,0,0,1,
                  1,0,0,0,1,
                  1,0,0,0,1,
                  1,1,1,1,1};
    bool P[5][5]={1,1,1,1,1,
                  1,0,0,0,1,
                  1,1,1,1,1,
                  1,0,0,0,0,
                  1,0,0,0,0};
    bool I[5][5]={1,1,1,1,1,
                  0,0,1,0,0,
                  0,0,1,0,0,
                  0,0,1,0,0,
                  1,1,1,1,1};
    bool D[5][5]={1,1,1,1,0,
                  1,0,0,0,1,
                  1,0,0,0,1,
                  1,0,0,0,1,
                  1,1,1,1,0};                            
    bool spasi[3][5]=
                 {0,0,0,
                  0,0,0,
                  0,0,0,
                  0,0,0,
                  0,0,0};
    bool B[5][5]={1,1,1,1,0,
                  1,0,0,0,1,
                  1,1,1,1,0,
                  1,0,0,0,1,
                  1,1,1,1,0};
    bool R[5][5]={1,1,1,1,0,
                  1,0,0,0,1,
                  1,1,1,1,0,
                  1,0,0,1,0,
                  1,0,0,0,1};
    int x=7;
    
    int i;
    int j;
    
    gotoxy(1,1);
    //////////////////////////////////////////////////////////////////////////////////////
    Beep(800,150); Beep(700,100); Beep(600,80); Beep(500,50); Beep(750,80); Beep(850,150); Sleep(1000);
    gotoxy(x,5);
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (S[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,6+i);
    }
    gotoxy(x+=6,5);
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (T[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,6+i);
    }
    gotoxy(x+=6,5);
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (U[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,6+i);
    }
     
    //Sleep(1000);
    //Sleep(1000);
    gotoxy(1,1);
    Beep(550,50); Beep(800,80); Beep(900,150); Beep(600,50); Beep(850,80); 
    gotoxy(x+=6,5);
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (P[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,6+i);
    }
    gotoxy(x+=6,5);
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (I[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,6+i);
    }
    gotoxy(x+=6,5);
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (D[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,6+i);
    }
    
    ///////////////////////////SPACE//////////////////////
    
    //Sleep(500);
    gotoxy(1,1);
    Sleep(500);
    gotoxy(x+=10,5);
    //Sleep(500); 
    //////////////////////////////////////////////////////
    
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (B[i][j]==1) {textcolor(MERAH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,6+i);
    }
    gotoxy(x+=6,5);
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (I[i][j]==1) {textcolor(MERAH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,6+i);
    }
    gotoxy(x+=6,5);
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (R[i][j]==1) {textcolor(MERAH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,6+i);
    }
    gotoxy(x+=6,5);
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (D[i][j]==1) {textcolor(MERAH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,6+i);
    }
    Sleep(1000);
    Beep(950,150); Beep(950,80); Beep(950,80); Beep(950,250);
    gotoxy(1,1);
    Sleep(500);   
}
