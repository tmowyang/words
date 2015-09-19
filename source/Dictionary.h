//=================================
// include guard
#ifndef __X_H_INCLUDED__   // if x.h hasn't been included yet...
#define __X_H_INCLUDED__   //   #define this so the compiler knows it has been included

//=================================
// forward declared dependencies
class Dictionary;

//=================================
// included dependencies
using namespace std;
#include <list>


class Dictionary
{
	public:
		Dictionary(string fileName);
		bool isWord(string word);

	private:
		list<string> data;
};

#endif