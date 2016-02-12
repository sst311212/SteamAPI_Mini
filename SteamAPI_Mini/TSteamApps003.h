#include "steam\ISteamApps003.h"

class TSteamApps003 : ISteamApps003
{
public:
	bool BIsSubscribed() {
		return TRUE;
	}
	bool BIsLowViolence() {
		return SteamApps->BIsLowViolence();
	}
	bool BIsCybercafe() {
		return SteamApps->BIsCybercafe();
	}
	bool BIsVACBanned() {
		return SteamApps->BIsVACBanned();
	}
	const char *GetCurrentGameLanguage() {
		extern CHAR szLang[128];
		return szLang;
	}
	const char *GetAvailableGameLanguages() {
		return SteamApps->GetAvailableGameLanguages();
	}
	bool BIsSubscribedApp(AppId_t nAppID) {
		return TRUE;
	}
	bool BIsDlcInstalled(AppId_t nAppID) {
		return TRUE;
	}
	ISteamApps003* SteamApps;
};