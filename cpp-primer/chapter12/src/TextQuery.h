// TextQuery.h

#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>

typedef std::pair<int, std::set<int>> QueryResult;

class TextQuery
{
public:
	TextQuery(std::istream &);
	QueryResult query(const std::string &) const;
	std::string getLineContent(const int) const;
	void showText() const;
	~TextQuery();
private:
	TextQuery();
	std::vector<std::string> text;
	std::map<std::string, std::set<int>> wordRecord;
};
#endif