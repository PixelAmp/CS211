//INSTRUCTION
//Look for ** to complete this program
//The output should match my hw1stackDemo.out

//=========================================================
//HW#: HW1P1 stack
//Your name: Raul Perez
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "stack.cpp"

//Purpose of the program: to evaluate post-fix expressions
//Algorithm: **
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  int answer = 0; //user can coose to run multiple times
  bool again = true; //flag to reapeat again or not
  bool work = true; // if the program throws an error

  while (again == true)
    {
      work = true;
      cout << "Enter a postfix expression: " ;
      cin >> expression;

      postfixstack.clearIt(); //clears the stack in case it needs to be used again and was left with elements still in it
      int i = 0;  // character position within expression
      char item;  // one char out of the expression
      int intItem = 0; //holds char that was turned into an int
      int result = 0; //result of the program is held here

      int box1;  // receive things from pop
      int box2;  // receive things from pop

      while (expression[i] != '\0')
	{
	  try
	    {
	      item = expression[i];  // current char
	      intItem = item - 48; //turns character item into an int

	      //2.  if it is an operand (number),
	      //    push it (you might get Overflow exception)

	      if ((intItem >=0) && (intItem < 10)) //checks to see if the number is within the range of the calculator
		{
		  postfixstack.push(intItem); //pushes the element into the stack
		}


	      //3.  else if it is an operator,
	      //    pop the two operands (you might get Underflow exception), and
	      //	apply the operator to the two operands, and push the result.
	      else if ( (item == '+') || (item == '-') || (item == '*'))
		{
		  postfixstack.pop(box1);
		  postfixstack.pop(box2);
		  //cases for different operators follow:

		  if (item == '-') // result = box2-box1;
		    {

		      result = box2 - box1;
		      //cout << "sub " << box2 << " from " << box1 << " into " << result << endl;
		    }

		  else if (item == '+') //result = box2+box1;
		    {
		      result = box2 + box1;
		      //cout << "add " << box2 << " and " << box1 << " into " << result << endl;
		    }

		  else if (item == '*') // result = box2-box1;
		    {
		      result = box2 * box1;
		      //cout << "mult " << box2 << " and " << box1 << " into " << result << endl;
		    }

		  postfixstack.push(result); //pushes the new result into the stack


		}
	      else throw "invalid item";
	    } // this closes try
	  //at this point the program is done or an error occured

	  // Catch exceptions and report problems and quit the program now.
	  // Error messages describe what is wrong with the expression.
	  catch (stack::Overflow)
	    {
	      cout << "Too many numbers in the input" << endl;
	      work = false;
	      break; //stops the loop to avoid repeating the same error code multiple times
	    }
	  catch (stack::Underflow) // for too few operands
	    {
	      cout << "Not enough numbers for the amount of signs entered" << endl;
	      work = false; //stops the loop to avoid repeating the same error code multiple times
	      break;
	    }
	  catch (char const* errorcode) // for invalid item
	    {
	      cout << "A part of your response could not be read" << endl;
	      work = false; //stops the loop to avoid repeating the same error code multiple times
	      break;
	    }
	  // go back to the loop after incrementing i so the program can continue to run

	  i++;
	}// end of while


      if (work) //skips this part if an error was thrown
      {
      // After the loop successfully completes:
      // The result will be at the top of the stack. Pop it and show it.

      postfixstack.pop(result); //gets the result element

      if(postfixstack.isEmpty())
	{
	    cout << endl; //makes space
	  cout << "The result of what you entered is " << result << "!" << endl;
	}

      else
	{
	  cout << "Not enough signs for the amount of numbers" << endl;
	  //postfixstack.displayAll();
	  //cout << "is still in the stack " << endl;
	}
      // If anything is left on the stack, an incomplete expression was found.
      // Inform the user.

      }
      cout << endl; //makes space
      cout << "Enter 0 to do another evaluation" << endl;
      cin >> answer;

      if (answer != 0)
	{
	  again = false;
	}

      cin.clear(); // this is here so that it can loop, without it it only asks once for some reason
      cin.ignore();
    }

  cout << "Thank you for using my program!" << endl;

}// end of the program
