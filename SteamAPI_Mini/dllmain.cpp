#include <stdio.h>
#include <Windows.h>
#include "GetValveAPI.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserve)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{	
		// Fetching SteamApps Interface Version
		auto lpByte = (LPSTR)GetValveAPI();
		while (1) {
			if (memcmp(lpByte, "STEAMAPPS_INTERFACE", 19) == 0) {
				sscanf_s(lpByte, "STEAMAPPS_INTERFACE_VERSION%03d", &dwSteamApps);
				break;
			}
			lpByte++;
		}

		// Setting Current Game Language
		WCHAR szProfile[MAX_PATH];
		GetModuleFileName(hModule, szProfile, MAX_PATH);
		for (int i = lstrlen(szProfile); i > 0; i--) {
			if (szProfile[i] == L'\\') {
				szProfile[i] = L'\0';
				break;
			}
		}
		lstrcat(szProfile, L"\\steam_api.ini");
		if (GetFileAttributes(szProfile) == INVALID_FILE_ATTRIBUTES) {
			MessageBox(NULL, L"Cannot find steam_api.ini", L"SteamAPI", MB_ICONERROR);
			ExitProcess(0);
		}
		WCHAR szLangU[128] = {0};
		GetPrivateProfileString(L"Setting", L"Language", L"english", szLangU, 128, szProfile);
		for (int i = 0; i < lstrlen(szLangU); i++)
			szLang[i] = (BYTE)szLangU[i];

		// Fetching DLC Ids And Name
		auto lpBuff = new WCHAR [30720], pBuff = lpBuff;
		memset(lpBuff, 0, 30720);
		GetPrivateProfileSection(L"DLC", lpBuff, 30720, szProfile);
		for (int i = 0; i < 256; i++) {
			if (*lpBuff == 0) {
				dwNumOfDLC = i;
				break;
			}
			WCHAR szName[256] = {0};
			swscanf_s(lpBuff, L"%d=%[^\x0]", &dwDLCArray[i], szName, 256);
			DWORD dwSize = lstrlen(szName) + 1;
			lpDLCArray[i] = new char [dwSize];
			memset(lpDLCArray[i], 0, dwSize);
			for (UINT j = 0; j < dwSize; j++)
				lpDLCArray[i][j] = (BYTE)szName[j];
			lpBuff += lstrlen(lpBuff) + 1;
		}
		delete [] pBuff;
	}
	return TRUE;
}