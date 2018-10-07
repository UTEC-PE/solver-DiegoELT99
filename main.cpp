#include <iostream>
#include "node.h"

using namespace std;

void menu() {
      system("cls");
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;

      //char* str="7/4*((a+b)*a)+3";
      //char* str="7/4*((a+-+--b)*a)+3";
      //char* str="2+(3)";
      char str[] = "7/4*((a+b)^4*a)+3";
}

// Prueba con:
// 7/4*((a+b)^4*a)+3    a=4, b=1 Resultado debería ser 4378
// a-2*5/2+1-2^4+a      a=3      Resultado debería ser -14
// 5--3 Te faltaron las combinaciones --, +-, etc
// Con operaciones pequeñas tipo 5+3 se queda en loop

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false),
    cin.tie(nullptr);
            /*menu();
            string equat;
            cin >> equat;*/

    string equat;
    if (argc == 2) {
        equat = argv[1];
    }
    else {
      throw "One argument expected";
    }

    Node Minerva(equat);
    Minerva.findPriority();
    cout << Minerva.operate();

    cout << "\nPress enter to continue ..."; 
    cin.get(); 
    return EXIT_SUCCESS;
}

