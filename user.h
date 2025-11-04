# ifndef USER_H
# define USER_H

#include "std.h"

class User {
    private:
      string vardas;
      string key;
      float balance;
      
    public:
      User(const string& vardas,const string& key, const float& balance) : vardas(vardas), key(key), balance(balance) {} 
      
      string getVard() const {return vardas;}
      string getKey() const {return key;}
      float getBalance() const {return balance;}

      void setBalance(float& bal) {balance = bal;}
      void changeBalance(float& kiekis) {balance += kiekis;}

      void printUser() const {
          cout << "Vardas: " << vardas << ", Key: " << key << ", Balance: " << balance << endl;
      }
  };

  # endif