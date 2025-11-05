# ifndef BIBL_H
# define BIBL_H


#include "std.h"
#include "Timer.h"
#include "user.h"
#include "hash.h"
#include "Transaction.h"
#include "Block.h"
#include "Functions.h"

string hashing(string );
vector <User> GeneruotiUsers(int );
void salt(string &input );
inline std::string ws2s(const std::wstring& );

extern int difficulty;

# endif