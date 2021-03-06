#ifndef PADSYSTEM_H_
#define PADSYSTEM_H_

#include "System/System.h"
#include <ogc/pad.h>
#include <wiiuse/wpad.h>

class PadSystem : public System {
	private:
	/*Here will be the instance stored*/
	static PadSystem* m_instance;
	/*Private constructor to prevent instancing*/
	PadSystem();
	public:
	~PadSystem();
	//Singleton
	static PadSystem* GetInstance();
	//Funcs
	//Events
	virtual void Initialize();
	virtual void Update( float dt ); 
	void SendMessage(ComponentMessage msg);
	//Utility
	void ScanPads(int controller);

	//Variables
	//@Logic components point to these variables
	WPADData m_data;
	u16 m_buttonsHeld, m_buttonsDown, m_buttonsUp;
	u16 m_wButtonsHeld, m_wButtonsDown, m_wButtonsUp;
	/*//From "PAD.H"
	u32 PAD_Init(void);
	u32 PAD_Sync(void);
	u32 PAD_Read(PADStatus *status);
	u32 PAD_Reset(u32 mask);
	u32 PAD_Recalibrate(u32 mask);
	void PAD_Clamp(PADStatus *status);
	void PAD_ControlMotor(s32 chan,u32 cmd);
	void PAD_SetSpec(u32 spec);

	u32 PAD_ScanPads(void);

	u16 PAD_ButtonsUp(int pad);
	u16 PAD_ButtonsDown(int pad);
	u16 PAD_ButtonsHeld(int pad);

	s8 PAD_SubStickX(int pad);
	s8 PAD_SubStickY(int pad);

	s8 PAD_StickX(int pad);
	s8 PAD_StickY(int pad);

	u8 PAD_TriggerL(int pad);
	u8 PAD_TriggerR(int pad);
	*/

};
#endif /*PADSYSTEM_H_*/
