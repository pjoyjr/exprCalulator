/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#ifndef EXPR_COMMAND_H
#define EXPR_COMMAND_H

#include "Stack.h"

class Expr_Command
{
public:
	Expr_Command(void);
	virtual ~Expr_Command(void);
	virtual int getPriority() = 0;
	virtual bool execute (Stack <int> & stack) = 0;
};

#endif