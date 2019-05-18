#include "NumberWidget.hpp"
#include "graphics.hpp"
#include <string>
using namespace genv;
NumberWidget::NumberWidget(int x, int y, int sx, int sy, int num, int also, int felso) : Widget(x,y,sx,sy)
{
   value = num;
   minimum = also;
   maximum = felso;
}
void NumberWidget::draw()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

    double a=_size_x, b = _size_y, meret, felosztharmad = _size_x/3;
    if(a < b){
        meret = (a/6) - a/20;
    }
    else{
        meret = b/7;
    }
    gout << move_to(_x+felosztharmad, _y) << color(255,255,255) << line(0, _size_y) << move_to(_x+_size_x-felosztharmad, _y)<< line(0, _size_y);  //fuggoleges elvalaszto vonal
    gout << move_to(_x+(felosztharmad/2), _y+(_size_y/2)) << line(-meret, 0) << move_to(_x+(felosztharmad/2), _y+_size_y/2) << line(meret, 0);              //bal oldali - jel
    gout << move_to(_x+_size_x-(felosztharmad/2), _y+(_size_y/2)) << line(-meret, 0) << move_to(_x+_size_x-(felosztharmad/2), _y+(_size_y/2)) << line(meret, 0);  //jobb oldali - jel
    gout << move_to(_x+_size_x-(felosztharmad/2), _y+(_size_y/2)) << line(0, -meret) << move_to(_x+_size_x-(felosztharmad/2), _y+(_size_y/2)) << line(0, meret); // jobb oldali | jel

    std::string numstring;
    numstring = std::to_string(value);
    gout << move_to(_x+(_size_x/2)-7, _y+(_size_y/2)+4) << text(numstring);  //szám kiírása

}
void NumberWidget::handle(event ev)
{
  if(ev.type == ev_mouse) {
    if(ev.button == btn_left) {
        if(((ev.pos_x > _x && ev.pos_x < _x+(_size_x/3)) &&  ((ev.pos_y > _y) && (ev.pos_y < _y+_size_y)))  && value > minimum){
            value--;
        }
        if(((ev.pos_x > _x+_size_x-(_size_x/3)) && (ev.pos_x < _x+_size_x)) &&  ((ev.pos_y > _y) && (ev.pos_y < _y+_size_y))  && value < maximum){
                value++;
        }
     }
   }
   if(ev.keycode == key_pgup && value < maximum-10){
    value +=10;
   }
   if(ev.keycode == key_pgdn && value > minimum+10){
    value -=10;
   }
   if(ev.keycode == key_up && value < maximum){
    value++;
   }
   if(ev.keycode == key_down && value > minimum){
    value--;
   }
}
