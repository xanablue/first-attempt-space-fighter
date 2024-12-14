
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

	/** @brief Basic particle initializer. */
	class ParticleInitializer : public IParticleInitializer
	{

	public:

		ParticleInitializer(const Color color = Color::WHITE, const float scale = 1)
		{
			m_color = color;
			m_scale = scale;
		}

		virtual ~ParticleInitializer() { }

		virtual void Initialize(IParticle* pParticle, Vector2& position) const
		{
			Particle* pP = (Particle*)pParticle;
			pP->SetLifeSpan(m_lifeSpan);
			pP->SetVelocity(m_velocity);
			pP->SetScale(m_scale);
			pP->SetColor(m_color);
			pP->Initialize(position);
		}

		virtual void SetScale(const float scale) { m_scale = scale; }

		virtual void SetColor(const Color color) { m_color = color; }

	private: 

		float m_lifeSpan = 0.5f;
		Vector2 m_velocity = Vector2::UNIT_Y * 50;
		float m_scale = 1;
		Color m_color = Color::WHITE;

	};

}