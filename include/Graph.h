#ifndef GRAPH_H
#define GRAPH_H
#include "clNode.h"
#include <vector>
using namespace std;
class Graph: public dDraw
{
    public:
        Graph();
        Graph(int n_, int * vert_, int* edges_);
        void dvudolnost();
        virtual ~Graph();
        void show();

    protected:

    private:
        int n;
        int dfs(int depth,int num,int sgn, vector<pair<int, int>> t );
        clNode * vert;
        int * edges;

};

#endif // GRAPH_H
