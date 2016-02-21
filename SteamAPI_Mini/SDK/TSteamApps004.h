#include "..\OSW\ISteamApps004.h"

class TSteamApps004 : ISteamApps004
{
public:
	TSteamApps004(ISteamApps004* SteamApps)
	{
		pOrig = SteamApps;
		WCHAR szBuff[256];
		GetPrivateProfileString(L"Setting", L"Language", L"english", szBuff, 128, szProfile);
		int size = lstrlen(szBuff);
		for (int i = 0; i < size; i++)
			szLanguage[i] = (BYTE)szBuff[i];
		szLanguage[size] = 0;
		WCHAR szSection[0x7FFF] = {0}, *Ptr = szSection;
		GetPrivateProfileSection(L"DLC", szSection, 0x7FFF, szProfile);
		for (int i = 0; *Ptr != 0; i++) {
			swscanf_s(Ptr, L"%d=%[^\n]", &iDLCArray[i], szBuff, 256);
			szDLCArray[i] = new char [256];
			int size = lstrlen(szBuff);
			for (int j = 0; j < size; j++)
				szDLCArray[i][j] = (BYTE)szBuff[j];
			Ptr += lstrlen(Ptr) + 1;
			iDLCCount = i + 1;
		}
	}

	bool BIsSubscribed() {
		return true;
	}
	bool BIsLowViolence() {
		return pOrig->BIsLowViolence();
	}
	bool BIsCybercafe() {
		return pOrig->BIsCybercafe();
	}
	bool BIsVACBanned() {
		return pOrig->BIsVACBanned();
	}
	const char *GetCurrentGameLanguage() {
		return szLanguage;
	}
	const char *GetAvailableGameLanguages() {
		return pOrig->GetAvailableGameLanguages();
	}
	bool BIsSubscribedApp(AppId_t nAppID) {
		return true;
	}
	bool BIsDlcInstalled(AppId_t nAppID) {
		return true;
	}
	uint32 GetEarliestPurchaseUnixTime(AppId_t nAppID) {
		return pOrig->GetEarliestPurchaseUnixTime(nAppID);
	}
	bool BIsSubscribedFromFreeWeekend() {
		return pOrig->BIsSubscribedFromFreeWeekend();
	}
	int GetDLCCount() {
		return iDLCCount;
	}
	bool BGetDLCDataByIndex(int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize) {
		*pAppID = iDLCArray[iDLC];
		*pbAvailable = true;
		strcpy_s(pchName, cchNameBufferSize, szDLCArray[iDLC]);
		return true;
	}
	void InstallDLC(AppId_t nAppID) {
		pOrig->InstallDLC(nAppID);
	}
	void UninstallDLC(AppId_t nAppID) {
		pOrig->UninstallDLC(nAppID);
	}
private:
	ISteamApps004* pOrig;
	char szLanguage[128];
	LPSTR szDLCArray[256];
	int iDLCCount, iDLCArray[256];
};