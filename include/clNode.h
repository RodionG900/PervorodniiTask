#ifndef CLNODE_H
#define CLNODE_H
#include <cstdlib>
#include "clCircle.h"


class clNode : public clCircle
{
    public:
        clNode();
        clNode(int x0, int y0, int num);
        void show();
        virtual ~clNode();

        char * Getstr() { return str; }
        void Setstr(int val) { itoa(val, str, 10); }
        bool color = 0;

    protected:

    private:
        char * str;

};


#endif // CLNODE_H
