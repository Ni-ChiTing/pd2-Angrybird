#include "wood.h"

wood::wood()
{
    bar::bar;
}

void wood::setpic()
{
    if(HP==10)
        g_pixmap.setPixmap(QPixmap(":/image/wood10.png"));
    if(HP==5)
         g_pixmap.setPixmap(QPixmap(":/image/wood5.png"));
}
