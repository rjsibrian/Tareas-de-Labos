#include <iostream>
#include <string>
using namespace std;

struct Datos{
    string id = "";
    string usuario = "";
    string perfil = "";
};

Datos solicitarDatos(void){
    Datos p;
    cout <<endl;
    cout << "Digite el ID: "; 
    getline(cin, p.id); cout <<endl;

    cout << "Digite el nombre de usuario: ";
    getline(cin, p.usuario); cout <<endl;

    cout << "Digite el perfil (administrador, cliente, o trabajador): ";
    getline(cin, p.perfil); cout <<endl;

    return p;
}

void mostrarDatos(Datos p){
        cout << "Registro: " << endl;
        cout << "ID: "; cout << p.id << endl;
        cout << "Nombre de usuario: "; cout << p.usuario << endl;
        cout << "Perfil: "; cout << p.perfil << endl;
        cout << endl;
}

//Uso de typedef para generalizar la lista doble con una plantilla

typedef Datos T;
const T noValido = {"","",""};

struct nodo{
    T dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        ListaDoble();
        ~ListaDoble();
        void insertFront(T);
        void insertBack(T);
        void traversalForwardDirection(void);
        void traversalReverseDirection(void);
        void deleteItem(T);
        bool empty(void);
        void insertAfter(T dato, T datoRef);
};

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertFront(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if(pInicio != NULL)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

void ListaDoble::insertBack(T dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin = pInicio;
        while(saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}

void ListaDoble::traversalForwardDirection(void){
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        mostrarDatos(saltarin->dato);//cout << saltarin->dato << endl;
        saltarin = saltarin->sig;
    }
}

void ListaDoble::traversalReverseDirection(void){
    if(!pInicio)
        return;
    nodo *p = pInicio;
    nodo *q = NULL;
    while(p){
        q = p;
        p = p->sig;
    }
    while(q){
        mostrarDatos(q->dato);//cout << q->dato << endl;
        q = q->ant;
    }
}

void ListaDoble::deleteItem(T datoB){
    if(!pInicio){ // Lista vacía.
        cout << "Actualmente no hay ningún registro." << endl;
    }
    else{ // Si la lista no está vacía, entonces:
        nodo *saltarin = pInicio;
        while(saltarin && (saltarin->dato).id.compare(datoB.id)!=0) // Saltar.
            saltarin = saltarin->sig; // Luego de saltar hay varias posibilidades:
        if(!saltarin) // a) saltarín se salió (el dato no está en la lista).
            cout << "El registro no está en la lista" << endl;
        else{ // Si saltarín no se salió (está sobre el dato a eliminar):
              // el nodo puede estar al principio, puede estar al final,
              // puede estar entre dos nodos, puede ser el único nodo.
            if(!saltarin->ant && saltarin->sig){ // Al principio (y hay más nodos).
                pInicio = pInicio->sig;
                pInicio->ant = NULL;
                delete saltarin;
            }
            else
                if(saltarin->ant && !saltarin->sig){
                    saltarin->ant->sig = NULL;
                    delete saltarin;
                }
                else
                    if(saltarin->ant && saltarin->sig){
                        saltarin->ant->sig = saltarin->sig;
                        saltarin->sig->ant = saltarin->ant;
                        delete saltarin;
                    }
                    else{
                        pInicio = NULL;
                        delete saltarin;
                    }
            cout << "Registro eliminado exitosamente!" << endl;
        }
    }
}

bool ListaDoble::empty(void){
    return pInicio == NULL;
}

void ListaDoble::insertAfter(T dato, T datoRef){
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;

    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin;
        saltarin = pInicio;
        while(saltarin->sig != NULL && (saltarin->dato).id.compare(datoRef.id) != 0){
            saltarin = saltarin->sig;
        }
        nuevo->sig = saltarin->sig;
        nuevo->ant = saltarin;
        if(saltarin->sig != NULL)
            saltarin->sig->ant = nuevo;
        saltarin->sig = nuevo;

    }
}

int menu(){
    int opcion = 0;
    cout << endl << "1) Agregar un registro al inicio." << endl;
    cout << "2) Agregar un registro al final." << endl;
    cout << "3) Mostrar registro de inicio a fin." << endl;
    cout << "4) Mostrar registro de fin a inicio." << endl;
    cout << "5) Eliminar un registro" << endl;
    cout << "6) Agregar registro despues de referencia." << endl;
    cout << "7) Salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    ListaDoble registro;
    
    bool continuar = true;
    Datos p;
    Datos pref;
    do{
        switch(menu()){
            case 1: //Agregar un registro al inicio de la lista
                p = solicitarDatos();
                registro.insertFront(p);
                cout << "Registro almacenado exitosamente!" << endl;
                break;
            case 2: //Agregar un registro al final de la lista
                p = solicitarDatos();
                registro.insertBack(p);
                cout << "Registro almacenado exitosamente!" << endl;
                break;
            case 3: //Mostrar registro de inicio a fin
                cout <<endl;
                registro.traversalForwardDirection();
                break;
            case 4: //Mostrar registro de fin a inicio
                cout <<endl;
                registro.traversalReverseDirection();
                break;
            case 5: //Eliminar un registro
                cout << endl;
                cout << "Digite los datos del registro que desea eliminar: " << endl;
                if(registro.empty()){
                    cout << endl;
                    cout << "No hay registros por eliminar" << endl;}
                else{
                    p = solicitarDatos();
                    registro.deleteItem(p);
                }
                break;
            case 6: //Agregar un registro después de referencia
                cout << "<Registro a insertar>" << endl;
                p = solicitarDatos();
                cout << "<Registro de referencia>" << endl;
                pref = solicitarDatos();
                registro.insertAfter(p, pref);
                cout << "Registro almacenado exitosamente!" << endl;
                break;
            case 7: //Salir
                continuar = false;
                break;
            default: //El usuario se equivoco
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}



