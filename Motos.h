//Haz arder tu corazón 

#include "bits2.h"
#include "Arch.h"
#include "Grafo.h"
#include <pthread.h>
#include<ctime>

using namespace std;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

int motos = 0;
int mt1 = 0;
int mt2 = 0;
int mt3 = 0;

void delay(int secs) {
  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

void *moto1(void *arg){
    int cos=3;
    int tiempo = 0;
    bool vis[8];
    ciclo(i,8)
    {
        vis[i]=false;
    }
    pedido destinos[5];
    pthread_mutex_lock( &mutex1 );
    ciclo(i,cos)
    {
        pedido act = pedidos.front();
        destinos[i] = act;
        pedidos.pop();
    }
    pthread_mutex_unlock( &mutex1 );
    ciclo(i,cos)
    {
        int cas = destinos[i].getCasa();
        if(!vis[cas])
        {
            tiempo = tiempo +padj[cas];
            while(cas!=6)
            {
                if(vis[cas])
                {
                    tiempo = tiempo - padj[cas];
                    break;
                }
                vis[cas]=true;
                cas = parent[cas];
            }
        }
    }
    delay(tiempo);
    cout<<tiempo<<"\n";
    cout<<"Pedidos moto 1 entregados\n";
    pthread_mutex_lock( &mutex2 );
    motos--;
    mt1=0;
    pthread_mutex_unlock( &mutex2 );
}

void *moto2(void *arg){
    int cos=3;
    int tiempo = 0;
    bool vis[8];
    ciclo(i,8)
    {
        vis[i]=false;
    }
    pedido destinos[5];
    pthread_mutex_lock( &mutex1 );
    ciclo(i,cos)
    {
        pedido act = pedidos.front();
        destinos[i] = act;
        pedidos.pop();
    }
    pthread_mutex_unlock( &mutex1 );
    ciclo(i,cos)
    {
        int cas = destinos[i].getCasa();
        if(!vis[cas])
        {
            tiempo = tiempo +padj[cas];
            while(cas!=6)
            {
                if(vis[cas])
                {
                    tiempo = tiempo - padj[cas];
                    break;
                }
                vis[cas]=true;
                cas = parent[cas];
            }
        }
    }
    delay(tiempo);
    cout<<tiempo<<"\n";
    cout<<"Pedidos moto 2 entregados\n";
    pthread_mutex_lock( &mutex2 );
    motos--;
    mt2=0;
    pthread_mutex_unlock( &mutex2 );
}

void *moto3(void *arg){
    int cos=3;
    int tiempo = 0;
    bool vis[8];
    ciclo(i,8)
    {
        vis[i]=false;
    }
    pedido destinos[5];
    pthread_mutex_lock( &mutex1 );
    ciclo(i,cos)
    {
        pedido act = pedidos.front();
        destinos[i] = act;
        pedidos.pop();
    }
    pthread_mutex_unlock( &mutex1 );
    ciclo(i,cos)
    {
        int cas = destinos[i].getCasa();
        if(!vis[cas])
        {
            tiempo = tiempo +padj[cas];
            while(cas!=6)
            {
                if(vis[cas])
                {
                    tiempo = tiempo - padj[cas];
                    break;
                }
                vis[cas]=true;
                cas = parent[cas];
            }
        }
    }
    delay(tiempo);
    cout<<tiempo<<"\n";
    cout<<"Pedidos moto 3 entregados\n";
    pthread_mutex_lock( &mutex2 );
    motos--;
    mt3=0;
    pthread_mutex_unlock( &mutex2 );
}