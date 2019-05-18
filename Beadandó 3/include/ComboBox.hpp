#ifndef COMBOBOX_H
#define COMBOBOX_H
#include <string>
#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
using namespace std;
class ComboBox : public virtual Widget {
protected:
    int dbmutat, selecteditem, eltolas;
    bool is_open, kilogos;
    vector<string> elemek;
public:
    ComboBox(int x, int y, int sx, int sy, int dbmax);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual void load(vector<string> be);
 //   virtual string vissza;
};
#endif // EXAMPLECHECKBOX_HPP_INCLUDED
