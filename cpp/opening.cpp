/*
A SIMPLE GAME
CODED BY SUNDERI PRANATA
UMN - COMPUTER ENGINEERING 2013
STUDENT NUMBER : 13110210010
------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------OPENING HEADER FILE------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <conio2.h>
#include <windows.h>
#include "judul.cpp"
#define PUTIH 8*15
#define COKLAT 5*15
#define HITAM 0
#define KUNING 15*15
#define MERAH 13*15
#define BG 15*12

using namespace std;

void burungup(int *x, int *y){
    gotoxy(*x,*y);
    textcolor(BG); cout<<"   "; textcolor(MERAH); cout<<" "; textcolor(BG); cout<<"  ";
    gotoxy(*x,*y+1);
    textcolor(BG); cout<<" "; textcolor(COKLAT); cout<<"  "; textcolor(PUTIH); cout<<" "; textcolor(HITAM); cout<<" "; textcolor(BG); cout<<" ";
    gotoxy(*x,*y+2);
    textcolor(BG); cout<<" "; textcolor(COKLAT); cout<<"  "; textcolor(PUTIH); cout<<"  "; textcolor(MERAH); cout<<" ";
    gotoxy(*x,*y+3);
    textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<"  "; textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<" "; textcolor(MERAH); cout<<" ";
    gotoxy(*x,*y+4);
    textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<"    "; textcolor(BG); cout<<" ";
    *x+=20;
}

void burungdown(int *x, int *y){
    gotoxy(*x,*y);
    textcolor(BG); cout<<"   "; textcolor(MERAH); cout<<" "; textcolor(BG); cout<<"  ";
    gotoxy(*x,*y+1);
    textcolor(BG); cout<<" "; textcolor(KUNING); cout<<"  ";  textcolor(PUTIH); cout<<"  "; textcolor(BG); cout<<" ";
    gotoxy(*x,*y+2);
    textcolor(BG); cout<<" "; textcolor(COKLAT); cout<<"  "; textcolor(PUTIH); cout<<" "; textcolor(HITAM); cout<<" "; textcolor(MERAH); cout<<" ";
    gotoxy(*x,*y+3);
    textcolor(MERAH); cout<<" "; textcolor(COKLAT); cout<<"  "; textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<" "; textcolor(MERAH); cout<<" ";
    gotoxy(*x,*y+4);
    textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<"    "; textcolor(BG); cout<<" ";
    *x+=20;
}
      
//void drawbird(){
void opening(){ 
    int i,j;
    int xup=4,yup=20;
    int xdown=15,ydown=15;
    
    textcolor(BG);
    system("cls");
    /*for(i=0;i<25;i++){
        for(j=0;j<79;j++) cout<<" ";
        
        cout<<endl;
    }*/
    
    judul();
    gotoxy(48,25);
    cout<< "Press any key to continue . . .";
    //gotoxy(40,10);
    while(1){
        burungup(&xup,&yup);
        burungdown(&xdown,&ydown);
        burungup(&xup,&yup);
        burungdown(&xdown,&ydown);
        burungup(&xup,&yup);
        burungdown(&xdown,&ydown);
        burungup(&xup,&yup);    
        
        xup=15,yup=15;
        xdown=4,ydown=20;
        
        Sleep(400);
        
        burungdown(&xdown,&ydown);
        burungup(&xup,&yup);
        burungdown(&xdown,&ydown);
        burungup(&xup,&yup);
        burungdown(&xdown,&ydown);
        burungup(&xup,&yup);
        burungdown(&xdown,&ydown);
        
        xup=4,yup=20;
        xdown=15,ydown=15;
        
        Sleep(400);
        if(kbhit()) break;
    }    
    
    
    //getch();    
}
