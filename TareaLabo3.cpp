#include <iostream>

using namespace std;

struct nodo{
    string cantidad = "";
    string masa = "";
    string CoNC = "";
    string ingredientes = "";
    nodo *sig;
};

class ListaSimple{

    private:
        nodo *pInicio;
    
    public:
        ListaSimple();
        void insertaNodo(void);
        void insInicio(string, string, string, string);
        void mostrarListaIter(void);
};

ListaSimple::ListaSimple(void)
{
    pInicio = NULL;
}

void ListaSimple::insertaNodo(void)
{
char opcion = 'S';
    string cantidad = "";
    string masa = "";
    string CoNC = "";
    string ingredientes = "";
    
    while(opcion == 'S'){
        cout <<endl;
        cout << "Digite la cantidad de pupusas que desea ordenar: "; 
        cin >> cantidad; cin.ignore(); cout <<endl;

        cout << "Escriba la masa que desea para sus pupusas (Arroz o maiz): ";
        cin >> masa; cin.ignore(); cout <<endl;

        cout << "Desea que le agreguemos una Coca-Cola a su pedido? (Responda SI o NO): ";
        getline(cin, CoNC); cout <<endl;

        cout << "Especifique de que ingrediente quiere las pupusas que ordeno (Ej. 3 de frijol con queso y dos de queso, etc.): ";
        getline(cin, ingredientes); cout <<endl;

        insInicio(cantidad, masa, CoNC, ingredientes);
        cout <<endl;

        cout << "Si desea agregar otro pedido, digite la letra mayuscula (S), y si quiere detener los pedidos, digite (N): "; cout <<endl;
        cin >> opcion; cout <<endl;
    }
    cout << endl;
}

void ListaSimple::insInicio(string cantidad, string masa, string CoCN, string ingredientes)
{
    nodo *nuevo;

    nuevo = new nodo;
    nuevo->cantidad = cantidad;
    nuevo->masa = masa;
    nuevo->CoNC = CoCN;
    nuevo->ingredientes = ingredientes;
    nuevo->sig = pInicio;
    pInicio = nuevo;
}

void ListaSimple::mostrarListaIter(void)
{
    nodo *saltarin;

    cout << endl;
    saltarin = pInicio;
    while(saltarin != NULL){
        cout << "Pedido: " << endl;
        cout << "Cantidad de pupusas: "; cout << saltarin->cantidad << endl;
        cout << "Masa seleccionada: "; cout << saltarin->masa << endl;
        cout << "Con Coca-Cola: "; cout << saltarin->CoNC << endl;
        cout << "Ingredientes seleccionados: "; cout << saltarin->ingredientes <<endl;
        cout <<endl;
        saltarin = saltarin->sig;
    }
}

int main(void)
{

    cout << endl;
    cout << "TAREA DE LABO 3: Administracion de una pupuseria." << endl << endl;

    ListaSimple objListaSimple;
    int opcion;

    while (opcion != 4)
    {
        cout <<"MENU:" <<endl;
        cout <<"1. Agregar una orden." <<endl;
        cout <<"2. Mostrar las ordenes." <<endl;
        cout <<"3. Salir." <<endl;

        cout <<endl;
        cout <<"Selecciona una opcion del MENU (1, 2 o 3): ",
        cin >> opcion;

        cout <<endl;

            switch (opcion)
        {
        case 1:
            cout <<"Usted selecciono agregar una orden." <<endl;
            cout <<endl;
            objListaSimple.insertaNodo();
            cout <<endl;
            break;

        case 2:
            cout <<"Usted selecciono mostrar las ordenes." <<endl;
            cout <<endl;
            objListaSimple.mostrarListaIter();
            cout <<endl;
            break;

        case 3:
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