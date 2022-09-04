#include <stdexcept>
#include "CoffeeMachineRecipe.h"

CoffeeMachineRecipe::CoffeeMachineRecipe() {
	m_recipes.push_back(GetEspressoRecipe());
	m_recipes.push_back(GetAmericanoRecipe());
	m_recipes.push_back(GetLatteRecipe());
}

Recipe CoffeeMachineRecipe::GetRecipe(const std::string& name) const {
	for (size_t i = 0; i < m_recipes.size(); ++i) {
		if (m_recipes[i].name == name) {
			return m_recipes[i];
		}
	}
	throw std::runtime_error(name);
}
std::string& CoffeeMachineRecipe::GetName(int num){
	
			return m_recipes[num-1].name;
	
}
size_t CoffeeMachineRecipe::GetSize() {

	return m_recipes.size();

}
	void CoffeeMachineRecipe::Set(std::string& name, int water, int sugar, int coffee, int t, int time, int milk)
{
		m_recipes.push_back(Recipe{ name,water,sugar, coffee,t, time, milk });
		std::cout << "Set recipe done.\n";
		
}
Recipe CoffeeMachineRecipe::GetEspressoRecipe() const {
	Recipe espresso;
	espresso.name = "Espresso";
	espresso.water = 40;
	espresso.coffee = 8;
	espresso.t = 95;
	espresso.time = 25;
	return espresso;
}

Recipe CoffeeMachineRecipe::GetAmericanoRecipe() const {
	Recipe americano;
	americano.name = "Americano";
	americano.water = 80;
	americano.coffee = 8;
	americano.t = 95;
	americano.time = 40;
	return americano;
}

Recipe CoffeeMachineRecipe::GetLatteRecipe() const {
	Recipe latte;
	latte.name = "Latte";
	latte.water = 80;
	latte.coffee = 16;
	latte.t = 95;
	latte.time = 40;
	latte.milk = 15;
	return latte;
}

