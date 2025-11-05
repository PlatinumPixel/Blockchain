#include "bibl.h"
#define UNICODE

int difficulty = 3;
vector <string> I;
vector <string> O;

int main(){
    setlocale(LC_ALL, "Lithuanian");
    vector <User> users = GeneruotiUsers(1000);
    
    printUsers(users);


 return 0;
}
