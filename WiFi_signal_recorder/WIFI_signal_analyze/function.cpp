#include "stdafx.h"

#include"Form1.h"

#include"function.h"

#define _WIN32_DCOM

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <wlanapi.h>
#include <objbase.h>
#include <wtypes.h>

#pragma comment(lib,"wlanapi.lib")


DWORD dwClientVersion = 2;
// 1 :Client version for Windows XP with SP3 and Wireless LAN API for Windows XP with SP2.
// 2 :Client version for Windows Vista and Windows Server 2008
int Datagridwidth;
int selected_comboBox;
struct stSSIDInfo stSSIDInfoList[SSIDInfoMAX];


HANDLE hClientHandle = NULL;
PWLAN_INTERFACE_INFO_LIST pInterfaceList = NULL;

using namespace WIFI_signal_analyze;
using namespace std;

namespace WIFI_signal_analyze 
{
	#pragma region 
	bool Form1::ScanSSID()
	{
		int count=0;

		DWORD dwResult = 0;

		PVOID pReserved = NULL;
		PWLAN_BSS_LIST pWlanBssList = NULL;
		PWLAN_AVAILABLE_NETWORK_LIST pAvailableNetworkList = NULL;
		DOT11_SSID dot11Ssid = {0};

		//dot11_BSS_type_infrastructure - An infrastructure BSS network. 
		//dot11_BSS_type_independent - An independent BSS (IBSS) network (an ad hoc network). 
		//dot11_BSS_type_any - Any BSS network.
		DOT11_BSS_TYPE dot11BssType = dot11_BSS_type_any;

		this->chart1->Series->Clear();
		this->dataGridView1->Enabled = true;
		this->dataGridView1->Rows->Clear();

		selected_comboBox = (int)this->comboBox1->SelectedIndex;
		if (selected_comboBox == -1)  selected_comboBox = 0;
		//showlog(selected_comboBox.ToString());

		dwResult = WlanScan(hClientHandle, &pInterfaceList->InterfaceInfo[selected_comboBox].InterfaceGuid ,NULL,NULL,NULL);
		if (dwResult != ERROR_SUCCESS) 
		{    
			showlog("something is wrong with WlanScan()\n");
			return false;
		}
		delay(2);
		
		dwResult = WlanGetNetworkBssList(hClientHandle, &pInterfaceList->InterfaceInfo[selected_comboBox].InterfaceGuid, NULL, dot11BssType, FALSE, pReserved, &pWlanBssList);

		if(dwResult!=ERROR_SUCCESS)
		{
			showlog("something is wrong with WlanGetNetworkBssList()\n");
			return false;
		}
		//showlog(pWlanBssList->dwNumberOfItems.ToString());

		dwResult = WlanGetAvailableNetworkList(hClientHandle, &pInterfaceList->InterfaceInfo[selected_comboBox].InterfaceGuid, WLAN_AVAILABLE_NETWORK_INCLUDE_ALL_MANUAL_HIDDEN_PROFILES, pReserved, &pAvailableNetworkList); 
		if(dwResult!=ERROR_SUCCESS)
		{
		  showlog("something is wrong with WlanGetAvailableNetworkList()\n");
		  return false;
		}
		//showlog(pAvailableNetworkList->dwNumberOfItems.ToString());

		if(pWlanBssList->dwNumberOfItems > 1) 
			this->dataGridView1->Rows->Add(pWlanBssList->dwNumberOfItems-1);

		for (int x=0; x<SSIDInfoMAX ;x++) 
		{
			memset(stSSIDInfoList[x].cMACaddr, 0,sizeof(stSSIDInfoList[x].cMACaddr));
			memset(stSSIDInfoList[x].cSSID, 0,sizeof(stSSIDInfoList[x].cSSID));
			memset(stSSIDInfoList[x].lRSSIRecord, 0,sizeof(stSSIDInfoList[x].lRSSIRecord));
			memset(stSSIDInfoList[x].ulSignalRecord, 0,sizeof(stSSIDInfoList[x].ulSignalRecord));
			stSSIDInfoList[count].dDataRate = 0;
			stSSIDInfoList[x].ulCenterFrequency = 0;
			stSSIDInfoList[x].iSecurity = 0;
			stSSIDInfoList[x].bConnected = false;
		}

		for (count=0;count < pWlanBssList->dwNumberOfItems;count++)
		{			
			sprintf(stSSIDInfoList[count].cMACaddr, "%02x%02x%02x%02x%02x%02x", pWlanBssList->wlanBssEntries[count].dot11Bssid[0], pWlanBssList->wlanBssEntries[count].dot11Bssid[1], pWlanBssList->wlanBssEntries[count].dot11Bssid[2], pWlanBssList->wlanBssEntries[count].dot11Bssid[3], pWlanBssList->wlanBssEntries[count].dot11Bssid[4], pWlanBssList->wlanBssEntries[count].dot11Bssid[5]);
			sprintf(stSSIDInfoList[count].cSSID, "%s", pWlanBssList->wlanBssEntries[count].dot11Ssid.ucSSID);
			stSSIDInfoList[count].lRSSICurrent = pWlanBssList->wlanBssEntries[count].lRssi; 
			stSSIDInfoList[count].ulSignalCurrent = pWlanBssList->wlanBssEntries[count].uLinkQuality;
			stSSIDInfoList[count].ulCenterFrequency = pWlanBssList->wlanBssEntries[count].ulChCenterFrequency;

			for (int y=0; y<3 ;y++)
			{
				stSSIDInfoList[count].iRGB[y] = rand()%255;
			}

			for (int y=0; y< pAvailableNetworkList->dwNumberOfItems; y++)
			{
				if (strcmp ((const char*)pAvailableNetworkList->Network[y].dot11Ssid.ucSSID,  (const char*)pWlanBssList->wlanBssEntries[count].dot11Ssid.ucSSID) == 0)
				{
					stSSIDInfoList[count].iSecurity = pAvailableNetworkList->Network[y].dot11DefaultAuthAlgorithm;
					//showlog(stSSIDInfoList[count].iSecurity.ToString());
				}			
			}


			for(int z=0; z< pWlanBssList->wlanBssEntries[count].wlanRateSet.uRateSetLength; z++)
			{
				if ((pWlanBssList->wlanBssEntries[count].wlanRateSet.usRateSet[z] & 0x7FFF) * 0.5 >= stSSIDInfoList[count].dDataRate )
					stSSIDInfoList[count].dDataRate = (pWlanBssList->wlanBssEntries[count].wlanRateSet.usRateSet[z] & 0x7FFF) * 0.5;
			}


			this->dataGridView1->Rows[count]->Cells[CheckCell]->Value = true;
			this->dataGridView1->Rows[count]->Cells[MacCell]->Value = (gcnew String (stSSIDInfoList[count].cMACaddr))->ToUpper();
			this->dataGridView1->Rows[count]->Cells[SSIDCell]->Value = (gcnew String (stSSIDInfoList[count].cSSID));
			this->dataGridView1->Rows[count]->Cells[SSCell]->Value = (stSSIDInfoList[count].ulSignalCurrent.ToString());
			this->dataGridView1->Rows[count]->Cells[DataRateCell]->Value = (stSSIDInfoList[count].dDataRate.ToString());

			this->dataGridView1->Rows[count]->Cells[RSSICell]->Value = (stSSIDInfoList[count].lRSSICurrent.ToString());
			if (stSSIDInfoList[count].lRSSICurrent >= -55 )
				this->dataGridView1->Rows[count]->Cells[RSSICell]->Style->BackColor = Color::FromArgb(96,169,23);
			else if ( -75 <= stSSIDInfoList[count].lRSSICurrent && stSSIDInfoList[count].lRSSICurrent < -55 )
				this->dataGridView1->Rows[count]->Cells[RSSICell]->Style->BackColor = Color::FromArgb(164,196,0);
			else if ( -85 <= stSSIDInfoList[count].lRSSICurrent && stSSIDInfoList[count].lRSSICurrent < -75 )
				this->dataGridView1->Rows[count]->Cells[RSSICell]->Style->BackColor = Color::FromArgb(227,200,0);
			else if ( -96 <= stSSIDInfoList[count].lRSSICurrent && stSSIDInfoList[count].lRSSICurrent < -85 )
				this->dataGridView1->Rows[count]->Cells[RSSICell]->Style->BackColor = Color::FromArgb(229,20,0);
			else
				this->dataGridView1->Rows[count]->Cells[RSSICell]->Style->BackColor = Color::FromArgb(180,180,180);
			

			switch(stSSIDInfoList[count].ulCenterFrequency)
			{
				case 2412000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("1");
					break;
				case 2417000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("2");
					break;
				case 2422000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("3");
					break;
				case 2427000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("4");
					break;
				case 2432000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("5");
					break;
				case 2437000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("6");
					break;
				case 2442000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("7");
					break;
				case 2447000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("8");
					break;
				case 2452000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("9");
					break;
				case 2457000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("10");
					break;
				case 2462000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("11");
					break;
				case 2467000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("12");
					break;
				case 2472000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("13");
					break;
				case 2484000:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = ("14");
					break;
				default:
					this->dataGridView1->Rows[count]->Cells[ChannelCell]->Value = stSSIDInfoList[count].ulCenterFrequency/1000 + "Mhz";
			}


			switch(stSSIDInfoList[count].iSecurity)
			{
				case DOT11_AUTH_ALGO_80211_OPEN:
					this->dataGridView1->Rows[count]->Cells[AuthCell]->Value = ("OPEN");
					break;
				case DOT11_AUTH_ALGO_80211_SHARED_KEY:
					this->dataGridView1->Rows[count]->Cells[AuthCell]->Value = ("SHARED KEY");
					break;
				case DOT11_AUTH_ALGO_WPA:
					this->dataGridView1->Rows[count]->Cells[AuthCell]->Value = ("WPA");
					break;
				case DOT11_AUTH_ALGO_WPA_PSK:
					this->dataGridView1->Rows[count]->Cells[AuthCell]->Value = ("WPA-PSK");
					break;
				case DOT11_AUTH_ALGO_WPA_NONE:
					this->dataGridView1->Rows[count]->Cells[AuthCell]->Value = ("WPA-NONE");
					break;
				case DOT11_AUTH_ALGO_RSNA:
					this->dataGridView1->Rows[count]->Cells[AuthCell]->Value = ("WPA2");
					break;
				case DOT11_AUTH_ALGO_RSNA_PSK:
					this->dataGridView1->Rows[count]->Cells[AuthCell]->Value = ("WPA2-PSK");
					break;
				defalut:
					this->dataGridView1->Rows[count]->Cells[AuthCell]->Value = ("IHV");
					break;
			}

			stSSIDInfoList[count].bShowSeries = true;
		}
		return true;
	}


