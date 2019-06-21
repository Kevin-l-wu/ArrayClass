#ifndef ARRAY_H_
#define ARRAY_H_
//Two phase construct do not support copy construct
class Array
{
private:
	int length;
	int* arrayPtr;
	Array(int length);
	bool Construct();
public:
	static Array* NewInstance(int length);
	Array(const Array& obj);
	Array& Self();
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
