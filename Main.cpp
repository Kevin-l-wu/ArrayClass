#include <iostream>
#include "HeapArray.h"

using namespace std;

int main()
{
	int i = 0;
	int getValue = 0;

	HeapArray<int>* pArray1 = HeapArray<int>::NewInstance(5);
	HeapArray<int>* pArray2 = HeapArray<int>::NewInstance(10);
	
	cout << "pArray1 = " << pArray1 << endl;
	cout << "pArray2 = " << pArray2 << endl;

	if(pArray1 && pArray2)
	{
		HeapArray<int>& array1 = pArray1->Self();
		HeapArray<int>& array2 = pArray2->Self();
		
		for(i = 0; i < array1.GetLength(); i++)
		{
			array1[i] = i;
		}
		
		for(i = 0; i < array1.GetLength(); i++)
		{
			cout << array1[i] << endl;
		}
		
		for(i = 0; i < array2.GetLength(); i++)
		{
			array2[i] = i + 10;
		}
		
		for(i = 0; i < array2.GetLength(); i++)
		{
			cout << array2[i] << endl;
		}
		
		array2 = array1;
		
		for(i = 0; i < array2.GetLength(); i++)
		{
			cout << array2[i] << endl;
		}
	}

	delete pArray2;
	delete pArray1;

	return 0;
}
