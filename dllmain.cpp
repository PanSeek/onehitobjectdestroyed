#include <Windows.h>
#include "MinHook.h"

typedef void(__cdecl* CTimer__Update) ();
CTimer__Update oldCTimerHook = NULL;

auto __cdecl hk_CTimer__Update(void) -> void {
	DWORD oldProt;
	VirtualProtect(reinterpret_cast<LPVOID>(0x005A0E1E), 8, PAGE_READWRITE, &oldProt);
	memset(reinterpret_cast<void*>(0x005A0E1E), 0x90, 0x2);
	VirtualProtect(reinterpret_cast<LPVOID>(0x005A0E1E), 8, oldProt, &oldProt);
	return oldCTimerHook();
}

class CMain {
public:
	CMain() {
		MH_Initialize();
		MH_CreateHook(reinterpret_cast<void*>(0x561B10), &hk_CTimer__Update, reinterpret_cast<void**>(&oldCTimerHook));
		MH_EnableHook(reinterpret_cast<void*>(0x561B10));
	};
	~CMain() {
		MH_Uninitialize();
	};
}; CMain plugin;
