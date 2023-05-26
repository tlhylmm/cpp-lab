// 1521 2021 1114 - Talha Yýlmam
// 1521 2020 1076 - Ahmet Kuddusi Albayrak

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm> // to remove spaces from string
#include <vector>
#include <cmath> //for getting power of a number
#include "Poly.h"
using namespace std;

//-------------------------------------------------
// Creates a polynomial from an expression.
// Returns a pointer to the first PolyNode in the list (head of the list)
//
// Expression will be of the following sort:
// Ex1: 2.3x^4 + 5x^3 - 2.64x - 4
// Ex2: -4.555x^10 - 45.44
// Ex3: x^6 + 2x^4 - x^3 - 6.3x + 4.223 
// Ex4: 34
// Ex5: -x+1
// Ex6: -3x^4    +   4x
// Ex7: -2x  - 5
//
PolyNode *CreatePoly(char *expr){	
	/* Plan Steps:
     *
     * -> Split the string into terms, get the coef and exp from each term
     * -> Put these values in a list, sort them by exponent
     * -> Create linked PolyNode list with these values
     * */

    /* The first part of the plan is to divide the string polynomial in two parts.
     * 
     * First part will check only the first term since it is the only term
     * that doesn't need to have a sign if it is positive (x rather than +x)
     * The first term has 2 possible formats:
     * 
     * 1- It may have a '+' or '-' sign, which resembles it's sign
     * 3- It may have no sign, which also means positive
     * 
     * Second part will check the rest of the terms. It will slice the string
     * while searching for + and - signs.
     * 
     * Both of these code's will put the sliced terms into a temporary vector
     * 
     * After filling the vector with term strings, we can start checking the 
     * each term to get the coefficient and exponent
     * There are 3 different formats for each term
     * 
     * 1- If it doesn't contain 'x' letter, then it is a constant term
     * 2- If it doesn't contain '^' symbol next to x, then it is a x^1 term
     * 3- If it contains '^' symbol, then it is a term with exponent > 1
     * 
     * Each formats have their own algorithm of finding the coefficient and
     * exponent, check the other explanation down below.
     * 
     * The second part of the plan is to check these 3 conditions seperately and
     * build polyNodes.
     * 
    */

    string poly(expr); // construct string from char pointer to operate easily
	if(poly == ""){return NULL;} // return null if argument is empty
	poly.erase(remove(poly.begin(), poly.end(), ' '), poly.end()); // remove space

    // convert all characters lowercase in case there is an "X" instead of "x"
    transform(poly.begin(), poly.end(), poly.begin(), ::tolower);

	// Reading only the first term:
	int i = 0;
	vector<string> myVect;
	string temp = ""; // will hold the terms as a string

    // Checking the sign of the first term:
    if(poly[0] == '+' || poly[0] == '-'){ //First term is positive
        temp += poly[0]; // add the sign if it has any
        i++; //pass the sign and move to the next index
    }
    else { // First term is positive (doesn't have a sign)
        temp += '+'; // add the + sign manually since it is not in the term 
    }

    // get the first term:
    while(!(poly[i] == '+' || poly[i] == '-')){
        if (i == poly.length()) { break; }
        temp += poly[i];
        i++;
    }
    i++; // move the index after the sign (start of the second terms coeff.)
    myVect.push_back(temp); // add the first term to the vector

	// Reading rest of the terms that definitely contains + or -:
	bool reachedEnd = false;
	while(i < poly.length()){
        temp = ""; //empty the temporary string term variable
        while(!(poly[i] == '+' || poly[i] == '-')){
            if(i == poly.length()){break;} //exit when reached the end of string
            if(poly[i - 1] == '+' || poly[i - 1] == '-'){
                // If we are at the beginning of the coefficient, get the sign:
                temp += poly[i-1];
            }
            temp += poly[i];
            i++;
        }
        myVect.push_back(temp);
        i++;
    }

    /* Iterate through vector items, find coefficient and exponent.
     * As it's told above, there are 3 formats of terms and each of them has
     * it's own way of finding the properties:
     *
     * 1- If it doesn't contain the letter "x"
     * -> It means that it is a constant term, so we directly set the coefficient
     *    attribute to 0, so is the exponent.
     * 
     * 2- If it contains "x" but doesn't contain "^" symbol
     * -> It means that it is a linear term, so we set the exponent to 1, then
     *    we get the left part of the x as coefficient
     * 
     * 3- If it contains "^" symbol
     * -> It means that it is a term with exponent > 1, so we get the right part
     *    of the ^ sign as exponent, then we get the left part of the x as 
     *    coefficient
     * 
     * Switch case will be used in this seperation!!
     * 
     * Note that if there is no left part of the x, or the left part only 
     * contains + symbol, the coefficient should be set as 1 
     */

    string term = ""; // will hold the each vector item
    string coefStr; // will hold the coefficient of the current term
    string expStr; // will hold the exponent of the current term
    int length; // will hold the length of the current term
    int format; // will be used in switch case
    bool containsX = false;
    bool containsSymbol = false; // ^ symbol
    int indexOfX; // will be used to navigate through left and right of X

    
    
    vector<PolyNode> tempVect; //will hold the coeffs and exps temporarily    
    PolyNode tempNode; //declare a temporary PolyNode
    tempNode.next = NULL; //this pointer won't be used right now
    
    for(vector<string>::iterator it = myVect.begin(); it != myVect.end(); it++){
        //reset the values of temporary PolyNode
        tempNode.coef = 0;        
        tempNode.exp = 0;        
        //reset the values:
        term = *it;
        indexOfX = 0;
        coefStr = "";
        expStr = "";
        containsX = false;
        containsSymbol = false;
        length = term.length();
        
        //check if it contains X or ^:
        for(int i = 0; i < length; i++){
            if(term[i] == 'x'){
                containsX = true;
                indexOfX = i;
            }
            if(term[i] == '^'){
                containsSymbol = true;
            }
        }

        //set the cases:
        if(containsX == false && containsSymbol == false){format = 1;}
        else if(containsX == true && containsSymbol == false){format = 2;}
        else if(containsX == true && containsSymbol == true){format = 3;}

        //get the coefficient and exponent depending on the type of format:
        switch (format) {
            case 1: // constant term
                tempNode.exp = 0;
                tempNode.coef = stod(term);
                break;
            
            case 2: // linear term
                tempNode.exp = 1;

                if(indexOfX == 0){tempNode.coef = 1;}
                else if(term[indexOfX - 1] == '+'){tempNode.coef = 1;}
                else if(term[indexOfX - 1] == '-'){tempNode.coef = -1;}
                else{
                    for(int i = (indexOfX - 1); i >= 0; i--){
                        coefStr += term[i];
                    }
                    reverse(coefStr.begin(), coefStr.end()); //reverse string
                    tempNode.coef = stod(coefStr);
                }
                break;
            
            case 3: // term with exponent > 1
                //get the exponent from the right of the ^ symbol:
                for(int i = (indexOfX + 2); i < length; i++){
                    expStr += term[i];
                }
                tempNode.exp = stoi(expStr);

                //get the coefficient from the right of the x:
                if(indexOfX == 0){tempNode.coef = 1;}
                else if(term[indexOfX - 1] == '+'){tempNode.coef = 1;}
                else if(term[indexOfX - 1] == '-'){tempNode.coef = -1;}
                else{
                    for(int i = (indexOfX - 1); i >= 0; i--){
                        coefStr += term[i];
                    }
                    reverse(coefStr.begin(), coefStr.end()); //reverse string
                    tempNode.coef = stod(coefStr);
                }
                break;
        
        }
        tempVect.push_back(tempNode); // add the node to temporary vector        
    }

    /* After getting coefficientsand exponents and filling a temporary array,
     * We need to check if there are any exponents that doesn't fit the definition
     * of polynomial function (being a negative or non-integer number)
     */
    PolyNode checkNode;
    int checkExp;
    for (auto itr = tempVect.begin(); itr != tempVect.end(); itr++) {
        checkNode = *itr;
        checkExp = checkNode.exp;
        if (!(checkExp >= 0)) {
            cout << "Error: Exponent doesn't fit the polynomial definition." << endl;
            system("pause");
            exit(0);
        }    
    }

    /* After filling the array with PolyNode objects, sorting them according to
     * exponent is needed, since sorting an inbuilt vector library is much 
     * easier than sorting a linkedlist, the sorting part will be done in here.
     * To sort a vector by object's attribute, a lambda std::sort expression
     * is used.
     */

    //sort the vector elements according to exponents
    //lambda expression to define sorting of exponents
    sort(tempVect.begin(), tempVect.end(), [](const PolyNode& bigger, const PolyNode& lower) {
      return bigger.exp > lower.exp;
    });

    // create linked PolyNode list
    int size = tempVect.size();

    // create first term
    PolyNode* head = new PolyNode();
    head->coef = tempVect[0].coef;
    head->exp = tempVect[0].exp;
    head->next = NULL; // default

    // keep creating nodes if terms > 1
    PolyNode* previous = head;
    if(size > 1){
        for (int i = 1; i < size; i++){
            PolyNode* newNode = new PolyNode();
            newNode->coef = tempVect[i].coef;
            newNode->exp = tempVect[i].exp;
            previous->next = newNode;
            previous = newNode;            
        }
        //set the last element's next as NULL
        previous->next = NULL;
    }

	return head;
} //end-CreatePoly

