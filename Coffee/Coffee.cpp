#include <iostream>
#include "CoffeeMachine.h"

int main() {
	//enter start val of ingredients:water,sugar,milk,coffee
	try {
		CoffeeMachine redmond(1000, 800, 50, 400);
		std::cout << "Enter new recipe name:";
		std::string name;
		std::cin >> name;
		int water;
		std::cout << "enter water val:";
		std::cin >> water;
		int sugar;
		std::cout << "enter sugar val:";
		std::cin >> sugar;
		int coffee;
		std::cout << "enter coffee val:";
		std::cin >> coffee;
		int t;
		std::cout << "enter t:";
		std::cin >> t;
		int time;
		std::cout << "enter time:";
		std::cin >> time;
		int milk;
		std::cout << "enter milk val:";
		std::cin >> milk;
		redmond.SetNewRecipe(name, water,sugar, coffee, t, time, milk);
		
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