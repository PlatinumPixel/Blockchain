# ifndef BLOCK_H
# define BLOCK_H

#include "std.h"
#include "bibl.h"

class Block {
    private:
      int index;
      Block* previousBlock;
      vector<Transaction> transactions;
      string previousHash;
      time_t timestamp;
      float version;
      string hash;
      long nonce;
      int difficulty;

    public:
      Block(int index, Block* prev, const vector<Transaction>& txs, const string& prevHash, float ver, int diff)
          : index(index), previousBlock(prev), transactions(txs), previousHash(prevHash), version(ver), difficulty(diff), nonce(0) {
          timestamp = std::time(nullptr); 
      }

      string getHash() const { return hash; }
    
  };

  # endif