	bool Form1::AUTO_SCAN()
	{
		int Bsscount=0;
		int dataGridcount = 0;

		char cTmpMACaddr[24] = {0};

		char cTmpSSID[128] = {0};

		DWORD dwResult = 0;

		PVOID pReserved = NULL;

		PWLAN_BSS_LIST pWlanBssList = NULL;

		//dot11_BSS_type_infrastructure - An infrastructure BSS network. 
		//dot11_BSS_type_independent - An independent BSS (IBSS) network (an ad hoc network). 
		//dot11_BSS_type_any - Any BSS network.
		DOT11_BSS_TYPE dot11BssType = dot11_BSS_type_any;

		dwResult = WlanScan(hClientHandle, &pInterfaceList->InterfaceInfo[selected_comboBox].InterfaceGuid ,NULL,NULL,NULL);
		if (dwResult != ERROR_SUCCESS) 
		{    
			showlog("something is wrong with WlanScan()\n");
			return false;
		}

		delay(2);
		
		dwResult = WlanGetNetworkBssList(hClientHandle, &pInterfaceList->InterfaceInfo[selected_comboBox].InterfaceGuid, NULL, dot11BssType, FALSE, pReserved, &pWlanBssList);
		if(dwResult!=ERROR_SUCCESS)
		{
			showlog("something is wrong with WlanGetNetworkBssList()\n");
			return false;
		}


		//Save RSSI to array
		for (Bsscount=0;Bsscount < pWlanBssList->dwNumberOfItems;Bsscount++)
		{
			memset(cTmpMACaddr, 0, sizeof(cTmpMACaddr));
			sprintf(cTmpMACaddr, "%02x%02x%02x%02x%02x%02x", pWlanBssList->wlanBssEntries[Bsscount].dot11Bssid[0], pWlanBssList->wlanBssEntries[Bsscount].dot11Bssid[1], pWlanBssList->wlanBssEntries[Bsscount].dot11Bssid[2], pWlanBssList->wlanBssEntries[Bsscount].dot11Bssid[3], pWlanBssList->wlanBssEntries[Bsscount].dot11Bssid[4], pWlanBssList->wlanBssEntries[Bsscount].dot11Bssid[5]);

			for (int i=0; i<=this->dataGridView1->RowCount; i++)
			{

				if (strcmp(cTmpMACaddr, stSSIDInfoList[i].cMACaddr) == 0)
				{
					stSSIDInfoList[i].ulSignalCurrent  = pWlanBssList->wlanBssEntries[Bsscount].uLinkQuality;
					stSSIDInfoList[i].lRSSICurrent	   = pWlanBssList->wlanBssEntries[Bsscount].lRssi; 
					stSSIDInfoList[i].lRSSIRecord[0]   = stSSIDInfoList[i].lRSSICurrent;
					
					stSSIDInfoList[i].ulSignalRecord[0]= stSSIDInfoList[i].ulSignalCurrent;


					int j=RecordCountMAX;
					while(1)
					{
						if (j == 1 ) break; // array[0] is current
						stSSIDInfoList[i].lRSSIRecord[j-1]   = stSSIDInfoList[i].lRSSIRecord[j-2];
						stSSIDInfoList[i].ulSignalRecord[j-1]= stSSIDInfoList[i].ulSignalRecord[j-2];
						j--;
					}
				}

			}
		}


		return true;

	}


