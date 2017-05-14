#ifndef JATEKMESTER_H
#define JATEKMESTER_H

#include "kocka.hpp"
#include "graphics.hpp"

using namespace std;
using namespace genv;

class jatekmester
{
    public:
        jatekmester();
        virtual int jatek();

    protected:
        AmobaKocka *palya[20][20];

    private:
        int aktualis;
};

#endif // JATEKMESTER_H
