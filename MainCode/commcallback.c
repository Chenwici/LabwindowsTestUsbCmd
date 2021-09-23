/********************************************************************************************/
/********************************************************************************************/
/* File:	InstallCommCallback.c															*/
/* Purpose:	This example illustrates the use of the RS232 Library's InstallComCallback		*/
/*			function to respond to the LWRS_RXFLAG event. The user will be asked to enter   */
/*			an event character. Whenever this event character is detected on the COM port,  */
/*			a callback function will be executed.											*/
/* Notes:	To run this example you need to do a Loopback Test, i.e. connect pin 2 to   	*/
/*			pin 3 on the serial port.														*/
/*			The example uses port 1 by default. To use another port, change the COM_PORT	*/
/*			defined value.																	*/
/********************************************************************************************/
/********************************************************************************************/

/********************************************************************************************/
/* Include files																			*/
/********************************************************************************************/
#include <rs232.h>
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "commcallback.h"
#include <formatio.h> 

/********************************************************************************************/
/* Constants																					*/
/********************************************************************************************/
#define COM_PORT	1

/********************************************************************************************/
/* Globals																					*/
/********************************************************************************************/
static int 	gHelpPanelHandle;
static int 	gPanelHandle;
static char gEventChar[2]; 

/********************************************************************************************/
/* Prototypes																				*/
/********************************************************************************************/
void CVICALLBACK Event_Char_Detect_Func (int portNo,int eventMask,void *callbackData);

/********************************************************************************************/
/* Application entry point.																	*/
/********************************************************************************************/
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)	/* Initialize CVI libraries */
		return -1;	/* out of memory */
	if ((gPanelHandle = LoadPanel (0, "commcallback.uir", PANEL)) < 0)
		return -1;
	if ((gHelpPanelHandle = LoadPanel (0, "commcallback.uir", HELP_PANEL)) < 0)
		return -1;
		
	/* 	Open and Configure Com port */
	OpenComConfig (COM_PORT, "", 9600, 0, 8, 1, 512, 512);
	
	/* 	Turn off Hardware handshaking (loopback test will not function with it on) */
	SetCTSMode (COM_PORT, LWRS_HWHANDSHAKE_OFF);
	
	/* 	Make sure Serial buffers are empty */
	FlushInQ (COM_PORT);
	FlushOutQ (COM_PORT);

	/* 	Promt the user to enter an event character. */
	PromptPopup ("Event Character", "Enter the Event Character", gEventChar, 1);
	
	/* 	Install a callback such that if the event character appears at the 
		receive buffer, our function will be notified.  */
	InstallComCallback (COM_PORT, LWRS_RXFLAG, 0, (int)gEventChar[0] , Event_Char_Detect_Func, 0);
	
	/* 	Display the panel and run the UI */
	DisplayPanel (gPanelHandle);
	RunUserInterface ();
	
	/*	Close the open COM port before exiting */
	CloseCom (COM_PORT);
	
	/*	Discard the loaded panels from memory */
	DiscardPanel (gPanelHandle);
	DiscardPanel (gHelpPanelHandle);
	
	return 0;
}

/********************************************************************************************/
/* SendData ():  Respond to the Send button to send characters out of the serial port.		*/
/********************************************************************************************/
int CVICALLBACK SendData (int panel, int control, int event, void *callbackData, 
							int eventData1, int eventData2)
{				   
	char info[20];
	
	switch (event)
		{
		case EVENT_COMMIT:
			SetCtrlVal (gPanelHandle, PANEL_OUTOUT_STRING, "\0");
			GetCtrlVal (gPanelHandle, PANEL_INPUT_STRING, info);
			FlushInQ (COM_PORT);
			ComWrt (COM_PORT, info, strlen(info));
			break;
		}
	return 0;
}

/********************************************************************************************/
/* Event_Char_Detect_Func ():  Fuction called when the event character is detected.			*/
/********************************************************************************************/
void CVICALLBACK Event_Char_Detect_Func (int portNo,int eventMask,void *callbackData)
{
	char outMessage[256];
	
	Fmt (outMessage, "%s<%s%s%s",
		  "The Character \"",gEventChar,"\" was detected");
	MessagePopup ("Install CommCallback", outMessage);
	return;
}	

/********************************************************************************************/
/* Help ():  Display help text.																*/
/********************************************************************************************/
int CVICALLBACK Help (int panel, int control, int event, void *callbackData, int eventData1,
						int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			InstallPopup (gHelpPanelHandle);
			break;
		}
	return 0;
}

/********************************************************************************************/
/* QuitHelpCB ():  Remove help text.														*/
/********************************************************************************************/
int CVICALLBACK QuitHelp (int panel, int control, int event, void *callbackData, 
							int eventData1, int eventData2)
{
	switch (event) 
		{
		case EVENT_COMMIT:
			RemovePopup (0);
			break;
		}
	return 0;
}

/********************************************************************************************/
/* ReceiveData ():  Read the data on the serial COM port.									*/
/********************************************************************************************/
int CVICALLBACK ReceiveData (int panel, int control, int event, void *callbackData, 
								int eventData1, int eventData2)
{
	char	readBuf[20] = {0};
	int	    strLen;
	
	switch (event)
		{
		case EVENT_COMMIT:
			/* 	Read the characters from the port */
			strLen = GetInQLen (COM_PORT);
			ComRd (COM_PORT, readBuf, strLen);
			SetCtrlVal (gPanelHandle, PANEL_OUTOUT_STRING, readBuf);
			SetActiveCtrl (gPanelHandle, PANEL_INPUT_STRING);
			break;
		}
	return 0;
}


/********************************************************************************************/
/* PanelCB ():  Quits this application.														*/
/********************************************************************************************/
int CVICALLBACK PanelCB (int panel, int event, void *callbackData,
							int eventData1, int eventData2)
{
	switch (event) 
		{
		case EVENT_CLOSE:
			QuitUserInterface (0);
			break;
		}
	return 0;
}

/********************************************************************************************/

int CVICALLBACK Quit (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			QuitUserInterface(0);
			break;
		}
	return 0;
}
