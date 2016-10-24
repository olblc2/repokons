//Anna Gogolinska
//leii

#include<iostream>
using namespace std;

template <typename T1, typename T>
class krawedz;

template <typename T1, typename T>
class kolejka;

template <typename T1, typename T>
class lista;

template <typename T1, typename T>
class wezel{
      private:
              T1 name;//moze zamiast int ma byc T?
              int key;//uzywany przy primie
              int kolor;//kolor w bfs,...
              int d;//glebokosc w bsf
              wezel* next;
              wezel* pop;
              krawedz<T1,T>* sasiad;
      public:
             wezel()
                    {}
             friend class lista<T1,T>;
             friend class krawedz<T1,T>;
             friend class kolejka<T1,T>;
             
             template <typename T2, typename T3>
             friend ostream & operator << (ostream &wyj, const lista<T2,T3> & l);
      };
      
      
template <typename T1, typename T>
class krawedz{
      private:
              T1 name;//moze zamiast int ma byc T?
              T waga;
              krawedz* next;
      public:
             krawedz()
                      {}
             template <typename T2, typename T3>
             friend ostream & operator << (ostream &, const lista<T2,T3> &);
             friend class wezel<T1,T>;
             friend class lista<T1,T>;
      };
      
template <typename T1, typename T>
class lista{
      private:
              wezel<T1,T>* pocz;
      public:
             lista(){
                     pocz=NULL;
                     }
             ~lista();
             bool pusta()
                  {
                  if(pocz==NULL)return true;
                  else return false;
                  }
             void dodaj(const T1 &,const T1 &, const T &);
             void bfs(const T1 & );
             void dfs();
             void odwiedz(wezel<T1,T> *);
             void dijkstra(const T1 & );
             void prim(const T1 & );
             void wypisz();
             template <typename T2, typename T3>
             friend ostream & operator << (ostream &, const lista<T2,T3> &);
      };


template <typename T1, typename T>
class kolejka{
  private:
    wezel<T1,T> *pocz, * kon;
  public:
    kolejka()
    {
      pocz=kon=NULL;
    }
    ~kolejka();
    bool pusta();
    void dodaj(const wezel<T1,T>*);
    void usun();  
    wezel<T1,T>* usunmin(); 
    void wypisz();
    friend class lista<T1,T>;
};

     
