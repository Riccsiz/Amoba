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
    bool restart =true;
    while (restart)
    {
        gm->kezd();
        int game = gm->jatek();

        if (game ==1)
        {
            restart = false;
        }

        if (game == 2)
        {
            gout << move_to(0,0) << color(0,0,0) << box(620,620);
            gout.load_font("Transformers Movie.ttf",30);
            gout << move_to (250,300) << color (255,255,255) << text("IT'S A DRAW");
            gout.load_font("Transformers Movie.ttf",22);
            gout << move_to (250,450) << color (255,255,255) << text("QUIT: 'ESCAPE'");
            gout << move_to (250,500) << color (255,255,255) << text("RESTART: 'ENTER'");
            gout << refresh;
            gout << refresh;
            event ev;
            while(gin >> ev && ev.keycode != key_enter && ev.keycode != key_escape)
            {

            }
            if (ev.keycode == key_escape)
            {
                restart = false;
            }
        }

        if (game == 3)
        {
            gout << move_to(0,0) << color(0,0,0) << box(620,620);
            gout.load_font("Transformers Movie.ttf",30);
            gout << move_to (250,300) << color (255,255,255) << text("RED WON !");
            gout.load_font("Transformers Movie.ttf",22);
            gout << move_to (250,450) << color (255,255,255) << text("QUIT: 'ESCAPE'");
            gout << move_to (250,500) << color (255,255,255) << text("RESTART: 'ENTER'");
            gout << refresh;
            event ev;
            while(gin >> ev && ev.keycode != key_enter && ev.keycode != key_escape)
            {

            }
            if (ev.keycode == key_escape)
            {
                restart = false;
            }
        }

        if (game == 4)
        {
            gout << move_to(0,0) << color(0,0,0) << box(620,620);
            gout.load_font("Transformers Movie.ttf",30);
            gout << move_to (250,300) << color (255,255,255) << text("GREEN WON !");
            gout.load_font("Transformers Movie.ttf",22);
            gout << move_to (250,450) << color (255,255,255) << text("QUIT: 'ESCAPE'");
            gout << move_to (250,500) << color (255,255,255) << text("RESTART: 'ENTER'");
            gout << refresh;
            gout << refresh;
            event ev;
            while(gin >> ev && ev.keycode != key_enter && ev.keycode != key_escape)
            {

            }
            if (ev.keycode == key_escape)
            {
                restart = false;
            }
        }
    }

    return 0;
}
