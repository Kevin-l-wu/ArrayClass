#include <iostream>
#include "Array.h"

using namespace std;

//TODO: Two Phase Construct is needed
Array::Array(int length)
{
	this->length = length;
}

bool Array::Construct()
{
	arrayPtr = new int[length];
	
	if(arrayPtr != NULL)
	{
		for(int i = 0; i < length; i++)
		{
			arrayPtr[i] = 0;
		}
		return true;
	}
	else
	{
		return false;
	}
}

Array* Array::NewInstance(int length)
{
	Array* ret = new Array(length);
	
	if((ret != NULL) && (ret->Construct() == false))
	{
		delete ret;
		ret = NULL;
	}
	
	return ret;
}

Array::Array(const Array& obj)
{
	cout << "Array::Array(const Array& obj)" << endl;

	int index = 0;

	this->length = obj.length;
	this->arrayPtr = new int[this->length];

	for(index = 0; index < this->length; index++)
	{
		this->arrayPtr[index] = obj.arrayPtr[index];
	}
}

Array& Array::Self()
{
	return *this;
}

int Array::GetLength()
{
	return length;
}

int& Array::operator[](int i)
{
	return this->arrayPtr[i];
}

Array& Array::operator=(Array& obj)
{
	if(this != &obj)
	{	
		int* pointer = new int[obj.length];
		
		if(pointer != NULL)
		{
			for(int index = 0; index < obj.length; index++)
			{
				pointer[index] = obj.arrayPtr[index];
			}

			if(this->arrayPtr != NULL)
			{
				delete[] this->arrayPtr;
			}
			
			this->length = obj.length;
			this->arrayPtr = pointer;
		}		
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
	if(arrayPtr != NULL)
	{
		delete[] arrayPtr;
		arrayPtr = NULL;
	}
}