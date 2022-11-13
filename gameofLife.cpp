#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;



bool getStatLeftUp(bool array[60][60],int X,int Y)
{
    return array[Y+1][X-1];
}
bool getStatLeft(bool array[60][60],int X,int Y)
{
    return array[Y+1][X];
}
bool getStatLeftDown(bool array[60][60],int X,int Y)
{
    return array[Y-1][X-1];
}
bool getStatUp(bool array[60][60],int X,int Y)
{
return array[Y+1][X];
}
bool getStatDown(bool array[60][60],int X,int Y)
{
return array[Y-1][X];
}
bool getStatRightUp(bool array[60][60],int X,int Y)
{
return array[Y+1][X+1];
}
bool getStatRight(bool array[60][60],int X,int Y)
{
return array[Y][X+1];
}
bool getStatRightDown(bool array[60][60],int X,int Y)
{
return array[Y-1][X+1];
}

bool alliveChecks(bool array[60][60],int X,int Y)
{

    if(array[Y][X])
    {int val=getStatLeftUp(array,X,Y)+getStatLeft(array,X,Y)+getStatLeftDown(array,X,Y)+getStatUp(array,X,Y)+getStatDown(array,X,Y)+getStatRightUp(array,X,Y)+getStatRight(array,X,Y)+getStatRightDown(array,X,Y);
        if(val==2||val==3){
            return true;
        }
    }
    if(!array[Y][X])
    {int val=getStatLeftUp(array,X,Y)+getStatLeft(array,X,Y)+getStatLeftDown(array,X,Y)+getStatUp(array,X,Y)+getStatDown(array,X,Y)+getStatRightUp(array,X,Y)+getStatRight(array,X,Y)+getStatRightDown(array,X,Y);
    if(val==3){
        return true;
    }
    }
    return false;

}


void coppy(bool array[60][60],bool array1[60][60],int size)
{
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            array1[i][j]=array[i][j];
        }
    }
}
void outputScreen(bool array[60][60],int sizeX,int sizeY){
    system("CLEAR");
    cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z A1 B1 C1 D1 E1 F1 G1 H1 I1";
        cout<<"\n";
     for(int i=10;i<sizeY;i++)
        {
            for(int j=10;j<sizeX;j++){
                if(array[i][j]){
                    cout<<"■ ";
                }
                else cout<<"□ ";
            }
            cout<<i-9;
            cout<<"\n";
        }
}


int numOnScreen(bool array[60][60]){
    int num=0;
    for(int i=5;i<55;i++){
        for(int j=5;j<55;j++){
            num=num+int(array[i][j]);
        }
    }
    return num;
}
int randomFunc()
{
    
    
    return rand()%2;
}

void glider(bool array[60][60],int X,int Y)
{

    array[Y][X]=0;
    array[Y][X-1]=1;
    array[Y-1][X]=1;
    array[Y-1][X+1]=1;
    array[Y][X+1]=1;
    array[Y+1][X+1]=1;
}

void box(bool array[60][60],int X,int Y,int size)
{
    for(int i =0;i<size;i++){
        for(int j=0;j<size;j++){
            array[Y+i][X+j]=1;
        }
    }
}

void lines(bool array[60][60],int X,int Y,int size,int f)
{
    if(f==1){
    for(int i=0;i<size;i++){
        array[Y+i][X]=1;
    }}
    else
    for(int i=0;i<size;i++){
        array[Y][X+i]=1;
    }}




int main(void)

{
    bool cells[60][60];
    bool cellsCopy[60][60];

    srand(time(0));
    for(int i=0;i<60;i++)
    {
        for(int j=0;j<60;j++){
            cells[i][j]=randomFunc();
        }
    }

//glider(cells,20,40);
int h=0;
    //glider(cells,34,44);
  
  //box(cells,30,30,30);
 //box(cells,20,20,5);

 lines(cells,20,20,40,1);
  outputScreen(cells,50,50);
    while(h<10000000){

        
        for(int i=1;i<59;i++)
        {
            for(int j=1;j<59;j++){
                cellsCopy[i][j]=alliveChecks(cells,j,i);
                if(h%400==0 && numOnScreen(cells)<200||h%10000==0){
                cells[i][j]=randomFunc();
                box(cells,30,30,14);
                
                }
            }
        }
        coppy(cellsCopy, cells,60);
        outputScreen(cells,50,50);
        cout<<"__________________________________________________________________________________\n";
        cout<<"Cells Alive:"<<numOnScreen(cells) <<"\n"<<"Gen:"<<h<<"\n";
        
        usleep(15000);
        
     h++;
    }
}

