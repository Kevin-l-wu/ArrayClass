#include "Array.h"

Array::Array(int length)
{
        this->length = length;
        arrayPtr = new int[this->length];
}

Array::Array(const Array& destArray)
{
	int index = 0;

	this->length = destArray.length;
	this->arrayPtr = new int[this->length];

	for(index = 0; index < this->length; index++)
	{
		this->arrayPtr[index] = destArray.arrayPtr[index];
	}
}


int Array::GetLength()
{
	return length;
}

void Array::SetValue(int index, int value)
{
        arrayPtr[index] = value;
}

int Array::GetValue(int index)
{
        return arrayPtr[index];
}

Array::~Array()
{
        delete[] arrayPtr;
}
