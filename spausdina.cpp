#include "bibl.h"

void spausdina(vector <string> I,vector <string> O){
    cout << "INPUT                                                                                                                                     OUTPUT" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
for (int i=0;i<I.size();i++){
    cout << std::left<<std::setw(100) << std::setfill(' ') << I[i] << std::fixed << " " <<  O[i] << endl;
}

}

void spausdinaFaila(vector <string> I,vector <string> O, string failas){
    std::ofstream rf (failas+".txt");
    rf << "INPUT                                                                                                                                     OUTPUT" << endl;
    rf << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
for (int i=0;i<I.size();i++){
    rf <<std::left<<std::setw(100) << std::setfill(' ')  << I[i] << std::fixed << " " <<  O[i] << endl;
}

}
