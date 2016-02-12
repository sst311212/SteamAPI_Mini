#include "steam\ISteamApps002.h"

class TSteamApps002 : ISteamApps002
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
	ISteamApps002* SteamApps;
};