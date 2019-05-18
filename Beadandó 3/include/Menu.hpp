#ifndef MENU_H
#define MENU_H
#include <string>
#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
using namespace std;
class Menu {
protected:
    bool honnan, hova;
public:
    Menu(bool be, bool ki);
    virtual void draw(genv::event ev);
    virtual bool begin(genv::event ev);
    virtual bool end(genv::event ev);


};
#endif // EXAMPLECHECKBOX_HPP_INCLUDED
