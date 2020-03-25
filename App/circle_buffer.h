/*
 * circle_buffer.h
 *
 *  Created on: 2020年3月25日
 *      Author: Administrator
 */

#ifndef CIRCLE_BUFFER_H_
#define CIRCLE_BUFFER_H_

template<typename T>
class CircleBuffer
{

public:
	CircleBuffer(int size = 10);
	CircleBuffer(const CircleBuffer &c) = delete;
	CircleBuffer operator=(const CircleBuffer &c) = delete;
	~CircleBuffer();
	T Pop();
	void Pop(T *list, int size);
	void Push(const T &v);
	void Push(const T *list, int size);
	inline int Length() const
	{
		return (_indexWrite - _indexRead + _size) % _size;
	}
private:
	int _indexRead;
	int _indexWrite;
	T *_data;
	int _size;
};




#endif /* CIRCLE_BUFFER_H_ */
