
#pragma once

/** @brief Represents a type of collision.
	@details Each collision type is represented by a unique bit-mask value.
	This allows for complex types without the need for a large number of unique values.
	It basically allows for a single number to represent multiple boolean values.
	For example, a collision type "player projectile" would be created by combining the "player" and "projectile" types,
	while an "enemy projectile" would be created by combining the "enemy" and "projectile" types.
*/
class CollisionType
{

public:
	
	/** @brief Instantiate a collision type object. */
	CollisionType() : m_value(0) { }
	virtual ~CollisionType() { }

	
	static const CollisionType None;

	static const CollisionType Player;
	static const CollisionType Enemy;

	static const CollisionType Ship;
	static const CollisionType Projectile;

	CollisionType &CollisionType::operator=(const CollisionType &type)
	{
		m_value = type.m_value;
		return *this;
	}

	bool CollisionType::operator==(const CollisionType &type) const
	{
		return m_value == type.m_value;
	}

	bool CollisionType::operator!=(const CollisionType &type) const
	{
		return m_value != type.m_value;
	}

	bool CollisionType::operator<(const CollisionType &type) const
	{
		return m_value < type.m_value;
	}

	bool CollisionType::operator>(const CollisionType &type) const
	{
		return m_value > type.m_value;
	}

	const CollisionType operator|(const CollisionType &type) const
	{
		return (CollisionType)(m_value | type.m_value);
	}

	CollisionType &CollisionType::operator|=(const CollisionType &type)
	{
		m_value |= type.m_value;

		return *this;
	}

	const CollisionType operator&(const CollisionType &type) const
	{
		return (CollisionType)(m_value & type.m_value);
	}

	CollisionType &CollisionType::operator&=(const CollisionType &type)
	{
		m_value &= type.m_value;

		return *this;
	}

	const CollisionType operator^(const CollisionType &type) const
	{
		return (CollisionType)(m_value ^ type.m_value);
	}

	CollisionType &CollisionType::operator^=(const CollisionType &type)
	{
		m_value ^= type.m_value;

		return *this;
	}

	/** @brief Check if the collision type contains a specific type.
		@param type The type to check.
		@return True if the type is contained within the collision type. */
	bool Contains(const CollisionType &type) const
	{
		return (m_value & type.m_value) > 0;
	}


protected:

	/** @brief Instantiate a collision type object with a specific value.
		@param value The value of the collision type. */
	CollisionType(const unsigned short value) { m_value = value; }


private:

	unsigned short m_value;

};