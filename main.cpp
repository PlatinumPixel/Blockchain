#include "bibl.h"
#include <charconv>
#define UNICODE

int difficulty = 3;

int main(){
    setlocale(LC_ALL, "Lithuanian");
    vector <User> users = GeneruotiUsers(1000);

    printUsers(users, 50);
    vector <Transaction> transactions = GeneruotiTransactions(users, 100);

    printTransactions(transactions);

    Blockchain blockchain;

    while (!transactions.empty()){
        int kiekis = std::min(100, int(transactions.size()));
        vector<Transaction> blockTransactions(transactions.begin(), transactions.begin() + kiekis);
        string previousHash = blockchain.getLatestBlock().getHash();

        string transactionhash;

        for (const Transaction& tx : blockTransactions) {
            transactionhash += tx.getId();
        }

        transactionhash = hashing(transactionhash);

        float version = 1.0f;
        std::uint64_t nonce = 0;
        std::uint64_t foundNonce = 0;
        string hash;

        // Build the header without nonce once; we'll append the nonce digits into a reusable buffer
        string headerNonceless = previousHash + std::to_string(std::time(nullptr)) + std::to_string(version) + transactionhash + std::to_string(difficulty);
        string trial = headerNonceless;
        trial.reserve(headerNonceless.size() + 32); // enough space for nonce digits

        // Try nonces until we find a hash that starts with the required number of '0' hex chars
        while (true) {
            trial.resize(headerNonceless.size());
            char buf[32];
            auto res = std::to_chars(buf, buf + sizeof(buf), nonce);
            trial.append(buf, res.ptr - buf);

            hash = hashing(trial);

            if (hash.size() >= (size_t)difficulty && hash.substr(0, difficulty) == string(difficulty, '0')) {
                foundNonce = nonce;
                break;
            }

            // Print progress occasionally (every 4096 iterations) to avoid slowing the loop
            if ((nonce & 0xFFF) == 0) {
                cout << "\r" << "Mining block... Nonce: " << nonce << " Hash: " << hash << std::flush;
            }

            ++nonce;
        }

        cout << endl << "Found nonce: " << foundNonce << endl;
        cout << "Hash: " << hash << endl;

    }


 return 0;
}
