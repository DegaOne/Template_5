#ifndef DEBUGSYSTEM_H_
#define DEBUGSYSTEM_H_

#include "System/System.h"
#include "System/GraphicSystem.h"
#include "FreeTypeGX.h"
#include <vector>

//Holds a queue of strings running down the screen depending on their position of the queue.
//The queue should be of limited size and delete last member when it exceeds its size
//Rendering of this text queue should be ruled by m_isEnabled; So this is mainly for Debug logging
//For breakpoint like behaviour, if need to pinpoint crashes, use exit(0).
class DebugSystem : public System {
	private:
	/*Here will be the instance stored*/
	static DebugSystem* m_instance;
	/*Private constructor to prevent instancing*/
	DebugSystem();
	public:
	~DebugSystem();
	//Singleton
	static DebugSystem* GetInstance();	
	//Funcs
	void Initialize();
	void SetFontTransform(GraphicSystem* gs);
	void AddLog(std::wstring log);
	void Update( float dt );
	//Render logs at right height, using freetypeGX
	void Render();
	
	//Variables
	bool m_isEnabled;
	//Debug font
	FreeTypeGX * m_debugFont;
	std::vector < std::wstring > m_stringLogs;
};

#endif /*DEBUGSYSTEM_H_*/