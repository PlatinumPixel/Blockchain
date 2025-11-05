# ifndef TRANSACTION_H
# define TRANSACTION_H

#include "bibl.h"

class Transaction {
    private:
      string siuntejas;
      string gavejas;
      long long kiekis;
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
          cout << "Transaction-------------:" << endl;
          cout << "Siuntejas: " << siuntejas << ", Gavejas: " << gavejas << ", Kiekis: " << kiekis << ", ID: " << id << endl;
      }

  };

vector <Transaction> GeneruotiTransactions(vector <User>& users, int kiekis){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(1, 100000);
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

vector<Transaction> VerifyTransactions(vector<Transaction>& transactions, vector<User>& users) {
    vector<Transaction> verified;

    auto findUser = [&](const string& key) -> User* {
        for (User& u : users) if (u.getKey() == key) return &u;
        return nullptr;
    };

    for (auto it = transactions.begin(); it != transactions.end(); ) {
        const Transaction& tx = *it;

        User* sender = findUser(tx.getSiunt());
        User* receiver = findUser(tx.getGav());
        if (!sender) {
            cout << "Unknown sender: " << tx.getSiunt() << endl;
            it = transactions.erase(it);
            continue;
        }

        if (sender->getBalance() < tx.getKiek()) {
            cout << "Insufficient balance: " << tx.getSiunt() << " for " << tx.getKiek() << endl;
            it = transactions.erase(it);
            continue;
        }

        if (hashing(std::to_string(tx.getKiek()) + tx.getSiunt() + tx.getGav()) != tx.getId()) {
            cout << "Invalid tx id: " << tx.getId() << endl;
            it = transactions.erase(it);
            continue;
        }
        sender->changeBalance(-tx.getKiek());
        receiver->changeBalance(tx.getKiek());

        verified.push_back(tx);

        ++it; 
    }

    return verified;
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