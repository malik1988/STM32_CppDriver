/*
 * circle_buffer.cpp
 *
 *  Created on: 2020年3月25日
 *      Author: Administrator
 */
#include "circle_buffer.h"

template<typename T>
CircleBuffer<T>::CircleBuffer(int size) :
		_indexRead(0), _indexWrite(0), _size(size)
{
	if (size > 0)
		_data = new T[size];
	else
	{
		//error
		throw("Circle Size Can't be 0!");
	}
}

template<typename T>
T CircleBuffer<T>::Pop()
{
	T v;
	if (_indexRead == _indexWrite)
	{ //空
	}
	else
	{
		v = _data[_indexRead];
		_indexRead = (_indexRead + 1) % _size;
	}
	return v;
}

template<typename T>
void CircleBuffer<T>::Pop(T *list, int size)
{

	for (int i = 0; i < size && _indexRead != _indexWrite;
			i++, _indexRead = (_indexRead + 1) % _size)
	{
		list[i] = _data[_indexRead];
	}
}
template<typename T>
void CircleBuffer<T>::Push(const T &v)
{
	if ((_indexWrite + 1) % _size == _indexRead)
	{ //满

	}
	else
	{
		_data[_indexWrite] = v;
		_indexWrite = (_indexWrite + 1) % _size;
	}
}
template<typename T>
void CircleBuffer<T>::Push(const T *list, int size)
{
	for (int i = 0; i < size && (_indexWrite + 1) % _size != _indexRead;
			i++, _indexWrite = (_indexWrite + 1) % _size)
	{
		_data[_indexWrite] = list[i];
	}
}
