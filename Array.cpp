// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <cstring>          // for size_t definition
#include <stdexcept>         // for std::out_of_bounds exception

#define DEFAULT_MAX_SIZE 20
// Array
template <typename T>
Array<T>::Array (void)
:Array_Base<T>(),
max_size_ (DEFAULT_MAX_SIZE)
{

}

// Array (size_t)
template <typename T>
Array<T>::Array (size_t length)
:Array_Base<T>(length),
max_size_ (length)
{

}

// Array (size_t, T)
template <typename T>
Array<T>::Array (size_t length, T fill)
:Array_Base<T>(length),
max_size_ (length)
{
	this->fill(fill);
}

// Array (const Array &)
template <typename T>
Array<T>::Array (const Array & array)
:Array_Base<T>(array.size())
{
	for(size_t i = 0; i<array.size(); i++)
	{
		this->set(i, array[i]);
	}
}

// ~Array
template <typename T>
Array <T>::~Array (void)
{
	
}

// operator =
template <typename T>
const Array<T> & Array<T>::operator = (const Array & rhs)
{
	if(this == &rhs)
		return *this;
	Array * temp = new Array(rhs);
	return *temp;
}

// operator []
template <typename T>
T & Array<T>::operator [] (size_t index)
{
	if(index >= this->size())
		throw std::out_of_range ("oor");
	return this->get(index);
}

// operator [] 
template <typename T>
const T & Array<T>::operator [] (size_t index) const
{
	if(index >= this->size())
		throw std::out_of_range ("oor");
	return this->get(index);
}

// operator ==
template <typename T>
bool Array<T>::operator == (const Array & rhs) const
{
	if(this == &rhs)
		return true;
	if(this->size() == rhs.size())
	{
		for(size_t i = 0; i < this->size(); i++)
		{
			if(this->data_[i] != rhs.data_[i])		
				return false;
		}
	}
	else
		return false;
	return true;
}

// operator !=
template <typename T>
bool Array<T>::operator != (const Array & rhs) const
{
	return !(*this == rhs);
}

// resize
template <typename T>
void Array<T>::resize (size_t new_size)
{
	if(new_size < max_size_)
		this->cur_size_ = new_size;
	if(new_size > max_size_)
	{
		T * temp  = new T[new_size];
		for(size_t i = 0; i<this->size(); i++)
		{
			temp[i] = this->data_[i];
		}
		this->data_ = temp;
		max_size_ = new_size;
		this->cur_size_ = new_size;
	}
}

//shrink
template <typename T>
void Array<T>::shrink(void)
{
	if(this->size() < max_size_)
	{
		T * temp = new T[this->size()];
		for(size_t i = 0; i <this->size(); i++)
		{
			temp[i] = this->get(i);
		}
		this->data_ = temp;
		max_size_ = this->size();
	}
}