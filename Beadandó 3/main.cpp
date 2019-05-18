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
        if(jatek->kiakarlepni == true){
            game = false;
        }
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
