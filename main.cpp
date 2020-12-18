#include <iostream>
#include <graphics.h>
#include "clNode.h"
#include "clLine.h"
#include "Graph.h"
#include <fstream>
using namespace std;
//Программа выполняет проверку на двудольность для введенного в виде таблицы графа. Граф не ориентирован,
// не взвешен(хотя в качестве веса ребра подходит любое положительное число).
// Если разделение на доли возможно, вершины покрасятся в разные цвета)
int main()
{

    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, "");
    int n;
    ifstream fin("input.txt");
    fin >> n;
    int ardob[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> ardob[i][j];
    fin.close();
    int arr [n];
    for(int i = 0; i<n;i++) arr[i]=i;

    int edges[n*n];
    int k = 0;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            edges[k] = ardob[i][j];
            k++;
        }
        cout << endl;
    }
    Graph g(n, arr, edges);
    g.show();
    readkey();

    g.dvudolnost();

    readkey();
    closegraph();
    return 0;
}
