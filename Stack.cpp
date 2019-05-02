/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#include "Stack.h"
#include <cstring>          // for size_t definition
// Stack


template <typename T>
Stack <T>::Stack (void)
:arr ()
,tail (0)
{

}

// Stack
template <typename T>
Stack <T>::Stack (const Stack & stack)
:arr (stack->getTail())
,tail (stack->getTail())
{
	for(size_t i = 0; i < stack->getTail; i++)
	{
		arr->set(i, stack->get(i));
	}
}

// ~Stack
template <typename T>
Stack <T>::~Stack (void)
{
}

// push
template <typename T>
void Stack <T>::push (T element)
{
	if(this->getTail() < arr.size())
	{
		arr.set(tail, element);
		tail++;
	}
	else{
		size_t newSize = arr.size() + 1;
		arr.resize(newSize);
		this->push(element);
	}
}

// pop
template <typename T>
void Stack <T>::pop (void)
{
	if(this->getTail() == 0)
		throw empty_exception();
	tail--;
}

// operator =
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if(this == &rhs)
		return *this;
  
  // COMMENT This is not making a copy of the rhs.
	this.arr.resize(rhs.getTail());
	for(size_t i = 0; i < rhs.getTail(); i++)
	{
		this.arr.set(i, rhs.arr.get(i));
	}
	this.tail = rhs.getTail(); 
	return *this;
	
}

// clear
template <typename T>
void Stack <T>::clear (void)
{
	tail = 0;
}
