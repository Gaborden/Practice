#include <TMath.h>
//task 1: Write a C++ program to check whether a given number is a power of two or not. 
bool isPowerofTwo(int x) {
	double n;
	//using double instead of int because - 2^n = 15, n would be ~3.9 -> using int will approxiamte it to 4 thus giving a true value 
	n = log2(x);
	if (n == floor(n)){
		return true;
	} 
	// floor rounds your number to the nearest possible integer
	else { 
		return false;
	}
}

//task 2: Write a C++ program to reverse the digits of a given integer i.e sample input: 4 sample output: 4 and sample input:123 and sample output:321
#include <iostream>
int tsk2(int x){
	int res =0; 
	// create a loop to reverse the integer
	while (x != 0){
		int lst = x % 10; // collects the last digit of the number 
		x = x/ 10; // updates the number by removing the last digit 

		int swt = res * 10 + lst; //creates the reversed number 
		// swt = switched number
		
		if (swt /10 !=res) {
			return 0;
		}

		res =swt; // should change the number so that the original "x" value becomes the reversed "x" value
	}
	return res; //should give the reversed intger 

}

//task 3: Write a C++ program to calcualte x raised to the power of n(x^n)
#include <TMath.h>
double tsk3(double x, double n){ // defines the two parameters that are going to be inputed when running root. 
	double y = TMath::Power(x,n); // add the double -> this defines y 
	return y; // will give us a numerical value when running root 
}

//task 4: Write a C++ program to get the Excel column title that corresponds to a given column number (integer value). 

string tsk4(int num){
	if (num == 0){
		return "";//telling the program to not give a value when its zero -> returns an empty string
	}
	return tsk4((num-1)/26) + static_cast<char>((num-1) % 26 + 'A');//converts a number into a character
}

//task 5: Write a C++ program to get the column number (integer value) that corrsponds to a column title as it appears on the excel sheet. 

/*string tsk5(char let){
	if (let == 0){
		return "";
	}
	return tsk5((let-1)/26) + static_cast<char>((let-1) % // unsure what to do next, will work on it again later ---> tried making it like what I did/found for taks 6, now believe that the method will not work */
//----attempt 2----

/*int tsk5(string s){
	int result =0; 
	for (const auto& c : s){
		result *= 26;
		result += c - 'A' + 1;
	}
	return result; 
			}
int main(){
	cout<<tsk5(A)<<endl;
	return 0;
}*/
//attempt 3
using namespace std;
int tsk5(string s){
	int num = 0;
	for (const auto& c : s){
		num *= 26;
		num += c - 'A' + 1;
	}
	return num; 
			}
int main(void){
	string coltitle = "C";
	cout<<"column_title ="<< coltitle << ", Corresponding number = " << tsk5(coltitle) << endl;
}



//task 6: Write a C++ program to add repeatedly all digits of a given non-negative number until the result only has one digit. 
#include <iostream>
using namespace std; // this allows for the commands that require std:: to be included without the need to add it as a prefix for all of them 

int tsk6(int n){
	int sum = 0;
	while (n > 0 || sum > 9){ 
	// while loop will repeatedly execute a block of code as long as a specified condition is true - if the condition is initially false, the loop body will not be executed at all 
		if ( n == 0){ 
		n = sum;
		sum = 0;
		} // if n = 0 then it starts a new iteration 
		sum += n % 10; 
		n /=10;
	} 
	return sum;
}
//task 7: Write a C++ program to check if a given integer is a power of three or not. 

//attempt 1
/*string tsk7(int n){
	using namespace std;
	while (n % 3 ==0 ){ // while loop that will continue to execute as long as the conditions in the () hold true
// n % 3 -> modulus operator => n is divided by 3
// == 0 -> this verifies if the remainder is zero 
// this means that n divided by there 3 has no remains 
	n = n / 3;
}
	if (1 == n) { 
		return "true";
	}else {
		return "false";
}

}*/

//attempt 2

bool tsk7(int x) {
	double n;
	// using the main base code from question 1, replacing log2() with log3()
	n = std::log(x) / std::log(3);
	if (n == floor(n)){
		return true;
	} 
	// floor rounds your number to the nearest possible integer
	else { 
		return false;
	}
}



//task 8: Write a C++ program to calculate the product of two positive integers represented as strings. Return the result as a string.
// ex; sample input: sn1 = "12" sn2="5" sample output: 12X5 = 60

