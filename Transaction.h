# ifndef TRANSACTION_H
# define TRANSACTION_H

#include "std.h"
#include "bibl.h"

class Transaction {
    private:
      string siuntejas;
      string gavejas;
      float kiekis;
      string id;
      
    public:
      Transaction(const string& s,const string& g, const float& k) : siuntejas(s), gavejas(g), kiekis(k) {
            id=hashing(s+g+std::to_string(k));
      } 
      
      string getSiunt() const {return siuntejas;}
      string getGav() const {return gavejas;}
      float getKiek() const {return kiekis;}
      string getId() const {return id;}

  };

  # endif