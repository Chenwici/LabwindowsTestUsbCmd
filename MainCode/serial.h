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

#define  CONFIG                           1
#define  CONFIG_COMPORT                   2       /* control type: slide, callback function: (none) */
#define  CONFIG_BAUDRATE                  3       /* control type: slide, callback function: (none) */
#define  CONFIG_PARITY                    4       /* control type: slide, callback function: (none) */
#define  CONFIG_DATABITS                  5       /* control type: slide, callback function: (none) */
#define  CONFIG_STOPBITS                  6       /* control type: slide, callback function: (none) */
#define  CONFIG_INPUTQ                    7       /* control type: numeric, callback function: InputQCallBack */
#define  CONFIG_OUTPUTQ                   8       /* control type: numeric, callback function: (none) */
#define  CONFIG_CTSMODE                   9       /* control type: binary, callback function: (none) */
#define  CONFIG_XMODE                     10      /* control type: binary, callback function: (none) */
#define  CONFIG_TIMEOUT                   11      /* control type: numeric, callback function: (none) */
#define  CONFIG_CLOSECONFIG               12      /* control type: command, callback function: CloseConfigCallback */
#define  CONFIG_TIMEOUT_MSG1              13      /* control type: textMsg, callback function: (none) */
#define  CONFIG_OUTQSIZE_MSG              14      /* control type: textMsg, callback function: (none) */

#define  SERIAL                           2
#define  SERIAL_CONFIG                    2       /* control type: command, callback function: ConfigCallBack */
#define  SERIAL_SENDTERM                  3       /* control type: ring, callback function: (none) */
#define  SERIAL_TBOX_SEND                 4       /* control type: textBox, callback function: (none) */
#define  SERIAL_SENDBYTE                  5       /* control type: numeric, callback function: (none) */
#define  SERIAL_SENDMODE                  6       /* control type: binary, callback function: SendModeCallBack */
#define  SERIAL_BYTES                     7       /* control type: numeric, callback function: (none) */
#define  SERIAL_SEND                      8       /* control type: command, callback function: SendCallBack */
#define  SERIAL_READ_COUNT                9       /* control type: numeric, callback function: (none) */
#define  SERIAL_READTERM                  10      /* control type: ring, callback function: (none) */
#define  SERIAL_TBOX_READ                 11      /* control type: textBox, callback function: (none) */
#define  SERIAL_READ                      12      /* control type: command, callback function: (none) */
#define  SERIAL_CLEARBOX                  13      /* control type: command, callback function: ClearBoxCallBack */
#define  SERIAL_QUIT                      14      /* control type: command, callback function: QuitCallBack */
#define  SERIAL_DECORATION                15      /* control type: deco, callback function: (none) */
#define  SERIAL_DECORATION_2              16      /* control type: deco, callback function: (none) */
#define  SERIAL_RCV_HELP_MSG              17      /* control type: textMsg, callback function: (none) */
#define  SERIAL_TRANS_HELP_MSG            18      /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK ClearBoxCallBack(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CloseConfigCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ConfigCallBack(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK InputQCallBack(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallBack(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SendCallBack(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SendModeCallBack(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
