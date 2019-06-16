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
	int& operator[](int i);
	Array& operator=(Array& obj);
	bool operator==(Array& obj);
	bool operator!=(Array& obj);

	bool SetValue(int index, int value);
	bool GetValue(int index, int& value);
	~Array();
};



#endif
