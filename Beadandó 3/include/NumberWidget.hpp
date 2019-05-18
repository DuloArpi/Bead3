#ifndef NUMBERWIDGET_H
#define NUMBERWIDGET_H
#include "graphics.hpp"
#include "widgets.hpp"
class NumberWidget : public virtual Widget {
protected:
    int value, minimum, maximum;
public:
    NumberWidget(int x, int y, int sx, int sy, int num, int also, int felso);
    virtual void draw() ;
    virtual void handle(genv::event ev);
};
#endif // EXAMPLECHECKBOX_HPP_INCLUDED
