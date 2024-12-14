
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

#include "KatanaEngine.h"

namespace KatanaEngine
{
	
	ParticlePool::ParticlePool(IParticleUpdater *pUpdater, IParticleRenderer *pRenderer)
	{
		m_pUpdater = pUpdater;
		m_pRenderer = pRenderer;
	}

	ParticlePool::~ParticlePool()
	{
		for (IParticle* pParticle : m_particles) delete pParticle;

		delete m_pUpdater;
		delete m_pRenderer;
	}

	void ParticlePool::Update(const GameTime& gameTime)
	{
		m_particlesIt = m_particles.begin();
		for (; m_particlesIt != m_particles.end(); m_particlesIt++)
		{
			IParticle* pParticle = *m_particlesIt;
			if (!pParticle->IsActive()) continue;
			m_pUpdater->Update(pParticle, gameTime);
		}
	}

	void ParticlePool::Draw(SpriteBatch& spriteBatch)
	{
		m_particlesIt = m_particles.begin();
		for (; m_particlesIt != m_particles.end(); m_particlesIt++)
		{
			IParticle* pParticle = *m_particlesIt;
			if (!pParticle->IsActive()) continue;
			m_pRenderer->Draw(pParticle, spriteBatch);
		}
	}

	IParticle* ParticlePool::GetInactiveParticle()
	{
		m_particlesIt = m_particles.begin();
		for (; m_particlesIt != m_particles.end(); m_particlesIt++)
		{
			IParticle* pParticle = *m_particlesIt;
			if (!pParticle->IsActive()) return pParticle;
		}

		return nullptr;
	}

}