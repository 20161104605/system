#include"define.h"
#include <iostream>
#include <cstring>
#include <String>
#include <stdio.h>
#include <sstream>
#include <fstream>
using namespace std;
 
int menu_select()//�˵�
{
    int MenuItem;
    
    printf("\n ");
    printf("         | *********����ϵͳ********* |           \n");
    printf("          | ---------------------------------- |          \n");
    printf("          |              ���˵���              |          \n");
    printf("          | ---------------------------------- |          \n");
    printf("          |	  1 --- ¼��ѧ����Ϣ  	       |          	  \n");
    printf("          |	  2 --- ¼�������Ϣ	       |              \n");
    printf("          |	  3 --- ¼��ѧ���ɼ�	       |              \n");
    printf("          |	  4 --- ��ѯ��Ϣ	           |              \n");
    printf("          |	  5 --- ���������Ϣ	       |              \n");
    printf("          |	  6 --- ����ϵͳ	           |              \n");
    printf("          |	  7 --- ��ѧ��������Ϣд���ļ����˳�|              \n");
    
    do
    {
        printf("\n������ѡ�1��7����");
        fflush(stdin);
        scanf("%d",&MenuItem);
    }while(MenuItem<1||MenuItem>7);
    
    return MenuItem;
}
void Sort(Student *s)/*����*/ 
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
        cout<<"��"<<stu[i][0].f<<"��"<<"   "<<"������ʽ��"<<stu[i][0].form<<endl;
        for(j=stu[i][0].f-1; j>=0; j--)
        {
            stu[i][j].rank=n;
            cout<<"ѧ�����:   ";
            cout<<stu[i][j].no<<endl;
            cout<<"ѧ������:   ";
            cout<<stu[i][j].name<<endl;
            cout<<"ѧ���Ա�:   ";
            cout<<stu[i][j].sex<<endl;
            cout<<"��Ŀ����:   ";
            cout<<stu[i][j].Program<<endl;
            cout<<"ѧ���༶:   ";
            cout<<stu[i][j].Class<<endl;
            cout<<"ѧ���绰:   ";
            cout<<stu[i][j].tel<<endl;
            cout<<"ѧ���ɼ�:   ";
            cout<<stu[i][j].avg<<endl;
            cout<<"ѧ������:   ";
            cout<<stu[i][j].rank<<endl;
            
            n++;
        }
        
    }
    
}
int change(Student *s)//�޸ĺ���
{
    int a;
    int i;
    int Num;
    int flag=1;
    struct Student x;
    int j;
    cout<<"�����Ҫ���ҵ�ѧ�����";
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
        cout<<"��ѧ����Ų����ڣ�����������"<<endl;
    }
    else
    {
        
        cout<<"�޸�ѧ����Ϣ������1���޸�ѧ���ɼ�������2��1/2��";
        cin>>Num;
        while(flag)
        {
            if(Num<1||Num>2)
            {
                cout<<"����������������룺";
                cin>>Num;
            }
            else if(Num==1)
            {
                cout<<"������������";
                cin>>x.name;
                s[i].name=x.name;
                cout<<"�������Ա�";
                cin>>x.sex;
                s[i].sex=x.sex;
                cout<<"�������Ŀ���ƣ�";
                cin>>x.Program;
                s[i].Program=x.Program;
                cout<<"�����������ʽ��";
                cin>>x.form;
                s[i].form=x.form;
                cout<<"������༶��";
                cin>>x.Class;
                s[i].Class=x.Class;
                cout<<"������绰��:";
                cin>>x.tel;
                s[i].tel=x.tel;
                flag=0;
            }
            else if(Num==2)
            {
                cout<<"�������һ����ί���:"<<endl;
                cin>>x.score[0];
                s[i].score[0]=x.score[0];
                cout<<"������ڶ�����ί���:"<<endl;
                cin>>x.score[1];
                s[i].score[1]=x.score[1];
                cout<<"�������������ί���:"<<endl;
                cin>>x.score[2];
                s[i].score[2]=x.score[2];
                cout<<"��������ĸ���ί���:"<<endl;
                cin>>x.score[3];
                s[i].score[3]=x.score[3];
                cout<<"������������ί���:"<<endl;
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
void searchlistmenu(Student * s,Referee *r)//��ѯ�˵�
{
    int menu;
    printf("	| ------------------------------------------------|\n");
    printf("	|                    ��ѯ�Ӳ˵���                 |\n");
    printf("	| ------------------------------------------------|\n");
    printf("	|                    1---����ѧ����Ų�ѯ           |\n");
    printf("	|                    2---����ѧ��������ѯ             |\n");
    printf("	|                    0---�������˵�               |\n");
    printf("	| ------------------------------------------------|\n");
    do
    {
        printf("\n������˵�������(0-2):");
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
int searchByNum(Student *s,Referee *r)//ѧ�Ų�ѯ
{
    int a;
    int i;
    int flag=1;
    while(flag)
    {
        cout<<"�����Ҫ���ҵ�ѧ�����";
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
            cout<<"��ѧ����Ų�����"<<endl;
            for(i=0; i<=0; )
            {
                cout<<"�Ƿ�Ҫ�������루Y/N��:";
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
            cout<<"���Ϊ"<<s[i].no<<"��ѧ��";
            cout<<"�����ǣ�";
            cout<<s[i].name<<endl;
            cout<<"�Ա�";
            cout<<s[i].sex<<endl;
            cout<<"��Ŀ���ƣ�";
            cout<<s[i].Program<<endl;
            cout<<"������ʽ��";
            cout<<s[i].form<<endl;
            cout<<"�༶��";
            cout<<s[i].Class<<endl;
            cout<<"�绰�ţ�";
            cout<<s[i].tel<<endl;
            cout<<"��һ����ί"<<r[0].name<<"�Ĵ��Ϊ��";
            cout<<s[i].score[0]<<endl;
            cout<<"�ڶ�����ί"<<r[1].name<<"�Ĵ��Ϊ��";
            cout<<s[i].score[1]<<endl;
            cout<<"��������ί"<<r[2].name<<"�Ĵ��Ϊ��";
            cout<<s[i].score[2]<<endl;
            cout<<"���ĸ���ί"<<r[3].name<<"�Ĵ��Ϊ��";
            cout<<s[i].score[3]<<endl;
            cout<<"�������ί"<<r[4].name<<"�Ĵ��Ϊ��";
            cout<<s[i].score[4]<<endl;
            cout<<"ȥ��һ����ͳɼ�Ϊ��";
            cout<<s[i].min<<endl;
            cout<<"ȥ��һ����߳ɼ�Ϊ��";
            cout<<s[i].max<<endl;
            cout<<"ƽ�����ǣ�";
            cout<<s[i].avg<<endl;
            flag=0;
        }
        
    }
    return 0;
}
int searchByName(Student *s,Referee *r)//������ѯ
{
    string S;
    int i;
    int flag=1;
    int n;
    while(flag)
    {
        cout<<"�����Ҫ���ҵ�ѧ�����";
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
            cout<<"��ѧ����Ų�����"<<endl;
            for(n=0; n<=0; )
            {
                cout<<"�Ƿ�Ҫ�������루Y/N��:";
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
            cout<<"���Ϊ"<<s[i].no<<"��ѧ��";
            cout<<"�����ǣ�";
            cout<<s[i].name<<endl;
            cout<<"�Ա�";
            cout<<s[i].sex<<endl;
            cout<<"��Ŀ���ƣ�";
            cout<<s[i].Program<<endl;
            cout<<"������ʽ��";
            cout<<s[i].form<<endl;
            cout<<"�༶��";
            cout<<s[i].Class<<endl;
            cout<<"�绰�ţ�";
            cout<<s[i].tel<<endl;
            cout<<"��һ����ί"<<r[0].name<<"�Ĵ��Ϊ��";
            cout<<s[i].score[0]<<endl;
            cout<<"�ڶ�����ί"<<r[1].name<<"�Ĵ��Ϊ��";
            cout<<s[i].score[1]<<endl;
            cout<<"��������ί"<<r[2].name<<"�Ĵ��Ϊ��";
            cout<<s[i].score[2]<<endl;
            cout<<"���ĸ���ί"<<r[3].name<<"�Ĵ��Ϊ��";
            cout<<s[i].score[3]<<endl;
            cout<<"�������ί"<<r[4].name<<"�Ĵ��Ϊ��";
            cout<<s[i].score[4]<<endl;
            cout<<"ȥ��һ����ͳɼ�Ϊ��";
            cout<<s[i].min<<endl;
            cout<<"ȥ��һ����߳ɼ�Ϊ��";
            cout<<s[i].max<<endl;
            cout<<"ƽ�����ǣ�";
            cout<<s[i].avg<<endl;
            flag=0;
        }
        
    }
    
    return 0;
}
void writestu(Student *s)//д��ѧ���ļ�����
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
        fprintf(fp,"ѧ�����,һ����ί���,������ί���,������ί���,�ĺ���ί���,�����ί���,��߷�,��ͷ�,ѧ��ƽ���ɼ�,ѧ������,ѧ������,ѧ���Ա�,��Ŀ����,������ʽ,ѧ���༶,ѧ���绰, \n");
        for(i=1 ;i<=5; i++)
        {
            k=1;
            for(j=stu[i][0].f-1; j>=0; j--)
            {
                
                fprintf(fp,"%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%s,%s,%s,%s,%s,%s,ѧ��%d\n",stu[i][j].no,stu[i][j].score[0],stu[i][j].score[1],stu[i][j].score[2],stu[i][j].score[3],stu[i][j].score[4],stu[i][j].max,stu[i][j].min,stu[i][j].avg,stu[i][j].rank,stu[i][j].name.c_str(),stu[i][j].sex.c_str(),stu[i][j].Program.c_str(),stu[i][j].form.c_str(),stu[i][j].Class.c_str(),stu[i][j].tel.c_str(),k);
                k++;
            }
            
        }
        printf("��Ϣ����ɹ���\n");
        fclose(fp);
    }
}

void writeref(Referee *r)//д������ļ����� 
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
        fprintf(fp,"��������,�����Ա�,���е绰��, \n");
        for(i=0; i<5; i++)
        {
            fprintf(fp,"%s,%s,%s,����%d\n",r[i].name.c_str(),r[i].sex.c_str(),r[i].tel.c_str(),k);
            k++;
        }
    }
}

int readstu(Student *s)//��ȡѧ���ļ�����
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
        fscanf(fp,"ѧ�����,һ����ί���,������ί���,������ί���,�ĺ���ί���,�����ί���,��߷�,��ͷ�,ѧ��ƽ���ɼ�,ѧ������,ѧ������,ѧ���Ա�,��Ŀ����,������ʽ,ѧ���༶,ѧ���绰, \n");
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


int readref(Referee *r)//��ȡ�����ļ�����
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
        fscanf(fp,"��������,�����Ա�,���е绰��, \n");
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

void inputscore(Student *s)//����ѧ���ɼ�����
{
    int i;
    int j;
    int flag=1;
    while(flag)
    {
        cout<<"������Ҫ���ֵ�ѧ�����"<<endl;
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
            cout<<"��ѧ����Ų����ڣ�����������"<<endl;
        }
        else
        {
            cout<<"�������һ����ί���:"<<endl;
            cin>>s[i].score[0];
            cout<<"������ڶ�����ί���:"<<endl;
            cin>>s[i].score[1];
            cout<<"�������������ί���:"<<endl;
            cin>>s[i].score[2];
            cout<<"��������ĸ���ί���:"<<endl;
            cin>>s[i].score[3];
            cout<<"������������ί���:"<<endl;
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

int inputstuinf(Student *s)//����ѧ����Ϣ����
{
    int n;
    int i;
    cout<<"�������������Ϣ"<<endl;
    int flag=1;
    while(flag)
    {
        cout<<"������ѧ�����"<<endl;
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
            cout<<"��ѧ������Ѵ��ڣ�����������"<<endl;
        }
        else
        {
            
            s[s[0].f].no=n;
            cout<<"������������";
            cin>>s[s[0].f].name;
            cout<<"�������Ա�";
            cin>>s[s[0].f].sex;
            cout<<"�������Ŀ���ƣ�";
            cin>>s[s[0].f].Program;
            cout<<"�����������ʽ��";
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
            cout<<"������༶��";
            cin>>s[s[0].f].Class;
            cout<<"������绰��:";
            cin>>s[s[0].f].tel;
            s[0].f++;
            flag=0;
        }
        
    }
    return 0;
}

void inputref(Referee *r)//���������Ϣ����
{
    int i;
    for(i=0; i<5; i++)
    {
        cout<<"�������"<<i+1<<"�Ų��е�����:";
        cin>>r[i].name;
        cout<<"�������"<<i+1<<"�Ų��е��Ա�:";
        cin>>r[i].sex;
        cout<<"�������"<<i+1<<"�Ų��еĵ绰��:";
        cin>>r[i].tel;
    }
}

void outputallinf(Student *s,Referee *r)//���������ѧ����Ϣ����
{
    int i;
    
    for(i=0; i<s[0].f; i++)
    {
        cout<<"���Ϊ"<<s[i].no<<"��ѧ��";
        cout<<"�����ǣ�";
        cout<<s[i].name<<endl;
        cout<<"�Ա�";
        cout<<s[i].sex<<endl;
        cout<<"��Ŀ���ƣ�";
        cout<<s[i].Program<<endl;
        cout<<"������ʽ��";
        cout<<s[i].form<<endl;
        cout<<"�༶��";
        cout<<s[i].Class<<endl;
        cout<<"�绰�ţ�";
        cout<<s[i].tel<<endl;
        cout<<"��һ����ί"<<r[0].name<<"�Ĵ��Ϊ��";
        cout<<s[i].score[0]<<endl;
        cout<<"�ڶ�����ί"<<r[1].name<<"�Ĵ��Ϊ��";
        cout<<s[i].score[1]<<endl;
        cout<<"��������ί"<<r[2].name<<"�Ĵ��Ϊ��";
        cout<<s[i].score[2]<<endl;
        cout<<"���ĸ���ί"<<r[3].name<<"�Ĵ��Ϊ��";
        cout<<s[i].score[3]<<endl;
        cout<<"�������ί"<<r[4].name<<"�Ĵ��Ϊ��";
        cout<<s[i].score[4]<<endl;
        cout<<"ȥ��һ����ͳɼ�Ϊ��";
        cout<<s[i].min<<endl;
        cout<<"ȥ��һ����߳ɼ�Ϊ��";
        cout<<s[i].max<<endl;
        cout<<"ƽ�����ǣ�";
        cout<<s[i].avg<<endl;
        
    }
}
