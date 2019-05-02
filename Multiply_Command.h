/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#ifndef MULTIPLY_COMMAND_H
#define MULTIPLY_COMMAND_H

#include "Binary_Op_Command.h"

class Multiply_Command : public Binary_Op_Command
{
public:
	Multiply_Command(void);
	~Multiply_Command(void);
	int getPriority();
	int evaluate(int n1, int n2) const;
};

#endif