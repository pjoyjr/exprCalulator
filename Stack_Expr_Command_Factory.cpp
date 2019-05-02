/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#include "Stack_Expr_Command_Factory.h"
#include "Expr_Command_Factory.h"
#include "Num_Command.h"
#include "Add_Command.h"
#include "Divide_Command.h"
#include "Mod_Command.h"
#include "Multiply_Command.h"
#include "Subtract_Command.h"

//Constructor
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory()
{
}

//Destructor
Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory()
{
}

//Command methods
Add_Command * Stack_Expr_Command_Factory::create_add_command(void)
{
	return new Add_Command();
}

Divide_Command * Stack_Expr_Command_Factory::create_divide_command(void)
{
	return new Divide_Command();
}

Mod_Command * Stack_Expr_Command_Factory::create_mod_command(void)
{
	return new Mod_Command();
}

Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command(void)
{
	return new Multiply_Command();
}

Num_Command * Stack_Expr_Command_Factory::create_num_command(int num)
{
	return new Num_Command(num);
}

Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command(void)
{
	return new Subtract_Command();	
}