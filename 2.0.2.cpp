#include <iostream>
#include <Windows.h>

#pragma comment(lib, "Winmm.lib")

using namespace std;

bool minecraftattach()
{
	HWND window = GetForegroundWindow();
	char windowsname[256];
	GetWindowTextA(window, windowsname, sizeof(windowsname));
	if (string(windowsname).find("Minecraft") != string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int CPS = NULL;
	cin >> CPS;
	int spike = 0;
	int sleeptime1, sleeptime2;
	while (1)
	{
		Sleep(1);
		timeBeginPeriod(1);
		if (minecraftattach() == true)
		{
			while (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			{
				sleeptime1 = (1000 + rand() % 100) / (CPS * 2);
				sleeptime2 = (1000 - rand() % 200) / (CPS * 2);
				SendMessageW(GetForegroundWindow(), WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(0, 0));
				Sleep(sleeptime1);
				SendMessageW(GetForegroundWindow(), WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(0, 0));
				Sleep(sleeptime2);
				spike++;

				if (spike == 30)
				{
					Sleep(70 + rand() % 80);
					spike = 0;
				}
				timeEndPeriod(1);
			}
		}
	}

	return 0;
}
