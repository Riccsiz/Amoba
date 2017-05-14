#ifndef KOCKA_HPP_INCLUDED
#define KOCKA_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

using namespace std;
using namespace genv;

class AmobaKocka : public Widget {
protected:
    int m_tartalom;
public:
    AmobaKocka(int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void handle(int ertek);
    virtual int tartalom();
};


#endif // KOCKA_HPP_INCLUDED

