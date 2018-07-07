#include"define.h"
#include <iostream>
#include <cstring>
#include <String>
#include <stdio.h>
#include <sstream>
#include <fstream>
using namespace std;
 
int menu_select()//菜单
{
    int MenuItem;
    
    printf("\n ");
    printf("         | *********评分系统********* |           \n");
    printf("          | ---------------------------------- |          \n");
    printf("          |              主菜单项              |          \n");
    printf("          | ---------------------------------- |          \n");
    printf("          |	  1 --- 录入学生信息  	       |          	  \n");
    printf("          |	  2 --- 录入裁判信息	       |              \n");
    printf("          |	  3 --- 录入学生成绩	       |              \n");
    printf("          |	  4 --- 查询信息	           |              \n");
    printf("          |	  5 --- 输出所有信息	       |              \n");
    printf("          |	  6 --- 排序系统	           |              \n");
    printf("          |	  7 --- 将学生裁判信息写入文件并退出|              \n");
    
    do
    {
        printf("\n请输入选项（1－7）：");
        fflush(stdin);
        scanf("%d",&MenuItem);
    }while(MenuItem<1||MenuItem>7);
    
    return MenuItem;
}
void Sort(Student *s)/*排序*/ 
{
    
    
    struct Student x;
    int i,j,k;
    int n;
    
    for(i=1; i<=5; i++)
    {
        k=0;
        for(j=0; j<s[0].f; j++)
        {
            if(s[j].pro==i)
            {
                stu[i][k]=s[j];
                k++;
            }
        }
        stu[i][0].f=k;
       
    }
    for(i=1; i<=5; i++)
    {
        for(j=1; j<stu[i][0].f; j++)
        {
            stu[i][j].f=stu[i][0].f;
        }
    }
    cout<<stu[1][0].f<<endl;
    for(i=1; i<=5; i++)
    {
        for(j=0; j<stu[i][0].f-i; j++)
        {
            if(stu[i][j].avg>stu[i][j+1].avg)
            {
                stu[0][0]=stu[i][j];
                stu[i][j]=stu[i][j+1];
                stu[i][j+1]=stu[0][0];
            }
            
        }
        
    }
    for(i=1; i<=5; i++)
    {
        n=1;
        cout<<"共"<<stu[i][0].f<<"项"<<"   "<<"表演形式："<<stu[i][0].form<<endl;
        for(j=stu[i][0].f-1; j>=0; j--)
        {
            stu[i][j].rank=n;
            cout<<"学生编号:   ";
            cout<<stu[i][j].no<<endl;
            cout<<"学生姓名:   ";
            cout<<stu[i][j].name<<endl;
            cout<<"学生性别:   ";
            cout<<stu[i][j].sex<<endl;
            cout<<"节目名称:   ";
            cout<<stu[i][j].Program<<endl;
            cout<<"学生班级:   ";
            cout<<stu[i][j].Class<<endl;
            cout<<"学生电话:   ";
            cout<<stu[i][j].tel<<endl;
            cout<<"学生成绩:   ";
            cout<<stu[i][j].avg<<endl;
            cout<<"学生排名:   ";
            cout<<stu[i][j].rank<<endl;
            
            n++;
        }
        
    }
    
}
int change(Student *s)//修改函数
{
    int a;
    int i;
    int Num;
    int flag=1;
    struct Student x;
    int j;
    cout<<"请输出要查找的学生编号";
    cin>>a;
    for(i=0; i<s[0].f; )
    {
        if(s[i].no!=a)
        {
            i++;
        }
        else{
            break;
        }
    }
    if(i>=s[0].f||a<=0)
    {
        cout<<"该学生编号不存在，请重新输入"<<endl;
    }
    else
    {
        
        cout<<"修改学生信息请输入1，修改学生成绩情输入2（1/2）";
        cin>>Num;
        while(flag)
        {
            if(Num<1||Num>2)
            {
                cout<<"输入错误请重新输入：";
                cin>>Num;
            }
            else if(Num==1)
            {
                cout<<"请输入姓名：";
                cin>>x.name;
                s[i].name=x.name;
                cout<<"请输入性别：";
                cin>>x.sex;
                s[i].sex=x.sex;
                cout<<"请输入节目名称：";
                cin>>x.Program;
                s[i].Program=x.Program;
                cout<<"请输入表演形式：";
                cin>>x.form;
                s[i].form=x.form;
                cout<<"请输入班级：";
                cin>>x.Class;
                s[i].Class=x.Class;
                cout<<"请输入电话号:";
                cin>>x.tel;
                s[i].tel=x.tel;
                flag=0;
            }
            else if(Num==2)
            {
                cout<<"请输入第一个评委打分:"<<endl;
                cin>>x.score[0];
                s[i].score[0]=x.score[0];
                cout<<"请输入第二个评委打分:"<<endl;
                cin>>x.score[1];
                s[i].score[1]=x.score[1];
                cout<<"请输入第三个评委打分:"<<endl;
                cin>>x.score[2];
                s[i].score[2]=x.score[2];
                cout<<"请输入第四个评委打分:"<<endl;
                cin>>x.score[3];
                s[i].score[3]=x.score[3];
                cout<<"请输入第五个评委打分:"<<endl;
                cin>>x.score[4];
                s[i].score[4]=x.score[4];
                s[i].min=s[i].score[0];
                for(j=0; j<5; j++)
                {
                    if(s[i].score[j]<s[i].min)
                    {
                        s[i].min=s[i].score[j];
                    }
                }
                
                s[i].max=s[i].score[0];
                for(j=0; j<5; j++)
                {
                    if(s[i].score[j]>s[i].max)
                    {
                        s[i].max=s[i].score[j];
                    }
                }
                s[i].avg=(s[i].score[0]+s[i].score[1]+s[i].score[2]+s[i].score[3]+s[i].score[4]-s[i].min-s[i].max)/3;
                flag=0;
            }
            
            flag=0;
        }
    }
    
    return 0;
}
void searchlistmenu(Student * s,Referee *r)//查询菜单
{
    int menu;
    printf("	| ------------------------------------------------|\n");
    printf("	|                    查询子菜单项                 |\n");
    printf("	| ------------------------------------------------|\n");
    printf("	|                    1---按照学生编号查询           |\n");
    printf("	|                    2---按照学生姓名查询             |\n");
    printf("	|                    0---返回主菜单               |\n");
    printf("	| ------------------------------------------------|\n");
    do
    {
        printf("\n请输入菜单项数字(0-2):");
        fflush(stdin);
        scanf("%d",&menu);
    }while(menu<0||menu>2);
    
    switch(menu)
    {
        case 1:
            searchByNum(s,r);
            break;
        case 2:
            searchByName(s,r);
            break;
    }
}
int searchByNum(Student *s,Referee *r)//学号查询
{
    int a;
    int i;
    int flag=1;
    while(flag)
    {
        cout<<"请输出要查找的学生编号";
        cin>>a;
        
        for(i=0; i<s[0].f; )
        {
            if(s[i].no!=a)
            {
                i++;
            }
            else{
                break;
            }
        }
        if(i>=s[0].f||a<=0)
        {
            cout<<"该学生编号不存在"<<endl;
            for(i=0; i<=0; )
            {
                cout<<"是否要重新输入（Y/N）:";
                char c;
                cin>>c;
                if(c=='y'||c=='Y')
                {
                    
                    i++;
                }
                else{
                    return 0;
                }
            }
            
        }
        else
        {
            cout<<"编号为"<<s[i].no<<"的学生";
            cout<<"姓名是：";
            cout<<s[i].name<<endl;
            cout<<"性别：";
            cout<<s[i].sex<<endl;
            cout<<"节目名称：";
            cout<<s[i].Program<<endl;
            cout<<"表演形式：";
            cout<<s[i].form<<endl;
            cout<<"班级：";
            cout<<s[i].Class<<endl;
            cout<<"电话号：";
            cout<<s[i].tel<<endl;
            cout<<"第一个评委"<<r[0].name<<"的打分为：";
            cout<<s[i].score[0]<<endl;
            cout<<"第二个评委"<<r[1].name<<"的打分为：";
            cout<<s[i].score[1]<<endl;
            cout<<"第三个评委"<<r[2].name<<"的打分为：";
            cout<<s[i].score[2]<<endl;
            cout<<"第四个评委"<<r[3].name<<"的打分为：";
            cout<<s[i].score[3]<<endl;
            cout<<"第五个评委"<<r[4].name<<"的打分为：";
            cout<<s[i].score[4]<<endl;
            cout<<"去掉一个最低成绩为：";
            cout<<s[i].min<<endl;
            cout<<"去掉一个最高成绩为：";
            cout<<s[i].max<<endl;
            cout<<"平均分是：";
            cout<<s[i].avg<<endl;
            flag=0;
        }
        
    }
    return 0;
}
int searchByName(Student *s,Referee *r)//姓名查询
{
    string S;
    int i;
    int flag=1;
    int n;
    while(flag)
    {
        cout<<"请输出要查找的学生编号";
        cin>>S;
        
        for(i=0; i<s[0].f; )
        {
            if(s[i].name!=S)
            {
                i++;
            }
            else{
                break;
            }
        }
        if(i>=s[0].f)
        {
            cout<<"该学生编号不存在"<<endl;
            for(n=0; n<=0; )
            {
                cout<<"是否要重新输入（Y/N）:";
                char c;
                cin>>c;
                if(c=='y'||c=='Y')
                {
                    
                    n++;
                }
                else{
                    return 0;
                }
            }
            
        }
        else
        {
            cout<<"编号为"<<s[i].no<<"的学生";
            cout<<"姓名是：";
            cout<<s[i].name<<endl;
            cout<<"性别：";
            cout<<s[i].sex<<endl;
            cout<<"节目名称：";
            cout<<s[i].Program<<endl;
            cout<<"表演形式：";
            cout<<s[i].form<<endl;
            cout<<"班级：";
            cout<<s[i].Class<<endl;
            cout<<"电话号：";
            cout<<s[i].tel<<endl;
            cout<<"第一个评委"<<r[0].name<<"的打分为：";
            cout<<s[i].score[0]<<endl;
            cout<<"第二个评委"<<r[1].name<<"的打分为：";
            cout<<s[i].score[1]<<endl;
            cout<<"第三个评委"<<r[2].name<<"的打分为：";
            cout<<s[i].score[2]<<endl;
            cout<<"第四个评委"<<r[3].name<<"的打分为：";
            cout<<s[i].score[3]<<endl;
            cout<<"第五个评委"<<r[4].name<<"的打分为：";
            cout<<s[i].score[4]<<endl;
            cout<<"去掉一个最低成绩为：";
            cout<<s[i].min<<endl;
            cout<<"去掉一个最高成绩为：";
            cout<<s[i].max<<endl;
            cout<<"平均分是：";
            cout<<s[i].avg<<endl;
            flag=0;
        }
        
    }
    
    return 0;
}
void writestu(Student *s)//写入学生文件函数
{
    int i;
    int j;
    FILE* fp;
    int k;
    fp = fopen("//Users//Madara-Fq//Desktop//system//score.csv", "w");
    if(fp == NULL)
        printf("The file can't be opened!\n");
    else
    {
        fprintf(fp,"学生编号,一号评委打分,二号评委打分,三号评委打分,四号评委打分,五号评委打分,最高分,最低分,学生平均成绩,学生排名,学生姓名,学生性别,节目名称,表演形式,学生班级,学生电话, \n");
        for(i=1 ;i<=5; i++)
        {
            k=1;
            for(j=stu[i][0].f-1; j>=0; j--)
            {
                
                fprintf(fp,"%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%s,%s,%s,%s,%s,%s,学生%d\n",stu[i][j].no,stu[i][j].score[0],stu[i][j].score[1],stu[i][j].score[2],stu[i][j].score[3],stu[i][j].score[4],stu[i][j].max,stu[i][j].min,stu[i][j].avg,stu[i][j].rank,stu[i][j].name.c_str(),stu[i][j].sex.c_str(),stu[i][j].Program.c_str(),stu[i][j].form.c_str(),stu[i][j].Class.c_str(),stu[i][j].tel.c_str(),k);
                k++;
            }
            
        }
        printf("信息保存成功！\n");
        fclose(fp);
    }
}

