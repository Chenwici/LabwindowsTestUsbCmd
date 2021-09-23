/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  HELP_PANEL                      1
#define  HELP_PANEL_TEXTBOX              2
#define  HELP_PANEL_QUIT_WINDOW          3       /* callback function: QuitHelp */

#define  PANEL                           2       /* callback function: PanelCB */
#define  PANEL_INPUT_STRING              2
#define  PANEL_SEND_DATA                 3       /* callback function: SendData */
#define  PANEL_OUTOUT_STRING             4
#define  PANEL_RECV_DATA                 5       /* callback function: ReceiveData */
#define  PANEL_QUITBUTTON                6       /* callback function: Quit */
#define  PANEL_HELP                      7       /* callback function: Help */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */ 

int  CVICALLBACK Help(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PanelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitHelp(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ReceiveData(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SendData(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
