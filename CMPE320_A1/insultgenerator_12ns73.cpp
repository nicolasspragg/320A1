#include "insultgenerator_12ns73.h"

//Created by Nicolas for CMPE 320
//program makes a set of random, unique insults

using namespace std;

InsultGenerator::InsultGenerator() {}

string InsultGenerator::talkToMe()
{
	srand(time(NULL));
	int insultSelectorIDForList1 = setRandomNum();
	int insultSelectorIDForList2 = setRandomNum();
	int insultSelectorIDForList3 = setRandomNum();

	cout << insultSelectorIDForList1 << endl;
	cout << insultSelectorIDForList2 << endl;
	cout << insultSelectorIDForList3 <<endl;
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
		throw FileException("Wrong file");
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
	return vector<string>();
}

vector<string> InsultGenerator::generateAndSave(string str, int n)
{
	return vector<string>();
}

int InsultGenerator::setRandomNum()
{
	
	int num = rand() % 49;
	return num;
	
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
try {
		ig.initialize();
	} catch (FileException& e) {
		cerr << e.what() << endl;
		return 1;
	}

	string dissTest = ig.talkToMe();

	cout << dissTest;
	
	cin.get();

	return 0;
}
