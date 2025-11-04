# ifndef BIBL_H
# define BIBL_H


#include "std.h"
#include "Timer.h"
#include "user.h"

string hashing(string& );
void spausdina(vector <string> ,vector <string> );
void rankinis(vector <string> &);
void salt(string &input);
inline std::string ws2s(const std::wstring& );
void failoNusk (vector<string> &, vector <string> &);
void failoNuskBeSalt (vector<string> &, vector <string> &);
void failoGen();
void spausdinaFaila(vector <string> ,vector <string> , string );

# endif