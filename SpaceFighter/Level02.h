#pragma once

#include "Level.h"

/** @brief The second level of the game. */
class Level02 : public Level
{

public:

	/** @brief Instantiate a level object. */
	Level02() { }
	virtual ~Level02() { }

	/** @brief Load the content for the level, including game objects and resources.
		@param resourceManager A reference to the game's resource manager,
		used for loading and managing game assets (resources). */
	virtual void LoadContent(ResourceManager& resourceManager);
};
