//C++ Tutorials --------------------------------

#include<iostream>
using namespace std;
//using w3 school (online website) to review and learn about the c++ coding language
int main(){
	cout << "Hello World!";
	return 0;
}

int numbers(){
	cout << 3 + 3;
	return 0;
}

// to add a new line of words in an output use \n 
int twolines(){
	cout << "Hello World!" << "\n";
	cout << "I am learning C++";
	return 0;
}
//adding two \n will create a black line in the output 
int blanklines(){
	cout << "Hello World!" << "\n\n";
	cout << "I am learning C++";
	return 0;
}

//another way to insert a line is to use endl 
int endl(){
	cout << "Hello  World!" << endl;
	cout << "I am learning C++";
	return 0;
}

//VARIABLES -----------------------------------------
// int - stores integers (whole numbers)
// double - stores floating point numbers, with deimals 
// char - stores singel characters 
// string - stores text such as "hello world" - string values are surrounded by double quotes
// bool - stores values with two states: true or false

//syntax - type variableName = value;

int num(){
        int myNum = 15;
	cout << myNum;
	return 0;
}

int add(){
	int x = 5;
        int y = 6; 
	int sum = x + y; 
 	cout << sum;

 	return 0;
} 

// constants - const ; it will keep the number constant and the variable will not be able to change
int constant(){
	const int myNum = 15 ; 
	cout << myNum;
	return 0;
}

// example of calculating the area of a rectangle - multiplying the length and width 
void rectangle(){
	int length = 4;
	int width = 6;
	int area = length * width;// multiplying the two defined variables

	//printing the variables 
	cout<< "Length is: " << length << "\n";
	cout<< "Width is: " << width << "\n";
	cout << "Area of the rectangle is: " << area << "\n";
}
// with int - need to include return 0; at the end. With void no need to include anything except } after cout<<...;

//User input cout - is used to output (print) values. cin - is a predifined variable that reads data from the keyboard with the extraction operator (>>).

void inputs(){
	int x;
	cout << "Type a number: ";  
	cin >> x;
	cout << "Your number is: " << x;
}

// calculator example
void calc(){
	int x,y;
	int sum;
	cout << "type a number: ";
	cin >> x;
	cout << "tyoe another number: ";
	cin >> y;
	sum = x + y;
	cout << "sum is: " << sum;
}

// Data type 
void types(){
	//stating the variables and their values
	int myNumint = 1000;
	float myNumfloat = 5.75;
	double myNumdouble = 19.99; // double has more decimal precision ~ 15 compared to float
	// printing the values 
	cout << "Int value is: " << myNumint << endl;
	cout << "Float value is: " << myNumfloat << endl;
	cout << "Double value is: " << myNumdouble << endl;
}
// Boolean data types - true or false values. true =1 and false =0	
void boolean(){
	bool isCodingFun = true;
	bool isFishTasty = false;
	cout << isCodingFun << endl;
	cout << isFishTasty << endl;
}
//Character types - single characters. Must be surrounded by single quotes: 'A' or 'c'
void grade(){
	char myGrade = 'B';
	cout << "my grade is: " << myGrade << endl;
}
//String types - string type is used to store a sequence of characters (text) - surrounded by double quotes

void characters(){
	string greeting = "Good morning, Bonjour, Guten Morgen, Buen dia ";
	cout << greeting << endl;
}
// Auto - the auto keyword automatically detects the type of a variable based on the value you assign to it.o

void automatic(){
	auto myNum =5;
	auto myFloatNum = 5.88;
	auto mydoubleNum = 9.98;
	auto myLetter = 'D';
	auto myBoolean = true;
	auto myString = string("Hello");
}

// example of multiple summation
void sum(){
	int x = 100 + 50;
	int sum1 = x + 250;
	int sum2 = sum1 + sum1; 
	int sum3 = sum2 - x; 
	cout << "sum3 is equal to: " << sum3 << endl;
}
//Arithmetic Operators
// + addition
// - subtraction 
// * multiplication
// / division
// % modulus - returns the divion remainder x%y
// ++ increment - increases the value of a variable by 1
// -- decrement - decreases the value of a variable by 1

//Assignment Operators 
// =   equal 
// +=  same as x = x + 3 - write it as x += 3
// -=  same as x = x - 3 
// *=  same as x = x * 3
// /=  same as x = x / 3
// %=  same as x = x % 3 

// Comparison Operators
// == equal to
// != not equal 
// > greater than 
// < less than 
// >= greatrer than or equal to 
// <= less than or equal to 

// Logic Operators - you can test true (1) or false (0) values with logic operator 
// && logic and - returns true if both statements are true ex: x < 5 && x < 10
// || loical or - returns true if one of the statemtns is true ex: x< 5 || x< 4
// ! logical not - reverse the result, returns false if the result is true ex: !(x < 5 && x < 10)

// Boolean expression
void greaterthan(){
	int x = 10;
	int y = 9; 
	cout << ( x > y) << endl;
}

