/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
 
#ifndef QUEUE_H
#define QUEUE_H


#include "Array.h"

// COMMENT You should use aggregation instead of inheritance since logically
// a queue is not an array. You are also violating LSP with this design.

template <typename T>
class Queue
{
public:
	typedef T type;
	/* @class empty_exception
	 *
	 * Exception thrown to indicate the stack is empty.
	 */
	class empty_exception : public std::exception
	{
	public:
		/// Default constructor.
		empty_exception(void)
		:std::exception()
		{

		}	
		/* Initializing constructor.
		 *
		 * @param[in]      msg         Error message.
		 */
		empty_exception(const char * msg)
		:std::exception(msg)
		{ 
		
		}
	};

	/// Default constructor.
	Queue (void);

	/* Copy constructor
	 *
	 * @param[in]     que         The source queue.
	 */
	Queue (const Queue & que);

	/// Destructor.
	~Queue (void);

	/* Assignment operation
	 *
	 * @param[in]       rhs      Right-hand side of equal sign
	 * @return          Reference to self
	 */
	const Queue & operator = (const Queue & rhs);
	
	/* After taking dequeueing, this method rearranges the array so the first element isnt missing,
	 * given there is an element to move into that first index and so on.
	 */
	void rearrange(void);
	
	/* Enqueue - adds the element to the end of the list
	 *
	 * @param[in]       <T>element
	 */
	void enqueue(T element);
		
	/* Dequeue - removes the element at the front of the list. If there are not elements in
	 * the queue, this method throws empty_exception, similar to stack 
	 */
	T dequeue(void);
	
	/* Retrieve the tail index of the queue. Tail is the index of
	 * the last element into the queue.
	 *
	 * @return          index of tail of queue
	 */
	size_t getTail (void) const;
	
	/* is_empty - test if the queue is empty. If the queue is empty, then this method returns true.
	 * else return false
	 */
	bool is_empty(void);
	
	
	///clear - removes all the elements in the queue	
	void clear(void);
private:
	Array<T> arr;
	size_t tail = 0; //define first empty space in array
};

#include "Queue.inl"
#include "Queue.cpp"

#endif
