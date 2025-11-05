# ifndef FUNCTIONS_H
# define FUNCTIONS_H

#include "std.h"
#include "bibl.h"

vector <User> GeneruotiUsers(int kiekis){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(100, 10000000);

    vector <User> users;

    for (int i=0;i<kiekis;i++){
        string vardas="User"+std::to_string(i);
        string key="Raktas"+std::to_string(i);
        float balance=distribution(generator);
        users.emplace_back(vardas,key,balance);
    }

    return users;
}



  # endif