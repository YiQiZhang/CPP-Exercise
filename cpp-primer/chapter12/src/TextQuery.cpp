#include <iostream>
#include <string>
#include <sstream>
#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(std::istream &in)
{
	string line;
	while(getline(in, line)) {
		string word;
		istringstream istrm(line);
		while(istrm >> word) {

			wordRecord[word].insert(text.size());
		}
		text.push_back(line);
	}
}


QueryResult TextQuery::query(const std::string &s) const
{
	auto word = wordRecord.find(s);
	if(word == wordRecord.cend()) {
		return {0, std::set<int>()};
	} else {
		return {word->second.size(), word->second};
	}
}

std::string TextQuery::getLineContent(const int index) const
{
	if(text.size() >= index) {
		return text[index];
	} else {
		return string("");
	}
}

void TextQuery::showText() const
{
	for(const auto &line : text) {
		cout << line << endl;
	}
}

TextQuery::~TextQuery() {

}