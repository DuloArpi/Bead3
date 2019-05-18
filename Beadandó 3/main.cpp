#include "graphics.hpp"
#include "widgets.hpp"
#include "NumberWidget.hpp"
#include "ComboBox.hpp"
#include "Master.hpp"
#include <vector>
#include <string>
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
    int game = false, gameover = false, menu = true;
    gout.open(800,700);
    vector<Widget*> w;
    vector<string> cuccok = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Hétfõ", "Kedd", "Szerda", "Csütörtök", "Péntek", "Szombat", "Vasárnap"};
    vector<string> cuccok2 = {"Egy", "Kettõ", "Három"};

                                        // x, y, x meret, y meret, kezdoszam, min, max korl
    NumberWidget * n1 = new NumberWidget(250, 250, 140, 130, 2, -10, 12);
    NumberWidget * n2 = new NumberWidget(10, 250, 70, 40, 2, -5, 7);

                                        // x, y, x meret, y meret, megjelenitedo elemek szama
    ComboBox * c1 = new ComboBox(10, 10, 100, 30, 5);
    ComboBox * c2 = new ComboBox(10, 10, 70, 30, 3);
    genv::event ev;
    Master * jatek = new Master(0,0,800,650);

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


    w.push_back(n1);
    w.push_back(n2);
    c1->load(cuccok);
    w.push_back(c1);
    c2->load(cuccok2);
    w.push_back(c2);

    for (Widget * wg : w) {
        wg->draw();
    }
    gout << refresh;
//    event_loop(w);
    return 0;
}
