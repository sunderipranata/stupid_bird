/*
A SIMPLE GAME
CODED BY SUNDERI PRANATA
UMN - COMPUTER ENGINEERING 2013
STUDENT NUMBER : 13110210010
------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------NUMBER HEADER FILE-------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
*/

void nol(int x){ 
    int i,j;
    bool R[5][5]={1,1,1,1,1,
                  1,0,0,0,1,
                  1,0,0,0,1,
                  1,0,0,0,1,
                  1,1,1,1,1};
    gotoxy(x,7);      
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (R[i][j]==1) {textcolor(PUTIH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,8+i);
    }
}
      
void satu(int x){ 
    int i,j;
    bool R[5][5]={0,0,0,0,1,
                  0,0,0,0,1,
                  0,0,0,0,1,
                  0,0,0,0,1,
                  0,0,0,0,1};
    gotoxy(x,7);      
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (R[i][j]==1) {textcolor(PUTIH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,8+i);
    }
}

void dua(int x){ 
    int i,j;
    bool R[5][5]={1,1,1,1,1,
                  0,0,0,0,1,
                  1,1,1,1,1,
                  1,0,0,0,0,
                  1,1,1,1,1};
    gotoxy(x,7);      
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (R[i][j]==1) {textcolor(PUTIH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,8+i);
    }
}

void tiga(int x){ 
    int i,j;
    bool R[5][5]={1,1,1,1,1,
                  0,0,0,0,1,
                  1,1,1,1,1,
                  0,0,0,0,1,
                  1,1,1,1,1};
    gotoxy(x,7);      
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (R[i][j]==1) {textcolor(PUTIH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,8+i);
    }
}

void empat(int x){ 
    int i,j;
    bool R[5][5]={1,0,0,0,1,
                  1,0,0,0,1,
                  1,1,1,1,1,
                  0,0,0,0,1,
                  0,0,0,0,1};
    gotoxy(x,7);      
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (R[i][j]==1) {textcolor(PUTIH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,8+i);
    }
}

void lima(int x){ 
    int i,j;
    bool R[5][5]={1,1,1,1,1,
                  1,0,0,0,0,
                  1,1,1,1,1,
                  0,0,0,0,1,
                  1,1,1,1,1,};
    gotoxy(x,7);      
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (R[i][j]==1) {textcolor(PUTIH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,8+i);
    }
}

void enam(int x){ 
    int i,j;
    bool R[5][5]={1,1,1,1,1,
                  1,0,0,0,0,
                  1,1,1,1,1,
                  1,0,0,0,1,
                  1,1,1,1,1};
    gotoxy(x,7);      
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (R[i][j]==1) {textcolor(PUTIH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,8+i);
    }
}

void tujuh(int x){ 
    int i,j;
    bool R[5][5]={1,1,1,1,1,
                  0,0,0,1,0,
                  0,0,1,0,0,
                  0,0,1,0,0,
                  0,0,1,0,0};
    gotoxy(x,7);      
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (R[i][j]==1) {textcolor(PUTIH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,8+i);
    }
}

void delapan(int x){ 
    int i,j;
    bool R[5][5]={1,1,1,1,1,
                  1,0,0,0,1,
                  1,1,1,1,1,
                  1,0,0,0,1,
                  1,1,1,1,1};
    gotoxy(x,7);      
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (R[i][j]==1) {textcolor(PUTIH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,8+i);
    }
}

void sembilan(int x){ 
    int i,j;
    bool R[5][5]={1,1,1,1,1,
                  1,0,0,0,1,
                  1,1,1,1,1,
                  0,0,0,0,1,
                  1,1,1,1,1};
    gotoxy(x,7);      
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (R[i][j]==1) {textcolor(PUTIH); cout<<" ";}
            else {textcolor(BG); cout<<" ";}
        }
        gotoxy(x,8+i);
    }
}
