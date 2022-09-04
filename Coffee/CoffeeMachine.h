#pragma once
#include "ICoffeeMachine.h"
#include "CoffeeMachineRecipe.h"

struct IngridientsLevel {
	int m_min;
	int m_low;
	int m_max;
};
class CoffeeMachine : public ICoffeeMachine
{
public:
	CoffeeMachine(int water, int sugar, int milk, int coffee);
	bool MakeDrink() override;
	bool ChekIngredientLowLvl(int, int, int, int) override;
	int AddWater(int)override;
	int AddSugar(int)override;
	int AddMilk(int)override;
	int AddCoffee(int)override;
	void SetNewRecipe()override;
private:
	CoffeeMachineRecipe m_recipe;

	//ingredients
	int m_curWater;
	int m_curSugar;
	int m_curMilk;
	int m_curValCoffee;
	//water lvl
	const IngridientsLevel m_watterLevel = { 0, 150, 1000 };
	//sugar lvl
	const IngridientsLevel m_sugarLevel = { 0, 100, 800};
	//milk lvl
	const IngridientsLevel m_milkLevel = { 0, 0, 300 };
	//coffee lvl
	const IngridientsLevel m_coffeeLevel = { 0, 0, 500 };
};


