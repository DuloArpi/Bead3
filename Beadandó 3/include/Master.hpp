#ifndef MASTER_H
#define MASTER_H
#include <string>
#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
using namespace std;
class Master {
protected:
    std::vector<std::vector<int>> elemek;
    int selcol=1, nyert = 0;
    bool valid = false;
    bool end = false;
public:
    bool kiakarlepni = false;
    bool gameover = false;
    int gamer = 1;
    bool reset = true;
    Master();
    virtual void is_selected(genv::event ev);
    virtual void draw(genv::event ev);
    virtual void place(genv::event ev);
    virtual void newboard();
    virtual void check();




};

#endif // MASTER_H
