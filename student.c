//
// Created by 86137 on 2023/7/11.
//
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "stu.h"
//通过平均成绩排序
void Sort_select(STU *head) {
    STU *p, *q;
    int score[20], num, class;
    char name[20], major[20];
    Inputstu(head);
    p = head->next;
    if (p == NULL) {
        printf("不存在该成绩！\n");
    } else {
        while (p->next != NULL) {
            q = p->next;  //第一重循环
            while (q != NULL) {  //如果p的总分大于q的总分
                if ((p->score[0] + p->score[1] + p->score[2]) > (q->score[0] + q->score[1] + q->score[2])) {
                    num = p->num;                  //交换他们的所有信息
                    p->num = q->num;
                    q->num = num;
                    strcpy(name, p->name);
                    strcpy(p->name, q->name);
                    strcpy(q->name, name);
                    strcpy(major, p->major);
                    strcpy(p->major, q->major);
                    strcpy(q->major, major);
                    class = p->classNo;
                    p->classNo = q->classNo;
                    q->classNo = class;
                    for (int j = 0; j < 3; j++) {
                        score[j] = p->score[j];
                        p->score[j] = q->score[j];
                        q->score[j] = score[j];
                    }
                }
                q = q->next;  //第一重循环往下走
            }
            p = p->next;   //第二重循环往下走
        }
    }
    p=head;
    Output(p);   //输出排序后的信息
    YesNo(p);
}

//输入学生信息，若不存在该班级或专业则提示并要求重新输入
void Input(STU *p){
    int i;
    char *str1="computer";
    char *str2="network";
    char *str3="software";
    printf("\n请输入学号; \n");
    scanf("%d", &p->num);
    getchar();
    printf("\n请输入姓名; \n");
    scanf("%s",p->name);
    printf("请输入专业(computer/network/software)??\n");
    scanf("%s",p->major);
    if((strcmp(p->major,str1)!=0)&&(strcmp(p->major,str2)!=0)&&(strcmp(p->major,str3)!=0)){
        for(int k=0;;k++) {
            printf("不存在该专业，请重新输入(computer/software/network)");
            scanf("%s",p->major);
            if((strcmp(p->major,str1)==0)||(strcmp(p->major,str2)==0)||(strcmp(p->major,str3)==0)){
                printf("\n输入成功\n");
                break;
            }
        }
    }
    printf("请输入班级：（1班/2班）\n");
    scanf("%d",&p->classNo);
    if((p->classNo!=1)&&(p->classNo!=2)&&(p->classNo!=3)){
        for(int t=0;;t++) {
            printf("不存在该班级，请重新输入班级：（1班/2班）");
            scanf("%d", &p->classNo);
            if((p->classNo>0)&&(p->classNo<4)){
                printf("\n输入成功\n");
                break;
            }
        }
    }
    getchar();
    printf("\n请依次输入每门成绩; \n");
    for (i = 0; i < 3; i++) {
        scanf("%d", &p->score[i]);
        getchar();
    }
}

//从文件中输出学生信息
void Inputstu(STU *head){
    STU *p1,*p2;
    FILE *fp;
    char filename[20];
    printf("请输入要打开的文件名（*.dat）");
    scanf("%s",filename);
    if((fp= fopen(filename,"rb"))==NULL){
        printf("error");
    }
    p2=head;
    do {
        p1=(STU*) malloc(LEN);
        fread(p1,LEN,1,fp);
        p2->next=p1;
        p2=p2->next;
    } while (p1->next!=NULL);
    fclose(fp);
}

//输出链表的所有信息
void Output(STU *head){
    STU *r=head->next;
    if(r==NULL){
        printf("此链表为空。\n");
    }else {
        do {
            printf("\n姓名：%5s\t学号：%5d\t专业:%s\t班级：%d\t成绩：%d\t%d\t%d\n", r->name, r->num, r->major, r->classNo,
                   r->score[0], r->score[1], r->score[2]);
            r = r->next;
        } while (r != NULL);
    }
}

//将链表保存进新文件，若成功保存则输出finish
STU *CreateList(char *filename,STU *head) {
    STU *q;
    FILE *fp;
    fp=fopen(filename, "wb");
    q=head->next;
    if(q==NULL){
        printf("此链表为空链表！");
        return 0;
    }
    do{
        fwrite(q, sizeof(STU),1,fp);
        q=q->next;
    } while (q!=NULL);
    fclose(fp);
    printf("finish\n");
    return head;
}

//输出一个结点的信息
void OutOneNode(STU *p) {
    printf("\n姓名：%5s\t学号：%5d\t专业:%s\t班级：%d\t成绩：%d\t%d\t%d\n", p->name, p->num, p->major, p->classNo,
           p->score[0], p->score[1], p->score[2]);
}

//查找出所有学生中总分最高的学生
void Max(STU *head){
    STU *p1;
    int index=0;
    int sum[20];
    int count=0;
    Inputstu(head);
    p1=head;
    for(int i=0;i<N;i++){
        p1=p1->next;
        sum[count++]=p1->score[0]+p1->score[1]+p1->score[2];
    }
    for(int t=0;t<count;t++){
        if(sum[t]>sum[index])
            index=t;
    }
    p1=head;
    for (int j = 0; j < count; j++) {
        p1=p1->next;
        if(sum[j]==sum[index]){
            printf("最高分的学生成绩为：\n");
            OutOneNode(p1);
            YesNo(p1);
        }
    }
}