// voting age example 
void vote(){
	int myAge = 20; 
	int votingAge = 18;
	if ( myAge >= votingAge) { 
		cout << "Old enough to vote!" << endl; 
	}
	else { 
		cout << "Not old enough to vote. "<< endl;
	cout << (myAge >= votingAge) << endl;
	}
}
// Condition statements 
// if - specify a block of code to be executed, if a specified condition is true 
// else - specify a block of code to be executed, if the same condition is false 
// else if -  to specify a new condition to test, if the first condition is false
// switch - to specify many alternative blocks of code to be executed 

void time(){
	int time = 20; 
	if (time < 18){
		cout << "Good day. " << endl;
	}
	else { 
		cout << "Good evening. " ; 
	}
}

// While loops
// loops can execute a block of code as long as a specified condition is reached. 
// the while loop loops through a block of code as long as a specified condition is true.
void whileloop(){
	int i = 0; 
	while (i < 5){
		cout << i << "\n";
		i ++;
	}
}

void countdwn(){
	int countdown = 3;
	while ( countdown > 0) {
		cout << countdown << "\n";
		countdown--;
	}
	cout << "Happy New Year!\n"; 
}
// do/while loop is a variant of the while loop. this loop will execue the code block once before checking if the condition is true. then it will repeat the loop as long as the condition is true. 
void examp(){
	int i =0;
	do {
		cout << i << "\n";
		i++;
	}
	while ( i < 5);
}

//example where the statement is false from the start 
void falsestat(){
	int i = 10;
	do {
		cout << " i is " << i << "\n";
		i++; 
	} 
	while (i < 5);
}
// user input example 
void input(){
	int number; 
		do { 
			cout << "Enter a positive number: ";
			cin >> number; 
		} 
	while ( number > 0);
} // the loop stops when a negative number or zero is entered

// example to reverse numbers
void reverse(){
	int numbers = 123456;
	int revNumbers = 0; 
	while ( numbers) {
		revNumbers = revNumbers * 10 + numbers % 10;
		numbers /=10;
	}
	cout << "reversed numbers: " << revNumbers << endl;
}

// For Loops - when you know how many times you want to loop through a block of code, use the for loop instead of the while loop. 
// syntax : for (statement 1; statemetn 2; statement 3;) { 
// } 
// statement 1 is executed (one time) before the execution of the code block 
// statement 2 defines the condition for executing the code block 
// statement 3 is executed (every time) after the code block has been excuted

void print(){
	for ( int i = 0; i < 5; i++){
		cout << i << endl;
	}
}

void printEven(){ // prints even numbers from 0 to 10 
	for ( int j = 0; j <= 10; j = j + 2){
		cout << j << endl; 
	}
}

void sumNum(){
	int sum = 0; 
	for ( int i =1; i <= 5; i++){
		sum = sum + i;
	}
	cout << "sum is : " << sum << endl; 
}

void countdown(){
	for (int i = 5; i > 0; i--){
		cout<< i << endl;
	}
}
//Nested loop - a loop inside a loop - the inner loop will be executed one time for each iteration of the outer loop 
 void nested(){
	 for (int i = 1; i <= 2; i++){
		 cout << "Outer : " << i << endl;
		 
		 for (int j = 1; j <= 3; j++) {
			 cout << "Inner : "  << j << endl;
		 }
	 }
 }
void multiplication(){
	for ( int i =1; i <=4; i++) {
		for (int j = 1; j <= 4; j++){
			cout << i * j << " " ;
		}
		cout << endl;
	}
}

// Foreach loop - known as ranged based for loop -- which is used to loop through elements in an array 
// Syntax: for ( type variableName : arrayName){
// ...}

void foreach(){
	int myNumbers[5] = { 10, 20, 30, 40, 50}; 
	for ( int i : myNumbers) { 
		cout << i << endl;
	}
}

void multiTable(){
	int number = 2;
	int i; 
	for ( i =1; i <= 10; i++){
		cout << number << " x " << i << " = " << number * i << endl;
	}
}

// Arrays - are used to store multiple values in a single variable, instead of declaring separate variables for each value - square brackets and specify the number of elements it should store 
void car(){
	string cars[4] = { "volvo", "BMW", "Ford", "Mazda"};
	cout << cars[0] << endl;
} // [0] indicated the first element in the array and prints volvo 

// Loop through an array 
void cars2(){
	string cars[5] = {"volvo", "BMW", "ford", "Mazda", "Tesla"};
	for ( int i =0; i < 5; i++){
		cout << cars[i] << endl;
	}
}
void arrayForEach(){
	int myNumbers[5] = { 10, 20, 30, 40, 50};
	for (int i : myNumbers){
		cout << i << endl;
	}
}

//to find out how many elements an array has 
void arrayelement(){
	int myNumbers[5] ={ 10, 20, 30, 40 ,50}; 
	int getArrayLength = sizeof(myNumbers) / sizeof(myNumbers[0]);
	cout << getArrayLength << endl;
}