/*string multiplyStrings( string s1, string s2){

	int n1 = s1.size(), n2=s2.size();
	if (n1 == 0 || n2 == 0) // || means that if the left hand side of the expression is true, the combine result is true (the right hand side of the expression is never evaluated) 
		return "0";
	// to verify if the string are negative 
	int nn = 1, mm = 1; 
	if (s1[0] == '-') // == equal to 
		nn = -1;
	if (s2[0] =='-') 
		mm = -1;

	int isNeg == nn * mm;

	vector<int> result(n1 + n2, 0);// makes the vector in reverse order 

	int i1 = 0;

	int i2 = 0;

	for (int i = n1 -1; i > =0; i --) { // go from right to left by s1

		if (s1[i] == '-') continue; 
		int carry =0;
		int n1 = s1[i] - '0' ;
		i2 =0;
	
	for ( int j = n2 -1; j > 0; j --){ // go from right to left by s2
		if (s2[j] == '-') continue; 
		int n2 = s2[j] - '0';
		
		int sum = n1 * n2 + result [i1 + i2] + carry; // multiply and add the result to the exisiting result 
		carry = sum / 10; // carry for the next iteration

		result[i1 + i2] = sum % 10;
		i2++;
		}
	if (carry > 0) 
		result[i1 +i2] += carry;
	i1++;
	}

	// NOT FINISHED ----- To be continuted */

#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std; 

//a function to multiplu two numbers which are represented as strings 
string tsk8(string sn1, string sn2){
	const auto char_to_int = [](const char c) { return c -'0';};
	const auto int_to_char = [](const int i) { return i + '0';};

//trying to convert the sting representation of numbers into integer vectors in reverse order 
	vector<int>n1;
	transform(sn1.rbegin(), sn1.rend(), back_inserter(n1), char_to_int);
	vector<int>n2;
	transform(sn2.rbegin(), sn2.rend(), back_inserter(n2), char_to_int);
	
// creating a temporary vector to store the intermediate multiplication results 
	vector<int>temp(n1.size() + n2.size());

// need to now performe the multipication number digit by digit 
	for(int i = 0; i < n1.size(); ++i){ // a for loop which can be used to repeat a block of code multiple times 
		for(int j = 0; j < n2.size(); ++j){ // int j =0; is the initialization step - it declares an integer variable j and initializes it to zerp, this becomes the loop counter or index - j < n2.size(); this is the loop condition, ie the loop will continue as long as j is smaller than n2.size(). the loop will iterate once for each element in n2 - ++j is the increment step. after each iteration of the loop, j is incremented by 1. 
			temp[i + j] +=n1[i] *n2[j]; // this is multiplying the i-th digit of n1 with the j-th digit of n2. Add the result to temp[i + j], which accumulates the product at the correct digit position ( x += y -> x = x + y; this means that the current value of x is added to the value of y and the result is assigned back to x) 
			temp[i +j + 1] += temp[i + j] /10; // if temp[i + j] is > 9, take the carry (/10) and add it to the next higher position (i + j + 1)
			temp[i +j] %=10; // only keeps the last digit (% 10) at this position after accounting for the carry 
		}
	}
	string result;
	transform(find_if(temp.rbegin(), prev(temp.rend()),[](const int i) {return i != 0;}), temp.rend(), back_inserter(result), int_to_char);
	return result;
} // when calling the numbers because its a string make sure to include tsk8("12" , "5")


//task 9: Write a C++ program to find the missing number in a given array of integers taken from the sequence 0,1,2,3,...,n.
//Sample input: arr[10] ={10,9,4,6,3,2,5,7,1,0}
//Sample output: Missing number in the said array: 8 

int tsk9(int nums[], int arr_size){
	if (nullptr ==nums || arr_size == 0){ // nullptr == nums checks to see if the pointer nums is null - nullptr is a macro that represents a null pointer || is the logical OR operator -> the condition is true if either of the espresions on the left or the right is true. arr_size == 0 checks whether the array size is 0, which tells us that there would be nothing to process. 
		return 0;
	}
	int result = arr_size; // initializes the result as the size of the array. 

	// the following is to search for the missing number 
	for (int i = 0; i < arr_size; i++){
		result ^= i;// the expresion x^= is equivalent to x = x ^ y -> the ^ operator performs a bitwise XOR (exclusive OR) operation on the binary representation of x and y
		result ^= nums[i];
	}
	return result;
} // after looking into it: to run the file in the root - must do the following;
// .L tsk1.C
// int num[] = {10, 9, 4, 6, 3, 3, 2, 5, 7, 1, 0};  <- this is listing the values in the array
// int size = size of(nums) /sizeof(nums[0]);
// tsk9(nums, size) 


//task 10: Write a C++ program to check whether a given positive integer is a perfect square or not. In mathematics, a square number or perfect square is an integer that is the square of an integer, in other words, ti is the product of some integer with itself. for example, 9 is a square number, since it can be written as 3x3. 
//Sample input: n=1 
//Is 1 a perfect number? 1
//Sa,ple input: n= 13
//Is 13 a perfect number? 0


bool tsk10( long long x) { // x a value type long long ( a data type for large integers (typically 64 bits))
	// square root of x
	if ( x >= 0){ // >= greate than or equal to
		long long sr = sqrt(x); // if product of sqrt is equal then return T/F
		return (sr * sr == x);
	}
	return false; 
}