//通过学号查找学生信息
void Search_num(STU * head ,int num){
    STU *p1,*p2;
    int id[20];
    int a=0;
    Inputstu(head);
    p1=head->next;
    for (int i = 0; p1!=NULL; i++) {
        id[i]=p1->num;
        p1=p1->next;
    }
    p2=head->next;
    for (int t = 0; p2!=NULL; t++) {
        if(id[t]==num){
            printf("该学生信息为：\n");
            OutOneNode(p2);
            YesNo(p2);
            a=1;
        }
        p2=p2->next;
    }
    if(a!=1){
        printf("不存在该学生！\n");
    }
}

//通过学号插入学生信息，并保证学号的有序性
void  InsertList(STU * head, STU stu){
    STU *p,*q;
    int id[20];
    int ID=stu.num;
    int count=0;
    Inputstu(head);
    p=head->next;
    for (int t = 0; p!=NULL; t++) {
        id[count++]=p->num;
        p=p->next;
    }
    p=head->next;
    q=&stu;
    for(int i=0;p!=NULL;i++) {
        if (ID == id[i]) {  //如果已经存在该学生
            printf("学生已存在，不可插入此信息\n");
            break;
        } else {
            if (ID < id[0]) {  //如果为第一个学生
                q->next = p;
                head->next = q;
                p=head;
                Output(p);
                YesNo(p);
                break;
            } else if (ID < id[i + 1]) { //如果插入在中间
                q->next = p->next;
                p->next = q;
                p=head;
                Output(p);
                YesNo(p);
                break;
            } else {
                if (p->next == NULL) {  //如果插入在尾部
                    p->next = q;
                    q->next = NULL;
                    p=head;
                    Output(p);
                    YesNo(p);
                    break;
                }
            }
        }
        p = p->next;
    }
}

//从链表中删除指定学号的学生
void  Delete_num(STU *head,int num){
    STU *p,*q;
    int b=0;
    Inputstu(head);
    p=head->next;
    q=head;
    for (int i = 0; i < N; i++) {
        if(p->num==num) {
            q->next=p->next;
            //free(p);
            b=1;
        }    //如果有相同学号的
        else{
            q=p;
            p=p->next;    //令q指针指向学号相同的学生信息处并输出q
        }
    }
    if(b!=1){  //若查找不到
        printf("不存在该学生。\n");
    }else{
        p=head;
        Output(p);
        YesNo(p);
    }
}

//从链表中删除指定姓名的学生
void  Delete_name(STU *head,char name[10]){
    STU *p,*q;
    int b=0;
    Inputstu(head);
    p=head->next;
    q=head;
    for (int i = 0; i < N; i++) {
        if(strcmp(p->name,name)==0){
            q->next=p->next;
            //free(p);
            b=1;
        }    //如果有相同学号的
        else{
            q=p;
            p=p->next;    //令q指针指向学号相同的学生信息处并输出q
        }
    }
    if(b!=1){  //若查找不到
        printf("不存在该学生。\n");
    }else{
        p=head;
        Output(p);
        YesNo(p);
    }
}

//查找某个专业、某个课程分数小于...的学生
void Search_major_subject_score(STU *head, char major[10], int subject , int grade){
    STU *p1,*p2,*p3,*head1;
    Inputstu(head);
    p1=head;
    head1=(STU*) malloc(LEN);
    p3=head1;
    for(int i=0;i<N;i++){
        p1=p1->next;
        if((strcmp(p1->major,major)==0)&&(p1->score[subject]<grade)){
            p2=(STU*) malloc(LEN);
            p2=p1;
            p3->next=p2;
            p3=p2;
        }
    }
    p3->next=NULL;
    p3=head1;
    Output(p3);
    YesNo(p3);
}

//删除某个班级、某门课程分数小于...的学生
void  Delete_class_subject_score(STU *head, int classno, int subject, int grade){
    STU *p,*q,*p1,*head1;
    Inputstu(head);
    p=head;
    head1=(STU*) malloc(LEN);
    q=head1;
    for (int i = 0; p->next!=NULL; i++) {
        p=p->next;
        if((p->classNo!=classno)||(p->score[subject]>grade)){
            p1=(STU*) malloc(LEN);
            *p1=*p;
            q->next=p1;
            q=p1;
        }
    }
    q->next=NULL;
    q=head1;
    if(q->next==NULL){
        printf("此链表已为空！\n");
        YesNo(q);
    } else {
        Output(q);
        YesNo(q);
    }
}

//修改指定学生的信息
void Change(STU *head,int scoreIndex) {
    STU *p;
    int k=0;
    Inputstu(head);
    p = head;
    for (int i = 0; i < N; i++) {
        p = p->next;
        if (scoreIndex == p->num) {
            OutOneNode(p);
            Input(p);
            k=1;
        }
    }
    if(k!=1){
        printf("不存在该学生，无法更改。\n");
    } else{
        p = head;
        Output(p);
        YesNo(p);
    }
}

//询问用户是否需要另存进新文件
void YesNo(STU *head){
    int a;
    char filename[20];
    printf("\n是否将排序后的信息存入新文件？(0为否，1为是)\n");
    scanf("%d",&a);
    if(a>0) {  //如果保存进新文件
        if (head->next == NULL) {
            printf("此链表为空，无法保存。\n");
        } else {
            printf("请输入要保存的新文件名（*.dat）：");
            scanf("%s", filename);
            CreateList(filename, head);
            printf("已保存。\n");
        }
    }
    else {                  //如果不保存进新文件
        printf("未保存并即将退出。");
    }
}