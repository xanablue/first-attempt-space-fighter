
#include "Weapon.h"

void Weapon::AttachTo(IAttachable* pAttachable, Vector2& position) {
	m_pGameObject = dynamic_cast<GameObject*>(pAttachable);
	m_offset = position;
}

Projectile* Weapon::GetProjectile()
{
	for (Projectile* pProjectile : *m_pProjectiles)
	{
		if (!pProjectile->IsActive()) return pProjectile;
	}

	return nullptr;
}