//Anna Gogolinska
//leii

#include<iostream>
#include"graf.hpp"

#define N 10000

using namespace std;

template <typename T1, typename T>
void lista<T1,T>::dodaj(const T1 & z, const T1& doo, const T &w)
{
     if(w>N){
                 cout<<"za duza waga"<<endl;
                 return;
                 }
     if(pusta()){
                 wezel<T1,T>* pom;
                 wezel<T1,T>* pom2;
                 pom=new wezel<T1,T>;
                 pom2=new wezel<T1,T>;
                 pom->name=z;
                 pom->key=pom->d=N;
                 pom->next=pom2;
                 pom->pop=NULL;
                 pom2->name=doo;
                 pom2->key=pom2->d=N;
                 pom2->next=NULL;
                 pom2->pop=NULL;
                 krawedz<T1,T>* sad1;
                 krawedz<T1,T>* sad2;
                 sad1=new krawedz<T1,T>;
                 sad2=new krawedz<T1,T>;
                 sad1->name=doo;
                 sad1->waga=w;
                 sad1->next=NULL;
                 pom->sasiad=sad1;
                 sad2->name=z;
                 sad2->waga=w;
                 sad2->next=NULL;
                 pom2->sasiad=sad2;
                 pocz=pom;
                 return;
                 }
     wezel<T1,T>* q;
     krawedz<T1,T>* sad;
     krawedz<T1,T>* sad2;
     q=pocz;
     while( (q!=NULL)&&(q->name!=z) )q=q->next;
     if(q==NULL)//nie ma wezla
               {
               q=pocz;
               pocz=new wezel<T1,T>;
               pocz->name=z;
               pocz->pop=NULL;
               pocz->next=q;
               pocz->key=pocz->d=N;
               sad=new krawedz<T1,T>;
               sad->name=doo;
               sad->waga=w;
               pocz->sasiad=sad;
               sad->next=NULL;
               }
     else {//wezel juz jest, dodaj tylko nowego sasiada
          sad=q->sasiad;
          sad2=new krawedz<T1,T>;
          sad2->name=doo;
          sad2->waga=w;
          q->sasiad=sad2;
          sad2->next=sad;
          }
     q=pocz;
     while( (q!=NULL)&&(q->name!=doo) )q=q->next;
     if(q==NULL)//nie ma wezla
               {
               q=pocz;
               pocz=new wezel<T1,T>;
               pocz->name=doo;
               pocz->pop=NULL;
               pocz->next=q;
               pocz->key=pocz->d=N;
               sad=new krawedz<T1,T>;
               sad->name=z;
               sad->waga=w;
               pocz->sasiad=sad;
               sad->next=NULL;
               }
     else {//wezel juz jest, dodaj tylko nowego sasiada
          sad=q->sasiad;
          sad2=new krawedz<T1,T>;
          sad2->name=z;
          sad2->waga=w;
          q->sasiad=sad2;
          sad2->next=sad;
          }
     return;
     }


template <typename T1, typename T>
ostream& operator << (ostream & wyj, const lista<T1,T> & l)
{
         wezel<T1,T>* q;
         krawedz<T1,T>* sad;
         q=l.pocz;
         while(q!=NULL){
                        wyj<<"wezel: "<<q->name<<" klucz: "<<q->key<<" sasiedzi:"<<endl;
                        if(q->pop!=NULL)cout<<"poprzednik: "<<q->pop->name<<" glebokosc: "<<q->d<<endl;
                        sad=q->sasiad;
                        while(sad!=NULL){
                                         wyj<<"    sasiad: "<<sad->name<<" wartosc: "<<sad->waga<<endl;
                                         sad=sad->next;
                                         }
                        q=q->next;
                        }
         return wyj;
         }



template <typename T1, typename T>
bool kolejka<T1,T>::pusta()
{
     if(kon==NULL)return true;
     else return false;
}

template <typename T1, typename T>
void kolejka<T1,T>::dodaj(const wezel<T1,T>* dod)
{
     if(pusta()){
                 pocz=new wezel<T1,T>;
                 pocz->name=dod->name;
                 pocz->key=dod->key;
                 pocz->sasiad=NULL;
                 pocz->next=pocz->pop=NULL;
                 kon=pocz;
                 }
     else{
          wezel<T1,T>* pom;
          pom=new wezel<T1,T>;
          pom->name=dod->name;
          pom->key=dod->key;
          pom->sasiad=NULL;
          pom->next=NULL;
          pom->pop=kon;
          kon->next=pom;
          kon=pom;
          }
     return;
}

