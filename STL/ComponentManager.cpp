#include "stdafx.h"
#include "ComponentManager.h"
#include "Component.h"

ComponentManager::ComponentManager()
{
	ComponentManager::Load();
}

ComponentManager::~ComponentManager()
{
}

void ComponentManager::Load()
{

	{
		auto rotation = make_unique<Rotation>();
		rotation->Set(0, 3);
		rotation->str = "1-1";

		vector<unique_ptr<Component>> vec;
		vec.push_back(move(rotation));
	
		vComponent.push_back(move(vec));
	}
	
	{
		unique_ptr<Rotation> ro = make_unique<Rotation>();
		ro->str = "2-1";
		ro->Set(0, 7);	
		unique_ptr<Rotation> ro2 = make_unique<Rotation>();
		ro2->str = "2-2";
		ro2->Set(0, 15);
		vector<unique_ptr<Component>> vec;
		vec.push_back(move(ro));
		vec.push_back(move(ro2));
	
		vComponent.push_back(move(vec));
	}

}
//vector<shared_ptr<Component>> MakeComponent()
//{
//	return NULL;
//}

std::vector<std::unique_ptr<Component>> ComponentManager::GetComponent(int n)
{
	return move(vComponent[n]);
}


