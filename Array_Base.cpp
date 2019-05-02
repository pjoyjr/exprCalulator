/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#include "Array_Base.h"
#include <cstring>          // for size_t definition
#include <stdexcept>         // for std::out_of_bounds exception


#define DEFAULT_CUR_SIZE 20

// Array_Base
template <typename T>
Array_Base <T>::Array_Base (void)
:data_ (new T[DEFAULT_CUR_SIZE]),
cur_size_ (DEFAULT_CUR_SIZE)
{

}

// Array_Base (size_t)
template <typename T>
Array_Base <T>::Array_Base (size_t length)
:data_ (new T[length]),
cur_size_ (length)
{

}

// Array_Base (size_t, T)
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
:data_ (new T[length]),
cur_size_ (length)
{
	this->fill(fill);
}

// Array_Base (const Array_Base &)
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array)
:data_ (new T[array.size()]),
cur_size_ (array.size())
{
	for(size_t i = 0; i<array.size(); i++)
	{
		data_[i] = array.data_[i];
	}
}

// ~Array_Base
template <typename T>
Array_Base <T>::~Array_Base (void)
{
	delete[] data_;
}

// operator =
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base & rhs)
{
	if(this == &rhs)
		return *this;
	Array_Base * temp = new Array_Base(rhs);
	return *temp;
}

// operator []
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	if(index >= cur_size_)
		throw std::out_of_range ("oor");
	return data_[index];
}

// operator [] 
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	if(index >= cur_size_)
		throw std::out_of_range ("oor");
	return data_[index];
}

// get
template <typename T>
T Array_Base <T>::get (size_t index) const
{
	if(index >= cur_size_)
		throw std::out_of_range ("oor");
	return data_[index];
}

// set
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
	if(index >= cur_size_)
		throw std::out_of_range("oor");
	data_[index] = value;
}

// find (T)
template  <typename T>
int Array_Base <T>::find (T value) const
{
	for(size_t i = 0; i<cur_size_; i++)
	{
		if(this->data_[i] == value)
			return i;
	}
	return -1;
}

// find (T, size_t) 
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	if(start >= cur_size_)
		throw std::out_of_range("oor");
	while(start<cur_size_)
	{
		if(this->get(start) == val)
			return start;
		start++;
	}
	return -1;
}

// operator ==
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
	if(this == &rhs)
		return true;
	if(this->size() == rhs.size())
	{
		for(size_t i = 0; i < this->size(); i++)
		{
			if(this->get(i) != rhs.get(i))	
				return false;
		}
	}
	else
		return false;
	return true;
}

// operator !=
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	return !(*this == rhs);
}

// fill
template <typename T>
void Array_Base <T>::fill (T value)
{
	for(size_t i = 0; i < this->size(); i++)
	{
		data_[i] = value;
	}
}

// reverse
template <typename T>
void Array_Base <T>::reverse (void)
{
	size_t j = this->size();
	for(size_t i = 0; i<(j/2); i++)
	{
		T temp = data_[i];
		data_[i] = data_[j-i-1];
		data_[j-i-1] = temp;
	}
}


// slice
template <typename T>
Array_Base<T> Array_Base <T>::slice (size_t begin) const
{
	if(begin >= this->size())
		throw std::out_of_range("oor");
	size_t count = 0;
	size_t slicerSize = this->size() - begin;
	Array_Base<T> * temp = new Array_Base<T>(slicerSize);
	while(count < slicerSize)
	{
		temp[count] = this->get(begin);
		begin++;
		count++;
	}
	return *temp;
}

// slice overloaded
template <typename T>
Array_Base<T> Array_Base<T>::slice (size_t begin, size_t end) const
{
	if(begin >= this->size())
		throw std::out_of_range("oor");
	size_t count = 0;
	size_t slicerSize = this->size() - begin;
	Array_Base<T> * temp = new Array_Base<T>(slicerSize);
	while(begin < end)
	{
		temp[count] = this->get(begin);
		begin++;
		count++;
	}
	return *temp;
}
