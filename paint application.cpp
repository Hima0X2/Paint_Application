#include<graphics.h>
#include<windows.h>
int main()
{
    initwindow(1000,1000,"Paint Application");
    int x=100,y=100;
    POINT cursor;
    setbkcolor(WHITE);
    cleardevice();
    while(1)
    {
        GetCursorPos(&cursor);
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            setfillstyle(1,BLACK);
            bar(cursor.x,cursor.y,cursor.x+10,cursor.y+10);
            clearmouseclick(WM_LBUTTONDOWN);
            //setcolor(RED);
        }
        //circle(cursor.x,cursor.y,20);
        if(GetAsyncKeyState(VK_RETURN))  //press enter
        {
            writeimagefile("hima.jpg");
            delay(200);                     //save paint as image file
            cleardevice();
        }
        if(GetAsyncKeyState(VK_SPACE))  //press space
        {
            cleardevice();               //device clear
        }
        if(GetAsyncKeyState(VK_ESCAPE))  //press esc
        {
            break;
        }
//        if(GetAsyncKeyState(VK_RBUTTON)){
//        	setfillstyle(1,WHITE);
//            bar(cursor.x,cursor.y,cursor.x+20,cursor.y+20);
//            clearmouseclick(WM_RBUTTONDOWN);
//		}
        outtextxy(200,60,"Click for Exit");
        settextstyle(5,0,4);
        if(mousex()>200&&mousex()<400&&mousey()>60&&mousey()<60+20)
        {
            setcolor(BLACK);
        }
        else
        {
            setcolor(BROWN);
        }
        if(mousex()>200 && mousex()<400 && mousey()>60 && mousey()<60+20 && ismouseclick(WM_LBUTTONDOWN))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            return 0;
        }
    }
    closegraph();
}

