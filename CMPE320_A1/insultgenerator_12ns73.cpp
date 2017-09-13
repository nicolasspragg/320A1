#include "insultgenerator_12ns73.h"

//Created by Nicolas for CMPE 320
//program makes a set of random, unique insults 
using namespace std;
InsultGenerator::InsultGenerator() {}

string InsultGenerator::talkToMe()
{
	int insultSelectorIDForList1 = setRandomNum();
	int insultSelectorIDForList2 = setRandomNum();
	int insultSelectorIDForList3 = setRandomNum();
	string diss = "Thou " + listOfInsults1[insultSelectorIDForList1] + " " + listOfInsults2[insultSelectorIDForList2] + " " + listOfInsults3[insultSelectorIDForList3] + "!";
	return diss;
}

// load in insults into vectors 
void InsultGenerator::initialize() {
	string line;
	string t1;
	string t2;
	string t3;
	ifstream txtFile("InsultsSource.txt");
	if (txtFile.fail()) {
		throw FileException("Wrong file. Program failed successfully");
		return;
	}
	while ((txtFile >> t1) && (txtFile >> t2) && (txtFile >> t3)) {
	listOfInsults1.push_back(t1);
	listOfInsults2.push_back(t2);
	listOfInsults3.push_back(t3);
	}
}


vector<string> InsultGenerator::generate(int n)
{
	if (n > 10000) { throw NumInsultsOutOfBounds("Too large"); return vector<string>(); }
	if (n <1) { throw NumInsultsOutOfBounds("Too small"); return vector<string>();}
	srand(time(NULL));
	while (n > setOfInsults.size()) {
		setOfInsults.insert(talkToMe());
	}
	vector<string> allInsultsGenerated (setOfInsults.begin(), setOfInsults.end());
	return allInsultsGenerated;
}

vector<string> InsultGenerator::generateAndSave(string str, int n)
{
	vector<string> insultsForFile = generate(n);
	ofstream output(str);
	if (output.fail()) {
		throw FileException("error writing to file");
		return vector<string>();
	}
	ostream_iterator<string> output_i(output, "\n");
	copy(insultsForFile.begin(), insultsForFile.end(), output_i);
	return insultsForFile;
}
int InsultGenerator::setRandomNum(){return rand() % 49;}
NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string &m) : message(m) {};
FileException::FileException(const string &m) : message(m) {};
string NumInsultsOutOfBounds::what(){
	return message;
}
string FileException::what() {
	return message;
}



