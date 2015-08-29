// main.cpp
#include <iostream>
#include <fstream>
#include "TextQuery.h"

using namespace std;

void
useQuery(ifstream &in){
	TextQuery tq(in);
	cout << "Input File: " << endl;
 	tq.showText();
	
	while(1) {
		cout << "enter word to look for, or q to quit: ";
		string word;
		if(!(cin >> word) || word == "q")
			break;

		QueryResult qr = tq.query(word);
		cout << word << "occur " << qr.first << " times" << endl;
		for_each(qr.second.begin(), qr.second.end(), 
			[&tq](const int index){
				cout << "at line " << (index + 1) << ". " << tq.getLineContent(index) << endl;
			}
		);
	}
}

int
main(int argc, char** argv) {
	if(argc < 2) {
		cout << "need a file to init." << endl;
		return 0;
	}
	
	ifstream infile(argv[1]);
	useQuery(infile);

	return 0;
}