#include <conio.h>
#include <iostream>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

typedef unsigned char Uchar;


int Rus()
   {
    char Temp[200];
    cin >> Temp;
    cout << Temp << endl;
    cout << "Русский" << endl;
    strcpy_s(Temp, "Русский");
    char res[200];
    CharToOemA(Temp, res);
    cout << res << endl;
    return 0;
}


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

// Текстовий курсор в точку x,y
void GoToXY(short x, short y)
{
    SetConsoleCursorPosition(console, { x, y });
    
}

int main()
{
    int x_left = 0, y_left = 0, x_right = 0, y_right = 0, width = 0, height = 0;

    string discription ="Completed by student of group 115 Serokurov I.P.";

    // Таблиця символив 
    cout << '\t' << Rus << endl;
    for (Uchar ch = 32; ch < 255; cout << ch++ << ' ');
    cout << endl;
    cout << '\t' << Rus;
    for (Uchar ch = 32; ch < 255; ch++)
    {
        cout << ch << '\x1a';
        cout.width(3);
        cout << (int)ch << " ";
    }
    cout << endl;
    
    Uchar Frames[] = { 179,205,255,184,213,212,190};
    cout << Rus << endl;
    cout << Frames[4] << Frames[1] << Frames[3] << endl;
    cout << Frames[0] << ' ' << Frames[0] << endl;
    cout << Frames[5] << Frames[1] << Frames[6] << endl;
    system("cls");

    // Запит на координати лівого верхнього кута рамки 
    GoToXY(50, 12);
    cout << "Enter left x,y ";
    cin >> x_left >> y_left;
    system("cls");

    // Запит на координати правого нижнього кута рамки  
    GoToXY(50, 12);
    cout << "Enter left x,y ";
    cin >> x_right >> y_right;
    system("cls");

    // Вираховуємо розмир рамки
    height = y_right - y_left;
    width = x_right - x_left;
        
    GoToXY(x_left, y_left);

    SetConsoleTextAttribute(console, BACKGROUND_BLUE | FOREGROUND_GREEN | (0 << 4));
    
   // Верх рамки 
    cout << Frames[4];
    for (int i = 0; i < width; i++) cout << Frames[1]; 
    {
        
        cout << Frames[3];
    }
    
    // середина рамки
   
    for (int i = 0; i < height; i++)
    {
    
    GoToXY(x_left,++y_left);
   
    cout << Frames[0];

    for (int j = 0; j < width; j++) cout <<' ';
    {
        
        cout << Frames[0];
           
    }    

    }
    // Низ
    GoToXY(x_left, ++y_left);
    
    cout << Frames[5];
    for (int i = 0; i < width; i++) cout << Frames[1]; {

        cout << Frames[6] << endl;
       
    }
    // Вивід тексту в середену рамки 
    int textX = x_left + (width - discription.length()) / 2;
    int textY = y_left - height  /2 ;    
    GoToXY(textX, textY);
   
   
    cout << discription << endl;
    _getch();

    return 0;

}
