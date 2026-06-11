//Pertaining to simple histograms


//task 1: Read a string and output histogram of character frequencies. Ignore spaces. Output characters in alaphabetical order 



//task 2: Give an array of integers (0-9),count how many times each number appears. 
using namespace std;
void histo2(int arr[], int n){
	int maxEle = *max_element(arr, arr + n); 
	for (int i = maxEle; i >= 0; i --){

		cout.width(2); 
		cout << right << i << "|";
		for (int j =0; j <n; j++){

			if 

