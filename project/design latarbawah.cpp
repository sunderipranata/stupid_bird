/*
A SIMPLE GAME
CODED BY SUNDERI PRANATA
UMN - COMPUTER ENGINEERING 2013
STUDENT NUMBER : 13110210010
------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------BACKGROUND(TREE) DESIGN HEADER FILE-------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <conio2.h>
#include <windows.h>

//#define BG 8*15
#define COKLAT 5*15
#define HITAM 0
#define KUNING 15*15
#define MERAHTUA 5*15
#define BG 15*12
#define HIJAUTUA 15*11

using namespace std;

void latarbegin(int x){
    
    gotoxy(x,23);
    textcolor(BG); cout<<" "; textcolor(BG); cout<<" "; textcolor(HIJAUTUA); cout<<" "; textcolor(BG); cout<<"  ";
    gotoxy(x,24);
    textcolor(BG); cout<<" "; textcolor(HIJAUTUA); cout<<" "; textcolor(MERAHTUA); cout<<" "; textcolor(HIJAUTUA); cout<<" "; textcolor(BG); cout<<"  ";
    gotoxy(x,25);
    textcolor(HIJAUTUA); cout<<"  "; textcolor(HIJAUTUA); cout<<"    ";
    x+=5;
}

void latar(int *x){
    
    gotoxy(*x,23);
    textcolor(BG); cout<<" "; textcolor(HIJAUTUA); cout<<" "; textcolor(BG); cout<<"  ";
    gotoxy(*x,24);
    textcolor(HIJAUTUA); cout<<" "; textcolor(MERAHTUA); cout<<" "; textcolor(HIJAUTUA); cout<<" "; textcolor(BG); cout<<"  ";
    gotoxy(*x,25);
    textcolor(HIJAUTUA); cout<<"    ";
    *x+=4;
}

void coverlatar(){
    gotoxy(11,23); textcolor(HIJAUTUA); cout<<" ";
    gotoxy(11,24); textcolor(MERAHTUA); cout<<" "; textcolor(HIJAUTUA); cout<<" "; textcolor(BG); cout<<" "; textcolor(HIJAUTUA); cout<<" ";
    gotoxy(11,25); textcolor(HIJAUTUA); cout<<"    ";
    
}

void drawlatar(){
    int x=9;
    
    latarbegin(x);
    for(int i=0;i<15;i++)
        latar(&x);
        
    gotoxy(1,1);
    //getch();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}
