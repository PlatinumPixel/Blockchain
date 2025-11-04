#include "bibl.h"

void failoGen(){
    string failas;
    int kiek;
    int ilg;
    const string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890{|}~`_^]@?>=<;:.-,+*)('&%$#![";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);
    
    cout << "Iveskite failo pavadinima (pvz. text)" << endl;
    cin >> failas;
    cout << "Iveskite kiek sugeneruoti stringu" << endl;
    cin >> kiek;
    cout << "Iveskite kokio ilgio stringai" << endl;
    cin >> ilg;
    
    std::stringstream eil;

    std::ofstream rf(failas+".txt");

    eil.str("");
    
    for (int i=1;i<=kiek;i++){
        for (int j=0;j<ilg;j++){
            eil << CHARACTERS[distribution(generator)]; 
        }
        rf << eil.str() << '\n';
        eil.str("");
    }
    rf.close();
}