void writeref(Referee *r)//写入裁判文件函数 
{
    FILE* fp;
    int k;
    int i;
    fp = fopen("//Users//Madara-Fq//Desktop//system//referee.csv", "w");
    if(fp == NULL)
        printf("The file can't be opened!\n");
    else
    {
        k=1;
        fprintf(fp,"裁判姓名,裁判性别,裁判电话号, \n");
        for(i=0; i<5; i++)
        {
            fprintf(fp,"%s,%s,%s,裁判%d\n",r[i].name.c_str(),r[i].sex.c_str(),r[i].tel.c_str(),k);
            k++;
        }
    }
}

int readstu(Student *s)//读取学生文件函数
{
    int i = 0;
    int j;
    int k;
    int o;
    int n;
    int l;
    char sum[100];
    //char name[20];
    //char tel[20];
    int no;
    double score[10];
    double max,min;
    //char sex[20];
    //char Program[20];
    //char form[20];
    //char Class[20];
    double avg;
    int rank;
    FILE* fp;
    fp = fopen("//Users//Madara-Fq//Desktop//system//score.csv", "r");
    if(fp == NULL)
        printf("The file can't be opened!\n");
    else
    {
        fscanf(fp,"学生编号,一号评委打分,二号评委打分,三号评委打分,四号评委打分,五号评委打分,最高分,最低分,学生平均成绩,学生排名,学生姓名,学生性别,节目名称,表演形式,学生班级,学生电话, \n");
        while(fscanf(fp,"%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%s\n",&no,&score[0],&score[1],&score[2],&score[3],&score[4],&max,&min,&avg,&rank,sum)!=EOF)
        {
            //cout<<sum<<endl;
            s[i].no=no;
            s[i].score[0]=score[0];
            s[i].score[1]=score[1];
            s[i].score[2]=score[2];
            s[i].score[3]=score[3];
            s[i].score[4]=score[4];
            s[i].min=min;
            s[i].max=max;
            s[i].rank=rank;
            s[i].avg=avg;
            k=0;
            n=0;
            for(j=0; j<strlen(sum); j++)
            {
                if(sum[j]==','&&j<strlen(sum)-1)
                {
                    l=0;
                    for(o=n; o<j; o++)
                    {
                        s[i].m[k][l]=sum[o];
                        l++;
                    }
                    //cout<<s[i].m[k]<<endl;
                    k++;
                    n=j+1;
                }
                //cout<<n<<" ";
                //cout<<k<<endl;
            }
            s[i].name=s[i].m[0];
            s[i].sex=s[i].m[1];
            s[i].Program=s[i].m[2];
            s[i].form=s[i].m[3];
            //cout<<s[i].m[3]<<endl;
            if(s[i].form=="MUSIC"||s[i].form=="music")
            {
                s[i].pro=1;
            }
            else if(s[i].form=="DANCE"||s[i].form=="dance")
            {
                s[i].pro=2;
            }
            else if(s[i].form=="OPU"||s[i].form=="opu")
            {
                s[i].pro=3;
            }
            else if(s[i].form=="DIA"||s[i].form=="dia")
            {
                s[i].pro=4;
            }
            else if(s[i].form=="MAGIC"||s[i].form=="magic")
            {
                s[i].pro=5;
            }
            else
            {
                s[i].pro=0;
            }
            s[i].Class=s[i].m[4];
            s[i].tel=s[i].m[5];
            i++;
        }
        
        
    }
    fclose(fp);
    //cout<<i<<endl;
    return i;
    
    
}


