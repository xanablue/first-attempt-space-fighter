#pragma once

#include "KatanaEngine.h"

using namespace KatanaEngine;

/** @brief Represents an explosion animation in the game. */
class Explosion
{

public:

	Explosion() { }
	virtual ~Explosion() { }
	/** @brief Update the explosion.
		@param gameTime A reference to the game time object. */
	virtual void Update(const GameTime& gameTime);

	/** @brief Render the explosion.
		@param spriteBatch A reference to the game's sprite batch, used for rendering. */
	virtual void Draw(SpriteBatch& spriteBatch);

	/** @brief Sets the explosion's animation.
		@param pAnimation The animation to set. */
	virtual void SetAnimation(Animation* pAnimation) { m_pAnimation = pAnimation; }

	/** @brief Activates the explosion.
		@param position The position to place the explosion.
		@param scale The scale of the explosion.  */
	virtual void Activate(const Vector2 position, const float scale = 1);

	/** @brief Checks if the explosion is active.
		@return True if the explosion is active. */
	virtual bool IsActive() const { return m_pAnimation->IsPlaying(); }

	/** @brief Set the sound that will be played when the explosion is activated.
		@param pSound A pointer to the audio sample. */
	virtual void SetSound(AudioSample* pSound) { m_pSound = pSound; }

	/** @brief Get the sound that will be played when the explosion is activated.
		@return A pointer to the audio sample. */
	virtual AudioSample* GetSound() { return m_pSound; }


protected:

	/** @brief Sets the explosion's position.
	@param position The explosion's new position. */
	virtual void SetPosition(const Vector2 position) { m_position = position; }


private:

	Animation* m_pAnimation = nullptr;
	AudioSample* m_pSound = nullptr;

	Vector2 m_position;

	float m_rotation = 0;
	float m_scale = 1;

};