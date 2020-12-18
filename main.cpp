#include <iostream>
#include <graphics.h>
#include "clNode.h"
#include "clLine.h"
#include "Graph.h"
#include <fstream>
using namespace std;
//��������� ��������� �������� �� ������������ ��� ���������� � ���� ������� �����. ���� �� ������������,
// �� �������(���� � �������� ���� ����� �������� ����� ������������� �����).
// ���� ���������� �� ���� ��������, ������� ���������� � ������ �����)
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
    }
    Graph g(n, arr, edges);
    g.show();
    readkey();

    g.dvudolnost();

    readkey();
    closegraph();
    return 0;
}
