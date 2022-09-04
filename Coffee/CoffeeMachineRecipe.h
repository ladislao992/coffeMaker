#pragma once
#include "ICoffeeMachineRecipe.h"
#include <vector>
#include <iostream>
enum drinkNumber {
	drinkError,
	Espresso,
	Americano,
	Latte
};
class CoffeeMachineRecipe : public ICoffeeMachineRecipe
{
public:
	CoffeeMachineRecipe();
	Recipe GetRecipe(const std::string& name) const override;
	std::string& GetName(int num)override;
	size_t GetSize()override;
	//void Del(int);
	void Set(std::string& name, int water, int sugar, int coffee, int t, int time, int milk)override;

private:
	Recipe GetEspressoRecipe() const;
	Recipe GetAmericanoRecipe() const;
	Recipe GetLatteRecipe() const;



private:
	std::vector<Recipe> m_recipes;
};