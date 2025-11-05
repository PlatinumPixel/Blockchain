# ifndef TRANSACTION_H
# define TRANSACTION_H

#include "bibl.h"

class Transaction {
    private:
      string siuntejas;
      string gavejas;
      int kiekis;
      string id;
      
    public:
      Transaction(const string& s,const string& g, const int& k) : siuntejas(s), gavejas(g), kiekis(k) {
            id=hashing(std::to_string(k)+s+g);
      } 
      
      string getSiunt() const {return siuntejas;}
      string getGav() const {return gavejas;}
      int getKiek() const {return kiekis;}
      string getId() const {return id;}
      void printTransaction() const {
          cout << "Siuntejas: " << siuntejas << ", Gavejas: " << gavejas << ", Kiekis: " << kiekis << ", ID: " << id << endl;
      }

  };

vector <Transaction> GeneruotiTransactions(vector <User>& users, int kiekis){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(1, 10000000);
    std::uniform_int_distribution<> distributionUser(0, users.size() - 1);

    vector <Transaction> transactions;

    for (int i=0;i<kiekis;i++){
      int siuntejas=0;
      int gavejas=0;
      while (siuntejas == gavejas ){
        siuntejas = distributionUser(generator);
        gavejas = distributionUser(generator);
      }
        int amount = distribution(generator);
        if (amount > users[siuntejas].getBalance()){
            i--;
            continue;
        }
        transactions.emplace_back(users[siuntejas].getKey(),users[gavejas].getKey(),amount);
        
    }

    return transactions;
}

void printTransactions(const vector <Transaction>& transactions){
    cout << "Transactions-------------:" << endl;
    cout << std::left<<std::setw(20) << std::setfill(' ') << "Siuntejas" << std::setw(20) << "Gavejas" << std::setw(15) << "Kiekis" << std::setw(70) << "ID" << endl;

    for (const Transaction& tx : transactions) {
        cout <<  std::left <<std::setw(20) << tx.getSiunt()<< std::setw(20) << tx.getGav()<< std::setw(15) << tx.getKiek() << std::setw(70) << tx.getId() << endl;
    }
  }

  void printTransactions(const vector <Transaction>& transactions, int n){
    std::ofstream rf ("transactions.txt");
    cout << "Transactions-------------:" << endl;
    rf << "Transactions-------------:" << endl;
    cout << std::left<<std::setw(20) << std::setfill(' ') << "Siuntejas" << std::setw(20) << "Gavejas" << std::setw(15) << "Kiekis" << std::setw(70) << "ID" << endl;
    rf << std::left<<std::setw(20) << std::setfill(' ') << "Siuntejas" << std::setw(20) << "Gavejas" << std::setw(15) << "Kiekis" << std::setw(70) << "ID" << endl;

    for (int i=0;i<n && i<transactions.size();i++) {
        const Transaction& tx = transactions[i];
        cout <<  std::left <<std::setw(20) << tx.getSiunt()<< std::setw(20) << tx.getGav()<< std::setw(15) << tx.getKiek() << std::setw(70) << tx.getId() << endl;
        rf <<  std::left <<std::setw(20) << tx.getSiunt()<< std::setw(20) << tx.getGav()<< std::setw(15) << tx.getKiek() << std::setw(70) << tx.getId() << endl;
      }
  }

  # endif