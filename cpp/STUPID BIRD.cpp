/*
A SIMPLE GAME
CODED BY SUNDERI PRANATA
UMN - COMPUTER ENGINEERING 2013
STUDENT NUMBER : 13110210010
------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------THIS IS THE MAIN PROGRAM-------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <conio2.h>
#include <windows.h>
#include "opening.cpp"
#include "coba11.cpp"
#include "coba12.cpp"
//#include "numberdata.cpp"
#define PUTIH 8*15
#define COKLAT 5*15
#define HITAM 0
#define KUNING 15*15
#define MERAH 13*15
//#define BACKGROUND 7*9
#define HOVER 9*7
#define BG2 
#define BG 15*12

using namespace std;

void drawplay(int BACKGROUND){
    bool P[6][5]={0,1,1,1,0,
                  0,1,0,1,0,
                  0,1,1,1,0,
                  0,1,0,0,0,
                  0,1,0,0,0,
                  0,0,0,0,0};
    bool L[6][4]={1,0,0,0,
                  1,0,0,0,
                  1,0,0,0,
                  1,0,0,0,
                  1,1,1,0,
                  0,0,0,0};
    bool A[6][4]={1,1,1,0,
                  1,0,1,0,
                  1,1,1,0,
                  1,0,1,0,
                  1,0,1,0,
                  0,0,0,0};
    bool Y[6][4]={1,0,1,0,
                  1,0,1,0,
                  1,1,1,0,
                  0,1,0,0,
                  0,1,0,0,
                  0,0,0,0};
    bool exclamation[6][2]=
                 {1,0,
                  1,0,
                  1,0,
                  0,0,
                  1,0,
                  0,0};
    
    int i;
    int j;       
    int x=17;
    
    gotoxy(x,5);
    textcolor(BACKGROUND);
    cout<<"                   ";
    
    gotoxy(x,6);
    for (i=0;i<6;i++){
        for(j=0;j<5;j++){
            //cout<<P[i][j];
            if (P[i][j]==1) {textcolor(MERAH); cout<<" ";}
            else {textcolor(BACKGROUND); cout<<" ";}
        }
        gotoxy(x,7+i);
    }
    
    gotoxy(x+=5,6);
    
    for (i=0;i<6;i++){
        for(j=0;j<4;j++){
            if (L[i][j]==1) {textcolor(MERAH); cout<<" ";}
            else {textcolor(BACKGROUND); cout<<" ";}
        }
        gotoxy(x,7+i);
    }
    
    gotoxy(x+=4,6);
    
    for (i=0;i<6;i++){
        for(j=0;j<4;j++){
            if (A[i][j]==1) {textcolor(MERAH); cout<<" ";}
            else {textcolor(BACKGROUND); cout<<" ";}
        }
        gotoxy(x,7+i);
    }
    
    gotoxy(x+=4,6);
    
    for (i=0;i<6;i++){
        for(j=0;j<4;j++){
            if (Y[i][j]==1) {textcolor(MERAH); cout<<" ";}
            else {textcolor(BACKGROUND); cout<<" ";}
        }
        gotoxy(x,7+i);
    }
    
    gotoxy(x+=4,6);
    
    for (i=0;i<6;i++){
        for(j=0;j<2;j++){
            if (exclamation[i][j]==1) {textcolor(MERAH); cout<<" ";}
            else {textcolor(BACKGROUND); cout<<" ";}
        }
        gotoxy(x,7+i);
    }
    gotoxy(19,7+i); cout<<"Get the highest";
    gotoxy(16,8+i); cout<<"SCORE in STUPID BIRD!";
}

void drawpractice(int BACKGROUND){
    bool P[6][5]={0,1,1,1,0,
                  0,1,0,1,0,
                  0,1,1,1,0,
                  0,1,0,0,0,
                  0,1,0,0,0,
                  0,0,0,0,0};
    bool R[6][4]={1,1,1,0,
                  1,0,1,0,
                  1,1,1,0,
                  1,1,0,0,
                  1,0,1,0,
                  0,0,0,0};
    bool A[6][4]={1,1,1,0,
                  1,0,1,0,
                  1,1,1,0,
                  1,0,1,0,
                  1,0,1,0,
                  0,0,0,0};
    bool C[6][4]={1,1,1,0,
                  1,0,0,0,
                  1,0,0,0,
                  1,0,0,0,
                  1,1,1,0,
                  0,0,0,0};
    bool T[6][4]={1,1,1,0,
                  0,1,0,0,
                  0,1,0,0,
                  0,1,0,0,
                  0,1,0,0,
                  0,0,0,0};
    bool I[6][4]={1,1,1,0,
                  0,1,0,0,
                  0,1,0,0,
                  0,1,0,0,
                  1,1,1,0,
                  0,0,0,0};
    bool E[6][4]={1,1,1,0,
                  1,0,0,0,
                  1,1,1,0,
                  1,0,0,0,
                  1,1,1,0,
                  0,0,0,0};
    
    int i;
    int j;       
    int x=43;
    
    gotoxy(x,5);
    textcolor(BACKGROUND);
    cout<<"                                 ";
    
    gotoxy(x,6);
    for (i=0;i<6;i++){
        for(j=0;j<5;j++){
            //cout<<P[i][j];
            if (P[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BACKGROUND); cout<<" ";}
        }
        gotoxy(x,7+i);
    }
    
    gotoxy(x+=5,6);
    
    for (i=0;i<6;i++){
        for(j=0;j<4;j++){
            if (R[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BACKGROUND); cout<<" ";}
        }
        gotoxy(x,7+i);
    }
    
    gotoxy(x+=4,6);
    
    for (i=0;i<6;i++){
        for(j=0;j<4;j++){
            if (A[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BACKGROUND); cout<<" ";}
        }
        gotoxy(x,7+i);
    }
    
    gotoxy(x+=4,6);
    
    for (i=0;i<6;i++){
        for(j=0;j<4;j++){
            if (C[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BACKGROUND); cout<<" ";}
        }
        gotoxy(x,7+i);
    }
    
    gotoxy(x+=4,6);
    
    for (i=0;i<6;i++){
        for(j=0;j<4;j++){
            if (T[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BACKGROUND); cout<<" ";}
        }
        gotoxy(x,7+i);
    }
    
    gotoxy(x+=4,6);
    
    for (i=0;i<6;i++){
        for(j=0;j<4;j++){
            if (I[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BACKGROUND); cout<<" ";}
        }
        gotoxy(x,7+i);
    }
    
    gotoxy(x+=4,6);
    
    for (i=0;i<6;i++){
        for(j=0;j<4;j++){
            if (C[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BACKGROUND); cout<<" ";}
        }
        gotoxy(x,7+i);
    }
    
    gotoxy(x+=4,6);
    
    for (i=0;i<6;i++){
        for(j=0;j<4;j++){
            if (E[i][j]==1) {textcolor(KUNING); cout<<" ";}
            else {textcolor(BACKGROUND); cout<<" ";}
        }
        gotoxy(x,7+i);
    }
    gotoxy(51,7+i); cout<<"Having troubles?";
    gotoxy(48,8+i); cout<<"Practice makes perfect!";
}


void Pilihan(int Pil)
        {    
             if (Pil==1)drawplay(HOVER); else drawplay(BG);
             if (Pil==2)drawpractice(HOVER); else drawpractice(BG);
             textcolor((Pil==3)?HOVER:BG);gotoxy(32,16);cout << "     HIGH SCORE    ";
             textcolor((Pil==4)?HOVER:BG);gotoxy(32,17);cout << "      CREDITS      ";
             textcolor((Pil==5)?HOVER:BG);gotoxy(32,18);cout << "     EXIT GAME     ";
             textcolor(7);
             gotoxy(1,25);
}


void burungup(int x, int y){
    gotoxy(x,y);
    textcolor(BG); cout<<"   "; textcolor(MERAH); cout<<" "; textcolor(BG); cout<<"  ";
    gotoxy(x,y+1);
    textcolor(BG); cout<<" "; textcolor(COKLAT); cout<<"  "; textcolor(PUTIH); cout<<" "; textcolor(HITAM); cout<<" "; textcolor(BG); cout<<" ";
    gotoxy(x,y+2);
    textcolor(BG); cout<<" "; textcolor(COKLAT); cout<<"  "; textcolor(PUTIH); cout<<"  "; textcolor(MERAH); cout<<" ";
    gotoxy(x,y+3);
    textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<"  "; textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<" "; textcolor(MERAH); cout<<" ";
    gotoxy(x,y+4);
    textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<"    "; textcolor(BG); cout<<" ";
    x+=20;
}

void burungdown(int x, int y){
    gotoxy(x,y);
    textcolor(BG); cout<<"   "; textcolor(MERAH); cout<<" "; textcolor(BG); cout<<"  ";
    gotoxy(x,y+1);
    textcolor(BG); cout<<" "; textcolor(KUNING); cout<<"  ";  textcolor(PUTIH); cout<<"  "; textcolor(BG); cout<<" ";
    gotoxy(x,y+2);
    textcolor(BG); cout<<" "; textcolor(COKLAT); cout<<"  "; textcolor(PUTIH); cout<<" "; textcolor(HITAM); cout<<" "; textcolor(MERAH); cout<<" ";
    gotoxy(x,y+3);
    textcolor(MERAH); cout<<" "; textcolor(COKLAT); cout<<"  "; textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<" "; textcolor(MERAH); cout<<" ";
    gotoxy(x,y+4);
    textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<"    "; textcolor(BG); cout<<" ";
    x+=20;
}
      
void drawmenu(){
    int i,j;
    int x=64,y=20;
    int xup=7,yup=24;
    int xdown=13,ydown=22;
    
    textcolor(BG);
    system("cls");
    
    textcolor(HITAM);
    gotoxy(xup,yup); cout<<" "; xup+=10;
    gotoxy(xdown,ydown); cout<<" "; xdown+=10;
    gotoxy(xup,yup); cout<<" "; xup+=10;
    gotoxy(xdown,ydown); cout<<" "; xdown+=10;
    gotoxy(xup,yup); cout<<" "; xup+=10;
    gotoxy(xdown,ydown); cout<<" "; xdown+=10;
    gotoxy(xup,yup); cout<<" "; xup+=10;
    gotoxy(xdown,ydown); cout<<" "; xdown+=10;
    gotoxy(xup,yup); cout<<" "; xup+=10;
    gotoxy(xdown,ydown); cout<<" "; xdown+=9;
    gotoxy(xup,yup); cout<<" "; xup+=10;
    gotoxy(xdown,ydown); cout<<" ";
    burungup(x,y);
    //burungdown(x,y);
    //bordermenu();
  //gotoxy(1,1);
    
}

void Credit()
{
          char *a[17] = {"    Ternyata AKU pun BISA    ",
                         "                             ",
                         "      Ideas & Programmer     ",
                         "   MYSELF - Sunderi Pranata  ",
                         "                             ",
                         "          Thanks To          ",
                         "                             ",
                         "             BRO             ",
                         "   Yustinus Widya Wiratama   ",
                         "                             ",
                         "       My Friends' HELP      ",
                         "    Character Illustrator    ",
                         "    Ivanka Desyra Susanto    ",
                         "                             ",
                         "        Sound Composer       ",
                         "          Erwin Chua         ",
                         "                             "};
          textcolor(BG);
          system("cls");
          gotoxy(49,25);cout << "Press any button to continue...";
          int curr = 18, pos;
          do{
            for(pos=5;pos<=22;pos++){
                gotoxy(28,pos); cout << "                             ";
                gotoxy(28,pos); if((pos-curr)>=0 && (pos-curr)<=17)cout << a[pos-curr];
            }
            curr--;
            Sleep(100);
          }while(!kbhit()&& curr>5);
          gotoxy(1,25);
          getch();
}

void highscore(){
    textcolor(BG);
    system("cls");
    FILE *fin;
    int n;
    fin = fopen("highscore.txt","rw");
    if(fin!=NULL)fscanf(fin,"%d",&n);
    fclose(fin);
    gotoxy(28,4); cout << "HIGHSCORE";
    
    if (n<10){
        switch(n%10){
            case 0: nol(41);     break;
            case 1: satu(41);    break;
            case 2: dua(41);     break;
            case 3: tiga(41);    break;
            case 4: empat(41);   break;
            case 5: lima(41);    break;
            case 6: enam(41);    break;
            case 7: tujuh(41);   break;
            case 8: delapan(41); break;
            case 9: sembilan(41);break;
        }
    }
    else{
        switch(n/10){
            case 0: nol(35);     break;
            case 1: satu(35);    break;
            case 2: dua(35);     break;
            case 3: tiga(35);    break;
            case 4: empat(35);   break;
            case 5: lima(35);    break;
            case 6: enam(35);    break;
            case 7: tujuh(35);   break;
            case 8: delapan(35); break;
            case 9: sembilan(35);break;
        }
        switch(n%10){
            case 0: nol(41);     break;
            case 1: satu(41);    break;
            case 2: dua(41);     break;
            case 3: tiga(41);    break;
            case 4: empat(41);   break;
            case 5: lima(41);    break;
            case 6: enam(41);    break;
            case 7: tujuh(41);   break;
            case 8: delapan(41); break;
            case 9: sembilan(41);break;
        }
    }
    gotoxy(1,1);
    
    getch();
}

int main(){
    int pil=1;
    
    opening();
    fflush(stdin);
    drawmenu();
    
    Pilihan(pil);
    while(1){
        switch(getch()){
            case 72: //up
                if(pil==1||pil==2) {pil=5; break;}
                else{
                        pil--; if(pil==0) pil=5; break;
                    } 
            case 80: //down
                if(pil==1||pil==2) {pil=3; break;}
                else{
                        pil++; if(pil==6) pil=1; break;
                    } 
            case 75: //left
                if(pil==2) pil=1;
                else if(pil==1) pil=2;
                break;
            case 77: //right
                if (pil==1) pil=2;
                else if(pil==2) pil=1;
                break;
            case 13:
                switch(pil){
                    case 1: system("cls"); game(); drawmenu(); break;
                    case 2: system("cls"); practice(); drawmenu(); break;
                    case 3: highscore(); drawmenu();break;
                    case 4: Credit(); drawmenu(); break;
                    case 5: return 0; break;
            }                
        }
        
        Pilihan(pil);
    }
    
}
