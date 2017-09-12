#pragma once

#include <vector>
#include <set>
#include<fstream>

#include <sstream>


using namespace std;

class InsultGenerator
{ 
public:

		InsultGenerator();
		string talkToMe();
		void initialize();
		vector<string> generate(const int n);
		vector<string> generateAndSave(const string str, const int n);
private:

		int randomNum();
		vector<string> listOfInsults1;
		vector<string> listOfInsults2;
		vector<string> listOfInsults3;
		set<string> setOfInsults;
		

};

class FileException {
public:
	FileException(const string&);
	string what();
private:
	string message;
};

class NumInsultsOutOfBounds {
public:
	NumInsultsOutOfBounds(const string&);
	string what();
private:
	string message;
};


