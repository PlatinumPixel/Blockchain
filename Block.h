# ifndef BLOCK_H
# define BLOCK_H

#include "bibl.h"

class Block {
    private:
      int index;
      Block* previousBlock;
      string previousHash;
      time_t timestamp;
      float version;
      string hash;
      long nonce;
      int difficulty;
      string merkleRoot;
      vector<Transaction> transactions;

    public:
    Block(int index, Block* prev, const string& prevHash, float ver, int diff, const vector<Transaction>& txs, int nonce, string hash, string root)
          : index(index), previousBlock(prev), transactions(txs), previousHash(prevHash), version(ver), difficulty(diff), nonce(nonce), hash(hash), merkleRoot(root) {
          timestamp = std::time(nullptr); 
      }

      string getHash() const { return hash; };
      int getIndex() const { return index; };
      void printBlockInfo() const {
          cout << "Block Info-------------:" << endl;
          cout << "Block Index: " << index << endl;
          cout << "Previous Hash: " << previousHash << endl;
          cout << "Timestamp: " << std::asctime(std::localtime(&timestamp));
          cout << "Version: " << version << endl;
          cout << "Difficulty: " << difficulty << endl;
          cout << "Nonce: " << nonce << endl;
          cout << "Hash: " << hash << endl;
          cout << "Transactions: " << transactions.size() << endl;
          cout << "Merkle Root: " << merkleRoot << endl;
      }

      const Transaction operator[](size_t index) const {
            return transactions[index];
      }
    
  };

  # endif