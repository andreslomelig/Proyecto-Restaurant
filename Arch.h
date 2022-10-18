//Haz arder tu corazón 

#include <bits/stdc++.h>

typedef long long LL;
#define pb push_back 
#define ciclo(i,x) for(int i=0;i<x;i++)
#define cicloR(i,x) for(int i=x-1;i>=0;i--)
#define TestCase(x) for(int Te=1;Te<=x;Te++)

using namespace std;

int pedact = 0;

int conver(string a)
{
    int tam = a.length();
    int num = 1;
    int act = 1;
    cicloR(i,tam)
    {
        num=num*((a[i]-48)*act);
        act=act*10;
    }
    return num;
}

class pedido{
    private:
        int num;
        string ped;
        int casa;
        int precio;
    public:
        pedido();
        pedido(int,string,int,int);
        int getCasa();
};

pedido::pedido(){};

pedido::pedido(int _num, string _ped, int _casa, int _precio){
    num = _num;
    ped = _ped;
    casa = _casa;
    precio = _precio;
}

int pedido::getCasa()
{
    return casa;
}

queue<pedido> pedidos;

void agregarPedido(string cad){
    int tam = cad.length();
    string arr[4];
    string act;
    int n = 0;
    ciclo(i,tam){
        if(cad[i]=='/')
        {
            arr[n] = act;
            n++;
            act = "";
        }
        else
        {
            act = act+cad[i];
        }
    }
    int num = conver(arr[0]);
    int casa = conver(arr[2]);
    int precio = conver(arr[3]);
    pedido actual(num,arr[1],casa,precio);
    pedidos.push(actual);
}


void lectura(string nombre)
{
    ifstream archivo;
    string text;

    archivo.open(nombre,ios::in);

    if(archivo.fail()){
        cout<<"El arhcivo no se puede abrir\n";
        return;
    }

    while(!archivo.eof()){
        getline(archivo,text);
        agregarPedido(text);
    }

    archivo.close();
    return;
}