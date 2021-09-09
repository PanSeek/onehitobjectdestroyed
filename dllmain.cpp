#include <Windows.h>

class CMain {
public:
	CMain() {
		VirtualProtect(reinterpret_cast<LPVOID>(0x005A0E1E), 2, PAGE_READWRITE, &oldProt);
		memset(reinterpret_cast<void*>(0x005A0E1E), 0x90, 0x2);
		VirtualProtect(reinterpret_cast<LPVOID>(0x005A0E1E), 2, oldProt, &oldProt);
	};
	~CMain() {
		VirtualProtect(reinterpret_cast<LPVOID>(0x005A0E1E), 2, PAGE_READWRITE, &oldProt);
		memcpy(reinterpret_cast<void*>(0x005A0E1E), "\x7A\x06", 0x2);
		VirtualProtect(reinterpret_cast<LPVOID>(0x005A0E1E), 2, oldProt, &oldProt);
	};
	DWORD oldProt;
}; CMain plugin;
