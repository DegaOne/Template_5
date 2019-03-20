#include "System/PadSystem.h"
#include "System/ObjectSystem.h"
#include "System/PhysicSystem.h"
#include "System/GraphicSystem.h"

//Instance
PadSystem * PadSystem::m_instance = NULL;
PadSystem * PadSystem::GetInstance()
{
	//Singleton
	if (m_instance == NULL)
	{
		m_instance = new PadSystem();
	}
	return m_instance;
}
//Constructor
PadSystem::PadSystem() {
	m_buttonsHeld = 0;
	m_buttonsUp = 0;
	m_buttonsDown = 0;

	m_wButtonsHeld = 0;
	m_wButtonsUp = 0;
	m_wButtonsDown = 0;

	//INPUT
	PAD_Init();
	WPAD_Init();
}
//Destructor
PadSystem::~PadSystem(){
	m_buttonsHeld = 0;
	m_buttonsUp = 0;
	m_buttonsDown = 0;
}	
//Init
void PadSystem::Initialize() {
	//Initialize LogicComponents;
	std::vector <LogicComponent *> logicComponents = ObjectSystem::GetInstance()->GetLogicComponentList();
	for (u16 i = 0; i < logicComponents.size(); i++){
		logicComponents[i]->OnStart();
	}
}
//Update
void PadSystem::Update( float dt ){
	//Scan input
	ScanPads(0);

	//Systems it may interact with:
	GraphicSystem * gs = GraphicSystem::GetInstance();
	ObjectSystem * os = ObjectSystem::GetInstance();
	PhysicSystem * ps = PhysicSystem::GetInstance();
	
	std::vector <LogicComponent *> logicComponents = os->GetLogicComponentList();
	
	//@Generic input
	if ( m_buttonsDown & PAD_BUTTON_X){
		gs->m_debug = !gs->m_debug;
	}
	if ( m_buttonsDown & PAD_BUTTON_Y ){
		ps->m_stepMode = !ps->m_stepMode;
	}
	if ( m_buttonsDown & PAD_TRIGGER_Z ){
		ps->m_stepOnce = true;
	}

	//@Update logic components
	for (u16 i = 0; i < logicComponents.size(); i++){
		LogicComponent * logic = logicComponents[i];
		logic->ComputeLogic(dt);
	}
}
//@Messaging
void PadSystem::SendMessage(ComponentMessage msg){
	//@Catch Player_Scored message
	if (msg == ComponentMessage::PLAYER_SCORED){
		//Get all logic components, find the one that's the player controller
		
	}
}
//Utility
//Scan
void PadSystem::ScanPads(int controller) {
	PAD_ScanPads();
	m_buttonsHeld = PAD_ButtonsHeld(controller);
	m_buttonsDown = PAD_ButtonsDown(controller);
	m_buttonsUp = PAD_ButtonsUp(controller);
}