template <typename T1, typename T>
void kolejka<T1,T>::usun(void)
{
     if(pusta()){
                 cout<<"kolejka jest pusta"<<endl;
                 return;
                 }
     if(pocz==kon){
                   delete pocz;
                   pocz=kon=NULL;
                   }
     else{
          wezel<T1,T>* pom;
          pom=pocz;
          pocz=pocz->next;
          pocz->pop=NULL;
          delete pom;
          }
     return;
}


template <typename T1, typename T>
void lista<T1,T>::bfs(const T1 & korz)
{
     wezel<T1,T>* s;
     s=pocz;
     while( (s!=NULL)&&(s->name!=korz) )s=s->next;
     if(s==NULL){
                 cout<<"nie ma takiego korzenia"<<endl;
                 return;
                 }
     wezel<T1,T>* u;
     wezel<T1,T>* pom;
     krawedz<T1,T>* sad;
     u=pocz;
     while(u!=NULL){
                    u->kolor=0;//bialy
                    u->d=N;
                    u->pop=NULL;
                    u=u->next;
                    }
     s->kolor=1;//szary
     s->d=0;
     kolejka<T1,T> Q;
     Q.dodaj(s);
     while(!Q.pusta()){
                       u=pocz;
                       while(u->name!=Q.pocz->name)u=u->next;
                       sad=u->sasiad;
                       while(sad!=NULL){
                                        pom=pocz;
                                        while(pom->name!=sad->name)pom=pom->next;
                                        if(pom->kolor==0){
                                                          pom->pop=u;
                                                          pom->kolor=1;
                                                          pom->d=u->d+1;
                                                          Q.dodaj(pom);
                                                          }
                                        sad=sad->next;
                                        }
                       Q.usun();
                       u->kolor=2;//czarny
                       }
     return;
}

                    
template <typename T1, typename T>
void lista<T1,T>::dfs(void)
{
     wezel<T1,T>* u;
     u=pocz;
     while(u!=NULL){
                    u->pop=NULL;
                    u->kolor=0;
                    u=u->next;
                    }
     u=pocz;
     while(u!=NULL){
                   if(u->kolor==0)odwiedz(u);
                   u=u->next;
                   }
     return;
     }

     
template <typename T1, typename T>
void lista<T1,T>::odwiedz(wezel<T1,T>* u)//do dfs
{
     u->kolor=1;
     krawedz<T1,T>* v;
     wezel<T1,T>* pom;
     v=u->sasiad;
     while(v!=NULL){
                   pom=pocz;
                   while(pom->name!=v->name)pom=pom->next;
                   if(pom->kolor==0){
                                     pom->pop=u;
                                     odwiedz(pom);
                                     }
                   v=v->next;
                   }
     u->kolor=2;
     }


template <typename T1, typename T>
void kolejka<T1,T>::wypisz()
{
     wezel<T1,T>* pom;
     pom=pocz;
     while(pom!=NULL){
                      cout<<"nazwa: "<<pom->name<<" klucz: "<<pom->key<<endl;
                      if(pom->pop==NULL)cout<<"    pop: NULL"<<endl;
                      else cout<<"    pop: "<<pom->pop->name<<endl;
                      if(pom->next==NULL)cout<<"    next: NULL"<<endl;
                      else cout<<"    next: "<<pom->next->name<<endl;
                      pom=pom->next;
                      }
     }
                      
                      
 
template <typename T1, typename T>
wezel<T1,T>* kolejka<T1,T>::usunmin(void)
{
          if(pusta()){
                      cout<<"kolejka jest pusta"<<endl;
                      return NULL;
                      }
          wezel<T1,T>* min;
          min=pocz;
          if(pocz==kon){
                        kon=pocz=NULL;
                        return min;
                        }
          wezel<T1,T>* pom;
          pom=pocz;
          while(pom!=NULL){
                           if(pom->key<min->key)min=pom;
                           pom=pom->next;
                           }
          if(min==pocz)pocz=pocz->next;
          else if(min==kon)kon=kon->pop;
          else{
               if(min->pop!=NULL)min->pop->next=min->next;
               if(min->next!=NULL)min->next->pop=min->pop;
               }          
          return min;
          }
          
          
