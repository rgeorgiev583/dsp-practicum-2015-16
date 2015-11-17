#ifndef STRING_WITH_HISTORY
#define STRING_WITH_HISTORY

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class StringWithHistory : public string
{
private:
	stack<string> undoData;
	stack<string> redoData;

public:
	void Undo();
	void Redo();

	StringWithHistory& operator=( string const& );
	StringWithHistory& operator+=( string const& );
	char& operator[]( size_t );
	operator string(){ return this->data(); }

	friend ostream& operator<<( ostream&, StringWithHistory const& );
};

#endif