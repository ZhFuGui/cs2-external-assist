#pragma once
//#include "Player/GetPlayerList.h"
#include "GameInfo/GetGameStatus.h"
//版本信息
BOOL VersionCheck=1;
//获取CS2.exe进程句柄
DWORD GamePid = 0;
HANDLE GameProcess = 0;
char GameFile[MAX_PATH]="Hello, CS2!";
//UI
HWND TestGameEnvironment_Button_hwnd; BOOL TestGameEnvironment;
HWND AutoAim_Button_hwnd; BOOL AutoAim_Button_Switch;
HWND ReportPosition_Button_hwnd; BOOL ReportPosition_Button_Switch;
HWND Enemy01_ID_Static_hwnd;
HWND Enemy02_ID_Static_hwnd;
HWND Enemy03_ID_Static_hwnd;
HWND Enemy04_ID_Static_hwnd;
HWND Enemy05_ID_Static_hwnd;
HWND Enemy06_ID_Static_hwnd;
HWND Enemy07_ID_Static_hwnd;
HWND Enemy08_ID_Static_hwnd;
HWND Enemy09_ID_Static_hwnd;
HWND Enemy10_ID_Static_hwnd;
HWND Enemy01_Where_Edit_hwnd;
HWND Enemy02_Where_Edit_hwnd;
HWND Enemy03_Where_Edit_hwnd;
HWND Enemy04_Where_Edit_hwnd;
HWND Enemy05_Where_Edit_hwnd;
HWND Enemy06_Where_Edit_hwnd;
HWND Enemy07_Where_Edit_hwnd;
HWND Enemy08_Where_Edit_hwnd;
HWND Enemy09_Where_Edit_hwnd;
HWND Enemy10_Where_Edit_hwnd;
HWND Enemy01_HP_Edit_hwnd;
HWND Enemy02_HP_Edit_hwnd;
HWND Enemy03_HP_Edit_hwnd;
HWND Enemy04_HP_Edit_hwnd;
HWND Enemy05_HP_Edit_hwnd;
HWND Enemy06_HP_Edit_hwnd;
HWND Enemy07_HP_Edit_hwnd;
HWND Enemy08_HP_Edit_hwnd;
HWND Enemy09_HP_Edit_hwnd;
HWND Enemy10_HP_Edit_hwnd;
HWND Enemy01_Distance_Edit_hwnd;
HWND Enemy02_Distance_Edit_hwnd;
HWND Enemy03_Distance_Edit_hwnd;
HWND Enemy04_Distance_Edit_hwnd;
HWND Enemy05_Distance_Edit_hwnd;
HWND Enemy06_Distance_Edit_hwnd;
HWND Enemy07_Distance_Edit_hwnd;
HWND Enemy08_Distance_Edit_hwnd;
HWND Enemy09_Distance_Edit_hwnd;
HWND Enemy10_Distance_Edit_hwnd;

//游戏是否打开线程函数
void WINAPI GetExeStatus();
HANDLE GetExeStatus_handle=0;
DWORD GetExeStatus_ThreadId =0;
BOOL GetExeStatus_switch=TRUE;
BOOL GameStatus = FALSE;
//模块地址
HMODULE ClientModuleAddress=0;
HMODULE Engine2ModuleAddress=0;
HMODULE MatchmakingModuleAddress=0;
HMODULE ServerModuleAddress = 0; 
HMODULE SDL3ModuleAddress = 0;
//全局窗口句柄
HWND g_HWND=0;
//地图地址
//游戏状态线程函数
GameStatusInfo GameStatusInfoS;
HANDLE GetGameModelStatus_handle = 0;
DWORD GetGameModelStatus_ThreadId = 0;
LPVOID CurrentMap_Address=0;
void WINAPI GetGameModelStatus();
int PeopleMultiple = 1;
DWORD CurrentMapStatus=0;
//获得人物列表线程函数
DWORD WINAPI GetPlayerList();
//我的信息
LPVOID Localplayer_Address;
//结构体
SLocalPlayer Localplayer; Player player; Player EnemyArray[10]; Player AllyArray[10]; Player AllPlayerArray[19]; Player InitialPlayer;
int EnemyNum; int AllyNum; int AllPlayerNum;
//报点线程
DWORD WINAPI ReportPositions();
BOOL ReportPositionStop = 0;
HANDLE ReportPositions_handle;
int ReportPositionWidth = 0;
int ReportPositionHeight = 0;
//CS2窗口是否是焦点
BOOL IFCS2FocalPoint = FALSE;
std::string FocWinTitle;
//自瞄相关
DWORD WINAPI Auto_Aim();
BOOL Auto_Aim_Stop = FALSE;
HANDLE Auto_Aim_handle;
DWORD Auto_Aim_Model = AimByAngle;
DWORD Auto_Aim_Object = AimAtTheEnemy;
int index_Player_LowestDistance_InMain = 0;
int index_Player_LowestAngle_InMain = 0; 
//自瞄角度相关
float Angle_H; float Angle_V;
//自瞄线程花费时间
std::chrono::steady_clock::time_point StartTime;
std::chrono::steady_clock::time_point EndTime;
long long DuringTime=0;
int pausetime = 2500;
//自瞄设置


BOOL POP = 0;
BOOL temp = 0;


















//调用重置函数==========================================================================
void ReSetVariableValue() {
	GameStatus = FALSE;
	GameProcess = 0;
	ClientModuleAddress = 0;
	Engine2ModuleAddress = 0;
	MatchmakingModuleAddress = 0;
	CurrentMap_Address = 0;
	Localplayer_Address = 0;
};
int IOI = 0;