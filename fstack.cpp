// Nikolas Lennon
// Copyright 2017

#include <iostream>
#include <string>
#include "tstack.h"

void Display();

template <typename Stack>
void CopyTest(Stack stack);

template <typename Stack>
void AssignTest(const Stack& stack);


//choose one of these for the stack API
typedef int ElementType;
//typedef char ElementType;

const size_t maxSize = 100;

typedef fsu::Stack<ElementType, maxSize> StackType;

int main() {
	
	//choose one of these fills for the type of "typdef" chosen above
	//ElementType fill = "*"; //char fill
	ElementType fill = 0; //int fill

	char selection;
	StackType stack(fill, 100);
	ElementType Tval;
	bool displayPrompt = true;


	std::cout << "This is a Stack " << "< " << "int" << " >" << " test program\n";
	Display();

	while (displayPrompt) {
		std::cout << "Enter [command][argument] ('M' for menu, 'Q' to quit): ";
		std::cin >> selection;

		switch (selection) {
			case 'Q': case 'q': case 'X': case 'x':  
				std::cout << "\nHave a nice day." << std::endl;
				displayPrompt = false;
				break;
			case '+': case '1':
				std::cin >> Tval;
				stack.Push(Tval);
				break;
			case 'D': case 'd':
				std::cout << "Stack contents: ";
				stack.Display(std::cout);
				std::cout << "\n";
				break;
			case 'S': case 's':
				std::cout << "Stack size = " << stack.Size() << std::endl;
				break;
			case '-': case '2':
				if (stack.Size() == 0) {
					std::cout << "** Stack error: Pop() called on an Empty Stack\n";
				}
				else {
					stack.Pop();
				}
				break;
			case 'C': case 'c':
				stack.Clear();
				break;
			case 'T': case 't':
				if (stack.Size() != 0) {
					std::cout << "Top of Stack: " << stack.Top() << "\n";
				}
				else {
					std::cout << "** Stack error: Top() called on an Empty Stack\n";
				}
				break;
			case 'M': case 'm':
				Display();
				break;
			case 'E': case 'e':
				if (stack.Empty() == true) {
					std::cout << "Stack is empty\n";
				}
				else
					std::cout << "Stack is not empty\n";
				break;
			case 'O': case 'o':
				char ofc;
				std::cin >> ofc;
				if (ofc == '0')               ofc = '\0';
				else if (ofc == 'b' || ofc == 'B') ofc = ' ';
				else if (ofc == 't' || ofc == 'T') ofc = '\t';
				else if (ofc == 'n' || ofc == 'N') ofc = '\n';
				else
				{
					std::cout << " ** bad ofc: only 0, b|B, t|T, n|N accepted\n";
					break;
				}
				stack.SetOFC(ofc);
				break;
			case '>':
				stack.SetDIR(-1);
				break;
			case '<':
				stack.SetDIR(1);
				break;
			case '=':
				CopyTest(stack);
				AssignTest(stack);
				break;
			case 'U': case 'u':
				stack.Dump(std::cout);
				break;
			default: 
				std::cout << "\n** Unrecognized command -- please try again.\n";
				break;
		}
	}
}

void Display() {
	std::cout << "Push(Tval)  .............  " << "+ tval or 1 tval\n";
	std::cout << "Pop()  ..................  " << "- or 2\n";
	std::cout << "Clear()  ................  " << "C\n";
	std::cout << "Top()  ..................  " << "T\n";
	std::cout << "Empty()  ................  " << "E\n";
	std::cout << "Size()  .................  " << "S\n";
	std::cout << "Copy tests  .............  " << "=\n";
	std::cout << "Display()  ..............  " << "D\n";
	std::cout << "SetOFC(ofc)  ............  " << "O 0|b|t|n\n";
	std::cout << "SetDIR(+1)  .............  " << "< (horizontal -->)\n";
	std::cout << "SetDIR(-1)  .............  " << "> (vertical   ^  )\n";
	std::cout << "Dump()  .................  " << "U\n";
	std::cout << "Display this menu  ......  " << "M\n";
}

template<typename Stack>
void CopyTest(Stack stack)
{
	if (stack.Size() > 0) {
		std::cout << "Copy Test:\n";
		std::cout << "Copied object       size: "
			<< stack.Size() << "\n"
			<< "                contents:  ";

		stack.Display(std::cout);
		std::cout << "\n";
	}
	else {
		std::cout << "Copy Test:\n";
		std::cout << "Copied object       size: "
			<< stack.Size() << "\n"
			<< "                contents:  ";

		stack.Display(std::cout);
		std::cout << "\n";
	}
}

template<typename Stack>
void AssignTest(const Stack & stack)
{
	StackType s1;

	s1 = stack;

	if (stack.Size() > 0) {
		std::cout << "AssignTest:\n"
			<< "Original object     size: "
			<< s1.Size() << "\n"
			<< "                contents:  ";
		s1.Display(std::cout);
		std::cout << "\n";

		std::cout << "Assignee object     size: "
			<< stack.Size() << "\n"
			<< "                contents:  ";
		stack.Display(std::cout);
		std::cout << "\n";
		std::cout << "ConstTest: OK" << std::endl;

	}
	else {
		std::cout << "AssignTest:\n"
			<< "Original object     size: "
			<< s1.Size() << "\n"
			<< "                contents:  ";
		s1.Display(std::cout);
		std::cout << "\n";

		std::cout << "Assignee object     size: "
			<< stack.Size() << "\n"
			<< "                contents:  ";
		stack.Display(std::cout);
		std::cout << "\n";
		std::cout << "ConstTest: inactive on empty stack" << std::endl;
	}
}
