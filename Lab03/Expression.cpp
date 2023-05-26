//1521 2021 1114 - Talha Yılmam
//1521 2020 1076 - Ahmet Kuddusi Albayrak

#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <algorithm> //to remove spaces
using namespace std;

/* Precedence:
 * 1- * /
 * 2- + -
 * 3- ( )
 */


///----------------------------------------------------------------------------------
/// Given an expression in infix-notation, converts it to a string in post-fix notation 
/// 
string Infix2Postfix(string &s) {
	//remove spaces from the string:
	s.erase(remove(s.begin(), s.end(), ' '), s.end());

	string result = "";
	stack<string> stack;
	int len = s.length();
	int i = 0;
	while(i < len){
		if(s[i] >= '0' && s[i] <= '9'){
			// there is a chance that a number can have more than 1 digit
			// so we need to scan until any one of the + - * / ( ) symbols found
			while(s[i] != '+' && s[i] != '-' &&
				  s[i] != '*' && s[i] != '/' && s[i] != '(' && s[i] != ')'){
				if(i >= len){break;} // break when end of the string reached
				result += s[i];
				i++;
			}
			i--;
			result += " "; // put a seperator space
		}
		else if(s[i] == '('){// "(", lowest priority
			stack.push("(");
		}
		else if(s[i] == ')'){ // ")"
			// output and pop until "(" found
			while(!stack.empty() && stack.top() != "("){	
				result += stack.top();
				result += " "; // put a seperator space
				stack.pop();
			}
			stack.pop(); //pop the "(" sign 
		}
		else if(s[i] == '*' || s[i] == '/'){ // "*" and "/"
			// output until lower precedence symbol found
			while((!stack.empty()) && (stack.top() != "+" && stack.top() != "-" &&
				  stack.top() != "(" && stack.top() != ")")){
					result += stack.top();
					result += " "; // put a seperator space
					stack.pop();
			}
			string store = "";
			store += s[i]; // convert char to string for pushing
			stack.push(store);
		}
		else if(s[i] == '+' || s[i] == '-'){ // "+" and "-"
			// output until lower precedence symbol found
			while(!stack.empty() && (stack.top() != "(" && stack.top() != ")")){
					result += stack.top();
					result += " "; // put a seperator space
					stack.pop();
			}
			string store = ""; // convert char to string for pushing
			store += s[i];
			stack.push(store); // push the symbol
		}
		i++;
	}

	// output the rest of the symbols in stack
	while( !(stack.empty()) ){
		result += stack.top();
		result += " "; // put a seperator space
		stack.pop();
	}
	return result;
} // end-Infix2Postfix

///----------------------------------------------------------------------------------
/// Given a string in post-fix notation, evaluates it and returns the result
/// 
int EvaluatePostfixExpression(string& s) {
	int result;
	int len = s.length();
	int i = 0;
	stack<double> stack;
	string temp;
	int tempNum;
	double n1, n2;

	while(i < len){
		// search for numbers:
		if(s[i] >= '0' && s[i] <= '9'){
			// if number has more than two digits get the next digits:
			while(s[i] != ' '){
				if(i >= len) {break;}
				temp += s[i];
				i++;
			}
			tempNum = stoi(temp);
			temp = ""; // empty the temp for getting next number
			stack.push(tempNum);
		}
		else if(s[i] == '*'){ // multiplication
			n1 = stack.top();
			stack.pop();
			n2 = stack.top();
			stack.pop();
			stack.push(n1 * n2);
		}
		else if(s[i] == '/'){ // division
			n1 = stack.top();
			stack.pop();
			n2 = stack.top();
			stack.pop();
			stack.push(n2 / n1);
		}
		else if(s[i] == '+'){ // addition
			n1 = stack.top();
			stack.pop();
			n2 = stack.top();
			stack.pop();
			stack.push(n1 + n2);
		}
		else if(s[i] == '-'){ // subtraction
			n1 = stack.top();
			stack.pop();
			n2 = stack.top();
			stack.pop();
			stack.push(n2 - n1);	
		}
		i++;
	}
    result = round(stack.top());
	return result;
} // end-EvaluatePostfixExpression