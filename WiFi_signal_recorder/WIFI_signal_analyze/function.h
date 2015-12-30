#pragma once
#define SSIDInfoMAX 256
#define RecordCountMAX 65536

#define CheckCell 0
#define MacCell 1
#define SSIDCell 2
#define RSSICell 3
#define SSCell 4
#define ChannelCell 5
#define AuthCell 6
#define DataRateCell 7
#define ColorCell 8


struct stSSIDInfo{
	char cMACaddr[24];
	char cSSID[128];
	unsigned long ulSignalCurrent;
	long lRSSICurrent;
	unsigned long ulSignalRecord[RecordCountMAX];
	long lRSSIRecord[RecordCountMAX];

	int iSecurity;
	bool bConnected;

	double dDataRate;
	unsigned long ulCenterFrequency;
	
	int iRGB[3];
	bool bShowSeries;
};