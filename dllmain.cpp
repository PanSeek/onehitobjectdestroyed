#include <windows.h>

struct stMain {
	stMain() {
		VirtualProtect(reinterpret_cast<LPVOID>(0x5A0E1E), 0x2, PAGE_READWRITE, &oldProt);
		memset(reinterpret_cast<void*>(0x5A0E1E), 0x90, 0x2);
		VirtualProtect(reinterpret_cast<LPVOID>(0x5A0E1E), 0x2, oldProt, &oldProt);
	};
	~stMain() {
		VirtualProtect(reinterpret_cast<LPVOID>(0x5A0E1E), 0x2, PAGE_READWRITE, &oldProt);
		memcpy(reinterpret_cast<void*>(0x5A0E1E), "\x7A\x06", 0x2);
		VirtualProtect(reinterpret_cast<LPVOID>(0x5A0E1E), 0x2, oldProt, &oldProt);
	};
	DWORD oldProt;
} plugin;
