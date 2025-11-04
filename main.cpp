#include "bibl.h"
#define UNICODE
vector <string> I;
vector <string> O;

int main(){
    setlocale(LC_ALL, "Lithuanian");
    int input;
    string failas;
    while ((true)){
        cout << "Iveskite skaiciu ka norite daryti " << endl;
        cout << "1 - Iveskite visus duomenis rankiniu budu(be salt generation) " << endl;
        cout << "2 - Iveskite duomenis rankniu budu(su salt generation) " << endl;
        cout << "3 - Sugeneruoti nauja duomenu faila " << endl;
        cout << "4 - Paiimti duomenis is failo (su salt generation) " << endl;          
        cout << "5 - Baigti darba ir spausdinti i terminala " << endl;
        cout << "6 - Baigti darba ir spausdinti i faila " << endl;

        try {
            if (!(cin>>input)||input<1 || input>7){
                cin.clear();
                cin.ignore();
                throw "Ivestas neteisingas simbolis";
            } 
        
            switch(input){
                case 1:
                    int n;
                    cout << "Kiek stringu hashint ";
                    cin >> n;
                    for (int i=0;i<n;i++){
                        rankinis(I);
                        O.push_back(hashing(I.back()));
                    }
                break;

                case 2:
                    cout << "Kiek stringu hashint ";
                    cin >> n;
                    for (int i=0;i<n;i++){
                        rankinis(I);
                        salt(I.back());
                        O.push_back(hashing(I.back()));
                    }
                break;

                case 3:
                    failoGen();
                break;

                case 4:
                    failoNusk(I,O);
                break;
                
                case 5:
                    spausdina(I,O);
                    cout << "Spauskite Enter, kad uzdaryti programa..." << endl;
                    cin.ignore();
                    cin.get();
                    return 0;
                 case 6:
                    cout << "Iveskite failo pavadinima ";
                    cin >> failas;
                    spausdinaFaila(I,O,failas);
                    cout << "Spauskite Enter, kad uzdaryti programa..." << endl;
                    cin.ignore();
                    cin.get();
                    return 0;
                default:
                    cout << "Ivedete neteisinga simobli, pabandykit vel! :)" << endl;
                break;
        }
        }   
        catch (char const *x){
            cout << x << endl;
            continue;
        }
    
    }
cout << "Spauskite Enter, kad uzdaryti programa..." << endl;
cin.ignore();
cin.get();
 return 0;
}
