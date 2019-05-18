#include "graphics.hpp"
#include "widgets.hpp"
#include "NumberWidget.hpp"
#include "ComboBox.hpp"
#include "Master.hpp"
#include "Menu.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
using namespace genv;

/*
void event_loop(vector<Widget*>& widgets) {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        gout << move_to(0,0) << color(0,0,0) << box(800,700);
        for (Widget * w : widgets) {
            w->draw();
        }
        gout << refresh;
    }
}
*/
int main()
{
    int game = false, gameover = false, menu = true, kilep = false;
    gout.open(800,700);
    genv::event ev;
    Master * jatek = new Master();

 while (kilep == false){

    while(gin >> ev && game == true) {
        if(jatek->reset == true){
            jatek->newboard();
        }
        jatek->place(ev);
        jatek->is_selected(ev);
        jatek->check();
        jatek->draw(ev);
        gout <<refresh;
    }
    Menu * menuben = new Menu(&menu, &game);
    while(gin >> ev && menu == true) {
        menuben->draw(ev);
        if(menuben->begin(ev) == true){
            menu=false;
            game=true;
        }
        if(menuben->end(ev) == true){
            menu=false;
        }
        gout << refresh;
    }


if(menu == false && game == false){
    kilep = true;
}
}

    return 0;
}
