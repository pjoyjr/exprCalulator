/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#ifndef SUBTRACT_COMMAND_H
#define SUBTRACT_COMMAND_H

#include "Binary_Op_Command.h"

class Subtract_Command : public Binary_Op_Command
{
public:
	Subtract_Command(void);
	~Subtract_Command(void);
	int getPriority();
	int evaluate(int n1, int n2) const;
};

#endif