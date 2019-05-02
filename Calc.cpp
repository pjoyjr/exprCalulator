/* Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */

#include "Calc.h"

Calc::Calc(void)
{
}

Calc::~Calc(void)
{
}

bool Calc::calculate(const std::string & infix, int & result)
{
	bool success = infix_to_postfix(infix);
	if (success)
		success = evaluate_post(result);
	return success;
}

bool Calc::isOperator(const std::string & infix)
{
    if(infix == "+" || infix == "-" || infix == "/" || infix == "*" || infix == "%" || infix == "(" || infix == ")")
        return true;
    return false;
}

bool Calc::isOperand(const std::string & infix)
{
    if(!isOperator(infix))
        return true;
    return false;
}

// COMMENT: You should implement the precedence function on
// the command object since it is better place there. Otherwise,
// it is hard to add new commands without having to change the
// underlying algorithm. Also, you are using if-else statements
// as opposed to inheritance and polymorphism, which is a code
// smell.

// implemented the precedence function on command objects elimating the if-else 
// statements and using inheritance and polymorphism DONE



Expr_Command * Calc::getCommand(std::string command)
{
	Expr_Command * cmd = 0;
	if(command == "+")
	{
		cmd = this->factory.create_add_command();
	}
	else if(command == "-")
	{
		cmd = this->factory.create_subtract_command();
	}			
	else if(command == "*")
	{
		cmd = this->factory.create_multiply_command();
	}
	else if(command == "/")
	{
		cmd = this->factory.create_divide_command();
	}
	else if(command == "%")
	{
		cmd = this->factory.create_mod_command();
	}
	return cmd;
}

bool Calc::infix_to_postfix(const std::string & infix)
{
	Stack<std::string> st;
	int lastToken = -1; //used for testing valid expressions
    Expr_Command * cmd = 0;
	
	// Vector of string to save tokens 
    std::vector <std::string> tokens;  
    std::stringstream check1(infix); 
    std::string intermediate;  
    while(getline(check1, intermediate, ' ')) 
    { 
        tokens.push_back(intermediate); 
    } 
    
	//infix to postfix algorithm
    for(int i = 0; i < tokens.size(); i++) 
    {
		//if token is a number
		if (isOperand(tokens[i]))
		{
			//make sure last token isnt a number.
			if (lastToken == 1)
				return false;
			lastToken = 1;
			int number = std::stoi(tokens[i]);
			cmd = this->factory.create_num_command(number);
			this->postfix.enqueue(cmd);
		} 	
		else if(isOperator(tokens[i]) && tokens[i] != "(" && tokens[i] != ")")
		{
			//make sure last token isnt a operator.
			if (lastToken == 0)
				return false;
			lastToken = 0;
			
			//while stack isnt empty, stack top d.n.e. ( and token has lower priority then top of stack
			while(!st.is_empty() && (st.top() != "(") && (getCommand(tokens[i])->getPriority() <= getCommand(st.top())->getPriority()) )
			{
				cmd = getCommand(st.top());
				this->postfix.enqueue(cmd);
				st.pop();
			}
			st.push(tokens[i]);
		}
		else if(tokens[i] == "(")
		{
			st.push(tokens[i]);
		}
		else if(tokens[i] == ")")
		{
			//pop stack until find (
			while(!st.is_empty() && (st.top() != "("))
			{
				cmd = getCommand(st.top());
				this->postfix.enqueue(cmd);
				st.pop();
			}
			if(!st.is_empty())
				st.pop();
			else
				return false;
		}
		else
			return false;
	}
	while(!st.is_empty())
	{
		if(st.top() != "(" && st.top() != ")")
		{
			cmd = getCommand(st.top());
			this->postfix.enqueue(cmd);
		}
		st.pop();
	}
	return true;
}

bool Calc::evaluate_post(int & result)
{
	Stack <int> stack;
	while(!this->postfix.is_empty())
	{
		Expr_Command * cmd = this->postfix.dequeue();
		if (!cmd->execute(stack))
			return false;
		delete cmd;
	}
	result = stack.top();
	stack.pop();
	return true;
}