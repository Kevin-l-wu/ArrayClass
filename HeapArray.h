#ifndef _HEAP_ARRAY_H_
#define _HEAP_ARRAY_H_

//Two phase construct do not support copy construct
template <typename T>
class HeapArray
{
private:
	int length;
	T* arrayPtr;
	HeapArray(int length);
	bool Construct();
public:
	static HeapArray<T>* NewInstance(int length);
	HeapArray(const HeapArray<T>& obj);
	HeapArray<T>& Self();
	int GetLength();
	
	T& operator[](int i);
	HeapArray<T>& operator=(HeapArray<T>& obj);
	bool operator==(HeapArray<T>& obj);
	bool operator!=(HeapArray<T>& obj);

	bool SetValue(int index, T value);
	bool GetValue(int index, T& value);
	~HeapArray();
};


template <typename T>
HeapArray<T>::HeapArray(int length)
{
	this->length = length;
}


template <typename T>
bool HeapArray<T>::Construct()
{
	arrayPtr = new T[length];
	
	return (arrayPtr != NULL);
}

template <typename T>
HeapArray<T>* HeapArray<T>::NewInstance(int length)
{
	HeapArray<T>* ret = new HeapArray<T>(length);
	
	if((ret != NULL) && (ret->Construct() == false))
	{
		delete ret;
		ret = NULL;
	}
	
	return ret;
}

template <typename T>
HeapArray<T>::HeapArray(const HeapArray& obj)
{
//	cout << "HeapArray::HeapArray(const HeapArray& obj)" << endl;

	int index = 0;

	this->length = obj.length;
	this->arrayPtr = new int[this->length];

	for(index = 0; index < this->length; index++)
	{
		this->arrayPtr[index] = obj.arrayPtr[index];
	}
}

template <typename T>
HeapArray<T>& HeapArray<T>::Self()
{
	return *this;
}

template <typename T>
int HeapArray<T>::GetLength()
{
	return length;
}

template <typename T>
T& HeapArray<T>::operator[](int i)
{
	return this->arrayPtr[i];
}

template <typename T>
HeapArray<T>& HeapArray<T>::operator=(HeapArray<T>& obj)
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

template <typename T>
bool HeapArray<T>::operator==(HeapArray& obj)
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

template <typename T>
bool HeapArray<T>::operator!=(HeapArray<T>& obj)
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

template <typename T>
bool HeapArray<T>::SetValue(int index, T value)
{
	bool ret = (0 <= index) && (index < length); 
	
	if(ret)
	{
		arrayPtr[index] = value;
	}
	
	return ret;
}

template <typename T>
bool HeapArray<T>::GetValue(int index, T& value)
{
	bool ret = (0 <= index) && (index < length); 
	
	if(ret)
	{
		value = arrayPtr[index];
	}
	
	return ret;
}

template <typename T>
HeapArray<T>::~HeapArray()
{
	if(arrayPtr != NULL)
	{
		delete[] arrayPtr;
		arrayPtr = NULL;
	}
}

#endif
