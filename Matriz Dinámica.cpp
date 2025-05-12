#include<iostream>

using namespace std;

/*Matrices dinámicas con apuntadores
    int fil = 5;                    Filas
    int col = 4;                    Columnas
    int** m = new int*[fil];        Se crea un apuntador m que apunta a un vector de apuntadores
    for(int i=0; i<fil; i++){       For que itera el vector de apuntadores "fil" veces
        m[i] = new int[col];        Por cada fila se crea un vector de enteros con extensión de "col"
        for(int j=0; j<col;j++){    For que itera "col" veces por cada fila, asignando el valor 0 a cada uno de los espacios
            m[i][j] = 0;
        }
    }
    
    
    for(int i=0; i<fil; i++){       For que itera "fil" veces
        delete[] m[i];              Elimina el vector al que apunta cada m[i] 
    }
    delete[] m;                     Elimina el vector al que apunta m
    
    
    
    return 0;
*/

class Matriz{
    int** m;    //Se crea el apuntador de apuntadores m
    int fil;    //Atributo para filas
    int col;    //Atributo para columnas

public:
//Crear matriz default como fue explicado al inicio del código
    Matriz(){
        fil = 5;
        col = 5;
        m = new int*[fil];
        for(int i=0; i<fil; i++){
            m[i] = new int[col];
            for(int j=0; j<col;j++){
                m[i][j] = 0;
            }
        }
    }
    
//Crear matriz con fil y col introducidas en el main
    Matriz(int f,int c){
        fil = f;
        col = c;
        m = new int*[fil];
        for(int i=0; i<fil; i++){
            m[i] = new int[col];
            for(int j=0; j<col;j++){
                m[i][j] = 0;
            }
        }
    }

//Elimina la matriz cuando deje de ser utilizada
    ~Matriz(){
        for(int i=0; i<fil; i++){
        delete[] m[i];
        }
    delete[] m;
    }

//Print
    void print(){
        for(int i=0; i<fil; i++){       //For que itera "fil" veces
            for(int j=0; j<col;j++){    //For que itera "col" veces
                cout<<m[i][j]<<"\t";    //Imprime cada valor con un espacio \t entre cada uno ""
            }
            cout<<endl;                 //Endline entre cada fila (estética)
        }cout<<endl;                    //Endline al final de la matriz (estética)
    }

//Añadir fila
    void addFil(){ 
        fil += 1;                       //Se añade una fila
        int** mt = new int*[fil];       //Se crea una apuntador temporal "mt"
        for(int i=0; i<fil-1; i++){     //For que itera hasta fil-2, para asignar los valores que ya se tenían en m
            mt[i] = new int[col];       
            for(int j=0; j<col;j++){
                mt[i][j] = m[i][j];     //Se asignan los valores
            }
        }
        mt[fil - 1] = new int[col];     //Se crea la última fila (fil-1)
        for (int j = 0; j < col; j++) {
            mt[fil - 1][j] = 0;         //Se inicializa cada valor de esta fila con 0
        }
        
        for(int i=0; i<fil-1; i++){
        delete[] m[i];
        }
        delete[] m;                     //Se elimina el espacio de memoria de m
        m = mt;                         //Se asigna el apuntador mt a m
    }

//Añadir columna
    void addCol(){
        col += 1;
        int** mt = new int*[fil];
        for(int i=0; i<fil; i++){
            mt[i] = new int[col];
            for(int j=0; j<col;j++){
                mt[i][j] = m[i][j];
            }
            mt[i][col - 1] = 0;
        }
        for(int i=0; i<fil; i++){
        delete[] m[i];
        }
        delete[] m;
        m = mt;
    }
    
//Añadir columnasssss
    void addCol(int d){
        col += d; //Aumenta el número de columnas "d" veces
        int** mt = new int*[fil]; //Se crea la matriz temporal
        for(int i=0; i<fil; i++){ 
            mt[i] = new int[col]; //Se crean las filas con una cantidad "col" de columnas
            for(int j=0; j<col-d;j++){ //Se asignan los valores hasta col-d, para no asignar valores innecesarios
                mt[i][j] = m[i][j]; 
            }
            for(int h=col-d; h<col;h++){
                mt[i][h] = 0; //Ahora se asignan 0 desde "col-d" hasta "col"
            }
        }
        for(int i=0; i<fil; i++){
        delete[] m[i];
        }
        delete[] m; //Se elimina la matriz m
        m = mt; //Se asigna el apuntador mt a m
    }

//Add
    void add(int d) {
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j] == 0) {
                m[i][j] = d;
                return;
            }
        }
    }
    
    addFil();
    add(d);
    }
    
    int getCol(){
        return col;
    }
    
    int getFil(){
        return fil;
    }
    
};
