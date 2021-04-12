#include<stdio.h>
#include<Windows.h>


#pragma comment(lib, "winmm.lib")
#include "Mmsystem.h"
#include "Digitalv.h"
MCI_OPEN_PARMS m_mciOpenParms;
MCI_PLAY_PARMS m_mciPlayParms;
DWORD m_dwDeviceID;
MCI_OPEN_PARMS mciOpen;
MCI_PLAY_PARMS mciPlay;

int dwID;


int main()
{

    mciOpen.lpstrElementName = "C:\\Users\\USER\\Documents\\heyonjoong\\테트리스\\tetris\\music\\231.mp3"; // 파일 경로 입력
    mciOpen.lpstrDeviceType = "mpegvideo";

    mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
        (DWORD)(LPVOID)&mciOpen);

    dwID = mciOpen.wDeviceID;

    mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // play & repeat
        (DWORD)(LPVOID)&m_mciPlayParms);

    while (1) {
        Sleep(100);
    }

  

