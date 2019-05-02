/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#include "Binary_Op_Command.h"

bool Binary_Op_Command::execute(Stack<int> & s)
{
	int n2 = s.top();
	s.pop();
	int n1 = s.top();
	s.pop();
	int result = this->evaluate(n1, n2);
	s.push(result);
	return true;
}