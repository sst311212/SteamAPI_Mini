#include "..\OSW\ISteamApps003.h"

class TSteamApps003 : ISteamApps003
{
public:
	TSteamApps003(ISteamApps003* SteamApps)
	{
		pOrig = SteamApps;
		WCHAR szBuff[128];
		GetPrivateProfileString(L"Setting", L"Language", L"english", szBuff, 128, szProfile);
		int size = lstrlen(szBuff);
		for (int i = 0; i < size; i++)
			szLanguage[i] = (BYTE)szBuff[i];
		szLanguage[size] = 0;
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
private:
	ISteamApps003* pOrig;
	char szLanguage[128];
};