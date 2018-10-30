/*
A SIMPLE GAME
CODED BY SUNDERI PRANATA
UMN - COMPUTER ENGINEERING 2013
STUDENT NUMBER : 13110210010
------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------MENU PLAY HEADER FILE----------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <conio2.h>
#include <windows.h>
#include<iomanip>
#include <fstream>  //fstream, ifstream, ofstream
#include <string>   //string, getline()

#include "design latarbawah.cpp"
#include "deadbirddata.cpp"
#include "numberdata.cpp"
#define PUTIH 8*15
#define COKLAT 5*15
#define HITAM 0
#define KUNING 15*15
#define MERAH 13*15
#define BG 15*12
#define HIJAU 3*15
#define HIJAUTUA 15*11

using namespace std;

class Bird{
    private:
        int x;
        int y;
    public:
        Bird(){x=34; y=10;}
        
        void burungup(){
            gotoxy(x+3,y); 
            textcolor(MERAH); cout<<" ";
            gotoxy(x+1,y+1);
            textcolor(COKLAT); cout<<"  "; textcolor(PUTIH); cout<<" "; textcolor(HITAM); cout<<" "; textcolor(BG); cout<<" ";
            gotoxy(x+1,y+2);
            textcolor(COKLAT); cout<<"  "; textcolor(PUTIH); cout<<"  "; textcolor(MERAH); cout<<" ";
            gotoxy(x,y+3);
            textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<"  "; textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<" "; textcolor(MERAH); cout<<" ";
            gotoxy(x,y+4);
            textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<"    ";
        }

        void burungdown(){
            gotoxy(x+3,y);
            textcolor(MERAH); cout<<" ";
            gotoxy(x+1,y+1);
            textcolor(KUNING); cout<<"  ";  textcolor(PUTIH); cout<<"  ";
            gotoxy(x+1,y+2);
            textcolor(COKLAT); cout<<"  "; textcolor(PUTIH); cout<<" "; textcolor(HITAM); cout<<" "; textcolor(MERAH); cout<<" ";
            gotoxy(x,y+3);
            textcolor(MERAH); cout<<" "; textcolor(COKLAT); cout<<"  "; textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<" "; textcolor(MERAH); cout<<" ";
            gotoxy(x,y+4);
            textcolor(MERAH); cout<<" "; textcolor(KUNING); cout<<"    ";
        }
        
        void burunghapus(){
            
            textcolor(BG);
            gotoxy(x+3,y-1);cout<<" ";
            gotoxy(x+1,y);cout<<"    ";
            gotoxy(x+1,y+1);cout<<"     ";
            gotoxy(x,y+2);cout<<"      ";
            gotoxy(x,y+3);cout<<"      ";
            gotoxy(x,y+4);cout<<"     ";
        }
        
        
        
        int get_x_bird(){return x;}
        void set_x_bird(int x){this->x=x;}
        int get_y_bird(){return y;}
        void set_y_bird(int y){this->y=y;}
};

class Obs{
    private:
        int x;
        int y;
        int z;
        int random1;
        int random2;
        int yobsup;
        int yobsdown;
    public:
        Obs(){
            x=68; z=1;
            random1=(rand()%10)+2;
            random2=25-random1-11;
        }
        ~Obs(){}
        void drawobs(){            
            int i;
            textcolor(HIJAU);
            
            
            y=25-random2;
            
            yobsup=random1+1;
            yobsdown=25-random2;
            
            //////////////////////////////////////////
            /////////////ATAS/////////////////////////
            //////////////////////////////////////////
            
            for(i=1;i<=random1;i++){
                gotoxy(x+1,i); cout <<  "      ";
            }    
            gotoxy(x,i);   cout << "        ";
            
            
            //////////////////////////////////////////
            //////////////BAWAH///////////////////////
            //////////////////////////////////////////
            gotoxy(x,y);   cout << "        ";
            for(i=1;i<=random2;i++){
                gotoxy(x+1,y+i); cout <<  "      ";
            }
            gotoxy(1,1);
            
            
        }
        
        void hapusobs(){
            int i;
            
            if (x+8>68) textcolor(0); else 
            textcolor(BG);
            /////////////ATAS////////////////////
            for(i=1;i<=random1;i++){
                gotoxy(x+1,i); cout <<  "       ";
            }    
            gotoxy(x,i);   cout << "         ";
            
            //////////////////////////////////
            //textcolor(15);                  //
            //gotoxy(x,i); cout<<"x";         //
            //gotoxy(1,1); cout<<x<<" "<<i;   //
            //textcolor(BG);                  //
            //////////////////////////////////
            
            
            
            //////////////BAWAH/////////////////  
             
            gotoxy(x,y);   cout << "         ";
            //////////////////////////////////
            //textcolor(15);                  //
            //gotoxy(x,y); cout<<"x";         //
            //gotoxy(1,2); cout<<x<<" "<<y;   //
            //textcolor(BG);                  //
            //////////////////////////////////
            
            if ((x+8)<=69){ 
                for(i=1;i<=random2-1;i++){
                    gotoxy(x+1,y+i); textcolor(BG); cout<<"      ";
                }
                switch(z){
                    case 1: gotoxy(x+6,23); textcolor(HIJAUTUA); cout<<" ";
                            gotoxy(x+6,24); textcolor(MERAHTUA);    cout<<" ";
                            gotoxy(x+6,25); textcolor(HIJAUTUA); cout<<" ";
                            z++;
                            break;
                    case 2: gotoxy(x+6,24); textcolor(HIJAUTUA); cout<<" ";
                            gotoxy(x+6,25); textcolor(HIJAUTUA); cout<<" ";
                            z++;
                            break;
                    case 3: gotoxy(x+6,25); textcolor(HIJAUTUA); cout<<" ";
                            z++;
                            break;
                    case 4: gotoxy(x+6,24); textcolor(HIJAUTUA); cout<<" ";
                            gotoxy(x+6,25); textcolor(HIJAUTUA); cout<<" ";
                            z++;
                            break;
                    case 5: gotoxy(x+6,23); textcolor(HIJAUTUA); cout<<" ";
                            gotoxy(x+6,24); textcolor(MERAHTUA);    cout<<" ";
                            gotoxy(x+6,25); textcolor(HIJAUTUA); cout<<" ";
                            z++;
                            break;
                    case 6: gotoxy(x+6,24); textcolor(HIJAUTUA); cout<<" ";
                            gotoxy(x+6,25); textcolor(HIJAUTUA); cout<<" ";
                            z=3;
                            break;
                }
            }
            else{
                for(i=1;i<=random2;i++){
                    gotoxy(x+1,y+i); textcolor(BG); cout<<"      ";
                }
            }
            gotoxy(1,1);
            
            
            
        }
                        
        int get_x_obs(){return x;}
        void set_x_obs(int x){this->x=x;}
        int get_y_obs(){return y;}
        void set_y_obs(int y){this->y=y;}
        int get_random1(){return random1;}
        int get_random2(){return random2;}
        void set_random1(int x){this->random1=x;}
        void set_random2(int x){this->random2=x;}
        int get_yobsup(){return yobsup;}
        int get_yobsdown(){return yobsdown;}
};

class Game{
    private:
        int score,ctr;
        bool dead;
        Bird burung;
        Obs obs1,obs2; //??
    public:
        Game(){ctr=0;score=0;dead=0;}
        void setBG(){
            textcolor(0);
            for(int j=1;j<=25;j++){
                gotoxy(1,j); cout<<"        ";
                gotoxy(77,j); cout<<"    ";
            }
            textcolor(15); gotoxy(1,8); cout<<"SCORE:"<<endl<<"0";
        }
        
        void drawborder(){
            textcolor(0);
            for(int j=1;j<=25;j++){
                gotoxy(9,j); cout<<"       ";
                gotoxy(68,j); cout<<"         ";
            }
            //gotoxy(1,1);
        }
        
        void deadmenu(){
            textcolor(BG);
            system("cls");
    
            deadbird(5);
            FILE *fin;
            int n;
            fin = fopen("highscore.txt","rw");
            if(fin!=NULL)fscanf(fin,"%d",&n);
            fclose(fin);
            
            FILE *fout;
            fout = fopen("highscore.txt","w");
            if(score > n)fprintf(fout,"%d",score);
            else fprintf(fout,"%d",n);
            fclose(fout);
            
            gotoxy(28,4); cout << "YOUR SCORE:";
            if (score>n) {
                gotoxy(28,13); cout << "YOU HAVE SET A NEW HIGHSCORE!";
                Beep(500,50); Beep(550,50); Beep(600,80); Beep(500,50); Beep(600,80); Beep(750,150); 
            }
            if (score<10){
                switch(score%10){
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
                switch(score/10){
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
                switch(score%10){
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
        
        int cekmati(){
            int i;
            if (burung.get_y_bird()>20) return 1; 
            if (burung.get_y_bird()<2) return 1;
            
            //untuk koordinat hidung burung dengan tiang atas, dalam kasus ini +2 dan +3 adalah sama
            //jadi for hanya sekali untuk salah satu hidung(atas or bawah)
            for(i=obs1.get_random1();i>=0;i--){
                if(burung.get_y_bird()+3==obs1.get_yobsup()-i && burung.get_x_bird()+5==obs1.get_x_obs()+1)return 1;
            }
            //untuk koordinat hidung burung dengan tiang bawah, dalam kasus ini +2 dan +3 adalah sama
            //jadi for hanya sekali untuk salah satu hidung(atas or bawah)
            for(i=0;i<=obs1.get_random2();i++){
                if(burung.get_y_bird()+2==obs1.get_yobsdown()+i && burung.get_x_bird()+5==obs1.get_x_obs()+1)return 1;
            }
            //untuk koordinat hidung burung dengan tiang atas, dalam kasus ini +2 dan +3 adalah sama
            //jadi for hanya sekali untuk salah satu hidung(atas or bawah)
            for(i=obs2.get_random1();i>=0;i--){
                if(burung.get_y_bird()+3==obs2.get_yobsup()-i && burung.get_x_bird()+5==obs2.get_x_obs()+1)return 1;
            }
            //untuk koordinat hidung burung dengan tiang bawah, dalam kasus ini +2 dan +3 adalah sama
            //jadi for hanya sekali untuk salah satu hidung(atas or bawah)
            for(i=0;i<=obs2.get_random2();i++){
                if(burung.get_y_bird()+2==obs2.get_yobsdown()+i && burung.get_x_bird()+5==obs2.get_x_obs()+1)return 1;
            }
            
            if (//untuk koordinat burung x+3,y (biji diatas kepala)
                burung.get_y_bird()==obs1.get_yobsup() && burung.get_x_bird()+3==obs1.get_x_obs() || 
                burung.get_y_bird()==obs1.get_yobsup() && burung.get_x_bird()+3==obs1.get_x_obs()+1 ||
                burung.get_y_bird()==obs1.get_yobsup() && burung.get_x_bird()+3==obs1.get_x_obs()+2 ||
                burung.get_y_bird()==obs1.get_yobsup() && burung.get_x_bird()+3==obs1.get_x_obs()+3 ||
                burung.get_y_bird()==obs1.get_yobsup() && burung.get_x_bird()+3==obs1.get_x_obs()+4 ||
                burung.get_y_bird()==obs1.get_yobsup() && burung.get_x_bird()+3==obs1.get_x_obs()+5 ||
                burung.get_y_bird()==obs1.get_yobsup() && burung.get_x_bird()+3==obs1.get_x_obs()+6 ||
                burung.get_y_bird()==obs1.get_yobsup() && burung.get_x_bird()+3==obs1.get_x_obs()+7 ||
                //untuk koordinat burung x+4,y+1 (tengah2 hidung dan jambul)
                burung.get_y_bird()+1==obs1.get_yobsup() && burung.get_x_bird()+4==obs1.get_x_obs() ||
                //untuk koordinat hidung burung atas  dengan ujung tiang atas x+5,y+2==x,y
                //untuk koordinat hidung burung bawah dengan ujung tiang atas x+5,y+3==x,y
                burung.get_y_bird()+2==obs1.get_yobsup() && burung.get_x_bird()+5==obs1.get_x_obs() ||
                burung.get_y_bird()+3==obs1.get_yobsup() && burung.get_x_bird()+5==obs1.get_x_obs() ||
                //untuk koordinat hidung burung atas  dengan ujung tiang bawah x+5,y+2==x,y
                //untuk koordinat hidung burung bawah dengan ujung tiang bawah x+5,y+3==x,y
                burung.get_y_bird()+2==obs1.get_yobsdown() && burung.get_x_bird()+5==obs1.get_x_obs() ||
                burung.get_y_bird()+3==obs1.get_yobsdown() && burung.get_x_bird()+5==obs1.get_x_obs() ||
                //untuk koordinat badan bawah burung bagian koordinat ujung kanan
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()+4==obs1.get_x_obs() ||
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()+4==obs1.get_x_obs()+1 ||
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()+4==obs1.get_x_obs()+2 ||
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()+4==obs1.get_x_obs()+3 ||
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()+4==obs1.get_x_obs()+4 ||
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()+4==obs1.get_x_obs()+5 ||
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()+4==obs1.get_x_obs()+6 ||
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()+4==obs1.get_x_obs()+7 ||
                //untuk koordinat badan bawah burung bagian koordinat ujung kiri
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()==obs1.get_x_obs() ||
                burung.get_y_bird() +4==obs1.get_yobsdown() && burung.get_x_bird()==obs1.get_x_obs()+1 ||
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()==obs1.get_x_obs()+2 ||
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()==obs1.get_x_obs()+3 ||
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()==obs1.get_x_obs()+4 ||
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()==obs1.get_x_obs()+5 ||
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()==obs1.get_x_obs()+6 ||
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()==obs1.get_x_obs()+7 ||
                
                //////////////////////////////////////////////////////////////////////////////////////
                ////////////////////////////OBSTACLE 2//////////////////////////////////////////////////
                /////////////////////////////////////////////////////////////////////////////////////
                
                burung.get_y_bird()==obs2.get_yobsup() && burung.get_x_bird()+3==obs2.get_x_obs() || 
                burung.get_y_bird()==obs2.get_yobsup() && burung.get_x_bird()+3==obs2.get_x_obs()+1 ||
                burung.get_y_bird()==obs2.get_yobsup() && burung.get_x_bird()+3==obs2.get_x_obs()+2 ||
                burung.get_y_bird()==obs2.get_yobsup() && burung.get_x_bird()+3==obs2.get_x_obs()+3 ||
                burung.get_y_bird()==obs2.get_yobsup() && burung.get_x_bird()+3==obs2.get_x_obs()+4 ||
                burung.get_y_bird()==obs2.get_yobsup() && burung.get_x_bird()+3==obs2.get_x_obs()+5 ||
                burung.get_y_bird()==obs2.get_yobsup() && burung.get_x_bird()+3==obs2.get_x_obs()+6 ||
                burung.get_y_bird()==obs2.get_yobsup() && burung.get_x_bird()+3==obs2.get_x_obs()+7 ||
                //untuk koordinat burung x+4,y+1 (tengah2 hidung dan jambul)
                burung.get_y_bird()+1==obs2.get_yobsup() && burung.get_x_bird()+4==obs2.get_x_obs() ||
                //untuk koordinat hidung burung atas  dengan ujung tiang atas x+5,y+2==x,y
                //untuk koordinat hidung burung bawah dengan ujung tiang atas x+5,y+3==x,y
                burung.get_y_bird()+2==obs2.get_yobsup() && burung.get_x_bird()+5==obs2.get_x_obs() ||
                burung.get_y_bird()+3==obs2.get_yobsup() && burung.get_x_bird()+5==obs2.get_x_obs() ||
                //untuk koordinat hidung burung atas  dengan ujung tiang bawah x+5,y+2==x,y
                //untuk koordinat hidung burung bawah dengan ujung tiang bawah x+5,y+3==x,y
                burung.get_y_bird()+2==obs2.get_yobsdown() && burung.get_x_bird()+5==obs2.get_x_obs() ||
                burung.get_y_bird()+3==obs2.get_yobsdown() && burung.get_x_bird()+5==obs2.get_x_obs() ||
                //untuk koordinat badan bawah burung bagian koordinat ujung kanan
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()+4==obs2.get_x_obs() ||
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()+4==obs2.get_x_obs()+1 ||
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()+4==obs2.get_x_obs()+2 ||
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()+4==obs2.get_x_obs()+3 ||
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()+4==obs2.get_x_obs()+4 ||
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()+4==obs2.get_x_obs()+5 ||
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()+4==obs2.get_x_obs()+6 ||
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()+4==obs2.get_x_obs()+7 ||
                //untuk koordinat badan bawah burung bagian koordinat ujung kiri
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()==obs2.get_x_obs() ||
                burung.get_y_bird() +4==obs2.get_yobsdown() && burung.get_x_bird()==obs2.get_x_obs()+1 ||
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()==obs2.get_x_obs()+2 ||
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()==obs2.get_x_obs()+3 ||
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()==obs2.get_x_obs()+4 ||
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()==obs2.get_x_obs()+5 ||
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()==obs2.get_x_obs()+6 ||
                burung.get_y_bird()+4==obs2.get_yobsdown() && burung.get_x_bird()==obs2.get_x_obs()+7                
                ) return 1;
            else return 0;
        }
        
        void burungjatuh(){
            if (dead==0){
                Sleep(300);
                Beep(1000,30); Beep(800,30); Beep(700,30); Beep(600,30); 
                
                drawborder();
                while(burung.get_y_bird()+4!=25){ 
                    burung.burunghapus();
                    burung.set_y_bird(burung.get_y_bird()+1);
                    obs1.drawobs();
                    if (ctr>25) obs2.drawobs();
                    drawborder();
                    burung.burungdown();
                    Sleep(80);
                }
                dead=1;
                textcolor(BG);
                gotoxy(27,obs1.get_y_obs()-2);
                cout<<"Press 'ENTER'";
                while(13!=getch()){
                    getch();
                }
                               
                deadmenu();
            }
        }
        
        void draw(){
            //textcolor(0);
            //system("cls");
            drawlatar();
            drawborder();
            //for(int i=23;i<26;i++){gotoxy(1,i); cout<<"        ";}
            textcolor(BG);
            gotoxy(burung.get_x_bird()-7,burung.get_y_bird()+6);
            cout<<"Press 'SPACE' to jump!";
            burung.burungup();
            
            if(32==getch()){
                Beep(2000,30);
                Beep(3000,30);
                gotoxy(burung.get_x_bird()-7,burung.get_y_bird()+6); textcolor(BG); cout<<"                      ";
                for(int i=0;i<3;i++){
                    obs1.drawobs();
                    burung.burungup();
                    Sleep(100);
                    burung.burunghapus();
                    obs1.hapusobs();
                    burung.set_y_bird(burung.get_y_bird()-1);
                    obs1.set_x_obs(obs1.get_x_obs()-1);
                }
                
                while(1){                    
                    if(kbhit() && 32==getch()){
                        //Beep(900,30);
                        //Beep(800,30);
                        
                        //Beep(1000,30);
                        //Beep(1200,30);
                        
                        Beep(2000,30);
                        Beep(3000,30);
                        if(dead==0){
                            for(int i=0;i<3;i++){
                                if (dead==0){
                                    burung.burungup();
                                    if (ctr>25){
                                        ctr++;
                                        if (obs1.get_x_obs()==34 || obs2.get_x_obs()==34) {Beep(700,30); Beep(900,80);  score++; textcolor(15); gotoxy(1,9); cout<<score;}
                                        //updateSCORE();
                                        if (obs1.get_x_obs()<10){
                                            obs1.hapusobs();
                                            obs1.set_random1((rand()%10)+2);
                                            obs1.set_random2(25-obs1.get_random1()-11);
                                            obs1.set_x_obs(68);
                                            //coverlatar();
                                            drawborder();
                                        }
                                        if (obs2.get_x_obs()<10){
                                            obs2.hapusobs();
                                            obs2.set_random1((rand()%10)+2);
                                            obs2.set_random2(25-obs2.get_random1()-11);
                                            obs2.set_x_obs(68);
                                            //coverlatar();
                                            drawborder();
                                        }
                                        obs1.drawobs();
                                        obs2.drawobs();
                                        if(cekmati()) {burungjatuh(); break;}
                                        if(obs1.get_x_obs()<16||obs1.get_x_obs()>58) drawborder();
                                        if(obs2.get_x_obs()<16||obs2.get_x_obs()>58) drawborder();
                                        Sleep(80);
                                        burung.burunghapus();
                                        obs1.hapusobs();
                                        obs2.hapusobs();
                                        burung.set_y_bird(burung.get_y_bird()-1);
                                        obs1.set_x_obs(obs1.get_x_obs()-1);
                                        obs2.set_x_obs(obs2.get_x_obs()-1);
                                        //if (burung.get_y_bird()<3) break;    
                                    }
                                    else{
                                        ctr++;
                                        if (obs1.get_x_obs()==34 || obs2.get_x_obs()==34) {Beep(700,30); Beep(900,80);  score++; textcolor(15); gotoxy(1,9); cout<<score;}
                                        if (obs1.get_x_obs()<10){
                                            obs1.hapusobs();
                                            obs1.set_random1((rand()%10)+2);
                                            obs1.set_random2(25-obs1.get_random1()-11);
                                            obs1.set_x_obs(68);
                                            //drawborder();
                                            //coverlatar();
                                        }
                                        obs1.drawobs();
                                        if(cekmati()) {burungjatuh(); break;}
                                        if(obs1.get_x_obs()<16||obs1.get_x_obs()>58) drawborder();
                                        Sleep(100);
                                        burung.burunghapus();
                                        obs1.hapusobs();
                                        burung.set_y_bird(burung.get_y_bird()-1);
                                        obs1.set_x_obs(obs1.get_x_obs()-1);
                                        //if (burung.get_y_bird()<3) break;
                                    }
                                }
                            }
                        }
                    }
                    else{
                        if(ctr>25){
                            ctr++;
                            if (obs1.get_x_obs()==34 || obs2.get_x_obs()==34) {Beep(700,30); Beep(900,80);  score++; textcolor(15); gotoxy(1,9); cout<<score;}
                            //updateSCORE();
                            burung.burungdown();
                            if (obs1.get_x_obs()<10){
                                obs1.hapusobs();
                                obs1.set_random1((rand()%10)+2);
                                obs1.set_random2(25-obs1.get_random1()-11);
                                obs1.set_x_obs(68);
                                //coverlatar();
                                drawborder();
                            }
                            if (obs2.get_x_obs()<10){
                                obs2.hapusobs();
                                obs2.set_random1((rand()%10)+2);
                                obs2.set_random2(25-obs2.get_random1()-11);
                                obs2.set_x_obs(68);
                                //coverlatar();
                                drawborder();
                            }
                            obs1.drawobs();
                            obs2.drawobs();
                            if(cekmati()) {burungjatuh(); break;}
                            if(obs1.get_x_obs()<16||obs1.get_x_obs()>58) drawborder();
                            if(obs2.get_x_obs()<16||obs2.get_x_obs()>58) drawborder();
                            Sleep(80);
                            burung.burunghapus();
                            obs1.hapusobs();
                            obs2.hapusobs();
                            burung.set_y_bird(burung.get_y_bird()+1);
                            obs1.set_x_obs(obs1.get_x_obs()-1);
                            obs2.set_x_obs(obs2.get_x_obs()-1);
                            //if (burung.get_y_bird()>20) break; 
                            //if (burung.get_y_bird()<3) break;
                        }
                        else{
                            ctr++;                
                            if (obs1.get_x_obs()==34 || obs2.get_x_obs()==34) {Beep(700,30); Beep(900,80);  score++; textcolor(15); gotoxy(1,9); cout<<score;}
                            burung.burungdown();
                            if (obs1.get_x_obs()<10){
                                obs1.hapusobs();
                                obs1.set_random1((rand()%10)+2);
                                obs1.set_random2(25-obs1.get_random1()-11);
                                obs1.set_x_obs(68);
                                //coverlatar();
                                //drawborder();
                            }
                            obs1.drawobs();
                            if(cekmati()) {burungjatuh(); break;}
                            if(obs1.get_x_obs()<16||obs1.get_x_obs()>58) drawborder();
                            Sleep(100);
                            burung.burunghapus();
                            obs1.hapusobs();
                            burung.set_y_bird(burung.get_y_bird()+1);
                            obs1.set_x_obs(obs1.get_x_obs()-1);
                            
                            //if (burung.get_y_bird()>20) break; 
                            //if (burung.get_y_bird()<3) break;
                        }
                    }
                }
            }
        }
};

//int main(){
void game(){
    Game GAME;
    textcolor(BG);
    system("cls");
    GAME.setBG();
    gotoxy(1,1);
    GAME.draw();
    
    
}
