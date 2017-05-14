#include "kocka.hpp"
#include "graphics.hpp"
using namespace genv;

AmobaKocka::AmobaKocka(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    m_tartalom=0;
}

void AmobaKocka::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    if (m_tartalom==0)
        gout << color(0,0,0);
    else if (m_tartalom==1)
        gout << color(255,0,0);
    else
        gout << color(0,255,0);
    gout << move_to(_x+4, _y+4) << line(_size_x-8, _size_y-8);
    gout << move_to(_x+5, _y+4) << line(_size_x-8, _size_y-8);
    gout << move_to(_x+_size_x-4, _y+4) << line(-_size_x+8, _size_y-8);
    gout << move_to(_x+_size_x-5, _y+4) << line(-_size_x+8, _size_y-8);

}

void AmobaKocka::handle(int ertek)
{
    m_tartalom = ertek;
    AmobaKocka::draw();
}

int AmobaKocka::tartalom()
{
    return m_tartalom;
}

