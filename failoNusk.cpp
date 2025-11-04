#include "bibl.h"
#define UNICODE

void failoNusk (vector<string> &A, vector <string> &O){
    string failas;
    setlocale(LC_ALL, "Lithuanian");

    cout << "Iveskite failo pavadinima (pvz. text.txt)" << endl;
    while(true){
        cin >> failas;
        if (!(std::filesystem::exists(failas))){
            cout << "Toks failas neegzistuoja, pabandykite vel" << endl;
            continue; 
        }
        break;
    }
    
    string eil;

    std::ifstream df(failas);
    Timer t;
    while(getline(df,eil)){
        A.push_back(eil);
        salt(A.back());
        O.push_back(hashing(A.back()));
    }
    cout << "Laiko uzturko nuskaityt ir hashint" << t.elapsed() << endl;
    df.close();
}

void failoNuskBeSalt (vector<string> &A, vector <string> &O){
    string failas;
    setlocale(LC_ALL, "Lithuanian");

    cout << "Iveskite failo pavadinima (pvz. text.txt)" << endl;
    while(true){
        cin >> failas;
        if (!(std::filesystem::exists(failas))){
            cout << "Toks failas neegzistuoja, pabandykite vel" << endl;
            continue; 
        }
        break;
    }
    
    string eil;

    std::ifstream df(failas);
    Timer t;
    while(getline(df,eil)){
        A.push_back(eil);
        O.push_back(hashing(A.back()));
    }
    cout << "Laiko uzturko nuskaityt ir hashint" << t.elapsed() << endl;
    df.close();
}