#include<iostream>
#include"graf.cpp"

using namespace std;

int main()
{
    char t;
    int z,doo;
    int w;
    lista<int,int> l;
	cout<<"zmiana";
    do
      {
      cout<<"czy dodac element? ";
      cin>>t;
      if(t=='t'){
                 cout<<"podaj z jakiego wezla ";
                 cin>>z;
                 cout<<"podaj do jakiego wezla ";
                 cin>>doo;
                 cout<<"podaj wartosc polaczenia ";
                 cin>>w;
                 l.dodaj(z,doo,w);
                 }
      }while(t!='n');
    cout<<l;
    cout<<"z jakiego wierzcholka chcesz zaczac bfs? ";
    cin>>z;
    //l.bfs(z);
    //cout<<l;
    l.prim(z);
    cout<<l;
    //l.dijkstra(z);
    //l.dfs();
    cout<<l;
    return 0;
}