int readref(Referee *r)//读取裁判文件函数
{
    FILE* fp;
    char sum[100];
    int i;
    int j,l,o,n,k;
    fp = fopen("//Users//Madara//Desktop//system//referee.csv", "r");
    if(fp == NULL)
        printf("The file can't be opened!\n");
    else
    {
        i=0;
        fscanf(fp,"裁判姓名,裁判性别,裁判电话号, \n");
        while(fscanf(fp,"%s",sum)!=EOF)
        {
            k=0;
            n=0;
            for(j=0; j<strlen(sum); j++)
            {
                if(sum[j]==',')
                {
                    l=0;
                    for(o=n; o<j; o++)
                    {
                        r[i].m[k][l]=sum[o];
                        l++;
                    }
                    k++;
                    n=j+1;
                }
                //cout<<n<<" ";
                //cout<<k<<endl;
            }
            r[i].name=r[i].m[0];
            r[i].sex=r[i].m[1];
            r[i].tel=r[i].m[2];
            i++;
        }
    }
    return 0;
}

void inputscore(Student *s)//输入学生成绩函数
{
    int i;
    int j;
    int flag=1;
    while(flag)
    {
        cout<<"请输入要评分的学生编号"<<endl;
        int n;
        cin>>n;
        for(i=0; i<s[0].f; )
        {
            if(s[i].no!=n)
            {
                i++;
            }
            else{
                break;
            }
        }
        
        if(i>=s[0].f||n<=0)
        {
            cout<<"该学生编号不存在，请重新输入"<<endl;
        }
        else
        {
            cout<<"请输入第一个评委打分:"<<endl;
            cin>>s[i].score[0];
            cout<<"请输入第二个评委打分:"<<endl;
            cin>>s[i].score[1];
            cout<<"请输入第三个评委打分:"<<endl;
            cin>>s[i].score[2];
            cout<<"请输入第四个评委打分:"<<endl;
            cin>>s[i].score[3];
            cout<<"请输入第五个评委打分:"<<endl;
            cin>>s[i].score[4];
            
            s[i].min=s[i].score[0];
            for(j=0; j<5; j++)
            {
                if(s[i].score[j]<s[i].min)
                {
                    s[i].min=s[i].score[j];
                }
            }
            
            s[i].max=s[i].score[0];
            for(j=0; j<5; j++)
            {
                if(s[i].score[j]>s[i].max)
                {
                    s[i].max=s[i].score[j];
                }
            }
            s[i].avg=(s[i].score[0]+s[i].score[1]+s[i].score[2]+s[i].score[3]+s[i].score[4]-s[i].min-s[i].max)/3;
            flag=0;
        }
    }
    
    
    
}

