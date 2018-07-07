//
//  main.cpp
//  project
//
//  Created by 彭皓 on 2018/7/7.
//  Copyright © 2018年 彭皓. All rights reserved.
//


#include <stdio.h>


# include<iostream>
# include<iomanip>
# define N  20   //评委的人数最多为20
# define M  50   //参赛选手的人数最多为50

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

# include<iostream>
# include<iomanip>
# define N  20   //评委的人数最多为20
# define M  50   //参赛选手的人数最多为50

using namespace std;

float CountAthleteScore(int , float ave, int n, float s[], int m);
void Sort(float a[], int n);
void Print(float a[], int n,int bh[]);
float b[M];
int bh[M];


void you()
{
    int i = 0, n, m, r;
    char name[20];                                            //姓名
    char sex[20];                                            //性别
    char phoneNum[20];                                        //联系方式
    char proName[20];                                        //项目名称
    char proNum[20];                                        //项目编号
    char ClassName[20];                                          //班级
    float s[N], a[M], ave = 0.0, sum = 0.0;
    cout << "******欢迎使用评分系统******" << endl;
    cout << "   请输入评委个数（>=3)：";
    cin >> n;
    cout << "   请输入参赛选手个数(>=2)：";
    cin >> m;
    cout << endl;
    
    ofstream outFile;
    outFile.open("/Users/penghao/Desktop/选手信息表.csv",ios::app); // 打开模式可省略
    for (i = 0; i<m; i++)
    {
        cout << " *********选手参赛信息*********" << endl;
        cout << "       编号为：";
        cin >> bh[i];
        cout << "       姓名：" ;
        cin >> name[i];
        cout << "       性别：" ;
        cin >> sex[i];
        cout << "       节目编号：" ;
        cin >> proNum[i];
        cout << "       节目名称：" ;
        cin >> proName[i];
        cout << "       所在班级：" ;
        cin >> ClassName[i];
        cout << "       联系方式：" ;
        cin >> phoneNum[i];
        
        a[r++] = CountAthleteScore(bh[i], ave, n, s, m);
        outFile << bh[i]<<",";
        outFile << name[i]<<",";
        outFile << sex[i]<<",";
        outFile << proNum[i]<<",";
        outFile << proName[i]<<",";
        outFile << ClassName[i]<<",";
        outFile << phoneNum[i]<<",";
        outFile << a[r] <<endl;
        
    }
    
    cout << m << "这位选手的平均成绩分别是：" << endl;
    for (r = 0; r<m; r++)
        cout << a[r] << "  ";
    cout << endl;
    Sort(a, m);
    Print(a, n, bh);
    outFile.close();
    
}

