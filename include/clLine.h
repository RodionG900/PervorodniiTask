#ifndef CLLINE_H
#define CLLINE_H
#include "dDraw.h"

class clLine : public dDraw
{
    public:
        clLine();

        clLine(int x3, int y3, int x4, int y4);
        virtual ~clLine();

        int Getx1() { return x1; }
        void Setx1(int val) { x1 = val; }
        int Gety1() { return y1; }
        void Sety1(int val) { y1 = val; }
        int Getx2() { return x2; }
        void Setx2(int val) { x2 = val; }
        int Gety2() { return y2; }
        void Sety2(int val) { y2 = val; }
        void show();

    protected:

    private:
        int x1;
        int y1;
        int x2;
        int y2;
};

#endif // CLLINE_H