// calculation of the average of different ages using an array
void sortAges(){
	int ages[8] = { 20, 22, 24, 35, 43, 28, 59, 77} ;
	float avg, sum = 0;
	int i;

	int length = sizeof(ages) / sizeof(ages[0]);
	
	for (int age : ages) {
		sum += age;
	}
	
	avg = sum/ length; 

	cout << "the average age is : " << avg << endl;

	int lowestAge = ages[0];

	for ( int age : ages) { 
		if (lowestAge > age){
			lowestAge = age;
		}
	}
	cout << "the lowest age is: " << lowestAge << endl;

	int highestAge = ages[0];
	for (int age : ages){ 
		if ( highestAge < age){ 
			highestAge = age;
		}
	}
	cout << "the highet age is: " << highestAge << endl;
}

// Multi dimensional arrays
// to declare a multi-dimensional array, define the variable type, specify the name of the array followed by square brackets whcih specify how many elements the main array has, followd by another set of square brackets which indicates how many elements the sub-arrays have: string letters[2][4];

void multiDimArray(){
	string letters[2][4] = { 
		{ "A", "B", "C", "D"},
		{ "E", "F", "G", "H"}
	};
	cout << letters[0][2] << endl;
}

void battleships(){
	bool ships[4][4]={
		{0, 1, 0, 1 },
		{0, 0, 0, 0 },
		{0, 0, 1, 0 },
		{1, 0, 0, 0 }
	};
	int hits = 0; 
	int numberOfTurns = 0;

	while ( hits < 4 ) {
		int row, column;
// asking the player to choose coordinates:
		cout << "Selecting Coordinates" << endl;
		cout << "Choose a row number between 0 and 3: ";
		cin >> row;

		cout << "Choose a column number betweeen 0 and 3: ";
		cin >> column;
// removing the ship if a player hits it: 
		if (ships[row][column]) {
			ships[row][column] = 0;
			hits ++; 
			cout << "Hit! " << (4-hits) << " left.\n\n";
		}
		else {
			cout << "Miss\n\n";
		}
		
// annoncing how many turns the player has taken 
		numberOfTurns++;
	}
	cout << "Victory!" << endl;
	cout << "You won in " << numberOfTurns << "turns" << endl;
}

//structures - also called structs are a way to group several related variables into one place, each variable is known as a member of the structure - a structure can contain many different data types; int, string, bool etc. 

void structure(){
	struct {
		int myNum;
		string myString;
	}
	myStructure;

	// assign values to members of myStructure
	myStructure.myNum = 1;
	myStructure.myString = "Hello World!";

	//print memebers of the structure 
	cout << myStructure.myNum << endl;
	cout << myStructure.myString << endl;
}
void multiStruct(){
	struct {
	       string brand;
	       string model;
	       int year;
	} 
	myCar1, myCar2;

	myCar1.brand = "BMW";
	myCar1.model = "X5";
	myCar1.year = 1999;

	myCar2.brand = "Ford";
	myCar2.model = "Mustang";
	myCar2.year = 1969;

	cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << endl;
	cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << endl;
}

// example 
void grades(){
	struct student{
		string name;
		int age;
		char grade;
	};
	student s1, s2, s3;

	s1.name = "Gen";
	s1.age = 20;
	s1.grade = 'A';

	s2.name = "Zoey";
	s2.age = 20;
	s2.grade = 'A';

	s3.name = "Sarah";
	s3.age = 21;
	s3.grade = 'A';

	cout << "Name: " << s1.name << endl;
	cout << "Age: " << s1.age << endl;
	cout << "Grade: " << s1.grade << "\n\n";

	cout << "Name: " << s2.name << endl;
	cout << "Age: " << s2.age << endl;
	cout << "Grade: " << s2.grade << "\n\n";

	cout << "Name: " << s3.name << endl;
	cout << "Age: " << s3.age << endl;
	cout << "Grade: " << s3.grade << "\n\n";

}


// References - a reference variable is an alias for an existing variable. It is created using the & operator

void ref(){
	string food = "Pizza";
	string &meal = food;

	cout << food << endl;
	cout << meal << endl; 
}

// Pointers - a variable that stores the memory adress of its value.  A pointer variable points to a data type (like int or string) of the same type, and is created with the * operator. The address of the variable you're working with is assigned to the pointer: 
void pointers(){
	string food = "Apples";
	string* ptr = &food;

	cout << food << endl;
	cout << &food << endl;

	cout << ptr << endl;

	// you can also uuse the * operator (the dereference operator) 
	cout << *ptr << endl;

	// you can also change the value of the pointer 
	*ptr = "Pears";
	
	// output of the new value of the pointer - pear
	cout << *ptr << endl;

	//output the new value of the food variable - pear
	cout << food << endl;
}

// C++ Functions ----------------------------------------------------------------------


// a function is a block of code which can only run when called 
// syntax - void myFunction(){
// ...
// }
//
// I've been running functions during most of the tutorials 
// syntax - void functionName( parameter1, parameter2, parameter3) {
// ...code...
// }
//

