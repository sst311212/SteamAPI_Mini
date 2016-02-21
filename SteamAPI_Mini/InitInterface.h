#include "SDK\TSteamApps002.h"
#include "SDK\TSteamApps003.h"
#include "SDK\TSteamApps004.h"
#include "SDK\TSteamApps005.h"
#include "SDK\TSteamApps006.h"
#include "SDK\TSteamApps007.h"

LPVOID TSteamApps;

void InitInterface()
{
	switch (iSteamApps)
	{
	case 2 :
		TSteamApps = new TSteamApps002((ISteamApps002*)fpApiAddr[659]());
		break;
	case 3 :
		TSteamApps = new TSteamApps003((ISteamApps003*)fpApiAddr[659]());
		break;
	case 4 :
		TSteamApps = new TSteamApps004((ISteamApps004*)fpApiAddr[659]());
		break;
	case 5 :
		TSteamApps = new TSteamApps005((ISteamApps005*)fpApiAddr[659]());
		break;
	case 6 :
		TSteamApps = new TSteamApps006((ISteamApps006*)fpApiAddr[659]());
		break;
	case 7 :
		TSteamApps = new TSteamApps007((ISteamApps007*)fpApiAddr[659]());
		break;
	}
}