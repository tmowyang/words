//=================================
// include guard
#ifndef __X_H_INCLUDED__   // if x.h hasn't been included yet...
#define __X_H_INCLUDED__   //   #define this so the compiler knows it has been included

//=================================
// forward declared dependencies
class Dictionary;

//=================================
// included dependencies

#include <list>
#include <string>

using namespace std;

class Dictionary
{
	public:
		Dictionary();
		bool isWord(std::string word);

	private:
		void initMemory();
		void loadDictionary();

		list<string> dictList;
		const string dictFilePath;
};

#endif