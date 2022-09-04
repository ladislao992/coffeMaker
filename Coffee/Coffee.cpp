#include <iostream>
#include "CoffeeMachine.h"

int main() {
	try {
	//enter start val of ingredients:water,sugar,milk,coffee
		CoffeeMachine redmond(1000, 800, 50, 400);
		
		redmond.SetNewRecipe();
		redmond.SetNewRecipe();
		redmond.SetNewRecipe();
		redmond.SetNewRecipe();
		
		
			while (true) {
				std::cout << "Select drink to make please\n";

				redmond.MakeDrink();
			}
		//redmond.MakeDrink();
		//redmond.MakeDrink();
		//redmond.AddCoffee(300);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what();
	}
}