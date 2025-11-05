# ifndef USER_H
# define USER_H

#include "std.h"

class User {
    private:
      string vardas;
      string key;
      int balance;
      
    public:
      User(const string& vardas,const string& key, const int& balance) : vardas(vardas), key(key), balance(balance) {} 
      
      string getVard() const {return vardas;}
      string getKey() const {return key;}
      int getBalance() const {return balance;}

      void setBalance(int& bal) {balance = bal;}
      void changeBalance(int& kiekis) {balance += kiekis;}

      void printUser() const {
          cout << "Vardas: " << vardas << ", Key: " << key << ", Balance: " << balance << endl;
      }
  };

vector <User> GeneruotiUsers(int kiekis){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(100, 10000000);

    vector <User> users;

    for (int i=0;i<kiekis;i++){
        string vardas="User"+std::to_string(i);
        string key="Raktas"+std::to_string(i);
        int balance=distribution(generator);
        users.emplace_back(vardas,key,balance);
    }

    return users;
}

void printUsers(const vector <User>& users){
    std::ofstream rf ("users.txt");
    cout << "Sugeneruoti users-------------:" << endl;
    rf << "Sugeneruoti users-------------:" << endl;

    cout << std::left<<std::setw(15) << std::setfill(' ') << "Naudotojai" << std::setw(15) << "Raktas" << std::setw(15) << "Balance" << endl;
    rf << std::left<<std::setw(15) << std::setfill(' ') << "Naudotojai" << std::setw(15) << "Raktas" << std::setw(15) << "Balance" << endl;

    for (const User& user : users) {
        cout <<  std::left <<std::setw(15) << user.getVard()<< std::setw(15) << user.getKey()<< std::setw(15) << user.getBalance() << endl;
        rf <<  std::left <<std::setw(15) << user.getVard()<< std::setw(15) << user.getKey()<< std::setw(15) << user.getBalance() << endl;
    }
}

  # endif