#include<stdio.h>
#include<string.h>
#include<stdbool.h>
//�إ߭n�p���ˬd�X�Ϊ��Ʀr
int num[7] = {0,8,7,6,8,7,6};
//�ˬd�Ǹ��P�ˬd�X�O�_���T���禡
bool check(char id[]){
    if((int)strlen(id) != 8 || (id[0] != 'D' && id[0] != 'E' && id[0] != 'M' && id[0] != 'P')){
        return false;
    }else{
        int S = 0,cur = 0;
        for(int i = 1;i <= 7;i++){
            cur = (id[i] - '0') * num[i];
            S += (cur / 10 + cur % 10);
        }
        if(((10 - S % 10)%10) == (id[7] - '0')){
            return true;
        }else{
            return false;
        }
    }
}
int main(){
    char student_id[10];
    char *part[128];
    //���x�s���O���}�C
    part['D'] = "�j��",part['E'] = "�i��",part['M'] = "�Ӥh",part['P'] = "�դh";
    //�p���e����~��
    long long year = 1970 + (time(NULL) / 31536000) - 1911;
    //��J�Ǹ��ô����ϥΪ̮榡
    while(printf("�п�J�Ǹ�(�榡�G�^��r��+7��Ʀr)�G") && scanf("%s",student_id) != EOF){
        //�I�s�禡�P�_�Ǹ��O�_���u
        if(check(student_id)){
            printf("�����u��Ǹ�\n");
            //�P�_�O�s�͡B�����ͩάO��L�~�žǥ�
            if(((student_id[1] - '0') * 10 + student_id[2] - '0') == year % 100){
                printf("�g�Ѩt�ΧP�_�z���{�Ҥj��%s���j�@�s�A�H�A�����߱z�i�J�{�Ҥj�ǡA�]����o�@�i�����\n",part[student_id[0]]);
            }else if(((year % 100) - ((student_id[1] - '0') * 10 + student_id[2] - '0')) > 4){
                printf("�g�Ѩt�ΧP�_�z���{�Ҥj��%s�������͡A�����y�z�b�ҷ~�W�~��V�O�A�]����o�@�i�����\n",part[student_id[0]]);
            }else{
                printf("�g�Ѩt�ΧP�_�z���{�Ҥj��%s���ǥ͡A���L�ڭ̥ثe��������ʶȭ��s�ͤΩ����͡A�q�Ш���\n",part[student_id[0]]);
            }
        }else{
            //��X�Ǹ����s�b
            printf("���Ǹ����s�b�A�Э��s��J\n");
        }
    }
    return 0;
}