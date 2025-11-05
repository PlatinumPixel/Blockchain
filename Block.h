# ifndef BLOCK_H
# define BLOCK_H

#include "std.h"
#include "bibl.h"

class Block {
    private:
      int index;
      vector<Transaction> transactions;
      string previousHash;
      time_t timestamp;
      float version;
      string hash;
      long int nonce;
      int difficulty;


      
    public:
      
      
      string getSiunt() const {return siuntejas;}
      string getGav() const {return gavejas;}
      float getKiek() const {return kiekis;}
      string getId() const {return id;}

  };

  # endif