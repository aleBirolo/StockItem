#ifndef STOCKITEM_H
#define STOCKITEM_H

#include <iostream>
#include <string.h>

using namespace std;

class StockItem
{
    public:
        StockItem(int id=0,const char *nombre=NULL, float precio=0, int nArticulos=0);
        void mostrar ();
        friend ostream &operator<< (ostream &sal, const StockItem &st);
        StockItem &operator++ ();
        StockItem operator++ (int);
        friend istream &operator>> (istream &ent, StockItem &st);
        ~StockItem();
    protected:

    private:
        int id;
        char *nombre;
        float precio;
        int nArticulos;
};

#endif // STOCKITEM_H
