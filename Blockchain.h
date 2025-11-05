# ifndef BLOCKCHAIN_H
# define BLOCKCHAIN_H

#include "std.h"
#include "bibl.h"

class Blockchain {
    private:
     vector <Block> chain; 

    public:
        Blockchain() {
            // create genesis block: index 0, no previous, prevHash string, version, difficulty, empty tx list
            string genesishash=hashing("000000000000000000000000000000000000000000000000000000000000001.03{}0");
            Block genesisBlock(0, nullptr, "000000000000000000000000000000000000000000000000000000000000000", 1.0, 3, {}, 0, genesishash);
            chain.emplace_back(genesisBlock);
        }

        void addBlock(const vector<Transaction>& txs, float ver, int diff, int nonce, string hash) {
            int idx = static_cast<int>(chain.size());
            Block* prev = chain.empty() ? nullptr : &chain.back();
            string prevHash=chain.back().getHash();
            chain.emplace_back(idx, prev, prevHash, ver, diff, txs, nonce, hash);
        }

        void addBlock(const Block& newBlock) {
            chain.emplace_back(newBlock);
        }
        
        const Block& getLatestBlock() const {
            return chain.back();
        }

        const Block& operator[](size_t index) const {
            return chain[index];
        }

        int size() const {
            return chain.size();
        }

        void printChain() const {
            std::ofstream rf ("blockchain.txt");
            cout << "Blockchain-------------:" << endl;
            for (const auto& block : chain) {
                cout << "Block Index: " << block.getIndex() << " Hash: " << block.getHash() << endl;
                rf << "Block Index: " << block.getIndex() << " Hash: " << block.getHash() << endl;
            }
        }
  };

  # endif