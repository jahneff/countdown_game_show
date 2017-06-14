#include <iostream>

using namespace std;

bool next_operation(int numbers[], int index, int total, int temp, char equation[]){
	if(temp == total){equation[index] = '.'; return true;}
	int guess;
	if (index > 4){
		return false;
	}
	guess = temp + numbers[index];
	equation[index] = '+';
	if (next_operation(numbers, index+1, total, guess, equation) == true){return true;}
	guess = temp - numbers[index];
	equation[(index)]= '-';
	if (next_operation(numbers, index+1, total, guess, equation) == true){return true;}
	guess = temp * numbers[index];
	equation[(index)]= '*';
	if (next_operation(numbers, index+1, total, guess, equation) == true){return true;}
	guess = temp / numbers[index];
	equation[(index)]= '/';
	if (next_operation(numbers, index+1, total, guess, equation) == true){return true;}
	return false;
}

int main(){
	int numbers[6];
	char equation[12];
	int final;
	cout << "Please enter 6 integers";
	for(int i = 0; i < 6; i++){
		cin >> numbers[i];
	}
	cout << "Now enter a total for these numbers to evaluate to." << endl;
	cin >> final;
	bool success;
	success = next_operation(numbers, 0, final, 0, equation);
	cout << success;
	if (success == true){
		
		cout << endl;
		cout << "Problem solved" << endl;
		cout << "Here's how: ";
		int k = 0;
		while (equation[k] != '.'){
			cout << numbers[k];
			cout << equation[k+1];
			k++;
		}
	}
	else{
		cout << "No solution found!" << endl;
	}
}

