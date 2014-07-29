// Skype Quote Generator
// Author: Carson Williams

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	if (OpenClipboard(NULL))
	{
		char *toSet = "<quote author=\"0\" authorname=\"Brandon Stewart\" conversation=\"0\" guid=\"x\" timestamp=\"0\">IM SO FANCY</quote>\0";
		UINT skypeformat = RegisterClipboardFormat(_T("SkypeMessageFragment"));
		int len = strlen(toSet);
		HGLOBAL gMem = GlobalAlloc(GMEM_DDESHARE, len);
		GlobalLock(gMem);
		memcpy(gMem, toSet, len);
		GlobalUnlock(gMem);
		SetClipboardData(skypeformat, gMem);
		CloseClipboard();
	}
	return 0;
}
