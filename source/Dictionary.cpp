#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <s3eFile.h>
#include <s3eMemory.h>

#include "Dictionary.h"



using namespace std;

static char* g_DataToBeRead;
const string dictFilePath = "Allwords.csv";

Dictionary::Dictionary()
{
	initMemory();
	loadDictionary();

}
void Dictionary::initMemory()
{
	//Open file using marmalade file opener
	s3eFile* file = s3eFileOpen(dictFilePath.c_str(), "rb");
	
	//Set Up Memory location for read
	s3eFreeBase((void*)g_DataToBeRead);
	int32 fileSize = s3eFileGetSize(file);
	g_DataToBeRead = (char*)s3eMallocBase(fileSize + 1);
	memset(g_DataToBeRead, 0, fileSize);

	//Read file and error out on error reading
	if (s3eFileRead(&g_DataToBeRead[0], fileSize, 1, file) != 1)
	{
		// An error has occurred, retrieve information for display
		s3eFileGetError();
	}
	else
	{
		// Data reading has been successful
		g_DataToBeRead[fileSize + 1] = '\0';
	}
}

void Dictionary::loadDictionary()
{
	string dictStr = g_DataToBeRead;
	string word = "";
	for (std::string::iterator it = dictStr.begin(); it != dictStr.end(); ++it)
	{
		if (*it == '\r')
		{
			dictList.push_back(word);
			word = "";
			printf(word.c_str());
		}
		else if (*it == '\n')
		{

		}
		else
		{
			word += *it;
		}
	}
}

bool Dictionary::isWord(string word)
{
	return binary_search(dictList.begin(), dictList.end(), word);

}

