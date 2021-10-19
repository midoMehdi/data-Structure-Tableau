#include<iostream>
#include"tableau.h"
using namespace std;
int main() {
	data_structure::tableau<int> array(1);
	array.ajouter(0);
	array.ajouter(1);
	array.ajouter(2);
	array.ajouter(3);
	array.ajouter(4);
	array.print();
	cout << array[2] << endl;
	const data_structure::tableau<int> array_2(array);
	cout << array_2[2] << endl;
	data_structure::tableau<int> array_3;
	array_3 = array;
	cout << array_3[2] << endl;
	try {
		cout << array_3[20] << endl;
	}
	catch (arrayExcpetion::tableauException e) {
		cout << e.print() << endl;
	}
	
	return 0;
}