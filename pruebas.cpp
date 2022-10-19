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

void delay(int secs) {
  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

void hacerPedido()
{
    string nom;
    cout<<"Porfavor dijiete el nombre del archivo con terminacion .txt\n";
    cin>>nom;
    lectura(nom);
}

void *worker(void *arg){
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
    pthread_mutex_lock( &mutex2 );
    motos--;
    pthread_mutex_unlock( &mutex2 );
}

int main()
{
    pthread_t thread1;
    graph g;
    int m = 5;
    bool directed = false;

    initialize_graph(&g, directed);

    insert_edge(&g,6,1,10,directed);
    insert_edge(&g,6,5,25,directed);
    insert_edge(&g,5,7,24,directed);
    insert_edge(&g,1,2,28,directed);
    insert_edge(&g,7,2,14,directed);
    insert_edge(&g,2,3,16,directed);
    insert_edge(&g,4,3,12,directed);
    insert_edge(&g,5,4,22,directed);
    insert_edge(&g,4,7,18,directed);

    print_graph(&g);
    cout<<"\n";
    cout<<dijkstra(&g,6)<<"\n";
    ciclo(i,8)
    {
        cout<<i<<" "<<parent[i]<<" ";
    }
    cout<<"\n";
    int select = 0;

    while(select!=2)
    {   if(motos!=3){
            cout<<"Selecione 1 para hacer un nuevo pedido\n";
            cout<<"Selecione 2 para cerrar el dia\n";
            cin>>select;

            if(select==1)
            {
                hacerPedido(); 
                pthread_create(&thread1,NULL, &worker ,NULL );
                motos++;                      
            }
            else if(select==2)
            {
                pthread_join(thread1, NULL);
                cout<<"Gran dia, los resultados se encuantran en el archivo resultados.txt";
            }
        }
        else{
            pthread_join(thread1, NULL);
        }
    }
}

