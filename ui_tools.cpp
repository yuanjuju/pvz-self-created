#include<cstdio>
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <Mmsystem.h>
#pragma comment(lib,"winmm.lib")

#include "ui_tools.h"


//设置光标位置
void Goto_XY(const int x, const int y)
{
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

//隐藏光标
void HideCursor()
{
	HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = 0;
	cinfo.dwSize = 1;
	SetConsoleCursorInfo(fd, &cinfo);
}

//设置窗口大小
void SetWindowSize(int cols, int lines)
{
	system("title \"植物大战僵尸（控制台版）- Plants vs. Zombies  \"");//设置窗口标题
	char cmd[30];
	sprintf(cmd, "mode con cols=%d lines=%d", cols, lines);
	system(cmd); //设置窗口宽度和高度
}

//设置文本颜色
void SetColor(int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

// 带颜色的文本输出，默认为黑底白字
void PrintWithColor(const string & str, int colorID)
{
	SetColor(colorID);
	cout << str;
	SetColor(DEFAULT_COLOR); //输出结束后设置回默认色
}

void PrintWithColor(int num, int colorID)
{
	SetColor(colorID);
	cout << num;
	SetColor(DEFAULT_COLOR); //输出结束后设置回默认色
}

void playMusic(int control,const char name[])  //传入参数，当参数为0时播放音乐
{
    if(control == 0)
    {
        PlaySound(TEXT(name),NULL,SND_ASYNC);//音乐开始
    }
    else
    {
        PlaySound(NULL,NULL,SND_PURGE);//音乐结束
    }
}

int getTerminalWidth() 
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void printCentered(const string &text,int i)
{
    if(i == 1 || i == 3)
    {
        int j = RANDOM(4);
        if(j == 0) SetColor(FOREGROUND_RED);
        else if(j == 1) SetColor(FOREGROUND_GREEN);
        else if(j == 2) SetColor(FOREGROUND_BLUE);
        else if(j ==3)SetColor(FOREGROUND_RED | FOREGROUND_GREEN);
        else SetColor(FOREGROUND_CYAN);
    }
    int screenWidth = getTerminalWidth();
    int padding = (screenWidth - text.length()) / 2;
    HideCursor();
    cout << setw(padding + text.length()) << text;
    if(i == 3) cout<<endl;
    SetColor(DEFAULT_COLOR);
}

void printTitle(string filename)
{
    //system("cls");
    Goto_XY(0,0);
    ifstream file(filename); // 创建输入文件流对象
    if (file.is_open())
    { // 检查文件是否成功打开
        string line;
        while (getline(file, line))
        {
            if(filename == "menu.txt") printCentered(line,3);
            else printCentered(line,1);      // 按行读取文件内容
        //    cout<<endl;
            Sleep(20); // 输出每一行内容
        }
        file.close(); // 关闭文件流
    } else 
    {
        cerr << "Failed to open file: " << filename << endl;
    }
}
