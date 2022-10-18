//Haz arder tu corazón 

#include <pthread.h>
#include "bits2.h"
#include "Arch.h"
#include "Grafo.h"

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int motos = 0;

void hacerPedido()
{
    string nom;
    cout<<"Porfavor dijiete el nombre del archivo con terminacion .txt\n";
    cin>>nom;
    lectura(nom);
}

void *worker(void *arg){
    int cos;
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
        while(cas!=6)
        {
            vis[cas]=true;
            cas = parent[cas];
        }
    }
}
int main()
{

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

    int select=0;
    while(select!=2)
    {
        if(motos!=3)
        {
            cout<<"Selecione 1 para hacer un nuevo pedido\n";
            cout<<"Seleciono 2 para cerrar el dia\n";
            cin>>select;
            if(select==1)
            {
                hacerPedido(); 
                if(pedidos.size()>=5)
                {
                    //hilo moto
                    //join
                    motos++;
                }                       
            }
            else if(select==2)
            {
                cout<<"Gran dia, los resultados se encuantran en el archivo resultados.txt";
            }
        }
        //join
    }
}

