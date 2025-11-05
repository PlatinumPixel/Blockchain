#include "bibl.h" 

string hashing(string& input){

    int val[64];
    int j=1;
    int size=input.size();
    val[0]=((input[0]*37)%1000/10%16+input[size-2])%1000/10%16;
    if (size < 64){    
        for (int i=1;i<64;i++){
            val[i%64]=(input[i%size]*val[(i-1)%64]+input[(i-1)%size])%1000/10%16;
            
        }
    }
    else {   
        for (int i=1;i<size;i++){
            val[i%64]=(input[i]*val[(i-1)%64]+input[i-1])%1000/10%16;
        }
    }
    stringstream hashed;
    for (int i=0;i<64;i++){
        hashed << hex << val[i]; 
    }
    return hashed.str();
}
void salt(string &input){

    const string CHARACTERS = "{|}~`_^]@?>=<;:.-,+*)('&%$#![";

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);
    int amount = distribution(generator);
        for (int i = 0; i < amount; i++) {
            input  += CHARACTERS[distribution(generator)];
        }
}