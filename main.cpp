#include "bibl.h"
#include <charconv>
#define UNICODE

int difficulty = 3;

int main(){
    setlocale(LC_ALL, "Lithuanian");
    vector <User> users = GeneruotiUsers(1000);

    printUsers(users, 50);
    vector <Transaction> transactions = GeneruotiTransactions(users,10000);
    printTransactions(transactions, 100);

    Blockchain blockchain;
    long limit = 500000;
    int abort = 0;
    while (!transactions.empty()){
        int chainsize = blockchain.size();
        int kiekis = std::min(100, int(transactions.size()));
        vector<Transaction> blockTransactions(transactions.begin(), transactions.begin() + kiekis);
        
        transactions=VerifyTransactions(transactions, users);
        string previousHash = blockchain.getLatestBlock().getHash();

        string transactionhash;

        for (const Transaction& tx : blockTransactions) {
            transactionhash += tx.getId();
        }

        transactionhash = hashing(transactionhash);

        float version = 1.0;
        long nonce = 0;
        long foundNonce = 0;
        string hash;

        string headerNonceless = previousHash + std::to_string(std::time(nullptr)) + std::to_string(version) + transactionhash + std::to_string(difficulty);


        // Try nonces until we find a hash that starts with the required number of '0' hex chars
        while (true) {
            hash = hashing(headerNonceless + std::to_string(nonce));

            if (hash.substr(0, difficulty) == string(difficulty, '0')) {
                foundNonce = nonce;
                break;
            }
            if (nonce % 100000 == 0) cout << "\r" << "Mining block... Nonce: " << nonce << " Hash: " << hash << std::flush;
            if (nonce > limit){
                cout << endl << "Mining aborted after 500,000 nonces. Taking new transactions" << endl;
                break;
            }
            ++nonce;
        }   
        if (nonce > limit){
            vector<Transaction> blockTransactions(transactions.end()-kiekis, transactions.end());
            abort++;
            if (abort >= 5){
                cout << "Multiple mining aborts. Increasing limit." << endl;
                limit +=500000;
            }
            continue;
        }
        abort=0;
        limit = 500000;
        cout << endl << "Found nonce: " << foundNonce << endl;
        cout << "Hash: " << hash << endl;

        blockchain.addBlock(blockTransactions, version, difficulty,nonce,hash);
        for (const Transaction& tx : blockTransactions) {
            for (User& user : users) {
                if (user.getKey() == tx.getSiunt()) {
                    user.changeBalance(-tx.getKiek());
                }
                if (user.getKey() == tx.getGav()) {
                    user.changeBalance(tx.getKiek());
                }
            }
        }
        transactions.erase(transactions.begin(), transactions.begin() + kiekis);

        cout << "Blockchain size: " << blockchain.size() << endl;
        cout << "Remaining transactions: " << transactions.size() << endl;
    }
    blockchain.printChain();
    blockchain[50].printBlockInfo();
    blockchain[50][10].printTransaction();

    printUsers(users, 100);


 return 0;
}