/// -------------------------------------------------
/// Walk over the poly nodes & delete them
///
void DeletePoly(PolyNode* poly) {
	PolyNode* current = poly;
	PolyNode* temp = NULL;
	while(current != NULL){
		temp = current->next;
		delete current;
		current = temp;
	}
} // end-DeletePoly
	
//-------------------------------------------------
// Adds a node (coefficient, exponent) to poly. If there already 
// is a node with the same exponent, then you simply add the coefficient
// to the existing coefficient. If not, you add a new node to polynomial
// Returns a pointer to the possibly new head of the polynomial.
//
PolyNode* AddNode(PolyNode *head, double coef, int exp){
	/* Go through the list and compare the given exp with the term's exponents.
	 * There are 3 possibilites:
	 * 
	 * 1- Given exp is not in the list and it is bigger than all of them:
	 * -> It means that it is a new term and it will be added as the new head
	 * 
	 * 2- Given exp is not in the list and there is a bigger exponent in terms
	 * -> It means that it is a new term and it should be placed in the right spot
	 * 
	 * 3- Given exp is in the list
	 * -> It means that it is not a new term, only the correct coefficient should
	 *    be updated
	 */
	
	bool newHead = true;
	bool newTerm = true;
	PolyNode* current = head;
	int j = 0; // will hold the index of each list element
	int previousBiggerTerm;
	int matchingTerm;
	while(current != NULL){
		if(current->exp > exp){
			previousBiggerTerm = j;
			newHead = false;
		}
		if(current->exp == exp){
			matchingTerm = j;
			newHead = false;
			newTerm = false;
		}
		current = current->next;
		j++;
	}
	
	if(newTerm && newHead){ //new head term
		PolyNode* newNode = new PolyNode();
		newNode->coef = coef;
		newNode->exp = exp;
		newNode->next = head; //new head's next points to previous head element
		head = newNode; //set a new head
	}
	else if(newTerm && !newHead){ //new term but not a new head
		PolyNode* a = head;
		int m = 0;
		while(a != NULL){
			if(m == previousBiggerTerm){
				PolyNode* newNode = new PolyNode();
				newNode->coef = coef;
				newNode->exp = exp;
				//put newNode in between bigger term and lower term:
				newNode->next = a->next;
				a->next = newNode;
				break;
			}
			m++;
			a = a->next;
		}
	}
	else{ //not a new term, raise the coefficient
		PolyNode* a = head;
        PolyNode* prevNode = a; //will follow the "a" from behind
        PolyNode* prePrevNode = prevNode; // will follow the prePrevNode from behind
		int m = 0;
		while(a != NULL){
			if(m == matchingTerm){
				a->coef += coef;
			}
            prePrevNode = prevNode;
            prevNode = a;
			a = a->next;
            //remove node if coeff = 0;
            if (prevNode->coef == 0) {
                delete prevNode;
                // the element 2 indexes behind, now points the element after
                // the deleted one
                prePrevNode->next = a;
                if (m == 0) { // if the head term's coeff = 0
                    head = a; // set the second term as new head
                }            
            }
			m++;
		}

	}	
	return head;
} // end-AddNode

