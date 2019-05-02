/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

// top
template <typename T>
inline
T Stack <T>::top (void) const
{
	if(this->is_empty())
		throw empty_exception();
	return arr.get((this->getTail()-1));
}

// is_empty
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	if(this->getTail() == 0)
		return true;
	return false;
}

// size
template <typename T>
inline
size_t Stack <T>::getTail (void) const
{
	return this->tail;
}

