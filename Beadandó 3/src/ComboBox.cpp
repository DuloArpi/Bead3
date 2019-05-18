#include "ComboBox.hpp"
#include "graphics.hpp"
#include <string>
#include <vector>
using namespace genv;
ComboBox::ComboBox(int x, int y, int sx, int sy, int dbmax) : Widget(x,y,sx,sy)
{
dbmutat = dbmax;
vector<string> elemek;

}
void ComboBox::draw()
{
    int sz1 = 0, sz2 = 0, sz3 = 0;
    gout << move_to(_x,_y) << color(255, 255, 255) << box(_size_x, _size_y) << move_to(_x+2, _y+2) << color(sz1, sz2, sz3) << box(_size_x-4, _size_y-4)
    << move_to(_x+_size_x-(_size_x/5), _y) << color(255, 255, 255) << line(0, _size_y);

    if(!is_open){
            gout << move_to(_x+_size_x-(_size_x/5)+4, _y+(_size_y/5)) << color(255, 255, 255) << line_to(_x+_size_x-6, _y+(_size_y/5));
            gout << move_to(_x+_size_x-(_size_x/5)+4, _y+(_size_y/5)) << line_to(_x+_size_x-3-((_size_x/6)/2),  _y+(_size_y/3));
            gout << move_to(_x+_size_x-6, _y+(_size_y/5)) << line_to(_x+_size_x-3-((_size_x/6)/2),  _y+(_size_y/3));

            gout << move_to(_x+4, _y+(_size_y/2)) << color(255, 255, 255) << text(elemek[selecteditem]);
    }
    if(is_open){
            gout << move_to(_x+_size_x-(_size_x/5)+4, _y+(_size_y/3)) << color(255, 255, 255) << line_to(_x+_size_x-6, _y+(_size_y/3));
            gout << move_to(_x+_size_x-(_size_x/5)+4, _y+(_size_y/3)) << line_to(_x+_size_x-3-((_size_x/6)/2),  _y+(_size_y/5));
            gout << move_to(_x+_size_x-6, _y+(_size_y/3)) << line_to(_x+_size_x-3-((_size_x/6)/2),  _y+(_size_y/5));

            gout << color(255, 255, 255) << move_to(_x, _y+_size_y) << box(_size_x, dbmutat*(_size_y+2));

        for(int i = 0; i < dbmutat; i++){
            gout << color(0, 0, 0) << move_to(_x+2, (_y+_size_y) + i*(_size_y+2)) << box(_size_x-4, _size_y)
            << color(255, 255, 255) <<move_to(_x+4,_y + _size_y/2+_size_y + i*(_size_y+2)  )  << text(elemek[i+eltolas]);
        }
    }
}
void ComboBox::handle(event ev)
{
    if(is_open){
         if (ev.type == ev_mouse) {
            if (ev.button == btn_wheeldown&& eltolas < elemek.size()-dbmutat) {
                    eltolas++;
            }
            if (ev.button == btn_wheelup && eltolas > 0) {
                    eltolas--;
            }
          }
    }

  if(ev.type == ev_mouse) {
    if(ev.button == btn_left) {
        if((ev.pos_x > _x+_size_x-(_size_x / 5) && ev.pos_x < _x + _size_x)  && (ev.pos_y < _y+_size_y && ev.pos_y > _y)){
            is_open = !is_open;
         }
     }
   }
    if(is_open){
            if(ev.type == ev_mouse){
                if(ev.button == btn_left) {

                    for(int i = 1; i <= dbmutat; i++){
                        if((ev.pos_x > _x && ev.pos_x < _x+_size_x) && ev.pos_y > _y+i*_size_y && ev.pos_y < _y+((i+1)*_size_y)){
                            selecteditem = i+eltolas-1;
                            is_open = false;
                            break;
                        }
                    }
                }
            }
    }

}
void ComboBox::load(vector<string> be){
elemek = be;
}
/*
string vissza(){
return elemek[selecteditem];

}*/