int inputstuinf(Student *s)//输入学生信息函数
{
    int n;
    int i;
    cout<<"请输入参赛者信息"<<endl;
    int flag=1;
    while(flag)
    {
        cout<<"请输入学生编号"<<endl;
        cin>>n;
        for(i=0; i<s[0].f; )
        {
            if(s[i].no!=n)
            {
                i++;
            }
            else{
                break;
            }
        }
        if(i<s[0].f)
        {
            cout<<"该学生编号已存在，请重新输入"<<endl;
        }
        else
        {
            
            s[s[0].f].no=n;
            cout<<"请输入姓名：";
            cin>>s[s[0].f].name;
            cout<<"请输入性别：";
            cin>>s[s[0].f].sex;
            cout<<"请输入节目名称：";
            cin>>s[s[0].f].Program;
            cout<<"请输入表演形式：";
            cin>>s[s[0].f].form;
            if(s[s[0].f].form=="singing"||s[s[0].f].form=="music")
            {
                s[s[0].f].pro=1;
            }
            else if(s[s[0].f].form=="dancing"||s[s[0].f].form=="dance")
            {
                s[s[0].f].pro=2;
            }
            else if(s[s[0].f].form=="comedy"||s[s[0].f].form=="com")
            {
                s[s[0].f].pro=3;
            }
            else if(s[s[0].f].form=="tragedy"||s[s[0].f].form=="tra")
            {
                s[s[0].f].pro=4;
            }
            else if(s[s[0].f].form=="MAGIC"||s[s[0].f].form=="magic")
            {
                s[s[0].f].pro=5;
            }
            else
            {
                s[s[0].f].pro=0;
            }
            cout<<"请输入班级：";
            cin>>s[s[0].f].Class;
            cout<<"请输入电话号:";
            cin>>s[s[0].f].tel;
            s[0].f++;
            flag=0;
        }
        
    }
    return 0;
}

