#include "graphics.hpp"
#include "widgets.hpp"
#include "kocka.hpp"
#include "jatekmester.hpp"
#include <vector>
using namespace std;
using namespace genv;


int main()
{
    gout.open(620,620);

    jatekmester *gm = new jatekmester;
    int game = gm->jatek();

    if (game == 2)
    {
        gout << move_to(0,0) << color(0,0,0) << box(620,620);
        gout << move_to (300,300) << color (255,255,255) << text("DÖNTETLEN");
        gout << refresh;
        event ev;
        while(gin >> ev && ev.keycode != key_enter)
        {

        }
    }

    if (game == 3)
    {
        gout << move_to(0,0) << color(0,0,0) << box(620,620);
        gout << move_to (300,300) << color (255,255,255) << text("PIROS NYERT");
        gout << refresh;
        event ev;
        while(gin >> ev && ev.keycode != key_enter)
        {

        }
    }

    if (game == 4)
    {
        gout << move_to(0,0) << color(0,0,0) << box(620,620);
        gout << move_to (300,300) << color (255,255,255) << text("ZÖLD NYERT");
        gout << refresh;
        event ev;
        while(gin >> ev && ev.keycode != key_enter)
        {

        }
    }

    return 0;
}
