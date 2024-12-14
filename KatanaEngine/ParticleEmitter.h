
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

	/** @brief Class for emitting particles. */
	class ParticleEmitter
	{

	public:

		ParticleEmitter(IParticleInitializer *pInitializer)
		{
			m_pInitializer = pInitializer;
		}

		virtual ~ParticleEmitter() { delete m_pInitializer; }


		/** @brief Emits particles.
			@param amount A number between 0 and 1 representing the amount of particles to emit. */
		virtual void Emit(const float amount, const GameTime& gameTime)
		{
			const float fCount = amount * m_maxParticlesPerSecond * (float)gameTime.GetElapsedTime();
			float iCount = (int)fCount;
			m_remainingParticles += fCount - iCount;

			while (iCount)
			{
				IParticle *pParticle = m_pPool->GetInactiveParticle();
				if (!pParticle) {
					m_remainingParticles += iCount;
					return;
				}

				m_pInitializer->Initialize(pParticle, m_position);
				iCount--;
			}
		}

		virtual void SetMaxParticlesPerSecond(const int max) { m_maxParticlesPerSecond = max; }

		virtual void SetParticlePool(ParticlePool *pPool) { m_pPool = pPool; }

		virtual void SetPosition(const Vector2 &position) { m_position = position; }

	private:

		Vector2 m_position;

		int m_maxParticlesPerSecond = 100;

		float m_remainingParticles = 0;

		ParticlePool *m_pPool = nullptr;

		IParticleInitializer *m_pInitializer = nullptr;

	};

}