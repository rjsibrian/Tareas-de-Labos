#include <iostream>
#include <string>

using namespace std;

struct nodo{
    string id = "";
    string dueno = "";
    string raza = "";
    string peso = "";
    string edad = "";
    nodo *sig;
};

class ListaCircSimple{

    private:
        nodo *pInicio;
    
    public:
        ListaCircSimple();
        ~ListaCircSimple();
        void insertaNodo(void);
        void insInicio(string, string, string, string, string);
        void insFinal(string, string, string, string, string);
        void mostrarPorId(string);
        void mostrarListaRecAux(nodo *);
        void eliminarListaCircRec(nodo *);
        bool eliminarElemento(string);

};

bool ListaCircSimple::eliminarElemento(string id) //Función que elimanará por ID
{
    if(!pInicio)
        return false;
    else{
        nodo *s = pInicio, *p;


        if(s->id == id){ //Cuando el primer nodo tiene el ID a borrar
            p = s;
            while(s->sig != pInicio){ //Buscar quien apunta a pInicio
                s = s->sig;
            }
            if (s->sig==pInicio) //Maneja excepcion cuando solamente hay un nodo
            {
                pInicio = NULL;
                
            }
            else
            {
                pInicio = pInicio->sig;
                s->sig = pInicio;
            }
            delete p; 
            cout <<"El registro ha sido borrado con exito." << endl;
            return true;
        }

        else{
            while(s->sig->id != id) { // Buscamos el nodo siguiente que contiene el ID            
                if(s->sig == pInicio){ // Manejamos la excepcion cuando el usuario digita incorrectamente el ID
                    cout <<"El id que digito no existe." <<endl;
                    return false;}
                else{
                    s = s-> sig; 
                }                
            }
            p = s->sig;
            s->sig = s->sig->sig;
            delete p;
            cout <<"El registro ha sido borrado con exito." << endl;
            return true;
        }
    }
}

ListaCircSimple::ListaCircSimple(void)
{
    pInicio = NULL;
}

ListaCircSimple::~ListaCircSimple()
{
    if(pInicio){
        eliminarListaCircRec(pInicio);
        pInicio = NULL;
    }
}

void ListaCircSimple::eliminarListaCircRec(nodo *p){
    if(p->sig != pInicio)
        eliminarListaCircRec(p->sig);
    delete p;
}

void ListaCircSimple::insertaNodo(void)
{
    char opcion = 'S';
    string id = "";
    string dueno = "";
    string raza = "";
    string peso = "";
    string edad = "";
    
    while(opcion == 'S'){
        cout <<endl;
        cout << "Digite su id (Porfavor no utilice espacios): "; 
        cin >> id; cin.ignore(); cout <<endl;

        cout << "Digite su primer nombre (Porfavor no utilice espacios): ";
        cin >> dueno; cin.ignore(); cout <<endl;

        cout << "Digite la raza de su mascota (Puede utilizar espacios): ";
        getline(cin, raza); cout <<endl;

        cout << "Digite el peso de su mascota (Puede utilizar espacios para especificar la unidad de peso): ";
        getline(cin, peso); cout <<endl;

        cout << "Digite la edad de su mascota (Puede utilizar espacios para especificar la unidad de tiempo): ";
        getline(cin, edad); cout <<endl;

        insInicio(id, dueno, raza, peso, edad);
        cout <<endl;

        

        cout << "Si desea crear otro registro, digite la letra mayuscula (S), y si quiere detener el registro, digite (N): ";
        cin >> opcion;
    }
    cout << endl;
}

void ListaCircSimple::insInicio(string id, string dueno, string raza, string peso, string edad)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->id = id;
    nuevo->dueno = dueno;
    nuevo->raza = raza;
    nuevo->peso = peso;
    nuevo->edad = edad;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else{
        nuevo->sig = pInicio;
        nodo *saltarin = pInicio;
        while(saltarin->sig != pInicio){
            saltarin = saltarin->sig;
        }
        saltarin->sig = nuevo;
        pInicio = nuevo;
    }
}

void ListaCircSimple::insFinal(string id, string dueno, string raza, string peso, string edad)
{
    nodo *nuevo, *saltarin;

    nuevo = new nodo;
    nuevo->id = id;
    nuevo->dueno = dueno;
    nuevo->raza = raza;
    nuevo->peso = peso;
    nuevo->edad = edad;

    if(!pInicio){ // Si la lista está vacía.
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else{ // Si la lista ya contiene nodos.
        nuevo->sig = pInicio;
        saltarin = pInicio;
        while(saltarin->sig != pInicio)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
    }
}

void ListaCircSimple::mostrarPorId(string id)
{
    nodo *saltarin;

    cout << endl;

    
    if(pInicio){ //Si hay elementos en la lista
        saltarin = pInicio; 
        while(saltarin->id != id) {  //Posicionamos a saltarin en el nodo que tiene el ID             
            if(saltarin->sig == pInicio){
                cout <<"El id que digito no existe." <<endl;
                return;
            }
            else{
                saltarin = saltarin-> sig;

            }                
        }
        cout <<"Rgistro solicitado:"; cout << endl;
        cout <<"ID: "; cout << saltarin->id << endl;
        cout <<"Nombre del dueno: "; cout << saltarin->dueno << endl;
        cout <<"Raza: "; cout << saltarin->raza << endl;
        cout <<"Peso: "; cout << saltarin->peso << endl;
        cout <<"Edad: "; cout << saltarin->edad << endl; 
        cout << endl;
    }
    else // Si no hay elementos en la lista
    {
        cout <<"No hay registros que mostrar." <<endl;
    }
    
}

int main(void)
{
    cout << endl;
    cout << "TAREA DE LABO 5: Administracion de una veterinaria." << endl << endl;

    ListaCircSimple objListaCircSimple;
    int opcion;
    string id;  

    while (opcion != 4)
    {
        cout <<"MENU:" <<endl;
        cout <<"1. Agregar un registro." <<endl;
        cout <<"2. Mostrar un registro por ID." <<endl;
        cout <<"3. Borrar un registro por ID." <<endl;
        cout <<"4. Salir." <<endl;

        cout <<endl;
        cout <<"Selecciona una opcion del MENU (1, 2, 3 o 4): ",
        cin >> opcion;

        cout <<endl;

            switch (opcion)
        {
        case 1:
            cout <<"Usted selecciono agregar un registro." <<endl;
            cout <<endl;

            objListaCircSimple.insertaNodo();
            cout <<endl;
            break;

        case 2:
            cout <<"Usted selecciono mostrar un registro por ID." <<endl;
            cout <<"Digite el id del registro que desea visualizar: ";
            cin >> id;
            objListaCircSimple.mostrarPorId(id);
            cout <<endl;
            break;

        case 3:
            
            cout <<"Usted selecciono borrar un registro por ID." <<endl;
            cout <<endl;

            cout <<"Digite el id del registro que desea eliminar: ";
            cin >> id;
            objListaCircSimple.eliminarElemento(id);
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