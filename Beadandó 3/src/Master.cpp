#include "Master.hpp"
#include "graphics.hpp"
#include <iostream>
#include <string>
using namespace genv;

Master::Master()
{
  std::cout << "Mater\n";
}
void Master::is_selected(genv::event ev){
        for(int i=0; i < 7; i++){
            if(ev.pos_x > 50+i*100 && ev.pos_x < 50+(i+1)*100)
                selcol = i;
        }
}

void Master::newboard(){

    if (reset == true){
        elemek.resize(7, std::vector<int>(6, 0));
        reset = false;

    }


    //cout << elemek[6][7];
}
void Master::draw(genv::event ev){
gout << color(0,128,255) << move_to(0,0) << box(50, 600) << move_to(750,0) << box(50,600) << move_to(0,600) << color(0,0,102) << box(800,50); // oldalso diszek kirajzolasa
for(int i = 0; i < 7; i++){                                                                                                                     //kozepso resz
        if(selcol == i) gout << move_to(50+i*100, 0) << color(204,229,255) << box(100, 600);
        else gout << move_to(50+i*100, 0) << color(0,76,153) << box(100, 600);
}
if(gamer == 1) gout << color(255,153,51) <<move_to(0,650) << box(800,50);                                                           //also resz
else if(gamer == 2) gout << color(255,51,51) <<move_to(0,650) << box(800,50);

int r = 30;
for(int i=0; i < 7; i++){                                                                                                       //korok kirajzolasa
    for(int j=0; j < 6; j++){

        for(int k=-r;  k < r; k++){
            for(int l=-r;  l< r; l++){
                if((k*k + l*l) <= r*r){
                        if(elemek[i][j] == 1) gout << color(255,153,0) << move_to(i*100+l+100, 600-(j*100+k+50)) << dot;
                        if(elemek[i][j] == 2) gout << color(255,51,51) << move_to(i*100+l+100, 600-(j*100+k+50)) << dot;
                        if(elemek[i][j] == 0) gout << color(0,0,0) << move_to(i*100+l+100, 600-(j*100+k+50)) << dot;
                        if(elemek[i][j] == 3) gout << color(0,255,0) << move_to(i*100+l+100, 600-(j*100+k+50)) << dot;
                }
            }
        }
    }
}

if(nyert == 1) {
    gout << move_to(370, 680) << color(255,255,255) << text("RED WON!");
}
if(nyert == 2) {
    gout << move_to(370, 680) << color(255,255,255) << text("ORANGE WON!");
}
if(nyert == 3) {
    gout << move_to(370, 680) << color(255,255,255) << text("DRAW!");
}



if(gameover == true) {

    if(ev.pos_x < 100 && ev.pos_x >0 && ev.pos_y > 650){
            gout << color(255,255,255) << move_to(0,650) << box(100,50) << move_to(5,655) << color(0,128,255) << box(90,40) << move_to(25, 680) << color(255,255,255) << text("RESTART");
            gout << color(255,255,255) << move_to(700,650) << box(100,50) << move_to(705,655) << color(0,0,102) << box(90,40) << move_to(730, 680) << color(255,255,255) << text("EXIT");
    }
    else if(ev.pos_x < 800 && ev.pos_x >700 && ev.pos_y > 650){

            gout << color(255,255,255) << move_to(700,650) << box(100,50) << move_to(705,655) << color(0,128,255) << box(90,40) << move_to(730, 680) << color(255,255,255) << text("EXIT");
            gout << color(255,255,255) << move_to(0,650) << box(100,50) << move_to(5,655) << color(0,0,102) << box(90,40) << move_to(25, 680) << color(255,255,255) << text("RESTART");
    }
    else {
        gout << color(255,255,255) << move_to(0,650) << box(100,50) << move_to(5,655) << color(0,0,102) << box(90,40) << move_to(25, 680) << color(255,255,255) << text("RESTART");
            gout << color(255,255,255) << move_to(700,650) << box(100,50) << move_to(705,655) << color(0,0,102) << box(90,40) << move_to(730, 680) << color(255,255,255) << text("EXIT");
    }








}






}

