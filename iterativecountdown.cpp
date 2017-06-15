#include <iostream>

using namespace std;

void print_intro(){
	cout << "*****************************************************************************************" << endl;
	cout << "**          Welcome to the Countdown problem solver system, iterative version!         **" << endl;
	cout << "** This program takes n integers and attempts to solve for a specific number with them **" << endl;
	cout << "*****************************************************************************************" << endl;
}

int set_temp(int temp, int m, int next){
	if (m == 0){temp = temp + next;}
	else if (m == 1){temp = temp - next;}
	else if (m == 2){temp = temp * next;}
	else if (m == 3){temp = temp / next;}
	return temp;
} 

char read_ops(int op){ //based on whether a loop counter is 1, 2, 3, or 4, returns the corresponding operator for printing
	char symbol;
	if (op == 0){symbol = '+';}
	else if (op == 1){symbol = '-';}
	else if (op == 2){symbol = '*';}
	else if (op == 3){symbol = '/';}
	else {symbol = 'e';} 
	return symbol;
}

int compare(int temp, int total, int solutions){
	if (temp == total){
	solutions++;
	return solutions;
	}
	else {return solutions;} 		
}

void pretty_print(int ops[], int numbers[]){
	cout << numbers[0]; 
        cout << read_ops(ops[0]) << numbers[1];		
	cout << read_ops(ops[1]) << numbers[2];		
	cout << read_ops(ops[2]) << numbers[3];		
	cout << read_ops(ops[3]) << numbers[4];		
	cout << read_ops(ops[4]) << numbers[5] << endl;
	
} 

int main(){
	int numbers[6];
	int ops[5];
	char equation[12];
	char symbols[5]; // = {1, 2, 3, 4}; 
	int total;
	print_intro();
	cout << "Please enter 6 integers" << endl;
	for(int i = 0; i < 6; i++){
		cin >> numbers[i];
	}
	
	cout << "Now enter a total for these numbers to evaluate to." << endl;
	cin >> total;
	
	cout << "total: " << total << endl;
	cout << "numbers: [";
	
	for (int i = 0; i < 5; i++){
		cout << numbers[i] << ", ";
	}	
	cout << numbers[5]  <<  "]" << endl;

	int temp_num_solutions = 0; 
	int num_solutions = 0;
	for(int h = 0; h < 4; h++){
	 for(int i = 0; i < 4; i++){
	  for(int j = 0; j < 4; j++){
	   for(int k = 0; k < 4; k++){
	    for(int l = 0; l < 4; l++){
		int temp = 0;
		temp = numbers[0];
		for (int m = 1; m < 6; m++){
			if (m == 1){	 
				temp = set_temp(temp, h, numbers[m]);
			}
			else if (m == 2){	
				temp = set_temp(temp, i, numbers[m]);
			}
			else if (m == 3){	
				temp = set_temp(temp, j, numbers[m]);
			}
			else if (m == 4){	
				temp = set_temp(temp, k, numbers[m]);
			}
			else if (m == 5){	
				temp = set_temp(temp, l, numbers[m]);
			}
										
		}
   		temp_num_solutions = compare(temp, total, num_solutions);
		if (temp_num_solutions != num_solutions){
			num_solutions = temp_num_solutions;
			cout << num_solutions << ".  "; 
			ops[0] = h;
			ops[1] = i;
			ops[2] = j; 
			ops[3] = k;
			ops[4] = l;	
			pretty_print(ops, numbers);
	   	}								
	    }					
           }		
	  }		
	 }	
	}

	cout << "num solutions:" << num_solutions << endl;
}

