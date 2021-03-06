#ifndef CONTROLLABLECOMPONENT_H_
#define CONTROLLABLECOMPONENT_H_

#include "Component/LogicComponent.h"
#include <gccore.h>

//Controllable components interact with the padSystem
class ControllableComponent : public LogicComponent{
public:
	//Constructor
	//@Point to instances in PadSystem
	ControllableComponent(u16 * buttonsHeld, u16 * buttonsDown, u16 * buttonsUp, u16 * wButtonsHeld, u16 * wButtonsDown, u16 * wButtonsUp, 
		float * swing, float * pitch, float * deviation, float * roll);
	virtual ~ControllableComponent();
	//Messaging
	//virtual bool Receive( ComponentMessage * msg );

	//Variables
	u16 * m_buttonsHeld;
	u16 * m_buttonsDown;
	u16 * m_buttonsUp;
	u16 * m_wButtonsHeld;
	u16 * m_wButtonsDown;
	u16 * m_wButtonsUp;
	float * m_swing;
	float * m_wPitch;
	float * m_deviation;
	float * m_wRoll;
};
#endif /*CONTROLLABLECOMPONENT_H_*/