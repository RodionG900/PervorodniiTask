#include "clCircle.h"
#include <iostream>
#include <graphics.h>

using namespace std;

clCircle::clCircle()
{
  //  cout << "clCircle::clCircle()" << endl;
}
clCircle::clCircle(int x0, int y0): x (x0), y (y0)
{
   // cout << "clCircle::clCircle(int x0, int y0)" << endl;
}

clCircle::~clCircle()
{
  //  cout << "clCircle::~clCircle()" << endl;
}

void clCircle::show()
{
    circle(x, y, r);

}
