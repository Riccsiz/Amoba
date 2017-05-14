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
        virtual int kezd();

    protected:
        AmobaKocka *palya[20][20];

    private:
        int aktualis;
        bool betelt();
        int kinyert();
};

#endif // JATEKMESTER_H
