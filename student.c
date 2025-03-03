//
// Created by 86137 on 2023/7/11.
//
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "stu.h"
//ͨ��ƽ���ɼ�����
void Sort_select(STU *head) {
    STU *p, *q;
    int score[20], num, class;
    char name[20], major[20];
    Inputstu(head);
    p = head->next;
    if (p == NULL) {
        printf("�����ڸóɼ���\n");
    } else {
        while (p->next != NULL) {
            q = p->next;  //��һ��ѭ��
            while (q != NULL) {  //���p���ִܷ���q���ܷ�
                if ((p->score[0] + p->score[1] + p->score[2]) > (q->score[0] + q->score[1] + q->score[2])) {
                    num = p->num;                  //�������ǵ�������Ϣ
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
                q = q->next;  //��һ��ѭ��������
            }
            p = p->next;   //�ڶ���ѭ��������
        }
    }
    p=head;
    Output(p);   //�����������Ϣ
    YesNo(p);
}

//����ѧ����Ϣ���������ڸð༶��רҵ����ʾ��Ҫ����������
void Input(STU *p){
    int i;
    char *str1="computer";
    char *str2="network";
    char *str3="software";
    printf("\n������ѧ��; \n");
    scanf("%d", &p->num);
    getchar();
    printf("\n����������; \n");
    scanf("%s",p->name);
    printf("������רҵ(computer/network/software)??\n");
    scanf("%s",p->major);
    if((strcmp(p->major,str1)!=0)&&(strcmp(p->major,str2)!=0)&&(strcmp(p->major,str3)!=0)){
        for(int k=0;;k++) {
            printf("�����ڸ�רҵ������������(computer/software/network)");
            scanf("%s",p->major);
            if((strcmp(p->major,str1)==0)||(strcmp(p->major,str2)==0)||(strcmp(p->major,str3)==0)){
                printf("\n����ɹ�\n");
                break;
            }
        }
    }
    printf("������༶����1��/2�ࣩ\n");
    scanf("%d",&p->classNo);
    if((p->classNo!=1)&&(p->classNo!=2)&&(p->classNo!=3)){
        for(int t=0;;t++) {
            printf("�����ڸð༶������������༶����1��/2�ࣩ");
            scanf("%d", &p->classNo);
            if((p->classNo>0)&&(p->classNo<4)){
                printf("\n����ɹ�\n");
                break;
            }
        }
    }
    getchar();
    printf("\n����������ÿ�ųɼ�; \n");
    for (i = 0; i < 3; i++) {
        scanf("%d", &p->score[i]);
        getchar();
    }
}

//���ļ������ѧ����Ϣ
void Inputstu(STU *head){
    STU *p1,*p2;
    FILE *fp;
    char filename[20];
    printf("������Ҫ�򿪵��ļ�����*.dat��");
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

//��������������Ϣ
void Output(STU *head){
    STU *r=head->next;
    if(r==NULL){
        printf("������Ϊ�ա�\n");
    }else {
        do {
            printf("\n������%5s\tѧ�ţ�%5d\tרҵ:%s\t�༶��%d\t�ɼ���%d\t%d\t%d\n", r->name, r->num, r->major, r->classNo,
                   r->score[0], r->score[1], r->score[2]);
            r = r->next;
        } while (r != NULL);
    }
}

//������������ļ������ɹ����������finish
STU *CreateList(char *filename,STU *head) {
    STU *q;
    FILE *fp;
    fp=fopen(filename, "wb");
    q=head->next;
    if(q==NULL){
        printf("������Ϊ������");
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

//���һ��������Ϣ
void OutOneNode(STU *p) {
    printf("\n������%5s\tѧ�ţ�%5d\tרҵ:%s\t�༶��%d\t�ɼ���%d\t%d\t%d\n", p->name, p->num, p->major, p->classNo,
           p->score[0], p->score[1], p->score[2]);
}

//���ҳ�����ѧ�����ܷ���ߵ�ѧ��
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
            printf("��߷ֵ�ѧ���ɼ�Ϊ��\n");
            OutOneNode(p1);
            YesNo(p1);
        }
    }
}

//ͨ��ѧ�Ų���ѧ����Ϣ
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
            printf("��ѧ����ϢΪ��\n");
            OutOneNode(p2);
            YesNo(p2);
            a=1;
        }
        p2=p2->next;
    }
    if(a!=1){
        printf("�����ڸ�ѧ����\n");
    }
}

//ͨ��ѧ�Ų���ѧ����Ϣ������֤ѧ�ŵ�������
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
        if (ID == id[i]) {  //����Ѿ����ڸ�ѧ��
            printf("ѧ���Ѵ��ڣ����ɲ������Ϣ\n");
            break;
        } else {
            if (ID < id[0]) {  //���Ϊ��һ��ѧ��
                q->next = p;
                head->next = q;
                p=head;
                Output(p);
                YesNo(p);
                break;
            } else if (ID < id[i + 1]) { //����������м�
                q->next = p->next;
                p->next = q;
                p=head;
                Output(p);
                YesNo(p);
                break;
            } else {
                if (p->next == NULL) {  //���������β��
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

//��������ɾ��ָ��ѧ�ŵ�ѧ��
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
        }    //�������ͬѧ�ŵ�
        else{
            q=p;
            p=p->next;    //��qָ��ָ��ѧ����ͬ��ѧ����Ϣ�������q
        }
    }
    if(b!=1){  //�����Ҳ���
        printf("�����ڸ�ѧ����\n");
    }else{
        p=head;
        Output(p);
        YesNo(p);
    }
}

//��������ɾ��ָ��������ѧ��
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
        }    //�������ͬѧ�ŵ�
        else{
            q=p;
            p=p->next;    //��qָ��ָ��ѧ����ͬ��ѧ����Ϣ�������q
        }
    }
    if(b!=1){  //�����Ҳ���
        printf("�����ڸ�ѧ����\n");
    }else{
        p=head;
        Output(p);
        YesNo(p);
    }
}

//����ĳ��רҵ��ĳ���γ̷���С��...��ѧ��
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

//ɾ��ĳ���༶��ĳ�ſγ̷���С��...��ѧ��
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
        printf("��������Ϊ�գ�\n");
        YesNo(q);
    } else {
        Output(q);
        YesNo(q);
    }
}

//�޸�ָ��ѧ������Ϣ
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
        printf("�����ڸ�ѧ�����޷����ġ�\n");
    } else{
        p = head;
        Output(p);
        YesNo(p);
    }
}

//ѯ���û��Ƿ���Ҫ�������ļ�
void YesNo(STU *head){
    int a;
    char filename[20];
    printf("\n�Ƿ���������Ϣ�������ļ���(0Ϊ��1Ϊ��)\n");
    scanf("%d",&a);
    if(a>0) {  //�����������ļ�
        if (head->next == NULL) {
            printf("������Ϊ�գ��޷����档\n");
        } else {
            printf("������Ҫ��������ļ�����*.dat����");
            scanf("%s", filename);
            CreateList(filename, head);
            printf("�ѱ��档\n");
        }
    }
    else {                  //�������������ļ�
        printf("δ���沢�����˳���");
    }
}