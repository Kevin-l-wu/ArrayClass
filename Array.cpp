#include <iostream>
#include "Array.h"

using namespace std;

Array::Array(int length)
{
        this->length = length;
        arrayPtr = new int[this->length];
}

Array::Array(const Array& destArray)
{
	cout << "Array::Array(const Array& destArray)" << endl;

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


int& Array::operator[](int i)
{
	return this->arrayPtr[i];
}

Array& Array::operator=(Array& destArray)
{
	cout << "Array& Array::operator=(Array& destArray)" << endl;

	int index = 0;

	if(this->length != 0)
	{
		delete[] this->arrayPtr;
	}

	this->length = destArray.length;
	this->arrayPtr = new int[this->length];

	for(index = 0; index < this->length; index++)
	{
		this->arrayPtr[index] = destArray.arrayPtr[index];
	}

	return *this;
}

bool Array::operator==(Array& obj)
{
	bool ret = false;
	int index = 0;


	if(this->length == 0 || obj.length == 0)
	{
		return false;
	}

	if(this->length == obj.length && this->length > 0 )
	{
		for(index = 0; index < this->length; index++)
		{
			if(this->arrayPtr[index] != obj.arrayPtr[index])
			{
				ret = false;
				break;
			}
			ret = true;
		}
	}else
	{
		return false;
	}

	return ret;
}

bool Array::operator!=(Array& obj)
{
	bool ret = true;
	int index = 0;	

	if(this->length == 0 || obj.length == 0)
	{
		return true;
	}
	
	if(this->length ==  obj.length && this->length > 0 )
	{
		for(index = 0; index < this->length; index++)
		{
			if(this->arrayPtr[index] != obj.arrayPtr[index])
			{
				ret = true;
				break;
			}
			ret = false;
		}
	}else
	{
		return true;
	}

	return ret;

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
