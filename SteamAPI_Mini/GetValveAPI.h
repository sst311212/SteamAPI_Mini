#include <Windows.h>
#include "HSteamApps.h"

HMODULE GetValveAPI() {
	// Search All Export Table By Itself
#ifdef _WIN64
	HMODULE hModule = GetModuleHandle(L"steam_api64.dll");
	HMODULE hValve = LoadLibrary(L"ValveAPI64.dll");
	auto dwBaseAddr = (DWORD64)hModule;
#else
	HMODULE hModule = GetModuleHandle(L"steam_api.dll");
	HMODULE hValve = LoadLibrary(L"ValveAPI.dll");
	auto dwBaseAddr = (DWORD)hModule;
#endif
	auto pIDH = (PIMAGE_DOS_HEADER)dwBaseAddr;
	auto pINH = (PIMAGE_NT_HEADERS)(dwBaseAddr + pIDH->e_lfanew);
	auto pIED = (PIMAGE_EXPORT_DIRECTORY)(dwBaseAddr + pINH->OptionalHeader.DataDirectory[0].VirtualAddress);
	auto lpLibNameAddr = (PDWORD)(dwBaseAddr + pIED->AddressOfNames);
	for (UINT i = 0; i < pIED->NumberOfNames; i++) {
		auto lpLibName = (LPSTR)(dwBaseAddr + *lpLibNameAddr);
		fpAddress[i] = GetProcAddress(hValve, lpLibName);
		lpLibNameAddr += 1;
	}
	return hValve;
}

#define DLLEXPORT extern "C" __declspec(dllexport)

DLLEXPORT void GetHSteamPipe() { fpAddress[0](); };
DLLEXPORT void GetHSteamUser() { fpAddress[1](); };
DLLEXPORT void SteamAPI_GetHSteamPipe() { fpAddress[2](); };
DLLEXPORT void SteamAPI_GetHSteamUser() { fpAddress[3](); };
DLLEXPORT void SteamAPI_GetSteamInstallPath() { fpAddress[4](); };

DLLEXPORT bool SteamAPI_Init()
{
	bool dwReturn = fpAddress[5]();
	if (!dwReturn) {
		MessageBox(NULL, L"Please start Steam", L"SteamAPI", MB_ICONERROR);
		ExitProcess(0);
	}
	HookSteamApps();
	return dwReturn;
};

DLLEXPORT void SteamAPI_InitSafe() { fpAddress[6](); };
DLLEXPORT void SteamAPI_IsSteamRunning() { fpAddress[7](); };
DLLEXPORT void SteamAPI_RegisterCallResult() { fpAddress[8](); };
DLLEXPORT void SteamAPI_RegisterCallback() { fpAddress[9](); };
DLLEXPORT void SteamAPI_RestartAppIfNecessary() { fpAddress[10](); };
DLLEXPORT void SteamAPI_RunCallbacks() { fpAddress[11](); };
DLLEXPORT void SteamAPI_SetBreakpadAppID() { fpAddress[12](); };
DLLEXPORT void SteamAPI_SetMiniDumpComment() { fpAddress[13](); };
DLLEXPORT void SteamAPI_SetTryCatchCallbacks() { fpAddress[14](); };
DLLEXPORT void SteamAPI_Shutdown() { fpAddress[15](); };
DLLEXPORT void SteamAPI_UnregisterCallResult() { fpAddress[16](); };
DLLEXPORT void SteamAPI_UnregisterCallback() { fpAddress[17](); };
DLLEXPORT void SteamAPI_UseBreakpadCrashHandler() { fpAddress[18](); };
DLLEXPORT void SteamAPI_WriteMiniDump() { fpAddress[19](); };
DLLEXPORT void SteamAppList() { fpAddress[20](); };
DLLEXPORT void* SteamApps() { return TSteamApps; };
DLLEXPORT void SteamClient() { fpAddress[22](); };
DLLEXPORT void SteamController() { fpAddress[23](); };
DLLEXPORT void SteamFriends() { fpAddress[24](); };
DLLEXPORT void SteamGameServer() { fpAddress[25](); };
DLLEXPORT void SteamGameServerApps() { fpAddress[26](); };
DLLEXPORT void SteamGameServerHTTP() { fpAddress[27](); };
DLLEXPORT void SteamGameServerInventory() { fpAddress[28](); };
DLLEXPORT void SteamGameServerNetworking() { fpAddress[29](); };
DLLEXPORT void SteamGameServerStats() { fpAddress[30](); };
DLLEXPORT void SteamGameServerUGC() { fpAddress[31](); };
DLLEXPORT void SteamGameServerUtils() { fpAddress[32](); };
DLLEXPORT void SteamGameServer_BSecure() { fpAddress[33](); };
DLLEXPORT void SteamGameServer_GetHSteamPipe() { fpAddress[34](); };
DLLEXPORT void SteamGameServer_GetHSteamUser() { fpAddress[35](); };
DLLEXPORT void SteamGameServer_GetIPCCallCount() { fpAddress[36](); };
DLLEXPORT void SteamGameServer_GetSteamID() { fpAddress[37](); };
DLLEXPORT void SteamGameServer_Init() { fpAddress[38](); };
DLLEXPORT void SteamGameServer_InitSafe() { fpAddress[39](); };
DLLEXPORT void SteamGameServer_RunCallbacks() { fpAddress[40](); };
DLLEXPORT void SteamGameServer_Shutdown() { fpAddress[41](); };
DLLEXPORT void SteamHTMLSurface() { fpAddress[42](); };
DLLEXPORT void SteamHTTP() { fpAddress[43](); };
DLLEXPORT void SteamInventory() { fpAddress[44](); };
DLLEXPORT void SteamMatchmaking() { fpAddress[45](); };
DLLEXPORT void SteamMatchmakingServers() { fpAddress[46](); };
DLLEXPORT void SteamMusic() { fpAddress[47](); };
DLLEXPORT void SteamMusicRemote() { fpAddress[48](); };
DLLEXPORT void SteamNetworking() { fpAddress[49](); };
DLLEXPORT void SteamRemoteStorage() { fpAddress[50](); };
DLLEXPORT void SteamScreenshots() { fpAddress[51](); };
DLLEXPORT void SteamUGC() { fpAddress[52](); };
DLLEXPORT void SteamUnifiedMessages() { fpAddress[53](); };
DLLEXPORT void SteamUser() { fpAddress[54](); };
DLLEXPORT void SteamUserStats() { fpAddress[55](); };
DLLEXPORT void SteamUtils() { fpAddress[56](); };
DLLEXPORT void SteamVideo() { fpAddress[57](); };
DLLEXPORT void Steam_GetHSteamUserCurrent() { fpAddress[58](); };
DLLEXPORT void Steam_RegisterInterfaceFuncs() { fpAddress[59](); };
DLLEXPORT void Steam_RunCallbacks() { fpAddress[60](); };
DLLEXPORT void g_pSteamClientGameServer() { fpAddress[61](); };