	int Form1::Chart_Refresh()
	{		
		int dataGridView_checked = 0;
		this->chart1->Series->Clear();

		for (int count=0; count < this->dataGridView1->RowCount; count++)
		{
			stSSIDInfoList[count].bShowSeries = (bool)this->dataGridView1->Rows[count]->Cells[CheckCell]->Value;

			if (stSSIDInfoList[count].bShowSeries)
			{
				int i = RecordCountMAX-1;
				String ^series = gcnew String(stSSIDInfoList[count].cMACaddr);
				
				this->chart1->Series->Add(series);
						
				this->chart1->Series[series]->ChartArea  = L"ChartArea1";
				this->chart1->Series[series]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
				this->chart1->Series[series]->Legend = L"Legend1";
				this->chart1->Series[series]->Name = series;
				this->chart1->Series[series]->LegendText = gcnew String(stSSIDInfoList[count].cSSID); //title
				this->chart1->Series[series]->BorderWidth = 3;
				this->chart1->Series[series]->Color = Color::FromArgb( stSSIDInfoList[count].iRGB[0], stSSIDInfoList[count].iRGB[1], stSSIDInfoList[count].iRGB[2] );
				this->chart1->Series[series]->Points->AddY(-100);
				
				while(1)
				{
					if (i < 0) break;

							
					if (stSSIDInfoList[count].lRSSIRecord[i] == NULL) 
					{
						i--;
						continue;
					}
					else
					{
						this->chart1->Series[series]->Points->AddY(stSSIDInfoList[count].lRSSIRecord[i]);
						i--;
					}
				}
			}
		}	
		return 0;
	}


