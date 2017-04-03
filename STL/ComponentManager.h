#pragma once

class Component;

class ComponentManager
{
private:
	vector< std::vector<std::unique_ptr<Component>>> vComponent;

public:
	ComponentManager();

	virtual ~ComponentManager();

	void Load();

	vector<shared_ptr<Component>> MakeComponent(){}

	std::vector<std::unique_ptr<Component>> GetComponent(int n);
};
	
