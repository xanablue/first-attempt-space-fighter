
/*
	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
		Katana Engine \/ © 2012 - Shuriken Studios LLC
				http://www.shurikenstudios.com
*/

#pragma once

#include "KatanaEngine.h"

namespace KatanaEngine
{

	/** @brief Instantiate a basic particle. */
	class Particle : public IParticle
	{

	public:

		Particle() { }
		virtual ~Particle() { }

		/** @brief Gets whether the particle is active.
			@return Returns true if the particle is active. */
		virtual bool IsActive() const { return m_lifeRemaining > 0; }

		/** @brief Gets the position of the particle.
			@return Returns the position of the particle. */
		virtual Vector2 GetPosition() const { return m_position; }

		/** @brief Gets the velocity of the particle.
			@return Returns the velocity of the particle. */
		virtual Vector2 GetVelocity() const { return m_velocity; }

		/** @brief Gets the color of the particle.
			@return Returns the color of the particle. */
		virtual Color GetColor() const { return m_color; }

		/** @brief Gets the scale of the particle.
			@return Returns the scale of the particle. */
		virtual float GetScale() const { return m_scale; }

		/** @brief Gets the life span of the particle.
		* @return Returns the life span of the particle. */
		virtual float GetLifeSpan() const { return m_lifeSpan; }

		/** @brief Gets the life remaining of the particle.
			@return Returns the life remaining of the particle. */
		virtual float GetLifeRemaining() const { return m_lifeRemaining; }

		/** @brief Sets the position of the particle.
			@param position The position to set. */
		virtual void SetPosition(const Vector2 position) { m_position = position; }

		/** @brief Sets the velocity of the particle.
			@param velocity The velocity to set. */
		virtual void SetVelocity(const Vector2 velocity) { m_velocity = velocity; }

		/** @brief Sets the color of the particle.
			@param color The color to set. */
		virtual void SetColor(const Color color) { m_color = color; }

		/** @brief Sets the scale of the particle.
			@param scale The scale to set. */
		virtual void SetScale(const float scale) { m_scale = scale; }

		/** @brief Sets the life span of the particle.
			@param lifeSpan The life span to set. */
		virtual void SetLifeSpan(const float lifeSpan) {
			m_lifeSpan = lifeSpan;
		}

		virtual float GetLifePercentage() const { return m_lifePercentage; }

		virtual void Initialize(Vector2& position) {
			m_position = position;
			m_lifeRemaining = m_lifeSpan;
		}

		virtual void Update(const GameTime& gameTime)
		{
			const float elapsed = (float)gameTime.GetElapsedTime();
			m_lifeRemaining -= elapsed;
			if (m_lifeRemaining < 0) m_lifeRemaining = 0;
			m_lifePercentage = m_lifeRemaining / m_lifeSpan;
			m_position += m_velocity * elapsed;
		}


	private:

		Vector2 m_position;
		Vector2 m_velocity;
		Color m_color = Color::WHITE;
		float m_scale = 1;
		
		float m_lifeSpan = 0;
		float m_lifeRemaining = 0;
		float m_lifePercentage = 0;
	};

}