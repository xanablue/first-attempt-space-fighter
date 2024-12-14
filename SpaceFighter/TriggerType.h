#pragma once

/** @brief Represents a type of trigger, which can be used to activate weapons.
	@details Each trigger type is represented by a unique bit-mask value.
	This class helps to decouple the weapon system from the input system.
*/
class TriggerType
{

public:

	/** @brief Instantiate a trigger type object. */
	TriggerType() { }
	virtual ~TriggerType() { }

	static const TriggerType None;
	static const TriggerType Primary;
	static const TriggerType Secondary;
	static const TriggerType Special;
	static const TriggerType All;


	TriggerType &TriggerType::operator=(const TriggerType &type)
	{
		m_value = type.m_value;

		return *this;
	}

	bool TriggerType::operator==(const TriggerType &type) const
	{
		return m_value == type.m_value;
	}

	bool TriggerType::operator!=(const TriggerType &type) const
	{
		return m_value != type.m_value;
	}

	bool TriggerType::operator<(const TriggerType &type) const
	{
		return m_value < type.m_value;
	}

	bool TriggerType::operator>(const TriggerType &type) const
	{
		return m_value > type.m_value;
	}

	const TriggerType operator|(const TriggerType &type) const
	{
		return (TriggerType)(m_value | type.m_value);
	}

	TriggerType &TriggerType::operator|=(const TriggerType &type)
	{
		m_value |= type.m_value;

		return *this;
	}

	const TriggerType operator&(const TriggerType &type) const
	{
		return (TriggerType)(m_value & type.m_value);
	}

	TriggerType &TriggerType::operator&=(const TriggerType &type)
	{
		m_value &= type.m_value;

		return *this;
	}

	const TriggerType operator^(const TriggerType &type) const
	{
		return (TriggerType)(m_value ^ type.m_value);
	}

	TriggerType &TriggerType::operator^=(const TriggerType &type)
	{
		m_value ^= type.m_value;

		return *this;
	}

	/** @brief Check if the trigger type contains a specific trigger.
		@param type The trigger type to check.
		@return True if the trigger type contains the specified trigger. */
	bool Contains(const TriggerType &type) const
	{
		return (m_value & type.m_value) > 0;
	}


protected:

	/** @brief Instantiate a trigger type object with a specific value.
		@param value The value of the trigger type. */
	TriggerType(const unsigned short value) { m_value = value; }


private:

	unsigned short m_value = 0;

};
