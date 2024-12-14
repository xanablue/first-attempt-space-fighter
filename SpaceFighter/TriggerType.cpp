
#include "TriggerType.h"

const TriggerType TriggerType::None			= TriggerType(0);
const TriggerType TriggerType::Primary		= TriggerType(1 << 0);
const TriggerType TriggerType::Secondary	= TriggerType(1 << 1);
const TriggerType TriggerType::Special		= TriggerType(1 << 2);
const TriggerType TriggerType::All			= TriggerType((unsigned short)(-1));