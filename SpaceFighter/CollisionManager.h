
#pragma once

#include "GameObject.h"

typedef void(*OnCollision)(GameObject *pGameObject1, GameObject *pGameObject2);

/** @brief Represents a collision manager that can be used to manage collisions between game objects. */
class CollisionManager
{

public:

	/** @brief Instantiate a collision manager. */
	CollisionManager() { }
	virtual ~CollisionManager() { }

	/** @brief Add a collision type to the manager.
		@remark Objects of these types will be checked for collisions.
		@param type1 The first collision type.
		@param type2 The second collision type.
		@param callback The callback function to call when a collision occurs. */
	virtual void AddCollisionType(const CollisionType type1, const CollisionType type2, OnCollision callback);

	/** @brief Add a non-collision type to the manager.
		@remark Objects of these types will not be checked for collisions. This is simply a performance optimization.
		@param type1 The first collision type.
		@param type2 The second collision type. */
	virtual void AddNonCollisionType(const CollisionType type1, const CollisionType type2);
	
	/** @brief Check for collisions between game objects.
		@param pGameObjects A pointer to the game objects to check for collisions.
		@remark This is called by the level, and should generally not be called anywhere else. */
	virtual void CheckCollision(GameObject *pGameObject1, GameObject *pGameObject2);


private:

	struct NonCollision
	{
		CollisionType Type1;
		CollisionType Type2;
	};

	struct Collision
	{
		CollisionType Type1;
		CollisionType Type2;
		OnCollision Callback = nullptr;
	};

	std::vector<NonCollision> m_nonCollisions;
	std::vector<NonCollision>::iterator m_nonCollisionIt;

	std::vector<Collision> m_collisions;
	std::vector<Collision>::iterator m_collisionIt;

};