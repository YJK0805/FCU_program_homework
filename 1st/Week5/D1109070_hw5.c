#include<stdio.h>
#include<string.h>
#include<stdbool.h>
//�ۦ�إ߸�ƫ��A�A���e��MBTI�B�Ϊ��B�H�����O�B�H��B�H��y�z
struct people{
    char *MBTI,*shape,*category,*personality,*describe;
}Role[16];
//���Ҩ�����i�J�{����T
void banner(bool check){
    if(check == true){
        printf("### ###  ## ##   ##  ###\n");
        printf("##  ##  ##   ##  ##   ##\n");
        printf("##      ##       ##   ##\n");
        printf("## ##   ##       ##   ##\n");
        printf("##      ##       ##   ##\n");
        printf("##      ##   ##  ##   ##\n");
        printf("####      ## ##    ## ##\n");
    }else{
        printf("### ### ## #####    ####  ### ###  #####\n");
        printf(" ## ##  #   ## ##  ##  ##  ##  #  ##  ##\n");
        printf(" ## ## ##   ## ##  ##  ##  ### #  ##\n");
        printf(" ## ## #    ####   ##  ##  # # #  ## ###\n");
        printf("  ## ###    ## #   ##  ##  # ###  ##  ##\n");
        printf("  ## ##     ## ##  ##  ##  #  ##  ##  ##\n");
        printf("   #  #    ### ###  ####  ###  #   ####\n");
    }
    return;
}
//�ŧi��J�����ܼƤΰO���լd���D���}�C
char *question[12];
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
//�p��BMI
double cal_BMI(int height,int weight){
    return weight * 1.0 / (height * 0.01 * height * 0.01);
}
//�p��BMR
double cal_BMR(int height,int weight,int gender,int age){
    return weight * 9.99 + 6.25 * height - 4.92 * age + (166 * gender - 161);
}
//�z�LBMI������ĳ
char* body_advice(double BMI){
    if(BMI < 18.5){
        return "�魫�L��\n����ĳ�G�ݦh�B�ʡA���Ŷ����A�W�j���A�������d�I\n";
    }else if(BMI >= 18.5 && BMI < 24){
        return "���d�魫\n����ĳ�G���ߡI�n�~��O��\n";
    }else if(BMI >= 24 && BMI < 27){
        return "�魫�L��\n����ĳ�G�n�ɧ֤O��u���d�魫�޲z�v�I\n";
    }else if(BMI >= 27){
        return "�έD\n����ĳ�G�ݭn�ߨ�O��u���d�魫�޲z�v\n";
    }
}
//�߰ݰ��D�P�����ﶵ�ƶq
void ask_answer_question(int *count){
    char answer;
    for(int i = 0;i < 12;i++){
        getchar();
        printf("%s���סG",question[i]);
        scanf("%c",&answer);
        count[answer]++;
    }
    return;
}
//��Xuser��MBTI
int search_MBTI(int *count){
    char user_MBTI[4] = {'\0'};
    if(count['I'] > count['E']){
        user_MBTI[0] = 'I';
    }else{
        user_MBTI[0] = 'E';
    }
    if(count['N'] > count['S']){
        user_MBTI[1] = 'N';
    }else{
        user_MBTI[1] = 'S';
    }
    if(count['T'] > count['F']){
        user_MBTI[2] = 'T';
    }else{
        user_MBTI[2] = 'F';
    }
    if(count['J'] > count['P']){
        user_MBTI[3] = 'J';
    }else{
        user_MBTI[3] = 'P';
    }
    //��Xuser��id(�z�LMBTI�d��)
    int user_id;
    for(int i = 0;i < 16;i++){
        if(user_MBTI[0] == Role[i].MBTI[0] && user_MBTI[1] == Role[i].MBTI[1] && user_MBTI[2] == Role[i].MBTI[2]&& user_MBTI[3] == Role[i].MBTI[3]){
            user_id = i;
            break;
        }
    }
    return user_id;
}
//��X�A�X���G���覡
void search_sport(int index){
    if(Role[index].MBTI == "ISTJ" || Role[index].MBTI == "ISFJ" || Role[index].MBTI == "ESTP" || Role[index].MBTI == "ESFP"){
        printf("�A�OSJ�H��A�A�A�X���G���覡���������_���B�~�a�V�m\n");
    }else if(Role[index].MBTI == "ISTP" || Role[index].MBTI == "ISFP" || Role[index].MBTI == "ESTP" || Role[index].MBTI == "ESFP"){
        printf("�A�OSP�H��A�A�A�X���G���覡�������סB��ı�ʶ���\n");
    }else if(Role[index].MBTI == "INFP" || Role[index].MBTI == "INFJ" || Role[index].MBTI == "ENFJ" || Role[index].MBTI == "ENFP"){
        printf("�A�ONF�H��A�A�A�X���G���覡���k���B���ޡB�Ť����\n");
    }else if(Role[index].MBTI == "INTJ" || Role[index].MBTI == "INTP" || Role[index].MBTI == "ENTJ" || Role[index].MBTI == "ENTP"){
        printf("�A�ONT�H��A�A�A�X���G���覡��Metaverse Cycling�B�֩Դ���\n");
    }
}
int main(){
    //�إ߽լd���D���}�C
    question[0] = "1. �b�ͬ��W�A�A����۫H�ۤv��______\n��ı(N)\n�g��(S)\n";
    question[1] = "2. �ݮѩΪ̬ݹq�v�ɡA�A��G�ƨ��⪺�Q�k�q�`�O______\n__�ܧ�J�Y�Ө��⪺�߱��A��ۥL�W�U�_��(F)\n__�L�̸�ڦb���P�@�ɡA����b�G�@���޿�(T)\n";
    question[2] = "3. ���b�j�U���� check in�A�A�|�q���̶}�l�[��o�������H\n__�ݩP���L�ȫȡA�òq���������ȸs(N)\n__���\�]�A�Ҧp��B�Q�O�B�a��B���N�~(S)\n__�ݧ��ѤU�o�i�Ȥl������B�C��P�y��(S)\n__�ݹq��B�\�U�B�Z�Ҧb���A�x���Ŷ��t�m(N)\n";
    question[3] = "4. ���ӱԭz�������A�������ǡH\n�`�����~�B�C��P����f�t(S)\n�̷ӨC�Ѥ߱��M�w�n�擄��(S)\n���Q�ʸ��A�P�ڪ���A�n�X��(N)\n��A����ˤ����n�A���b�N�n(N)\n";
    question[4] = "5. ��s���Ҫ��Ĥ@�ѡA�A�|______\n�q�q���ۤv���Ʊ��A���Ӧn�N���H����(I)\n�D�ʧ�H�f�ܡA�ܧֶ}�l�{�ѷs�B��(E)\n";
    question[5] = "6. ��B�ͤ@�_�X�h���A�A�q�`______\n������W�Ҧ����ʡA���{�֦b�䤤(E)\n��F�Y�Ӯɶ��I�A�|��M�}�l���(I)\n";
    question[6] = "7. ��j����i��Ҧ���ʡA�A�ɦV______\n�����¹w�]�ؼЫe�i�A�t�Գt�M(J)\n�٬O�|�q�Y�}�l���}�A�F�ݦ��(P)\n";
    question[7] = "8. �Aı�o����ؤH�۳B����ۦb�H\n���I���ܡA���B�B���H�۷Q���H(F)\n����H���A�����Ƥ����������H(T)\n";
    question[8] = "9. �u�@�W�o�ܷͫФH���ơA�A�|�ɦV���B�z�H\n�ۤv��Ӧa���R�@�R�A�ⱡ�����Ʊ��N�S�ƤF(I)\n�ߨ��B�ͤj��S��A�ⱡ���o�����N�S�ƤF(E)\n";
    question[9] = "10. ���@�ӬO�A����z�Q���ͬ��`���H\n��u�@�P�𮧧������}�A�𮧮ɧ�������(J)\n�Q�u�@�N�u�@�B�Q�𮧴N�𮧡A�H�ߩұ�(P)\n";
    question[10] = "11. ���Y�ݦV�ѪšA���Ⱖ�����L�@�����������A�o�ɧA�|�Q______\n�z�A�o�ӵe���u���A�߱��n�n(F)\n���Ⱖ�O���򳾰ڡH(T)\n��A�Ѧ�w�g�o��ߤF�I(T)\n�u�Q���e�̤@�˦ۥѦۦb(F)\n";
    question[11] = "12. �A���u�۫ߪ��H�A�~��֦��ۥѡv�o�y�ܪ��Q�k������� ______\n�{�P�çV�O����(J)\n��ť�N���O�s�j(P)\n";
    //�إ�16�ب��⪺MBTI�B�Ϊ��B�H�����O�B�H��B�H��y�z
    Role[0].MBTI = "INTJ",Role[0].shape = "�T����",Role[0].category = "���R�a",Role[0].personality = "�ؿv�v",Role[0].describe = "�I���Q���O�M�Բ��ʪ���Q�a�A�@���Ҧb�p�������C";
    Role[1].MBTI = "INTP",Role[1].shape = "�����",Role[1].category = "���R�a",Role[1].personality = "�޿�Ǯa",Role[1].describe = "�㦳�гy�O���o���a�A�諭�Ѧ��ۤ������C";
    Role[2].MBTI = "ENTJ",Role[2].shape = "�����",Role[2].category = "���R�a",Role[2].personality = "�����x",Role[2].describe = "�j�x�A�I���Q���O�B�N�ӱj�j����ɪ̡A�`����γгy�ѨM��k�C";
    Role[3].MBTI = "ENTP",Role[3].shape = "�嫬",Role[3].category = "���R�a",Role[3].personality = "�G�׮a",Role[3].describe = "�o���n�_����Q�̡A���|�����󴼤O�W���D�ԡC";
    Role[4].MBTI = "INFJ",Role[4].shape = "Scutoid",Role[4].category = "�~��a",Role[4].personality = "���Ҫ�",Role[4].describe = "�w�R�ӯ����A�P�ɹ��R�H�ߥB�����h�ª��z�Q�D�q�̡C";
    Role[5].MBTI = "INFP",Role[5].shape = "�E���",Role[5].category = "�~��a",Role[5].personality = "�հ���",Role[5].describe = "�ַN�A���}���Q�L�D�q�̡A�`�O�����a������z�Ѵ������U�C";
    Role[6].MBTI = "ENFJ",Role[6].shape = "����",Role[6].category = "�~��a",Role[6].personality = "�D��",Role[6].describe = "�I���y�O���R�H�ߪ���ɪ̡A����ť���۰g����O�C";
    Role[7].MBTI = "ENFP",Role[7].shape = "�̤G���P",Role[7].category = "�~��a",Role[7].personality = "�v���",Role[7].describe = "�����A���гy�O�R���檺�ۥѦۦb���H�A�`����z�ѷL���C";
    Role[8].MBTI = "ISTJ",Role[8].shape = "�K���",Role[8].category = "�u�@��",Role[8].personality = "���y�v",Role[8].describe = "��ڥB�`���ƹꪺ�ӤH�A�i�a�ʤ��e�h�áC";
    Role[9].MBTI = "ISFJ",Role[9].shape = "�L��",Role[9].category = "�u�@��",Role[9].personality = "�u�ê�",Role[9].describe = "�D�`�M�`�ӷŷx���u�@�̡A�ɨ�ǳƵ۫O�@�R�۪��H�̡C";
    Role[10].MBTI = "ESTJ",Role[10].shape = "��1000���",Role[10].category = "�u�@��",Role[10].personality = "�`�g�z",Role[10].describe = "�X�⪺�޲z�̡A�b�޲z�Ʊ��ΤH���譱�L�P�ۤ�C";
    Role[11].MBTI = "ESFJ",Role[11].shape = "�����",Role[11].category = "�u�@��",Role[11].personality = "���F�x",Role[11].describe = "�����P���ߡA�R�橹���w�諸�H�̡A�`�O���ߴ������U�C";
    Role[12].MBTI = "ISTP",Role[12].shape = "�|���P�P",Role[12].category = "���I�a",Role[12].personality = "Ų��a",Role[12].describe = "�j�x�ӹ�ڪ�����a�A�ժ��ϥΥ���Φ����u��C";
    Role[13].MBTI = "ISFP",Role[13].shape = "�����P�P",Role[13].category = "���I�a",Role[13].personality = "���I�a",Role[13].describe = "�F�����y�O�����N�a�A�ɨ�ǳƵ۱����M����s�A�ƪ��C";
    Role[14].MBTI = "ESTP",Role[14].shape = "�K���P�P",Role[14].category = "���I�a",Role[14].personality = "���~�a",Role[14].describe = "�o���A��O�R�K����P�����H�̡A�u�ߨɨ��ͬ��b��t�C";
    Role[15].MBTI = "ESFP",Role[15].shape = "�߫}��",Role[15].category = "���I�a",Role[15].personality = "��t��",Role[15].describe = "�۵o���A��O�R�K�Ӽ�������t�̡Хͬ��b�L�̩P��ä��L��C";
    //�O��MBTI����U�ӵ��ת��ƶq�P��l�ƭ�
    int count[128] = {0};
    for(int i = 0;i < 128;i++){
        count[i] = 100;
    }
    char student_id[10];
    while(printf("�п�J�Ǹ�(�榡�G�^��r��+7��Ʀr)�G") && scanf("%s",student_id) != EOF){
        if(check(student_id)){
            //��X�i�J�t�ξ�T
            banner(check(student_id));
            printf("�����u��Ǹ��A�w��ϥΦ��A��\n");
            //��J�����B�魫�B�ʧO�B�~��
            int height,weight,gender,age;
            printf("�п�J����(cm)�G");
            scanf("%d", &height);
            printf("�п�J�魫(kg)�G");
            scanf("%d", &weight);
            printf("�п�J�ʧO(�k1 �k0)�G");
            scanf("%d", &gender);
            printf("�п�J�~�֡G");
            scanf("%d", &age);
            //�z�Lfuntion�p��BMI,BMR
            double BMI = cal_BMI(height,weight), BMR = cal_BMR(height,weight,gender,age);
            printf("�z��BMI�G%.1f\n�z��BMR�G%.1f\n%s\n�w���~�򰵤߲z�����I\n",BMI,BMR,body_advice(BMI));
            ask_answer_question(count);
            int MBTI_index = search_MBTI(count);
            printf("�z���߲z���絲�G�G\nMBTI 16���H��G%s\n�Ϊ��G%s\n�H�����O�G%s\n�H��G%s\n�H��y�z�G%s\n",Role[MBTI_index].MBTI,Role[MBTI_index].shape,Role[MBTI_index].category,Role[MBTI_index].personality,Role[MBTI_index].describe);
            search_sport(MBTI_index);
        }else{
            //��X��T�B�Ǹ����s�b
            banner(check(student_id));
            printf("���Ǹ����s�b�A�Э��s��J\n");
        }
    }
    return 0;
}