#include <Windows.h>

LPVOID TSteamApps;
FARPROC fpAddress[62];
CHAR szLang[128], *lpDLCArray[256];
DWORD dwSteamApps, dwNumOfDLC, dwDLCArray[256];

#include "TSteamApps002.h"
#include "TSteamApps003.h"
#include "TSteamApps004.h"
#include "TSteamApps005.h"
#include "TSteamApps006.h"
#include "TSteamApps007.h"

void HookSteamApps()
{
	// Using Custom SteamApps Version
	switch (dwSteamApps)
	{
	case 2 :
		TSteamApps = new TSteamApps002;
		((TSteamApps002*)TSteamApps)->SteamApps = (ISteamApps002*)fpAddress[21]();
		break;
	case 3 :
		TSteamApps = new TSteamApps003;
		((TSteamApps003*)TSteamApps)->SteamApps = (ISteamApps003*)fpAddress[21]();
		break;
	case 4 :
		TSteamApps = new TSteamApps004;
		((TSteamApps004*)TSteamApps)->SteamApps = (ISteamApps004*)fpAddress[21]();
		break;
	case 5 :
		TSteamApps = new TSteamApps005;
		((TSteamApps005*)TSteamApps)->SteamApps = (ISteamApps005*)fpAddress[21]();
		break;
	case 6 :
		TSteamApps = new TSteamApps006;
		((TSteamApps006*)TSteamApps)->SteamApps = (ISteamApps006*)fpAddress[21]();
		break;
	case 7 :
		TSteamApps = new TSteamApps006;
		((TSteamApps006*)TSteamApps)->SteamApps = (ISteamApps006*)fpAddress[21]();
		break;
	}
}