
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

	/** @brief Class that manages a pool of particles. */
	class ParticlePool
	{

	public:

		/** @brief Creates a new instance of ParticlePool. */
		ParticlePool(IParticleUpdater* pUpdater, IParticleRenderer* pRenderer);
		virtual ~ParticlePool();

		virtual void Update(const GameTime& gameTime);

		virtual void Draw(SpriteBatch& spriteBatch);

		virtual IParticle *GetInactiveParticle();

		virtual void AddParticle(IParticle *pParticle) { m_particles.push_back(pParticle); }

	private:

		std::vector<IParticle *> m_particles;
		std::vector<IParticle *>::iterator m_particlesIt;

		IParticleUpdater* m_pUpdater = nullptr;
		IParticleRenderer* m_pRenderer = nullptr;
		
	};

}