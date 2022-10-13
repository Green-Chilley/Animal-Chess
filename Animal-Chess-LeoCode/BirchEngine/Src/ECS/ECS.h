#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t; // For extensions such as physics, AI ...

inline ComponentID getComponentTypeID() { // Creating the component ID
	
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept {

	static ComponentID typeID = getComponentTypeID(); // Generate a new lastID and put into lastID
	return typeID;
}

// Tell if the entity have a component attach
constexpr std::size_t maxComponents = 32; // Max components that an entity can hold

using ComponentBitSet = std::bitset<maxComponents>; // Compare if the entity has a certain amount of components
using ComponentArray = std::array<Component*, maxComponents>; // An array of component pointers and the length of the maxcomponents

class Component {
public:
	Entity* entity;

	virtual void init() {}
	virtual void update() {}
	virtual  void draw() {}

	virtual ~Component() {}

};

class Entity {
private:
	bool active = true; // See if the entity is actives
	std::vector<std::unique_ptr<Component>> components; // vector is like an arry but dont have a set size

	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

public:
	void update() {
		for (auto& c : components) c->update(); // For every c component
	}

	void draw() {

		for (auto& c : components) c->draw();
	}

	bool isActive() const { return active; }

	void destroy() { active = false; }

	template <typename T> bool hasComponent() const {
		return componentBitSet[getComponentTypeID<T>()]; // T represent the type of component and the componentBitSet is used to see if the entity has the T component or not
	}

	// Add component to the entity
	// Research more on this block of code!!!

	template <typename T, typename ...TArgs>
	T& addcomponent(TArgs&&...mArgs) {
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this; // c is short for component
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitSet[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}

	template <typename T> T& getComponent() const { 
		
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};

	class Manager { // Manage all the entities
	private:
		std::vector<std::unique_ptr<Entity>> entities; // Setting the array/ vector of entities

	public:
		void update() {
			for (auto& e : entities) e->update(); // e stands for entity // auto& e (for each entity in the vector)
		}

		void draw() {
			for (auto& e : entities) e->draw();
		}

		// Manager to move through the entities and remove the ones that are inactive

		void refresh() {
			entities.erase(std::remove_if(std::begin(entities), std::end(entities),
				[](const std::unique_ptr<Entity>& mEntity) {
					return !mEntity->isActive(); // Checking if the entity is active or not
				}),
				std::end(entities)); // Delete the entity
		}

		Entity& addEntity() {
			Entity* e = new Entity();
			std::unique_ptr<Entity> uPtr{ e }; // initialise uPtr to e
			entities.emplace_back(std::move(uPtr)); // Add the new entity to the list
			return *e;
		}
				
	};