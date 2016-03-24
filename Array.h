#ifndef ARRAY_H_
#define ARRAY_H_

class Array
{
private:
	int length;
	int* arrayPtr;
public:
	Array(int length);
	Array(const Array& destArray);
	int GetLength();
	void SetValue(int index, int value);
	int GetValue(int index);
	~Array();
};



#endif
