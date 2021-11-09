#include <iostream>

using namespace std;

struct nodo{
    string nombre = "";
    string apellido = "";
    string carnet = "";
    string numero = "";
    string edad = "";
    string correo = "";
    nodo *sig;

};

class ListaSimple{

    private:
        nodo *pInicio;
    
    public:
        ListaSimple();
        void insertaNodo(void);
        void insInicio(string, string, string,string, string, string);
        void mostrarListaIter(void);
        bool eliminarElemento(string);
};

ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}

void ListaSimple::insertaNodo(void)
{
    char opcion = 'S';
    string dato = "";
    string nombre = "";
    string apellido = "";
    string carnet = "";
    string numero = "";
    string edad = "";
    string correo = "";
    
    while(opcion == 'S'){
        cout <<endl;
        cout << "Digite el numero de carnet de la persona que desea registrar (Porfavor no utilice espacios): "; 
        cin >> carnet; cout <<endl;

        cout << "Digite el primer nombre de la persona que desea registrar (Porfavor no utilice espacios): ";
        cin >> nombre; cout <<endl;

        cout << "Digite el primer apellido de la persona que desea registrar (Porfavor no utilice espacios): ";
        cin >> apellido; cout <<endl;

        cout << "Digite la edad de la persona que desea registrar (Porfavor no utilice espacios): ";
        cin >> edad; cout <<endl;

        cout << "Digite el numero de telefono de la persona que desea registrar (Porfavor no utilice espacios): ";
        cin >> numero; cout <<endl;

        cout << "Digite el correo electronico de la persona que desea registrar (Porfavor no utilice espacios):";
        cin >> correo; cout <<endl;

        if (opcion != 'N'){
        insInicio(carnet, nombre, apellido, edad, numero, correo);
        cout <<endl;
        cout << "Si desea registrar a otra persona, digite la letra mayuscula (S), y si quiere detener el registro, digite (N): ";
        cin >> opcion;
        
           }
    }
}

void ListaSimple::insInicio(string carnet, string nombre, string apellido, string edad, string numero, string correo)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->carnet = carnet;
    nuevo->nombre = nombre;
    nuevo->apellido = apellido;
    nuevo->edad = edad;
    nuevo->numero = numero;
    nuevo->correo = correo;
    nuevo->sig = pInicio;
    pInicio = nuevo;

}

void ListaSimple::mostrarListaIter(void)
{
    nodo *saltarin;
    int i = 1;  

    cout << endl;
    saltarin = pInicio;
    while(saltarin != NULL){
        cout <<"Datos de la persona registrada:" << endl;
        cout <<"Numero de carnet: " <<saltarin->carnet << endl;
        cout <<"Nombre: " <<saltarin->nombre << endl;
        cout <<"Apellido: " <<saltarin->apellido << endl;
        cout <<"Edad: " <<saltarin->edad << endl;
        cout <<"Numero telefonico: " <<saltarin->numero << endl;
        cout <<"Correo electronico: " <<saltarin->correo << endl;
        cout << endl;
        i ++;
        saltarin = saltarin->sig;
    }
}

bool ListaSimple::eliminarElemento(string carnet)

{

    if(!pInicio)

        return false;

    else{

        nodo *s = pInicio, *p;



        if(s->carnet == carnet){

            pInicio = pInicio->sig;

            delete s;

            return true;

        }

        else{

            while(s->sig && s->sig->carnet != carnet)

                s = s-> sig;

            if(!s->sig)

                return false;

            else{

                p = s->sig;

                s->sig = s->sig->sig;

                delete p;

                return true;

            }
        }
    }
    
}

using namespace std;

int main(void){

    ListaSimple objListaSimple;
    int opcion;
    string carnet;

    cout <<"EJERCICIO DE PRIMER LABO." <<endl;
    cout <<endl;

    

    cout <<endl;

    while (opcion != 4)
    {
        cout <<"MENU:" <<endl;
        cout <<"1. LLenar la lista." <<endl;
        cout <<"2. Eliminar a una persona." <<endl;
        cout <<"3. Mostrar a todas las pesonas." <<endl;
        cout <<"4. Salir." <<endl;

        cout <<endl;
        cout <<"Selecciona una opcion del MENU (1, 2, 3 o 4): ",
        cin >> opcion;

        cout <<endl;

            switch (opcion)
        {
        case 1:
            cout <<"Usted selecciono LLenar la lista." <<endl;
            cout <<endl;

            objListaSimple.insertaNodo();
            cout <<endl;
            break;

        case 2:
            cout <<"Usted selecciono Eliminar a una persona" <<endl;
            cout <<endl;

            cout <<"Digite el carnet de la persona que desea eliminar del registro: ";
            cin >> carnet;
            objListaSimple.eliminarElemento(carnet);
            cout <<"La persona ha sido eliminada del registo con exito, puede verificarlo digitando el numero 3." << endl;
            cout <<endl;
            break;

        case 3:
            cout <<"Usted selecciono Mostrar a todas las pesonas." <<endl;
            objListaSimple.mostrarListaIter();
            cout <<endl;
            break;

        case 4:
            cout <<"Usted selecciono Salir." <<endl;
            cout <<endl;
            break;
        
        default:
            cout <<"Respuesta invalida" <<endl;
            cout <<endl;
            break;
        }
    }
    
    return 0;
}