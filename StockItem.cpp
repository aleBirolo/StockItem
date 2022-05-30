#include "StockItem.h"

StockItem::StockItem(int id,const char *nombre, float precio, int nArticulos)
{
    this->id=id;

    //this->nombre = new char[1];
    //this->nombre[0]='\0';
    if (nombre == NULL)
        this->nombre=NULL;
    else
    {
        this->nombre= new char[ strlen(nombre) + 1 ];
        strcpy(this->nombre, nombre);
    }

    this->precio=precio;
    this->nArticulos=nArticulos;
}

void StockItem::mostrar ()
{
    cout << "id = "             << this->id
         << " , nombre = "      << ((this->nombre != NULL) ? this->nombre : "NULL")
         << " , precio = "      << this->precio
         << " , nArticulos = "  << this->nArticulos
         << endl;
}

ostream& operator<< (ostream &sal, const StockItem &st)
{
    return sal << "id = "            << st.id
               << " , nombre = "     << ((st.nombre != NULL) ? st.nombre : "NULL")
               << " , precio = "     << st.precio
               << " , nArticulos = " << st.nArticulos;
}

StockItem &StockItem::operator++ ()
{
    this->nArticulos++;

    return *this;
}

StockItem StockItem::operator++ (int)
{
    StockItem temp=*this;

    ++*this;

    return temp;
}

istream &operator>> (istream &ent, StockItem &st)
{
    char linea[500];

    cout << "Ingrese ID: ";
    ent  >> st.id ;
    ent.ignore();
    cout << "Ingrese Nombre: ";
    ent.getline(linea, 500);
    st.nombre = new char[strlen(linea)+1];
    strcpy(st.nombre, linea);

    cout << "Ingrese Precio: ";
    ent  >> st.precio ;
    cout << "Ingrese nArticulos: ";
    ent  >> st.nArticulos ;
    return ent;
}

StockItem::~StockItem()
{
    delete []this->nombre;
}
