#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
	int i = 0;
	int index = 0;

	Array array1(5);

	for(i = 0; i < array1.GetLength(); i++)
	{
		array1.SetValue(i, i);
	}

	Array array2(5);
	array2 = array1;

	cout << "array1" << endl;

	for(i = 0; i < array1.GetLength(); i++)
        {
                cout << array1.GetValue(i) << endl;
        }

	cout << "array2" << endl;

	for(i = 0; i < array2.GetLength(); i++)
	{
		cout << array2.GetValue(i) << endl;
	}

	cout << "----------operator== test----------" << endl;

	if(array1 == array2)
	{
		cout << "array1 = array2" << endl;
	}
	else
	{
		cout << "array1 != array2" <<endl;
	}

	cout << "----------operator!= test----------" << endl;

	if(array1 != array2)
	{
		cout << "array1 != array2" << endl;
	}
	else
	{
		cout << "array1 = array2" <<endl;
	}

	cout << "----------operator[] test----------" << endl;
	
	for(index = 0; index < array1.GetLength(); index++)
	{
		cout << array1[index] << endl;
	}
	

	return 0;
}
