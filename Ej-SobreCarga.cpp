//Nombre:
//TP Nro:
//Ej Nro:
//Comentarios:
#include<iostream>
using namespace std;



class Fecha
{
private:
    int _dia;
    int _mes;
    int _anio;
public:
    Fecha(int dia = 0,int mes = 0,int anio = 0 )
    {
        _dia = dia;
        _mes = mes;
        _anio = anio;
    }
    //setters y getters
    void setDia(const int dia)
    {
        _dia = dia;
    }
    void setMes(const int mes)
    {
        _mes = mes;
    }
    void setAnio(const int anio)
    {
        _anio = anio;
    }
    //void setearTodo(const int dia, const int mes, const int anio){_dia = dia; _mes = mes; _anio = anio;}

    int getDia()const
    {
        return _dia;
    }
    int getMes()const
    {
        return _mes;
    }
    int getAnio()const
    {
        return _anio;
    }

    void mostrarFecha()
    {
        cout << _dia << "/" << _mes << "/" << _anio << endl;
    }


    void cargar()
    {
        cout<<"Dia: ";
        cin >> _dia;
        cout<<"Mes: ";
        cin >> _mes;
        cout<<"Anio: ";
        cin >> _anio;
    }

    int getDiaActual()
    {
        time_t t = time(NULL); //time_t es un alias para un entero de 32 y 64 bits - time(NULL) nos da el el tiempo en formato 'timestamp' -> "Epoch time" es un punto inicial (como el 1 de enero de 1970, a las 00:00:00 UTC)
        struct tm *f = localtime(&t);// el struct tm convierte el timestamp a un formato entendible
        _dia = (*f).tm_mday; ////(*f).tm_mday => indirecciona f y accede a tm_day
        return _dia;
    }

    int getMesActual()
    {
        time_t t = time(NULL);
        struct tm *f = localtime(&t);

        _mes = f->tm_mon + 1;
        return _mes;
    }

    int getAnioActual()
    {
        time_t t = time(NULL);
        struct tm *f = localtime(&t);

        _anio = f->tm_year + 1900;
        return _anio;
    }
    int getHoraActual()
    {
        time_t t = time(NULL);
        struct tm *f = localtime(&t);
        return f->tm_hour;
    }

    int getMinutoActual()
    {
        time_t t = time(NULL);
        struct tm *f = localtime(&t);
        return f->tm_min;
    }

    int getSegundoActual()
    {
        time_t t = time(NULL);
        struct tm *f = localtime(&t);
        return f->tm_sec;
    }


    ~Fecha() {}

//a)Operador ==: debe recibir un objeto Fecha y devolver verdadero si son
// iguales y falso si son distintos


    bool operator == (Fecha &fec)
    {
        if(_dia == fec.getDia() && _mes == fec.getMes() && _anio == fec.getAnio())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

//b)Operador >: debe recibir un objeto Fecha y devolver verdadero si
// el objeto que llama al método es mayor y falso si no.
// Mayor significa que está más adelante en el calendario

    bool operator > (Fecha &fec2)
    {
        if(_anio > fec2.getAnio())
        {
            return true;
        }

       else if (_anio == fec2.getAnio())
        {
            if(_mes > fec2.getMes())
            {
                return true;
            }

        }

        else if (_mes == fec2.getMes())
        {
            if(_dia > fec2.getDia())
            {
                return true;
            }
            else
            {
                return false;
            }
        } return false;
    }


//c)+=: debe recibir un valor entero, y modificar al objeto que llama en una
// cantidad de días equivalente al valor entero que recibe.


void operator += (int d){
_dia = d;

}


//d) Operador ==: debe recibir una cadena (const char *) y devolver verdadero
// si esa cadena coincide con el nombre del mes del objeto que llama al método




};



int main(void)
{
    Fecha fecha1(2,8,98);
    Fecha fecha2(2,8,97);


    if(fecha1 > fecha2)
    {
        cout << "Las fecha 1 es mayor " << endl;
    }
    else
    {
        cout << "Las fecha 1 es menor" << endl;
    }


    fecha1 += 5;

    fecha1.mostrarFecha();


//fecha1.mostrarFecha();
//fecha2.mostrarFecha();
    return 0;
}
