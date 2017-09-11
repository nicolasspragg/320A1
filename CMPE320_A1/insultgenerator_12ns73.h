#pragma once
#include <vector>
#include <set>
class insultgenerator_12ns73
{
public:
	insultgenerator_12ns73();
	
	~insultgenerator_12ns73();
};

class InsultGenerator
{ public:
	InsultGenerator();
	string talkToMe();
	void initialize();
	vector<string> generate(int n);
	vector<string> generateAndSave(string str, int n);
private:
	int randomNum();
	vector<string> list1;
	vector<string> list2;
	vector<string> list2;
	set<string> setOfInsults;

};

class FileException {
public:
	FileException(string str) { message = str; }
	string what() { return message; }
private:
	string message;
};

class NumInsultsOutOfBounds {
public:
	NumInsultsOutOfBounds(string str) { message = str; }
	string what() { return message; }
private:
	string message;
};