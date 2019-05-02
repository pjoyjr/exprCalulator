/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#ifndef BINARY_OP_COMMAND_H
#define BINARY_OP_COMMAND_H

#include "Stack.h"
#include "Expr_Command.h"

class Binary_Op_Command : public Expr_Command
{
public:
	bool execute(Stack <int> & s);
	virtual int evaluate(int n1, int n2) const = 0;
};

#endif