	int Form1::DataGridView_Refresh()
	{
		int dataGridrowcount = this->dataGridView1->RowCount;

		for (int stSSID=0; stSSID < SSIDInfoMAX ; stSSID++)
		{
			
			for (int i=0; i < this->dataGridView1->RowCount; i++)
			{
				char cTmpMACaddr[24] = {0};
				sprintf(cTmpMACaddr, "%s", this->dataGridView1->Rows[i]->Cells[MacCell]->Value->ToString()->ToLower());

				if (strcmp(stSSIDInfoList[stSSID].cMACaddr, cTmpMACaddr) == 0)
				{
					this->dataGridView1->Rows[i]->Cells[RSSICell]->Value = (stSSIDInfoList[stSSID].lRSSICurrent.ToString());

					if (stSSIDInfoList[stSSID].lRSSICurrent >= -55 )
						this->dataGridView1->Rows[i]->Cells[RSSICell]->Style->BackColor = Color::FromArgb(96,169,23);
					else if ( -75 <= stSSIDInfoList[stSSID].lRSSICurrent && stSSIDInfoList[stSSID].lRSSICurrent < -55 )
						this->dataGridView1->Rows[i]->Cells[RSSICell]->Style->BackColor = Color::FromArgb(164,196,0);
					else if ( -85 <= stSSIDInfoList[stSSID].lRSSICurrent && stSSIDInfoList[stSSID].lRSSICurrent < -75 )
						this->dataGridView1->Rows[i]->Cells[RSSICell]->Style->BackColor = Color::FromArgb(227,200,0);
					else if ( -96 <= stSSIDInfoList[stSSID].lRSSICurrent && stSSIDInfoList[stSSID].lRSSICurrent < -85 )
						this->dataGridView1->Rows[i]->Cells[RSSICell]->Style->BackColor = Color::FromArgb(229,20,0);
					else
						this->dataGridView1->Rows[i]->Cells[RSSICell]->Style->BackColor = Color::FromArgb(180,180,180);

					this->dataGridView1->Rows[i]->Cells[SSCell]->Value = (stSSIDInfoList[stSSID].ulSignalCurrent.ToString());
					this->dataGridView1->Rows[i]->Cells[ColorCell]->Style->BackColor = Color::FromArgb(stSSIDInfoList[stSSID].iRGB[0], stSSIDInfoList[stSSID].iRGB[1], stSSIDInfoList[stSSID].iRGB[2]);
					break;
				}
			}
		}
		return 0;
	}


