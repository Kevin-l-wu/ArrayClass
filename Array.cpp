#include <iostream>
#include "Array.h"

using namespace std;

//TODO: Two Phase Construct is needed
Array::Array(int length)
{
	arrayPtr = new int[length];
	
	for(int i = 0; i < length; i++)
	{
		arrayPtr[i] = 0;
	}
	
	this->length = length;
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

bool Array::SetValue(int index, int value)
{
	bool ret = (0 <= index) && (index < length); 
	
	if(ret)
	{
		arrayPtr[index] = value;
	}
	
	return ret;
}

bool Array::GetValue(int index, int& value)
{
	bool ret = (0 <= index) && (index < length); 
	
	if(ret)
	{
		value = arrayPtr[index];
	}
	
	return ret;
}

Array::~Array()
{
        delete[] arrayPtr;
}
