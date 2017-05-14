#include "graphics.hpp"
#include "kocka.hpp"
#include "jatekmester.hpp"



jatekmester::jatekmester()
{
    aktualis = 1;
    for(int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            palya[i][j] = new AmobaKocka(i*30+10,j*30+10,30,30);
            palya[i][j]->draw();
            palya[i][j]->handle(1); //TEST !


        }
    }
    palya[0][0]->handle(0); // TEST !!
    gout << refresh;
}

int jatekmester::jatek()
{
    event ev;
    while(gin >> ev)
    {
        if (ev.type == ev_key && ev.keycode == key_escape)
        {
            return 1;
        }
        if (ev.type == ev_mouse && ev.pos_x <= 610 && ev.pos_x >= 10 && ev.pos_y >= 10 && ev.pos_y <= 610 && ev.button == btn_left)
        {
/*            if (palya[(ev.pos_x-10)/30][(ev.pos_y-10)/30]->tartalom() ==0)
                palya[(ev.pos_x-10)/30][(ev.pos_y-10)/30]->handle(1);*/
            AmobaKocka *k =palya[(ev.pos_x-10)/30][(ev.pos_y-10)/30];
            if(k->tartalom()==0)
            {
                k->handle(aktualis);
                aktualis = 3 - aktualis;
            }
        }
        gout << refresh;
        if (betelt())
        {
            return 2;
        }
    }
    return 0;
}

bool jatekmester::betelt()
{
    for(int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (palya[i][j]->tartalom() == 0)
            {
                return false;
            }

        }
    }
    return true;
}

int jatekmester::kinyert()
{

}
