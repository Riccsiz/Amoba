#include "graphics.hpp"
#include "widgets.hpp"
#include "kocka.hpp"
#include <vector>
using namespace std;
using namespace genv;


int main()
{
    gout.open(400,400);

    AmobaKocka *k = new AmobaKocka(10,10,30,30);
    k->draw();
    gout << refresh;

    event ev;
    while(gin >> ev) {
        if (ev.type == ev_mouse && ev.button==btn_left)
            if(k->is_selected(ev.pos_x,ev.pos_y))
                k->handle(1);
                gout << refresh;
    }
    return 0;
}
