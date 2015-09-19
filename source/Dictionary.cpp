#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>

#include "Dictionary.h"

using namespace std;



Dictionary::Dictionary(string fileName)
{
	ifstream file(fileName.c_str()); 

	while (file.good())
	{
		string line;
		getline(file, line);
		data.insert(data.end(), line.c_str());
	}
}

bool Dictionary::isWord(string word)
{
	return binary_search(data.begin(), data.end(), word);
}
