
#include "CollisionType.h"

const CollisionType CollisionType::None			= CollisionType(0);
const CollisionType CollisionType::Player		= CollisionType(1 << 0);
const CollisionType CollisionType::Enemy		= CollisionType(1 << 1);
const CollisionType CollisionType::Ship			= CollisionType(1 << 2);
const CollisionType CollisionType::Projectile	= CollisionType(1 << 3);