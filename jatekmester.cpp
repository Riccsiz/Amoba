#include "graphics.hpp"
#include "kocka.hpp"
#include "jatekmester.hpp"



jatekmester::jatekmester()
{
    for(int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            palya[i][j] = new AmobaKocka(i*30+10,j*30+10,30,30);
        }
    }
}

jatekmester::kezd()
{
    aktualis = 1;
    for(int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            palya[i][j]->handle(0);
            palya[i][j]->draw();
        }
    }
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

        if (ev.type == ev_key && ev.keycode == key_enter)
        {
            kezd();
        }

        if (ev.type == ev_mouse && ev.pos_x <= 620-10 && ev.pos_x >= 10 && ev.pos_y >= 10 && ev.pos_y <= 620-10 && ev.button == btn_left)
        {
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
        int k = kinyert();
        if (k > 0)
        {
            return 2+k;
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
    for(int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {

            //vízszintes
            if (i+5 < 20)
            {
                if (palya[i][j]->tartalom() >0 && palya[i][j]->tartalom() == palya[i+1][j]->tartalom() && palya[i][j]->tartalom() == palya[i+2][j]->tartalom() && palya[i][j]->tartalom() == palya[i+3][j]->tartalom() && palya[i][j]->tartalom() == palya[i+4][j]->tartalom() )
                {
                    return palya[i][j]->tartalom();
                }
            }

            //függõleges
            if (j+5 < 20)
            {
                if (palya[i][j]->tartalom() >0 && palya[i][j]->tartalom() == palya[i][j+1]->tartalom() && palya[i][j]->tartalom() == palya[i][j+2]->tartalom() && palya[i][j]->tartalom() == palya[i][j+3]->tartalom() && palya[i][j]->tartalom() == palya[i][j+4]->tartalom() )
                {
                    return palya[i][j]->tartalom();
                }
            }

            //jobbra átló
            if (j+5 < 20 && i+5 <20)
            {
                if (palya[i][j]->tartalom() >0 && palya[i][j]->tartalom() == palya[i+1][j+1]->tartalom() && palya[i][j]->tartalom() == palya[i+2][j+2]->tartalom() && palya[i][j]->tartalom() == palya[i+3][j+3]->tartalom() && palya[i][j]->tartalom() == palya[i+4][j+4]->tartalom() )
                {
                    return palya[i][j]->tartalom();
                }
            }

            //balra átló
            if (j+5 < 20 && i-5 >= 0)
            {
                if (palya[i][j]->tartalom() >0 && palya[i][j]->tartalom() == palya[i-1][j+1]->tartalom() && palya[i][j]->tartalom() == palya[i-2][j+2]->tartalom() && palya[i][j]->tartalom() == palya[i-3][j+3]->tartalom() && palya[i][j]->tartalom() == palya[i-4][j+4]->tartalom() )
                {
                    return palya[i][j]->tartalom();
                }
            }

        }
    }
    return 0;
}