void Master::place(genv::event ev){


    if(ev.type == ev_mouse) {
        if(ev.button == btn_left) {
            if(elemek[selcol][0] == 0 && gameover == false){
                elemek[selcol][0] = gamer;
                if(gamer == 1) gamer = 2;
                else gamer = 1;
            }
            else {
            for(int i=1 ; i <7; i++){
                if(elemek[selcol][i-1] > 0 && elemek[selcol][i] == 0 && elemek[selcol][5] == 0 && gameover == false){

                    elemek[selcol][i] = gamer;
                    valid = true;
                    break;
                }

            }
            }

if(gamer == 1 && valid == true) gamer = 2;
else if(valid == true) gamer = 1;
valid = false;

      }
    }


   if(ev.type == ev_mouse) {
        if(ev.button == btn_left) {

            if(ev.pos_x < 800 && ev.pos_x >700 && ev.pos_y > 650){
                kiakarlepni = true;

            }
            if(ev.pos_x < 100 && ev.pos_x >0 && ev.pos_y > 650){
                reset = true;
                gameover = false;

            }
        }
   }
}



void Master::check(){

for(int i=0; i < 4; i++){                                                   //vizszintes ellenorzes
    for(int j=0; j < 6; j++){
            if((elemek[i][j] == elemek[i+1][j]) && ( elemek[i][j] == elemek[i+2][j])  && (elemek[i][j] == elemek[i+3][j]) && (elemek[i][j] > 0)){
                end = true;
                elemek[i][j] = 3;
                elemek[i+1][j] = 3;
                elemek[i+2][j] = 3;
                elemek[i+3][j] = 3;
                gameover = true;
                nyert = gamer;
                break;
            }
        }
        if(gameover){
            break;
    }
}
for(int i=0; i < 7; i++){                                                   //fuggoleges ellenorzes
    for(int j=0; j < 3; j++){
            if((elemek[i][j] == elemek[i][j+1]) && ( elemek[i][j] == elemek[i][j+2])  && (elemek[i][j] == elemek[i][j+3]) && (elemek[i][j] > 0)){
                end = true;
                elemek[i][j] = 3;
                elemek[i][j+1] = 3;
                elemek[i][j+2] = 3;
                elemek[i][j+3] = 3;
                gameover = true;
                nyert = gamer;
                break;

            }
    }
        if(gameover){
            break;
        }
}


for(int i=0; i < 4; i++){                                                   //jobb folfele nezo ellenorzes
    for(int j=0; j < 3; j++){
            if((elemek[i][j] == elemek[i+1][j+1]) && ( elemek[i][j] == elemek[i+2][j+2])  && (elemek[i][j] == elemek[i+3][j+3]) && (elemek[i][j] > 0)){
                end = true;
                elemek[i][j] = 3;
                elemek[i+1][j+1] = 3;
                elemek[i+2][j+2] = 3;
                elemek[i+3][j+3] = 3;
                gameover = true;
                nyert = gamer;
                break;

            }
    }
        if(gameover){
            break;
        }
}
for(int i=0; i < 4; i++){                                                   //bal folfele nezo ellenorzes
    for(int j=3; j < 6; j++){
            if((elemek[i][j] == elemek[i+1][j-1]) && ( elemek[i][j] == elemek[i+2][j-2])  && (elemek[i][j] == elemek[i+3][j-3]) && (elemek[i][j] > 0)){
                end = true;
                elemek[i][j] = 3;
                elemek[i+1][j-1] = 3;
                elemek[i+2][j-2] = 3;
                elemek[i+3][j-3] = 3;
                gameover = true;
                nyert = gamer;
                break;

            }
    }

        if(gameover){
            break;
        }
bool vege = true;
for(int i=0; i < 6; i++)  {

    if(elemek[i][5] == 0){
        vege = false;

    }


}
if (vege == true){
nyert = 3;
gameover = true;

}

}














}