template <typename T1, typename T>
void lista<T1,T>::prim(const T1 & korz)
{
     wezel<T1,T>* r;
     r=pocz;
     while((r!=NULL)&&(r->name!=korz))r=r->next;
     if(r==NULL){
                 cout<<"nie ma takiego korzenia"<<endl;
                 return;
                 }
     wezel<T1,T>* u;
     wezel<T1,T>* pom;
     wezel<T1,T>* pom2;
     wezel<T1,T>* v;
     krawedz<T1,T>* sad;
     u=pocz;
     while(u!=NULL){
                    u->key=N;
                    u->pop=NULL;
                    u=u->next;
                    }
     r->key=0;
     r->pop=NULL;
     kolejka<T1,T> Q;
     u=pocz;
     while(u!=NULL){
                    Q.dodaj(u);
                    u=u->next;
                    }
     while(!Q.pusta()){
                       u=Q.usunmin();//u to min w kolejce Q
                       pom=pocz;//pom to min na liscie sasiadztwa (pom=u tylko na innych listach)
                       while(pom->name!=u->name)pom=pom->next;
                       sad=pom->sasiad;
                       while(sad!=NULL){//sad(jako sasiad)==pom2(Q)==v(lista)
                                        pom2=Q.pocz;
                                        while((pom2!=NULL)&&(pom2->name!=sad->name))pom2=pom2->next;
                                        //szuka czy sasiad sad jest w Q, jesli tak to jest to pom2
                                        if((pom2!=NULL)&&(sad->waga<pom2->key))
                                             {
                                             v=pocz;
                                             while((v!=NULL)&&(v->name!=sad->name))v=v->next;
                                             v->pop=pom;
                                             pom2->key=sad->waga;
                                             }
                                        sad=sad->next;                   
                                        }
                       }
     }
     
     
template <typename T1, typename T>
void lista<T1,T>::dijkstra(const T1 & ko)
{
     wezel<T1,T>* s;
     s=pocz;
     while((s!=NULL)&&(s->name!=ko))s=s->next;
     if(s==NULL){
                 cout<<"nie ma takiego korzenia"<<endl;
                 return;
                 }
     kolejka<T1,T> S;
     kolejka<T1,T> Q;
     wezel<T1,T> * u;//u to min usuniete z kolejki
     krawedz<T1,T>* v;//to sasiad u
     wezel<T1,T>* lv;//to sasiad tylko ze na liscie
     wezel<T1,T>* lu;//to tez wezel u tylko ze na liscie 
     wezel<T1,T>* qv;
     u=pocz;
     while(u!=NULL){
                    u->pop=s;
                    u->key=N;
                    u=u->next;
                    }
     s->pop=NULL;
     s->key=0;
     u=pocz;
     while(u!=NULL){
                    Q.dodaj(u);
                    u=u->next;
                    }            
     while(!Q.pusta()){
                       u=Q.usunmin();
                       S.dodaj(u);
                       lu=pocz;
                       while(lu->name!=u->name)lu=lu->next;
                       v=lu->sasiad;
                       while(v!=NULL){
                                      lv=pocz;
                                      qv=Q.pocz;
                                      while((qv!=NULL)&&(qv->name!=v->name))qv=qv->next;
                                      while(lv->name!=v->name)lv=lv->next;
                                      if(lv->key>lu->key+v->waga){
                                                                  lv->key=lu->key+v->waga;
                                                                  if(qv!=NULL)qv->key=lv->key;
                                                                  lv->pop=lu;
                                                                  }
                                      v=v->next;
                                      }
                       }
     }

template<typename T1, typename T>
lista<T1,T>::~lista()
{
     wezel<T1,T>* pom;
     krawedz<T1,T>* sad;
     krawedz<T1,T>* sad2;
     while(pocz!=NULL){
                       pom=pocz;
                       sad=pocz->sasiad;
                       while(sad!=NULL){
                                        sad2=sad;
                                        sad=sad->next;
                                        delete sad2;
                                        }
                       pocz=pocz->next;
                       delete pom;
                       }
     }

template<typename T1, typename T>
kolejka<T1,T>::~kolejka()
{
     wezel<T1,T>* pom;
     while(pocz!=NULL){
                       pom=pocz;
                       pocz=pocz->next;
                       delete pom;
                       }
     pocz=kon=NULL;
     }

