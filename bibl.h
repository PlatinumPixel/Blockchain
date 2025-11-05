# ifndef BIBL_H
# define BIBL_H


#include "std.h"
#include "Timer.h"
#include "user.h"
#include "Transaction.h"

string hashing(string& );
void salt(string &input);
inline std::string ws2s(const std::wstring& );

extern int difficulty;

# endif