#include<stdio.h>
#include<stdlib.h>
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
    //�p���e����~��
    long long year = 1970 + (time(NULL) / 31536000) - 1911;
    //��J�Ǹ��ô����ϥΪ̮榡
    while(printf("�п�J�Ǹ�(�榡�G�^��r��+7��Ʀr)�G") && scanf("%s",student_id) != EOF){
        //�I�s�禡�P�_�Ǹ��O�_���u
        if(check(student_id)){
            printf("�����u��Ǹ�\n");
            //�]�w�üƺؤl
            srand(time(NULL));
            //�]�w���B�ﶵ
            int lucky = rand() % 4,choose;
            //�üƲ��ͩ��B�ﶵ�A�������O�̿�ܿﶵ�A�p�G��ܻP���ۦP�Y��o�H����ƪ������
            while(printf("�п��0~3�䤤�@�ӼƦr�ө���G") && scanf("%d",&choose)){
                if(choose >= 0 && choose <= 3){
                    if(choose == lucky){
                        int discount = rand() % 10;
                        if(discount == 0){
                            printf("���ߤ����A�A��o�����y��������O0��\n");    
                        }else{
                            printf("���ߤ����A�A��o1�i%d������\n",discount);
                        }
                    }else{
                        printf("�ܥi���S�������A�w��A�ץ��{\n");
                    }
                    break;
                }else{
                    printf("��J���~�A�Э��s��J\n");
                }
            }
        }else{
            //��X�Ǹ����s�b
            printf("���Ǹ����s�b�A�Э��s��J\n");
        }
    }
    return 0;
}