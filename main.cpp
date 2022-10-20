//Haz arder tu corazón 


#include "Motos.h"

using namespace std;

void hacerPedido()
{
    string nom;
    cout<<"Porfavor dijite el nombre del archivo con terminacion .txt\n";
    cin>>nom;
    lectura(nom);
}

int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
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
    dijkstra(&g,6);

    int select = 0;

    while(select!=2)
    {   if(motos!=3){
            cout<<"Selecione 1 para hacer un nuevo pedido\n";
            cout<<"Selecione 2 para cerrar el dia\n";
            cin>>select;

            if(select==1)
            {
                hacerPedido(); 
                if(mt1==0)
                {
                    pthread_create(&thread1,NULL, &moto1 ,NULL );
                    mt1=1;
                    motos++;                      
                }
                else if(mt2==0)
                {
                    pthread_create(&thread2,NULL, &moto2 ,NULL );
                    mt2=1;
                    motos++;                      
                }
                else if(mt3==0)
                {
                    pthread_create(&thread3,NULL, &moto3 ,NULL );
                    mt3=1;
                    motos++;                      
                }

            }
            else if(select==2)
            {
                if(mt1==1)
                {
                    cout<<"Esperando moto 1\n";
                    pthread_join(thread1, NULL);
                }
                if(mt2==1)
                {
                    cout<<"Esperando moto 2\n";
                    pthread_join(thread2, NULL);
                }
                if(mt3==1)
                {
                    cout<<"Esperando moto 3\n";
                    pthread_join(thread3, NULL);
                }
                cout<<"Gran dia, los resultados se encuantran en el archivo resultados.txt";
            }
        }
        else{
            while(mt1==1 && mt2==1 && mt3==1){}
        }
    }    
}