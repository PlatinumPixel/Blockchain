# ifndef BLOCKCHAIN_H
# define BLOCKCHAIN_H

#include "std.h"
#include "bibl.h"

class Blockchain {
    private:
     vector <Block> chain; 

    public:
        Blockchain() {
            Block genesisBlock(0, nullptr, {}, "000000000000000000000000000000000000000000000000000000000000000", 1.0, 3);
            chain.emplace_back(genesisBlock);
        }

        void addBlock(const vector<Transaction>& txs, const string& prevHash, float ver, int diff) {
            int idx = static_cast<int>(chain.size());
            Block* prev = chain.empty() ? nullptr : &chain.back();
            chain.emplace_back(idx, prev, txs, prevHash, ver, diff);
        }
        
        const Block& getLatestBlock() const {
            return chain.back();
        }
  };

  # endif