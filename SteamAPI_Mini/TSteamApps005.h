#include "steam\ISteamApps005.h"

class TSteamApps005 : ISteamApps005
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
	uint32 GetEarliestPurchaseUnixTime(AppId_t nAppID) {
		return SteamApps->GetEarliestPurchaseUnixTime(nAppID);
	}
	bool BIsSubscribedFromFreeWeekend() {
		return SteamApps->BIsSubscribedFromFreeWeekend();
	}
	int GetDLCCount() {
		extern DWORD dwNumOfDLC;
		return dwNumOfDLC;
	}
	bool BGetDLCDataByIndex(int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize) {
		extern DWORD dwDLCArray[256];
		extern CHAR *lpDLCArray[256];
		*pAppID = dwDLCArray[iDLC];
		*pbAvailable = true;
		strcpy_s(pchName, cchNameBufferSize, lpDLCArray[iDLC]);
		return true;
	}
	void InstallDLC(AppId_t nAppID) {
		SteamApps->InstallDLC(nAppID);
	}
	void UninstallDLC(AppId_t nAppID) {
		SteamApps->UninstallDLC(nAppID);
	}
	void RequestAppProofOfPurchaseKey(AppId_t nAppID) {
		SteamApps->RequestAppProofOfPurchaseKey(nAppID);
	}
	bool GetCurrentBetaName(char *pchName, int cchNameBufferSize) {
		return SteamApps->GetCurrentBetaName(pchName, cchNameBufferSize);
	}
	bool MarkContentCorrupt(bool bMissingFilesOnly) {
		return SteamApps->MarkContentCorrupt(bMissingFilesOnly);
	}
	uint32 GetInstalledDepots( DepotId_t *pvecDepots, uint32 cMaxDepots ) {
		return SteamApps->GetInstalledDepots(pvecDepots, cMaxDepots);
	}
	uint32 GetAppInstallDir(AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize) {
		return SteamApps->GetAppInstallDir(appID, pchFolder, cchFolderBufferSize);
	}
	bool BIsAppInstalled(AppId_t appID) {
		return TRUE;
	}
	ISteamApps005* SteamApps;
};