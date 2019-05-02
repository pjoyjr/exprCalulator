// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

// get tail
template <typename T>
inline
size_t Queue <T>::getTail (void) const
{
	return this->tail;
}

// is_empty
template <typename T>
inline
bool Queue <T>::is_empty(void)
{
	if(this->getTail() == 0)
		return true;
	return false;
}