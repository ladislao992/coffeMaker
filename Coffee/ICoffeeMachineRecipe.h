#pragma once
#include <string>

struct Recipe {
	std::string name;
	int water = 0;//ml
	int sugar = 0;//mg
	int milk = 0;//ml
	int coffee = 0;//mg
	int t = 0;// water themperature
	int time = 0;//sec.
};

class ICoffeeMachineRecipe {
public:
	virtual Recipe GetRecipe(const std::string& name) const = 0;
	virtual std::string& GetName(int num)=0;
	virtual size_t GetSize() = 0;
	virtual void Set(std::string& name, int water,int sugar, int coffee, int t, int time, int milk)=0;
	~ICoffeeMachineRecipe() = default;
};