//-------------------------------------------------
// Adds two polynomials and returns a new polynomial that contains the result
// Computes: poly3 = poly1 + poly2 and returns poly3
//
PolyNode *Add(PolyNode *poly1, PolyNode *poly2){
	/* The plan is to create a empty list and fill it with poly1
	 * then add the poly2 using AddNode() function
	 */
	
	PolyNode* poly3 = new PolyNode();
	poly3->coef = 0;
	poly3->exp = 0;
	poly3->next = NULL;
	PolyNode* a = poly1;
	PolyNode* b = poly2;

	//fill the poly3 with poly1's terms
	while(a != NULL){
		poly3 = AddNode(poly3, a->coef, a->exp);
		a = a->next;
	}
	//add the terms of poly2
	while(b != NULL){
		poly3 = AddNode(poly3, b->coef, b->exp);
		b = b->next;
	}

	return poly3;
} //end-Add

//-------------------------------------------------
// Subtracts poly2 from poly1 and returns the resulting polynomial
// Computes: poly3 = poly1 - poly2 and returns poly3
//
PolyNode *Subtract(PolyNode *poly1, PolyNode *poly2){
	/* The plan is to create a empty list and fill it with poly1
	 * then multiply poly2's coefficients with -1 then add to the poly1
	 * using AddNode() function
	 */
	
	PolyNode* poly3 = new PolyNode();
	poly3->coef = 0;
	poly3->exp = 0;
	poly3->next = NULL;
	PolyNode* a = poly1;
	PolyNode* b = poly2;

	//fill the poly3 with poly1's terms
	while(a != NULL){
		poly3 = AddNode(poly3, a->coef, a->exp);
		a = a->next;
	}
	//add the poly2's term's additive inverses
	while(b != NULL){
		poly3 = AddNode(poly3, -1 * (b->coef), b->exp);
		b = b->next;
	}

	return poly3;
} //end-Substract

