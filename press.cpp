#include <curses.h>
#include <time.h>
#include <iostream>
 
using namespace std;
 
int main()
{
    int ch;
    while (1){
        if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真
            ch = wgetch();//使用_getch()函数获取按下的键值
            cout << ch;
            if (ch == 27){ break; }//当按下ESC时循环，ESC键的键值时27.
        }
    }
    system("pause");
}