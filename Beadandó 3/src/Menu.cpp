#include "Menu.hpp"
#include "graphics.hpp"
#include <string>
#include <iostream>
#include <vector>
using namespace genv;
Menu::Menu(bool be, bool ki) : honnan(be), hova(ki)
{
honnan = be;
hova = ki;
vector<string> elemek;

}
void Menu::draw(genv::event ev)
{       gout << move_to(0,0) << color(200,200,0) << box(800, 700);
        gout << color(250, 250, 250);
        gout << move_to(100, 100) << box(600, 200);
        if(ev.pos_x < 600 && ev.pos_x > 200 && ev.pos_y < 300 && ev.pos_y > 100){
            gout << color(0, 0, 153);
        }
        else gout << color(20, 20, 20);
        gout << move_to(100+5, 100+5) << box(590, 190);
        gout << color(255, 255, 255) << move_to(370, 200) << text("START");


        gout << color(250, 250, 250);
        gout << move_to(100, 400) << box(600, 200);
        if(ev.pos_x < 600 && ev.pos_x > 200 && ev.pos_y < 600 && ev.pos_y > 400){
            gout << color(0, 0, 153);
        }
        else gout << color(20, 20, 20);
        gout << move_to(100+5, 400+5) << box(590, 190);
        gout << color(255, 255, 255) << move_to(370, 500) << text("EXIT");
}
bool Menu::begin(event ev)
{
   if(ev.type == ev_mouse) {
        if(ev.button == btn_left) {
            if(ev.pos_x < 600 && ev.pos_x > 200 && ev.pos_y < 300 && ev.pos_y > 100){
                return true;
            }
        }
   }
return false;
}



bool Menu::end(event ev)
{
   if(ev.type == ev_mouse) {
        if(ev.button == btn_left) {
            if(ev.pos_x < 600 && ev.pos_x > 200 && ev.pos_y < 600 && ev.pos_y > 400){
                return true;
            }
        }
   }
return false;
}






