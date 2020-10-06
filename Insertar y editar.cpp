#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

string C1 = "CREAR_TABLA";
string C2 = "INSERTAR";
string C4 = "SELECT_*_DESDE";
string C3 = "BORRAR DESDE";
string C5 = "MODIFICAR";

string tipo1 = "int";
string tipo2 = "char";
string tipo3 = "date";

list<string> lista;
list<string> type;

void removespaceWord(string str)
{
    //elimina la ", ) (" y lo convierte en " "
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ',' || str[i] == '(' || str[i] == ')' || str[i] == '-')
            str[i] = ' ';
    }

    istringstream ss(str);
    //ingreso el comando a la lista
    while (ss)
    {
        string word;
        ss >> word;
        lista.push_back(word);
    }
}


bool fileExists()
{
    string temp;
    list<string> ::iterator it = lista.begin();
    advance(it, 1);
    temp = *it + ".txt";

    ifstream file(temp.c_str(), ios_base::out | ios_base::in);
    if (!file)
        return 1;
    return 0;

}




void create()
{

    bool temp = 0;
    string prueba;
    list<string> ::iterator it = lista.begin();
    list<string> ::iterator its = type.begin();
    advance(it, 1);


    temp = fileExists(); //verifica si ya existe es nombre

    if (temp == 0)
        cout << "YA EXISTE TABLA " << *it << "\n\n";

    else {

        //********************crea el nombre de .txt***********************************       
        prueba = *it + ".txt";
        ofstream MyReadFile(prueba.c_str());

        cout << "\n\nLA TABLA " << prueba << " SE CREO EXISTOSAMENTE\n\n";



        //*********************Ingresa las cabezaras de la tabla***********************

        //"count" tiene que ser 2 porque estamos saltando el comando y el nombre
        int count = 2;

        for (its = type.begin(); its != type.end(); its++)
        {
            advance(it, 1);
            MyReadFile << *it + " (" + *its + ") " << "\t";
        }

        // Close the file
        MyReadFile.close();
        //system("cls");
    }
}

void tipos()
{
    int flag = 0;
    list<string> temp;
    list<string>::iterator itrr;
    for (itrr = lista.begin(); itrr != lista.end(); itrr++)
    {
        if (*itrr == tipo1)
        {
            type.push_back(tipo1);
            flag++;
            temp.push_back(tipo1);
        }
        else if (*itrr == tipo2)
        {
            type.push_back(tipo2);
            flag++;
            temp.push_back(tipo2);
        }
        else if (*itrr == tipo3)
        {
            type.push_back(tipo3);
            flag++;
            temp.push_back(tipo3);
        }

    }
    if (flag == 0)
        cout << "SYNTAX_ERROR: COMAND NOT FOUND";
    for (itrr = temp.begin(); itrr != temp.end(); itrr++)
        lista.remove(*itrr);
    temp.clear();

}

void insert()
{

    //falta recibir datos de el tipo valido y 
    //falta resperal la primera fila

    bool temp = 0;
    string prueba;
    list<string> ::iterator it = lista.begin();
    list<string> ::iterator its = type.begin();
    advance(it, 1);
    temp = fileExists(); //verifica si ya existe es nombre

    if (temp == 1)
        cout << "TABLA NO EXISTE" << *it << "\n\n";
    else
    {
        cout << "\n\n\n\entre jejeje\n\n\n";
        prueba = *it + ".txt";
        ofstream MyReadFile(prueba.c_str());
        if (MyReadFile.is_open())
        {
            for (int i = 1; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    MyReadFile << "hola\t";
                }
                MyReadFile << "\n";
            }
            MyReadFile.close();
        }
    }

}

void edit_file(int line_to_change, int column_to_change, const std::string& change_to)
{
    if (std::ifstream in{ "txt_in" })
        if (std::ofstream out{ "txt_out" })
        {
            int line = 1, column = 1;
            std::string word;
            char whitespace;
            while (in >> word && in.get(whitespace))
            {
                if (line == line_to_change && column == column_to_change)
                    word = change_to;
                out << word << whitespace;
                if (whitespace == '\n') // newline...
                {
                    ++line;
                    column = 1;
                }
                else // presumably a tab...
                    ++column;
            }
        }
        else
            std::cerr << "unable to open output file\n";
    else
        std::cerr << "unable to open input file\n";
}

void commands(list<string> x)
{

    if (C1 == (x.front()))
    {
        create();
        //cout << "crea\n";
    }
    if (C2 == (x.front())) 
    {
        insert();
        cout << "insert\n";
    }
    if (C3.compare(x.front()) == 0)
    {
        //create();
        cout << "del\n";
    }
    if (C4.compare(x.front()) == 0)
    {
        //create();
        cout << "select\n";
    }
    if (C5.compare(x.front()) == 0)
    {
        //create();
        cout << "mod\n";
    }
    else { cout << "SYNTAX_ERROR: COMAND NOT FOUND"; }


}

int main()
{
    string x;

    while (true)
    {
        cout << "ingrese comando: ";

        //creo ingreso el texto *COMANDO*. se hace de esta forma para poder 
        //usar espacios
        getline(cin, x);

        //funcion que saca los espacios
        removespaceWord(x);
        tipos();
        //cout << temp.front();
        commands(lista);


        //creo un iterador para poder imprimir la pablabra   **solo para probar (tester)**
/*
        list<string>::iterator itr;
        list<string>::iterator itrs;
        cout << "lista de lista\n";
        for (itr = lista.begin(); itr != lista.end(); itr++)
            cout << *itr << "\n";

        cout << "lista de type\n";
        for (itrs = type.begin(); itrs != type.end(); itrs++)
            cout << *itrs << "\n";
*/
        lista.clear();
        type.clear();
        //system("cls");



    }

}