float CountAthleteScore(int , float ave, int n, float s[], int m)
{
    int j,k,r=0;
    static int w=0;
    float t,sum=0.0;
    ave=0.0;
    
    cout<<"请输入该选手的成绩："<<endl;
    for(k=0;k<n;k++)//不加花括号会出现错误
    {
        cout<<endl;
        cout<<"输入第"<<k+1<<"位评委给分: ";
        cin>>s[k];
        if((s[k]>10)||(s[k]<0))
        {
            cout<<"第"<<k+1<<"位评委输入时出现错误,请重新输入"<<endl;
            k--;
        }
    }
    
    for(k=0;k<n-1;k++)     //对每位选手的成绩排序，以便去掉最低分和最高分;
    {
        for(j=k+1;j<n;j++)
            if(s[k]<s[j])
            {
                t=s[k];
                s[k]=s[j];
                s[j]=t;
            }
    }
    cout<<"对评委给分由高到低进行排序："<<endl;
    for(k=0;k<n;k++)
        cout<<s[k]<<"  ";
    cout<<endl;
    cout<<"去掉一个最高分"<<s[0]<<",一个最低分"<<s[n-1]<<",后的结果："<<endl;
    for(k=0;k<n-2;k++)
    {
        cout<<s[k+1]<<"  ";
        sum=sum+s[k+1];
    }
    cout<<endl;
    ave= sum/float(n-2);
    b[w++]=ave;
    cout<<"该选手平均分="<<ave<<endl;
    return ave;
    cout<<"*************************"<<endl;
    
}
void Sort(float a[],  int m)
{
    
    int j;
    int r;
    float t;
    
    for(r=0;r<m-1;r++)     //对平均成绩进行排序;
    {
        for(j=0;j<m-1-r;j++)
            if(a[j]<a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
    }
    cout<<"由高到低排序后的成绩为："<<endl;
    for(r=0;r<m;r++)
        cout<<a[r]<<"  ";
    cout<<endl;
    cout<<"************************"<<endl;
    cout<<"************************"<<endl;
}


void Print(float a[], int m,int bh[])
{
    int i;
    if((a[0]!=a[1])&&a[1]!=a[2])
        
    {
        if(m>2){
            cout<<setw(18)<<"编号"<<setw(15)<<"成绩"<<endl;
            cout<<"冠军:   ";
            
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(14)<<a[0]<<endl;
            cout<<"亚军：  ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(14)<<a[1]<<endl;
            cout<<"季军：  ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[2])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(14)<<a[2]<<endl;
        }
        else{
            
            cout<<setw(18)<<"编号"<<setw(15)<<"成绩"<<endl;
            cout<<"冠军：   ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(13)<<a[0]<<endl;
            cout<<"亚军：   ";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    break;
            }
            cout<<setw(7)<<bh[i];
            cout<<setw(13)<<a[1]<<endl;
        }
    }
    
    else if((a[0]==a[1])&&(a[1]!=a[2]))
    {
        cout<<"**两位选手并列第一"<<endl;
        if(m>2)
        {
            cout<<"冠军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<bh[i]<<"  ";
            }
            cout<<"成绩为："<<a[1]<<endl;
            cout<<"亚军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[2])
                    break;
            }
            cout<<bh[i];
            cout<<"成绩为："<<a[2]<<endl;
            
        }
        else
        {
            cout<<"冠军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<bh[i];cout<<"   ";
            cout<<"成绩为："<<a[1]<<endl;
        }
    }
    else if((a[0]!=a[1])&&(a[1]==a[2]))
    {
        if(m>2)
        {
            cout<<"**几位选手并列第二"<<endl;
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    break;
            }
            cout<<"冠军   编号为："<<bh[i];
            cout<<"成绩为："<<a[0]<<endl;
            
            cout<<"亚军   编号为：";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    cout<<bh[i]<<"   ";
            }
            
            cout<<"成绩为："<<a[2]<<endl;
        }
        else
        {
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<"冠军   编号为："<<bh[i]<<"   ";}
            cout<<"成绩为："<<a[0]<<endl;
            for(i=0;i<m;i++)
            {
                if(b[i]==a[1])
                    cout<<"亚军   编号为："<<bh[i]<<"   ";
            }
            cout<<"成绩为："<<a[1]<<endl;
        }
    }
    else if((a[0]==a[1])&&(a[1]==a[2]))
    {
        if(m>2)
        {
            cout<<"**几位选手并列第一"<<endl;
            cout<<"冠军   编号为:";
            
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<bh[i]<<"   ";
            }
            cout<<"成绩为："<<a[0]<<endl;
            
        }
        else
        {
            cout<<"**两位选手并列第一"<<endl;
            cout<<"冠军   编号为:";
            for(i=0;i<m;i++)
            {
                if(b[i]==a[0])
                    cout<<bh[i]<<"   ";
            }
            
        }
    }
}


void com()
{
    ifstream fin("/Users/penghao/Desktop/选手信息表.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        cout << "编号,姓名,性别,节目编号,节目名称,所在班级,联系方式，平均分" << endl << line << endl; //整行输出
    }
    
}

void con()
{
    ifstream fin("/Users/penghao/Desktop/评委信息表.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        cout << "姓名,性别,电话：" << endl << line << endl; //整行输出
    }
    
}


int main()
{
    
    int i;
    while (1)
    {
        cout << "| ---------------------------------- |\n";
        cout << "| ***********欢迎来到此系统*************|\n";
        cout << "| ---------------------------------- |\n";
        cout << "|        1 --- 读取选手的比赛信息       |\n";
        cout << "|        2 --- 读取评委的信息          |\n";
        cout << "|        3 --- 输入新的选手信息         |\n";
        cout << "|        0 --- 退出系统               |\n";
        cout << "| ---------------------------------- |\n";
        cout << "\n 请选择功能：";
        cin >> i;
        switch (i)
        {
            case 1:
                com();
                break;
            case 2:
                con();
                break;
            case 3:
                you();
                break;
            case 0:
                return 0;
        }
    }
}

