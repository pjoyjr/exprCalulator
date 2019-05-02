/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#ifndef CALC_H
#define CALC_H

#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h> 
#include <string>
#include "Array_Base.h"
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Expr_Command.h"
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"

class Calc
{
public:
	class invalid_infix : public std::logic_error
	{
		public:
			explicit invalid_infix (const std::string& arg)
			:std::logic_error (arg)
			{
			}
	};

	// Default constructor
	Calc(void);

	// Destructor
	~Calc(void);

	bool calculate(const std::string & infix, int & result);
private:
	//helper methods
	bool isOperator(const std::string & infix);	
	bool isOperand(const std::string & infix);
	Expr_Command * getCommand(std::string command);
	
	//methods called in calculate
	bool infix_to_postfix(const std::string & infix);
	bool evaluate_post(int & result);

	Stack_Expr_Command_Factory factory;
	Queue <Expr_Command *> postfix;
};


#endif