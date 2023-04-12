#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

//the class component is above at this header
class component;
//the class entity is above at this header
class entity;
//the componentID is used so the cod doesnt have duplicate ID created
using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
	static ComponentID lastID = 0 ;
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static_assert (std::is_base_of<component, T>::value, "");
	static ComponentID typeID = getComponentTypeID();
	return typeID;
		
}
//we want to be able to tell if an entity have a component attach
constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<component*, maxComponents>;

//class for the components

class component
{
public:
	entity* entity;

	//virtual so it can be overwrited
	virtual void init(){}
	virtual void update(){}
	virtual void draw(){}

	virtual ~component() {}

private:
};

class entity
{
public:
	void update()
	{
		//this will be updating the components
		for (auto& c : components) c->update();
		
		
	}

	void Draw()
	{
		//this will be passing this information passing in the struct placed at 
		for (auto& c : components) c->draw();
	}

	bool isActive() { return active; }

	void destroy() { active = false; }

	template <typename T > bool hasComponent() const
	{
		return componentBitSet[getComponentTypeID<T>];
	}
	//all the entities will pass here, basiccly if we want to create a tile she will pass here and go to init by the variable c
	//this woudnt be the best way to do it for objects but as im using entities it will work
	//in this step is important to notice that entities are being used and not objects
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;
		
		c->init();
		return *c;

	}

	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);

	}

	


private:
	bool active = true;
	std::vector<std::unique_ptr<component>> components;

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;


};

class Manager
{
public:
	void update()
	{
		//e will be the entities
		for (auto& e : entities) e->update();
	}

	void Draw()
	{
		for (auto& e : entities) e->Draw();
	}
	//move throw the entities
	void refresh()
	{
		entities.erase(std::remove_if(std::begin(entities), std::end(entities),
			[](const std::unique_ptr<entity>& mEntity)
		{
			return !mEntity->isActive();
		}),
		std::end(entities));
	}
	entity& addEntity()
	{
		entity* e = new entity();
		//this will be the smart point that will manage anothe object through a pointer and dispose of that object when the unique_ptr goes out of scope
		std::unique_ptr<entity> uPtr{ e };
		entities.emplace_back(std::move(uPtr));
		return *e;
	}
	 
private:
	std::vector<std::unique_ptr<entity>> entities;

};