#include "..\OSW\ISteamApps006.h"

class TSteamApps006 : ISteamApps006
{
public:
	TSteamApps006(ISteamApps006* SteamApps)
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
	void RequestAppProofOfPurchaseKey(AppId_t nAppID) {
		pOrig->RequestAppProofOfPurchaseKey(nAppID);
	}
	bool GetCurrentBetaName(char *pchName, int cchNameBufferSize) {
		return pOrig->GetCurrentBetaName(pchName, cchNameBufferSize);
	}
	bool MarkContentCorrupt(bool bMissingFilesOnly) {
		return pOrig->MarkContentCorrupt(bMissingFilesOnly);
	}
	uint32 GetInstalledDepots(AppId_t appID, DepotId_t *pvecDepots, uint32 cMaxDepots) {
		return pOrig->GetInstalledDepots(appID, pvecDepots, cMaxDepots);
	}
	uint32 GetAppInstallDir(AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize) {
		return pOrig->GetAppInstallDir(appID, pchFolder, cchFolderBufferSize);
	}
	bool BIsAppInstalled(AppId_t appID) {
		return true;
	}
	CSteamID GetAppOwner() {
		return pOrig->GetAppOwner();
	}
	const char *GetLaunchQueryParam(const char *pchKey) {
		return pOrig->GetLaunchQueryParam(pchKey);
	}
	bool GetDlcDownloadProgress( AppId_t nAppID, uint64 *punBytesDownloaded, uint64 *punBytesTotal ) {
		return pOrig->GetDlcDownloadProgress(nAppID, punBytesDownloaded, punBytesTotal);
	}
private:
	ISteamApps006* pOrig;
	char szLanguage[128];
	LPSTR szDLCArray[256];
	int iDLCCount, iDLCArray[256];
};