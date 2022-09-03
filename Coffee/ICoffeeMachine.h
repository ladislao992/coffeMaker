#pragma once
#include"CoffeeMachineRecipe.h"

class ICoffeeMachine
{
public:	
	virtual bool MakeDrink(/*const std::string& name*/) = 0;
	virtual bool ChekIngredientLowLvl(int water, int sugar, int milk, int coffee)= 0;
	virtual int AddWater(int)= 0;
	virtual int AddSugar(int)= 0;
	virtual int AddMilk(int)= 0;
	virtual int AddCoffee(int)= 0;
	virtual void SetNewRecipe(std::string& name, int water, int sugar, int coffee, int t, int time, int milk) = 0;
	virtual ~ICoffeeMachine() = default;
};