	bool Form1::set_interface()
	{
			DWORD dwResult = 0;

			PVOID pReserved = NULL;
			DWORD pdwNegotiatedVersion = 0;

			if (hClientHandle == NULL)
			{
				dwResult = WlanOpenHandle(dwClientVersion, pReserved, &pdwNegotiatedVersion, &hClientHandle);
				if(dwResult!=ERROR_SUCCESS)
				{
				  showlog("something is wrong with WlanOpenHndle()\n");
				  return false;
				}
			}
			
			dwResult = WlanEnumInterfaces(hClientHandle, pReserved, &pInterfaceList);
			if(dwResult!=ERROR_SUCCESS)
			{
			  showlog("something is wrong with WlanEnumInterfaces()\n");
			  return false;
			}

			comboBox1->Items->Clear();
			//showlog(pInterfaceList->dwNumberOfItems.ToString());

			switch (pInterfaceList->dwNumberOfItems)
			{
			case 0:
				this->comboBox1->Text = "No aviable WIFI card";
				this->Set_Button->Enabled = false;
				return false;
			case 1:
				this->comboBox1->Text = gcnew String(pInterfaceList->InterfaceInfo[0].strInterfaceDescription);

				this->Set_Button->Enabled = true;
				this->Set_Button->Focus();
				return true;
			default:
				for (int i=0; i<pInterfaceList->dwNumberOfItems; i++)
					this->comboBox1->Items->Add( gcnew String(pInterfaceList->InterfaceInfo[i].strInterfaceDescription)); 
				this->comboBox1->Text = gcnew String(pInterfaceList->InterfaceInfo[0].strInterfaceDescription);
				this->Set_Button->Enabled = true;
				return true;
			}
	}


	void Form1::SaveDatatoFile(String ^File)
	{
		
		StreamWriter^ sw = gcnew StreamWriter(File);
		for (int count=0; count < SSIDInfoMAX ; count++)
		{
			if (stSSIDInfoList[count].bShowSeries)
			{
				int i = RecordCountMAX-1;	
				
				String ^tmp = "";
				
				while(1)
				{
					if (i < 0) break;
					if (stSSIDInfoList[count].lRSSIRecord[i] == NULL) 
					{
						i--;
						continue;
					}
					else
					{
						tmp = tmp + "," + stSSIDInfoList[count].lRSSIRecord[i];
						i--;
					}
				}
				
				sw->WriteLine(DateTime::Now);
				sw->WriteLine("MAC : " + gcnew String(stSSIDInfoList[count].cMACaddr) );
				sw->WriteLine("SSID : " + gcnew String(stSSIDInfoList[count].cSSID) );
				sw->WriteLine("RSSI:");
				sw->WriteLine(tmp);
				sw->WriteLine("===================================");
				
			}
		}
		sw->Close();
	}



	void Form1::showlog(String ^data)
	{
		this->textBox2->AppendText("\r\n"+data);
	}


	void Form1::delay(int Seconds)
	{
		DateTime Start = System::DateTime::Now;

		while ( (System::DateTime::Now - Start).TotalSeconds  <= Seconds)
			Application::DoEvents();
	}

	void Form1::ResizeDatagrid(int widthoffset, bool flag)
	{
		
		if(flag) 
			Datagridwidth = this->dataGridView1->Columns[CheckCell]->Width + this->dataGridView1->Columns[MacCell]->Width + this->dataGridView1->Columns[SSIDCell]->Width 
					+ this->dataGridView1->Columns[RSSICell]->Width + this->dataGridView1->Columns[SSCell]->Width + this->dataGridView1->Columns[ChannelCell]->Width 
					+ this->dataGridView1->Columns[AuthCell]->Width + this->dataGridView1->Columns[DataRateCell]->Width + this->dataGridView1->Columns[ColorCell]->Width;
		Datagridwidth = Datagridwidth - widthoffset;
		this->dataGridView1->Width = Datagridwidth;

	}


#pragma endregion

};