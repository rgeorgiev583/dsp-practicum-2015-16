#include "stdafx.h"
#include "string_with_history.h"

void StringWithHistory::Undo()
{
	if( !undoData.empty() )
	{
		redoData.push( this->data() );
		string::operator=( undoData.top() );
		undoData.pop();
	}
}

void StringWithHistory::Redo()
{
	if( !redoData.empty() )
	{
		undoData.push( this->data() );
		string::operator=( redoData.top() );
		redoData.pop();
	}
}

StringWithHistory& StringWithHistory::operator=( string const& src )
{
	if( this != &src )
	{
		undoData.push( this->data() );
		string::operator=(src);
	}
	return *this;
}

StringWithHistory& StringWithHistory::operator+=( string const& other )
{
	undoData.push( this->data() );
	string::operator+=( other );
	return *this;
}

char& StringWithHistory::operator[]( size_t index )
{
	if( index < this->size() )
	{
		return string::operator[](index);
	}
}

ostream& operator<<( ostream& os, StringWithHistory const& src )
{
	os<<src.data();
	return os;
}