#include "clNode.h"
#include <iostream>

using namespace std;

clNode::clNode(): str(new char[5])
{
   // cout<<"clNode()\n";
}
clNode::clNode(int x0, int y0, int num):clCircle(x0, y0), str(new char[5])
{
   // cout<<"clNode(int x0, int y0, int num)\n";
    Setstr(num);
}

clNode::~clNode()
{
    delete [] str;
   // cout<<"~clNode()\n";
}
void clNode::show()
{
    int x = Getx()-4;
    int y = Gety() -8;
    clCircle::show();
    outtextxy(x, y, str);
}