void inputref(Referee *r)//输入裁判信息函数
{
    int i;
    for(i=0; i<5; i++)
    {
        cout<<"请输入第"<<i+1<<"号裁判的姓名:";
        cin>>r[i].name;
        cout<<"请输入第"<<i+1<<"号裁判的性别:";
        cin>>r[i].sex;
        cout<<"请输入第"<<i+1<<"号裁判的电话号:";
        cin>>r[i].tel;
    }
}

void outputallinf(Student *s,Referee *r)//输出裁判与学生信息函数
{
    int i;
    
    for(i=0; i<s[0].f; i++)
    {
        cout<<"编号为"<<s[i].no<<"的学生";
        cout<<"姓名是：";
        cout<<s[i].name<<endl;
        cout<<"性别：";
        cout<<s[i].sex<<endl;
        cout<<"节目名称：";
        cout<<s[i].Program<<endl;
        cout<<"表演形式：";
        cout<<s[i].form<<endl;
        cout<<"班级：";
        cout<<s[i].Class<<endl;
        cout<<"电话号：";
        cout<<s[i].tel<<endl;
        cout<<"第一个评委"<<r[0].name<<"的打分为：";
        cout<<s[i].score[0]<<endl;
        cout<<"第二个评委"<<r[1].name<<"的打分为：";
        cout<<s[i].score[1]<<endl;
        cout<<"第三个评委"<<r[2].name<<"的打分为：";
        cout<<s[i].score[2]<<endl;
        cout<<"第四个评委"<<r[3].name<<"的打分为：";
        cout<<s[i].score[3]<<endl;
        cout<<"第五个评委"<<r[4].name<<"的打分为：";
        cout<<s[i].score[4]<<endl;
        cout<<"去掉一个最低成绩为：";
        cout<<s[i].min<<endl;
        cout<<"去掉一个最高成绩为：";
        cout<<s[i].max<<endl;
        cout<<"平均分是：";
        cout<<s[i].avg<<endl;
        
    }
}
