#include <iostream>
#include "CoffeeMachine.h"

int main() {
	try {
		//enter start val of ingredients:water,sugar,milk,coffee
		CoffeeMachine redmond(1000, 800, 50, 400);
		while (true) {
			std::cout << "Select operation between:\n 1.Make drink.\n 2.Set manual recipe. ";
			int operation;
			std::cin >> operation;
			switch (operation) {
			case 1:
				std::cout << "Select drink to make please\n";
				redmond.MakeDrink();
				break;
			case 2:
				redmond.SetNewRecipe();
				break;
			/*case 3:
				redmond.Delete();*/
			default:
				break;
			}
		}

	}
	catch (const std::exception& ex) {
		std::cerr << ex.what();
	}
}