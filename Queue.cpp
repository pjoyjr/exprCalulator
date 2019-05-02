/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#include <cstring>          // for size_t definition
#include "Queue.h"
#include <stdexcept>         // for std::out_of_bounds exception

template <typename T>
Queue <T>::Queue (void)
:arr (),
tail (0)
{

}

template <typename T>
Queue <T>::Queue(const Queue & que)
:arr (que.getTail()),
tail (0)
{
	for(size_t i = 0; i < que->getTail(); i++)
	{
		arr.set(i, arr.get(i));
		tail++;
	}
}

template <typename T>
Queue <T>::~Queue(void)
{
	
}

template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	if(this == &rhs)
		return *this;
	
  // This is not making a copy of the rhs.
	this->arr.resize(rhs.getTail());
	for(size_t i = 0; i < rhs.getTail(); i++)
	{
		this->arr.set(i, rhs.arr.get(i));
	}
	this->tail = rhs.getTail(); 
	return *this;
}

template <typename T>
void Queue <T>::rearrange(void)
{
	for(size_t i = 0; i < (this->getTail()-1); i++)
	{
		T swap = arr.get(i+1);
		arr.set(i, swap);
	}
	tail--;
}

template <typename T>
void Queue <T>::enqueue(T element)
{
	if(this->getTail() < arr.size())
	{
		arr.set(tail, element);
		tail++;
	}
	else
	{
		arr.resize(arr.size()+1);
		this->enqueue(element);
	}
	
}

template <typename T>
T Queue <T>::dequeue(void)
{
	if(this->is_empty())
		throw empty_exception();
  
  // COMMENT This design is OK, but it is not the best design. This will be
  // a very expensive array to use if you are dequeing a lot of elements. This
  // is because you are copying N elements each time you dequeue 1 element.
  // Instead, you only want to copy element when necessary. Come up with a better
  // design that is not as expensive for the client to use.
  
	T temp = arr.get(0);
	this->rearrange();
	return temp;
}


template <typename T>
void Queue <T>::clear(void)
{
	tail = 0;
}
