#include "node.h"
#include "list.h"
#include "studente.h"
#include <iostream>

using namespace std;

int main() {
	
	List<int> list;
	
	for(int i=1; i<=5; i++)
		list.insertInOrder(i, List<int>::DECRESC);
	
//	for(int i=5; i>=0; i--)
//		list.insertInOrder(i, List<int>::CRESC);
		
//	list.insertInOrder(6, List<int>::CRESC); //1 2 3 4 5 6
//	cout<<list;
//	list.insertInOrder(3, List<int>::DECRESC); //3 1 2 3 4 5 6
//	list.insertInOrder(5, List<int>::DECRESC); //5 3 1 2 3 4 5 6
//	list.insertInOrder(4, List<int>::DECRESC); //5 3 4 1 2 3 4 5 6
//	list.insertInOrder(6, List<int>::CRESC); //5 3 4 1 2 3 4 5 6 6
//	cout<<list;
	
	//0 decresc
	//5 4 3 2 1 
		
}
