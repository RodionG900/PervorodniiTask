#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <iostream>
#include <vector>
#include "Graph.h"


Graph::Graph()
{

}
Graph::Graph(int n_, int * vert_, int* edges_): n(n_), vert(new clNode[n_]), edges(new int[n_*n_]){
    double pi = 3.14;
    //задаем координаты вершин(стоят по кругу, считаются с нуля)
    for(int i = 0; i<n_; i++){
        char s[5];
        vert[i].Setstr(vert_[i]);
        vert[i].Setx((int)(315+100*(cos(2*pi*i/n))));
        vert[i].Sety((int)(215+100*(sin(2*pi*i/n))));
    }
    //переносим матрицу смежности
    for(int i = 0; i<n*n; i++) {
            edges[i] = edges_[i];
    }
}
Graph::~Graph()
{

}
void Graph::show()
{
    //выводит вершиы
    for(int i = 0; i<n; i++){
        vert[i].show();
    }
    //выводит ребра
    for(int i = 0; i<n; i++){
        for(int j=0; j<=i; j++ ){
            if (edges[n*i+j]>0){
                line(vert[i].Getx(), vert[i].Gety(), vert[j].Getx(), vert[j].Gety());
                char ch[5];
                itoa(edges[n*i+j], ch, 10);
            }
        }
    }
}
int Graph::dfs(int depth,int num,int sgn, vector<pair<int, int>> t ){
    //стандартный проход в глубину, красит текущую вершину в зависимости от предыдущей вершины и идет дальше
    //натыкаясь на уже покрашенную смотрит нет ли противоречия и возвращается.
    if(depth>n) return 0;
    //это проверка на покрашенность и покраска:
    if(t[num].second==-1) {
            t[num].second = (sgn+1)%2;
            vert[num].color = (sgn+1)%2;
    }
    else if((sgn+(t[num].second))%2==0) {
            return 1;
    }
    else return 0;
    //это рекурсивный переход:
    int m = 0;
    for(int i = 0; i<n; i++){
        int l = t[num].second;
        if(edges[n*num+i]>0) m+=dfs(depth+1, i, l, t);
    }
    return m>0;
}
void Graph::dvudolnost()
{
    //двудольность графа равносильна покраске в 2 цвета
    //алгоритм запускает покраску на компонентах связности графа с помощью dfs
    //при обнаружении противоречия(вообще говоря это значит, что мы
    //пришли в какую-то уже покрашенную вершину, цвет которой совпал с предыдущей),
    //алгоритм останавливается и выводит impossible
    //если все компоненты успешно покрашены, картинка красится в новые цвета(цвет отвечает за долю двудольного графа)
    vector<pair<int, int>> ver(n);
    for(int i = 0; i<n; i++){
        ver[i] = make_pair(i, -1);
    }
    //k равен 0 пока dfs не наткнется на противоречие
    int k=0;
    for(int i = 0; i<n; i++){
        //запускаю поиск на каждой из ещё не обработанных вершин(граф может быть несвязен)
        if(ver[i].second==-1) k = dfs(0, i,1, ver);

        if (k==1){
            cout<<"\nImpossible\n";
            break;
        }
    }
    if(k==0){
        cout<<"\nPossible!\n";
    }



    for(int i = 0; i<n; i++){
        if(k==0) setcolor(vert[i].color+6);
        vert[i].show();
    }
}

