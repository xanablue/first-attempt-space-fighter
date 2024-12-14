#include "Explosion.h"

void Explosion::Update(const GameTime& gameTime)
{
	m_pAnimation->Update(gameTime);
}


void Explosion::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		Vector2 center = m_pAnimation->GetFrame(0)->GetCenter();
		spriteBatch.Draw(m_pAnimation, m_position, Color::WHITE, center, Vector2::ONE * m_scale, m_rotation);
	}
}


void Explosion::Activate(const Vector2 position, const float scale)
{
	SetPosition(position);
	m_scale = scale;
	m_rotation = Math::GetRandomFloat() * 2 * Math::PI;
	m_pAnimation->SetLoopCount(0);
	m_pAnimation->Play();
	if (m_pSound) m_pSound->Play();
}