//-------------------------------------------------
// Multiplies poly1 and poly2 and returns the resulting polynomial
// Computes: poly3 = poly1 * poly2 and returns poly3
//
PolyNode *Multiply(PolyNode *poly1, PolyNode *poly2){
	/* The plan is to create a empty list and for the each term of poly1,
	 * add poly1's current term's coefficient multiplied by every coefficient 
	 * of poly2. Same for the exponents but addition instead of multiplication
	 */
	
	PolyNode* poly3 = new PolyNode();
	poly3->coef = 0;
	poly3->exp = 0;
	poly3->next = NULL;
	PolyNode* a = poly1;
	PolyNode* b = poly2;

	while(a != NULL){
		b = poly2; // return back to the head of the poly2 for each term of poly1
		while(b != NULL){
			poly3 = AddNode(poly3, a->coef * b->coef, a->exp + b->exp);
			b = b->next;
		}
		a = a->next;
	}

	return poly3;
} //end-Multiply

//-------------------------------------------------
// Evaluates the polynomial at a particular "x" value and returns the result
//
double Evaluate(PolyNode *poly, double x){
	double result = 0;
	PolyNode* current = poly;
	while(current != NULL){
		//increment the result by the evaluation of current term
		result += (current->coef) * pow(x, current->exp);
		current = current->next;
	}

	return result;
} //end-Evaluate

//-------------------------------------------------
// Computes the derivative of the polynomial and returns it
// Ex: poly(x) = 3x^4 - 2x + 1-->Derivative(poly) = 12x^3 - 2
//
PolyNode *Derivative(PolyNode *poly){
	/* The plan is to create an empty node then add the derived terms of 
	 * given poly. The constant term has a derivative of 0. So we pass the term
	 * with the exponent of 0
	 */

	PolyNode* derivedPoly = new PolyNode();
	derivedPoly->coef = 0;
	derivedPoly->exp = 0;
	derivedPoly->next = NULL;

	PolyNode* current = poly;
	while(current != NULL){
		if(current->exp != 0){
			derivedPoly = AddNode(derivedPoly, current->coef * current->exp, current->exp - 1);
		}
        current = current->next;
	}

	return derivedPoly;
} //end-Derivative

//-------------------------------------------------
// Plots the polynomial in the range [x1, x2].
// -39<=x1<x2<=39
// -12<=y<=12
// On the middle of the screen you gotta have x & y axis plotted
// During evaluation, if "y" value does not fit on the screen,
// then just skip it. Otherwise put a '*' char depicting the curve
//
void Plot(PolyNode* poly, int x1, int x2) {
	/* The plan is to create a coordinate system according to given x and y limits
     * Start the coordinate system from 39 to -39 and 12 to -12
     * index zero means the middle of the coordinate system so put a line
     * while iterating through indexes, if the given coordinate matches with
     * the evaluated y value, print *, print space otherwise.
     */    
    
	for (int y = 12; y >= -12; y--) {
		for (int x = -39; x <= 39; x++) {
			if (y == 0 && x == 0) {  // cross point of x and y
				cout << "+"; //print crossed lines
			}
            // print axis lines:
			else if (y == 0) { 
				cout << "-";
			}
			else if (x == 0) {
				cout << "|";
			}
            // print * at matched y coordinates:
			else if (y == (int)Evaluate(poly, x)) {
				cout << "*";
			}
            // print space otherwise
			else {
				cout << " "; //for empty dots
			}
		}
		cout << endl; //to the new line
	}
} //end-Plot
