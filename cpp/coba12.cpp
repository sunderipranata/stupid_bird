/*
A SIMPLE GAME
CODED BY SUNDERI PRANATA
UMN - COMPUTER ENGINEERING 2013
STUDENT NUMBER : 13110210010
------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------MENU PRACTICE HEADER FILE------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <conio2.h>
#include <windows.h>

//#include "design latarbawah.cpp"

#define PUTIH 8*15
#define COKLAT 5*15
#define HITAM 0
#define KUNING 15*15
#define MERAH 13*15
#define BG 15*12
#define HIJAU 3*15
#define HIJAUTUA 15*11

using namespace std;

class Bird2{
    private:
        int x;
        int y;
    public:
        Bird2(){x=34; y=10;}
        
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

class Obs2{
    private:
        int x;
        int y;
        int z;
        int random1;
        int random2;
        int yobsup;
        int yobsdown;
    public:
        Obs2(){
            x=68; z=1;
            random1=(rand()%10)+2;
            random2=25-random1-11;
        }
        ~Obs2(){}
        void drawobs(){            
            int i;
            textcolor(HIJAU);
            
            
            y=25-random2;
            
            yobsup=random1+1;
            yobsdown=25-random2;
            /////////////ATAS////////////////////
            for(i=1;i<=random1;i++){
                gotoxy(x+1,i); cout <<  "      ";
            }    
            gotoxy(x,i);   cout << "        ";
            
            //////////////BAWAH/////////////////   
            gotoxy(x,y);   cout << "        ";
            
            for(i=1;i<=random2;i++){
                gotoxy(x+1,y+i); cout <<  "      ";
            }
            gotoxy(1,1);
            
            
        }
        
        void hapusobs(){
            int i;
            
            if (x+8>68) textcolor(0); else textcolor(BG);
            /////////////ATAS////////////////////
            for(i=1;i<=random1;i++){
                gotoxy(x+1,i); cout <<  "       ";
            }    
            gotoxy(x,i);   cout << "         ";
            
            //////////////BAWAH/////////////////  
             
            gotoxy(x,y);   cout << "         ";
            
            if ((x+8)<=69){ 
                for(i=1;i<=random2;i++){
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
                    gotoxy(x+1,y+i); textcolor(0); cout<<"      ";
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

class Game2{
    private:
        int ctr,spd;
        bool dead,stop;
        Bird2 burung;
        Obs2 obs1,obs2;
    public:
        Game2(){dead=0;ctr=0;spd=100,stop=0;}
        int getstop(){return stop;}
        void setspeed(){
            int spdtemp=spd;
            textcolor(BG);
            system("cls");
            gotoxy(30,11);
            cout<<"SET your desired speed (use arrow up and down)";
            gotoxy(35,12);
            cout<<spd;
            char input=0;
            while(input!=13){
                input=getch();
                fflush(stdin);
                switch(input){
                    case 72: 
                        if (spdtemp!=120){
                            gotoxy(35,12); cout<<"   ";
                            spdtemp+=10; gotoxy(35,12);
                            cout<<spdtemp; 
                        }
                        break;
                    case 80:
                        if(spdtemp!=80){
                            gotoxy(35,12); cout<<"   ";
                            spdtemp-=10; gotoxy(35,12);
                            cout<<spdtemp;
                        }
                        break;
                }
            }
            if (spdtemp>spd) spd=100-(spdtemp-100);
            else if (spdtemp<spd) spd=spd+(100-spdtemp);
            else{}
        }
        void setBG(){
            textcolor(BG);
            for(int j=1;j<=25;j++){
                gotoxy(16,j); cout<<"                                                    ";
            }
        }
        
        void drawborder(){
            textcolor(0);
            for(int j=1;j<=25;j++){
                gotoxy(1,j); cout<<"                ";
                gotoxy(68,j); cout<<"            ";
            }
            gotoxy(1,1);
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
            
            if (//untuk koordinat burung x+3,y (biji diatas kepala)
                burung.get_y_bird()==obs1.get_yobsup() && burung.get_x_bird()+3==obs1.get_x_obs()  || 
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
                burung.get_y_bird()+4==obs1.get_yobsdown() && burung.get_x_bird()==obs1.get_x_obs()+7                
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
                    Sleep(spd);
                }
                dead=1;
            }
        }
        
        void draw(){
            drawlatar();
            drawborder();
            textcolor(BG);
            gotoxy(burung.get_x_bird()-7,burung.get_y_bird()+6);
            cout<<"Press 'SPACE' to jump!";
            gotoxy(burung.get_x_bird()-7,burung.get_y_bird()+7);
            cout<<"Press 'ESC' to back to MAIN MENU";
            burung.burungup();
            char input;
            input=getch();
            if(27==input){stop=1;}//return 0;}
            else{ 
                if(32==input){
                    Beep(2000,25);
                    Beep(3000,25);
                    textcolor(BG);
                    gotoxy(burung.get_x_bird()-7,burung.get_y_bird()+6); cout<<"                      ";
                    gotoxy(burung.get_x_bird()-7,burung.get_y_bird()+7); cout<<"                                ";
                    for(int i=0;i<3;i++){
                        obs1.drawobs();
                        burung.burungup();
                        Sleep(spd);
                        burung.burunghapus();
                        obs1.hapusobs();
                        burung.set_y_bird(burung.get_y_bird()-1);
                        obs1.set_x_obs(obs1.get_x_obs()-1);
                    }
                    
                    while(1){                   
                        if(kbhit() && 32==getch()){
                            Beep(2000,25);
                            Beep(3000,25);
                            
                            if(dead==0){
                                for(int i=0;i<3;i++){
                                    if (dead==0){
                                        burung.burungup();
                                        if (obs1.get_x_obs()==34) {Beep(700,30); Beep(900,50);}
                                        if (obs1.get_x_obs()<10){
                                            obs1.hapusobs();
                                            obs1.set_random1((rand()%10)+2);
                                            obs1.set_random2(25-obs1.get_random1()-11);
                                            obs1.set_x_obs(68);
                                            drawborder();
                                        }
                                        obs1.drawobs();
                                        if(cekmati()) {burungjatuh(); break;}
                                        if(obs1.get_x_obs()<16||obs1.get_x_obs()>58) drawborder();
                                        Sleep(spd);
                                        burung.burunghapus();
                                        obs1.hapusobs();
                                        
                                        burung.set_y_bird(burung.get_y_bird()-1);
                                        obs1.set_x_obs(obs1.get_x_obs()-1);
                                    }
                                    
                                    //if (burung.get_y_bird()<3) break;
                                }
                            }
                        }
                        else{
                            if (obs1.get_x_obs()==34) {Beep(700,30); Beep(900,50);}
                            burung.burungdown();
                            if (obs1.get_x_obs()<10){
                                obs1.hapusobs();
                                obs1.set_random1((rand()%10)+2);
                                obs1.set_random2(25-obs1.get_random1()-11);
                                obs1.set_x_obs(68);
                                drawborder();
                            }
                            obs1.drawobs();
                            if(cekmati()) {burungjatuh(); break;}
                            if(obs1.get_x_obs()<16||obs1.get_x_obs()>58) drawborder();
                            Sleep(spd);
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

void practice(){
    while(1){
        Game2 GAME;
        textcolor(BG);
        system("cls");
        GAME.setspeed();
        textcolor(0);
        system("cls");
        GAME.setBG();
        gotoxy(1,1);
        GAME.draw();
        if(GAME.getstop()==1) break;
    }
    
    
}
