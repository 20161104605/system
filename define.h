#include <iostream>
#include <cstring>
#include <String>
#include <stdio.h>
#include <sstream>
#include <fstream>
using namespace std;

struct Student
{
    int no;//ѧ�����
    string name;//ѧ������
    string sex;//ѧ���Ա�
    string Program;//��Ŀ����
    string form;//������ʽ
    string Class;//ѧ���༶
    string tel;//ѧ���绰
    int f;//������
    double score[10];//ѧ���ɼ�
    double min;//��ͷ�
    double max;//��߷�
    double avg;//ƽ����
    int pro;//���ݷ�ʽ����ֵ
    int rank;//����
    char m[20][20];//��ʼ����
};
struct Referee
{
    string name;//��������
    string sex;//�����Ա�
    string tel;//���е绰
    char m[20][20];//��ʼ������
};

/*����������*/ 
void searchlistmenu(Student * s,Referee *r);
int searchByNum(Student *s,Referee *r);
int searchByName(Student *s,Referee *r);
void inputscore(Student *s);
int inputstuinf(Student *s);
void inputref(Referee *r);
void outputallinf(Student *s,int n,Referee *r);
int change(Student *s);
int readstu(Student *s);
void writestu(Student *s);
int readref(Referee *r);
void writeref(Referee *r);

//ȫ�ֱ���
struct Student s[100];
struct Referee r[100];
struct Student stu[100][100];

//��Ŀ���ƺ궨��
//#define music 1/*����*/
//#define dance 2/*�赸*/
//#define com 3/*ϲ��*/ 
//#define tra 4/*����*/ 
//#define magic 5/*ħ��*/ 
