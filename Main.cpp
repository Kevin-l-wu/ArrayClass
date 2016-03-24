#include "iostream"
#include "Array.h"

using namespace std;

int main()
{
	int i = 0;

	Array array1(5);

	for(i = 0; i < array1.GetLength(); i++)
	{
		array1.SetValue(i, i);
	}

	Array array2 = array1;

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

	return 0;
}
