#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include "ui_tools.h"
#include "fengmian.h"
#include"Game.h"

using namespace std;

//背景叙述模块
//=========================================================================
void display_txt(string filename)
{
    int i;
    ifstream file(filename); // 创建输入文件流对象
    if (file.is_open())
    { // 检查文件是否成功打开
        string line;
        while (getline(file, line))
        {                 // 按行读取文件内容
            cout<<line<<endl; // 输出每一行内容
        }
        file.close(); // 关闭文件流
    } else 
    {
        cerr << "Failed to open file: " << filename << endl;
    }
}

void chat()
{
    ifstream chatfile("Conversation content.txt");
    if (!chatfile.is_open())
    {
        cout<< "Failed to open the file." <<endl;
        return;
    }
    string filename[3] = {"jiangwang.txt","null","daifu.txt"};
    for(int j = 4;j < 14;j+=2)
    {
        display_txt(filename[j % 4]);
        Sleep(800);
        switch(j)
        {
            case 6: playMusic(0,"crazydavecrazy.wav");break;
            case 10:playMusic(0,"crazydaveextralong1.wav");break;
            case 14: playMusic(0,"crazydaveextralong2.wav");break;
            case 4:playMusic(0,"sukhbir3.wav");break;
            case 8:playMusic(0,"sukhbir2.wav");break;
            case 12: playMusic(0,"sukhbir.wav");break;
        }
        cout<<endl;
        string line;
        getline(chatfile,line);
        cout<<line<<endl;
        if(!chatfile.eof()) cout<<endl<<endl;
        Sleep(500);
        system("pause");
        system("cls"); 
    }
    chatfile.close();
}
//=========================================================================

//封面板块
//=========================================================================
void option()
{
    cout<<endl<<endl;
    string str = "1.新玩家         2.旧玩家          3.设置";
    printCentered(str,0);
}

void set()
{
    void game_begin();
    int i;
    system("cls");  //清屏函数
    string str = "1.关闭音乐      2.返回  ";
    printCentered(str,0);
    cout<<endl<<endl<<endl<<"请输入：   ";
    cin>>i;
    switch(i)
    {
        case 1: playMusic(1); set(); break; //执行完1选项后仍返回设置页面
        case 2: game_begin(); break;
        default:
        {
            cout<<"输入有误，请重新输入：";
            Sleep(2000);
            set();
        }
    }
}


void game_begin()
{
    system("title \"植物大战僵尸（控制台版）- Plants vs. Zombies  \"");
    playMusic(0);
    while(!_kbhit())
    {
        printTitle("fengmian.txt");
        string teamname = "————by 制作团队";
        cout<<setw(getTerminalWidth()*2 - teamname.length()*2)<<teamname<<endl;
        option();
        cout<<endl<<endl<<"请选择:  ";
    }
    char ch = _getch();
    skip(ch);
}
//=========================================================================

//菜单板块
//=========================================================================
void set_menu()
{
    system("cls");
    while(!_kbhit())
    {
        printTitle("menu.txt");
        cout<<endl<<endl;
        string choice = "1.无尽模式    2.植物or僵尸说明";
        printCentered(choice,0);
        cout<<endl<<endl;
        cout<<"请输入：  ";
    }
    char i = _getch();
    switch(i)
    {
        case '1':
        {
            break;
        }
        case '2':
        {
            system("cls");
            display_txt("declaration.txt");//此处接入说明
            system("pause");
            set_menu();
            break;
        }
        default:
        {
            cout<<"输入有误！请重新输入!  ";
            Sleep(700);
            set_menu();
        }
    }
}


void skip(char i)
{
    switch(i)
    {
        case '1': system("cls"),chat();//此处进行背景叙述
        case '2':
        {
            set_menu();
            playMusic(1);
            Game myGame;	
	        myGame.init();
	        myGame.loop();
            break;
        }
        case '3':
        {
            set();
            break;
        }
        default: 
        {
            printCentered("输入有误，请重新输入！",0);
            cin>>i;
            skip(i);
        }         
    }
}
//=========================================================================