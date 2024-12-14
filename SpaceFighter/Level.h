
#pragma once

#include "KatanaEngine.h"
#include "PlayerShip.h"
#include "CollisionManager.h"
#include "Explosion.h"

using namespace KatanaEngine;

class GameplayScreen;

/** @brief Represents a level in the game. */
class Level
{

public:

	/** @brief Instantiate a level object. */
	Level();
	virtual ~Level();

	/** @brief Load the content for the level, including game objects and resources.
		@param resourceManager A reference to the game's resource manager,
		used for loading and managing game assets (resources). */
	virtual void LoadContent(ResourceManager& resourceManager);

	/** @brief Unload the content for the level. */
	virtual void UnloadContent() { };

	/** @brief Handle input for the level.
		@param input The current state of all player input devices. */
	virtual void HandleInput(const InputState& input);

	/** @brief Update the level.
		@param pGameTime Timing values including time since last update. */
	virtual void Update(const GameTime& gameTime);

	/** @brief Render the level, and all of the game objects within it.
		@param spriteBatch A reference to the game's sprite batch, used for rendering. */
	virtual void Draw(SpriteBatch& spriteBatch);

	/** @brief Add a game object to the level.
		This object will be updated, rendered, and checked for collisions.
		@param pGameObject A pointer to the game object to add. */
	virtual void AddGameObject(GameObject* pGameObject) { m_gameObjects.push_back(pGameObject); }

	/** @brief Update the position of a game object within the level,
		based on its collision sector (only objects within the same or adjacent sectors will be checked for collisions).
		@param pGameObject A pointer to the game object to update. */
	virtual void UpdateSectorPosition(GameObject* pGameObject);

	/** @brief Set a reference to the gameplay screen.
		@param pGameplayScreen A pointer to the gameplay screen. */
	virtual void SetGameplayScreen(GameplayScreen* pGameplayScreen) { m_pGameplayScreen = pGameplayScreen; }

	/** @brief Spawn an explosion at a specific position.
		@param position The position to spawn the explosion at. */
	virtual void SpawnExplosion(GameObject* pExplodingObject);

	/** @brief Set the background texture for the level.
		@param pBackground A pointer to the texture to use as the background. */
	virtual void SetBackground(Texture* pBackground) { m_pBackground = pBackground; }

	/** @brief Get the alpha value of the screen.
		@return The alpha value of the screen. */
	virtual float GetAlpha() const;

	/** @brief Check if the screen is transitioning.
		@return True if the screen is transitioning. */
	virtual bool IsScreenTransitioning() const { return GetAlpha() < 1; }

	/** @brief Get a pointer to the closest object of a specific type.
		@param position The position to check from.
		@param range The maximum range to check.
		@return A pointer to the closest object of the specified type. */
	template <typename T>
	T* GetClosestObject(const Vector2 position, const float range)
	{
		float squaredRange = range * range;
		if (range <= 0)
		{
			int w = Game::GetScreenWidth();
			int h = Game::GetScreenHeight();
			squaredRange = w * w + h * h;
		}
		float squaredDistance;

		std::vector<GameObject*>::iterator m_it = m_gameObjects.begin();
		T* pClosest = nullptr;

		for (; m_it != m_gameObjects.end(); m_it++)
		{
			GameObject* pGameObject = *m_it;
			if (pGameObject->IsActive()) continue;

			squaredDistance = (position - pGameObject->GetPosition()).LengthSquared();
			if (squaredDistance < squaredRange)
			{
				T* pObject = dynamic_cast<T*>(pGameObject);
				if (pObject)
				{
					pClosest = pObject;
					squaredRange = squaredDistance;
				}
			}
		}

		return pClosest;
	}

	//returns the total amount of time the game has been paused
	double GetPausedTime() const { return m_pausedTime; }
	//adds to score
	void AddScore(int scoreToAdd) { m_score += scoreToAdd; }

	// Xana - Flag for game over
	static bool s_gameOver;
	// Xana - Setting for game over
	static void SetGameOver(bool gameover) { s_gameOver = gameover; }
	// Xana - Resets health/game over
	static void ResetLevel(PlayerShip* m_pPlayerShip);

protected:

	/** @brief Get a pointer to the collision manager.
		@return A pointer to the collision manager. */
	virtual CollisionManager* GetCollisionManager() { return m_pCollisionManager; }

	/** @brief Set the background audio for the level.
		@param pAudio A pointer to the audio sample to play. */
	virtual void SetBackgroundAudio(AudioSample* pAudio) { m_pAudio = pAudio; }

	/** @brief Get the background audio for the level.
		@return A pointer to the audio sample to play. */
	virtual AudioSample* GetBackgroundAudio() { return m_pAudio; }

	/** @brief Get a pointer to the gameplay screen.
        @return A pointer to the gameplay screen. */
	virtual GameplayScreen* GetGameplayScreen() const { return m_pGameplayScreen; }

private:

	static std::vector<Explosion *> s_explosions;
	//std::vector<Explosion *>::iterator m_explosionIt;

	CollisionManager* m_pCollisionManager = nullptr;

	GameplayScreen* m_pGameplayScreen = nullptr;

	AudioSample* m_pAudio = nullptr;

	Texture* m_pBackground = nullptr;

	std::vector<GameObject*>* m_pSectors;

	Vector2 m_sectorCount;
	Vector2 m_sectorSize;

	unsigned int m_totalSectorCount = 0;

	std::vector<GameObject*> m_gameObjects;
	std::vector<GameObject*>::iterator m_gameObjectIt;

	PlayerShip* m_pPlayerShip;
	std::vector<Projectile*> m_projectiles;

	void CheckCollisions(std::vector<GameObject*>& sector);

	virtual Vector2 GetSectorCount() const { return m_sectorCount; }

	virtual Vector2 GetSectorSize() const { return m_sectorSize; }

	virtual unsigned int GetTotalSectorCount() const { return m_totalSectorCount; }

	virtual std::vector<GameObject*>* GetSectors() { return m_pSectors; }

	//score
	int m_score;

	//whether or not the level is paused
	bool m_paused;

	//total time the game has been paused because some things use total time to determine where they should be
	double m_pausedTime;

	//font for pause text
	Font* m_pFont;
};