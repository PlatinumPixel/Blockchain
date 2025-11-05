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
      long nonce;
      int difficulty;

    public:
      
    
  };

  # endif