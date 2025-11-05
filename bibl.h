# ifndef BIBL_H
# define BIBL_H


#include "std.h"
#include "user.h"
#include "hash.h"
#include "Transaction.h"
#include "Block.h"
#include "Blockchain.h"
#include "Functions.h"

string hashing(string );
vector <User> GeneruotiUsers(int );
void salt(string &input );

extern int difficulty;

# endif