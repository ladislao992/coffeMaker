#include <iostream>
#include "CoffeeMachine.h"
#include "CoffeeMachineRecipe.h"

CoffeeMachine::CoffeeMachine(int water, int sugar, int milk, int coffee):
	m_curWater(water),
	m_curSugar(sugar),
	m_curMilk(milk),
	m_curValCoffee(coffee)
{
	if (m_curWater <= m_watterLevel.m_min || m_curValCoffee <= m_coffeeLevel.m_min) {
		std::cout << "chek lvl of water and coffee";
	}	

}
bool CoffeeMachine::ChekIngredientLowLvl(int water, int sugar, int milk, int coffee) {
	bool res = true;
	if (m_curWater <= m_watterLevel.m_low) {
		std::cout << "Water low level" << std::endl;
		if (m_curWater - water <= m_watterLevel.m_min) {
			std::cout << "Water min level, please add water" << std::endl;
			std::cout << "Please enter water value to add:";
			int add;
			std::cin >> add;
			if (add<80) {
				std::cout << "Add more water:";
				std::cin >> add;
			}			
				AddWater(add);
			
		
		}
	}
	if (m_curSugar <= m_sugarLevel.m_low) {
		std::cout << "Sugar low level" << std::endl;
		if (m_curSugar - sugar <= m_watterLevel.m_min) {
			std::cout << "Sugar min level, please add sugar, or make without." << std::endl;
			std::cout << "Please enter sugar value to add:";
			int add;
			std::cin >> add;
			if (add < 20) {
				std::cout << "Add more sugar:";
				std::cin >> add;
			}
			AddSugar(add);

		}
	}
	if (m_curMilk - milk <= m_milkLevel.m_min) {
		std::cout << "Milk min level, please add milk, or choose another drink" << std::endl;
		std::cout << "Please enter milk value to add:";
		int add;
		std::cin >> add;
		if (add < 20) {
			std::cout << "Add more milk:";
			std::cin >> add;
		}
		AddMilk(add);

	}
	if (m_curValCoffee - coffee <= m_coffeeLevel.m_min) {
		std::cout << "Coffee min level, please add coffee please" << std::endl;
		std::cout << "Please enter coffee value to add:";
		int add;
		std::cin >> add;
		if (add < 20) {
			std::cout << "Add more coffee:";
			std::cin >> add;
		}
		AddCoffee(add);

	}
	return res;
}

bool CoffeeMachine::MakeDrink() {
	std::string name;
	int num;
	for (int i = 1; i <= m_recipe.GetSize(); ++i) {
		std::cout << i <<". " << m_recipe.GetName(i) << std::endl;
	}	
	std::cin >> num;
	if (num > m_recipe.GetSize()) {
		throw std::runtime_error("Sorry.Incorrect input");
	}

  name = m_recipe.GetName(num);

	const Recipe& curRecipe = m_recipe.GetRecipe(name);
	bool res = ChekIngredientLowLvl(curRecipe.water, curRecipe.sugar, curRecipe.milk, curRecipe.coffee);
	if (res) {
		m_curWater -= curRecipe.water;
		m_curSugar -= curRecipe.sugar;
		m_curMilk -= curRecipe.milk;
		m_curValCoffee -= curRecipe.coffee;
		std::cout << "Make '" << curRecipe.name<< "', done\n";
	}
	return res;
}
void CoffeeMachine::SetNewRecipe() {
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
	m_recipe.Set(name, water, sugar, coffee, t, time, milk);
}
int AddIngredient(int volumeToAdd, int& curIngridientVolume, int max) {
	int res = 0;
	curIngridientVolume += volumeToAdd;
	if (curIngridientVolume > max) {
		res = curIngridientVolume - max;
		curIngridientVolume = max;
	}
	return res;
}

int CoffeeMachine::AddWater(int add) {
	return AddIngredient(add, m_curWater, m_watterLevel.m_max);
}

int CoffeeMachine::AddSugar(int add) {
	return AddIngredient(add, m_curSugar, m_sugarLevel.m_max);
}

int CoffeeMachine::AddMilk(int add) {
	return AddIngredient(add, m_curMilk, m_milkLevel.m_max);
}

int CoffeeMachine::AddCoffee(int add) {
	return AddIngredient(add, m_curValCoffee, m_coffeeLevel.m_max);
}