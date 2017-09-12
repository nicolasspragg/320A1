#include "insultgenerator_12ns73.h"

//Created by Nicolas for CMPE 320
//program makes a set of random, unique insults
#include <iostream>
#include<fstream>
#include<string>
#include <sstream>
#include<vector>
using namespace std;


InsultGenerator::InsultGenerator() {}

string InsultGenerator::talkToMe()
{
	string str= "hello";
	return str;
}

// load in insults into vectors 
void InsultGenerator::initialize() {
	string line;
	string t1;
	string t2;
	string t3;

	ifstream txtFile("InsultsSource.txt");
	if (txtFile.fail()) {
		throw FileException("Wrong file");
		return;
	}

	while ((txtFile >> t1) && (txtFile >> t2) && (txtFile >> t3)) {
	listOfInsults1.push_back(t1);
	listOfInsults2.push_back(t2);
	listOfInsults3.push_back(t3);
	}


	for (size_t i = 0; i < listOfInsults1.size(); i++)
	{
		cout << listOfInsults1[i] << ' ';
	}


}





vector<string> InsultGenerator::generate(int n)
{
	return vector<string>();
}

vector<string> InsultGenerator::generateAndSave(string str, int n)
{
	return vector<string>();
}

int InsultGenerator::randomNum()
{
	return 0;
}

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string &m) : message(m) {};
FileException::FileException(const string &m) : message(m) {};
string NumInsultsOutOfBounds::what(){
	return message;
}
string FileException::what() {
	return message;
}

// testing 
int main() {
	InsultGenerator ig;

	ig.initialize();

	cin.get();
	return 0;
}
