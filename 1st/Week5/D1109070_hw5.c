#include<stdio.h>
#include<string.h>
#include<stdbool.h>
//自行建立資料型態，內容有MBTI、形狀、人格類別、人格、人格描述
struct people{
    char *MBTI,*shape,*category,*personality,*describe;
}Role[16];
//驗證身分後進入程式橫幅
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
//宣告輸入答案變數及記錄調查問題的陣列
char *question[12];
//建立要計算檢查碼用的數字
int num[7] = {0,8,7,6,8,7,6};
//檢查學號與檢查碼是否正確的函式
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
//計算BMI
double cal_BMI(int height,int weight){
    return weight * 1.0 / (height * 0.01 * height * 0.01);
}
//計算BMR
double cal_BMR(int height,int weight,int gender,int age){
    return weight * 9.99 + 6.25 * height - 4.92 * age + (166 * gender - 161);
}
//透過BMI給體位建議
char* body_advice(double BMI){
    if(BMI < 18.5){
        return "體重過輕\n體位建議：需多運動，均衡飲食，增強體能，維持健康！\n";
    }else if(BMI >= 18.5 && BMI < 24){
        return "健康體重\n體位建議：恭喜！要繼續保持\n";
    }else if(BMI >= 24 && BMI < 27){
        return "體重過重\n體位建議：要盡快力行「健康體重管理」！\n";
    }else if(BMI >= 27){
        return "肥胖\n體位建議：需要立刻力行「健康體重管理」\n";
    }
}
//詢問問題與紀錄選項數量
void ask_answer_question(int *count){
    char answer;
    for(int i = 0;i < 12;i++){
        getchar();
        printf("%s答案：",question[i]);
        scanf("%c",&answer);
        count[answer]++;
    }
    return;
}
//找出user的MBTI
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
    //找出user的id(透過MBTI查找)
    int user_id;
    for(int i = 0;i < 16;i++){
        if(user_MBTI[0] == Role[i].MBTI[0] && user_MBTI[1] == Role[i].MBTI[1] && user_MBTI[2] == Role[i].MBTI[2]&& user_MBTI[3] == Role[i].MBTI[3]){
            user_id = i;
            break;
        }
    }
    return user_id;
}
//找出適合的瘦身方式
void search_sport(int index){
    if(Role[index].MBTI == "ISTJ" || Role[index].MBTI == "ISFJ" || Role[index].MBTI == "ESTP" || Role[index].MBTI == "ESFP"){
        printf("你是SJ人格，你適合的瘦身方式為間歇性斷食、居家訓練\n");
    }else if(Role[index].MBTI == "ISTP" || Role[index].MBTI == "ISFP" || Role[index].MBTI == "ESTP" || Role[index].MBTI == "ESFP"){
        printf("你是SP人格，你適合的瘦身方式為醫美減脂、直覺性飲食\n");
    }else if(Role[index].MBTI == "INFP" || Role[index].MBTI == "INFJ" || Role[index].MBTI == "ENFJ" || Role[index].MBTI == "ENFP"){
        printf("你是NF人格，你適合的瘦身方式為攀岩、鋼管、空中瑜伽\n");
    }else if(Role[index].MBTI == "INTJ" || Role[index].MBTI == "INTP" || Role[index].MBTI == "ENTJ" || Role[index].MBTI == "ENTP"){
        printf("你是NT人格，你適合的瘦身方式為Metaverse Cycling、皮拉提斯\n");
    }
}
int main(){
    //建立調查問題的陣列
    question[0] = "1. 在生活上，你比較相信自己的______\n直覺(N)\n經驗(S)\n";
    question[1] = "2. 看書或者看電影時，你對故事角色的想法通常是______\n__很投入某個角色的心情，跟著他上下起伏(F)\n__他們跟我在不同世界，比較在乎劇情邏輯(T)\n";
    question[2] = "3. 坐在大廳等待 check in，你會從哪裡開始觀察這間飯店？\n__看周圍其他旅客，並猜測飯店的客群(N)\n__看擺設，例如花、吊燈、地毯、藝術品(S)\n__看屁股下這張椅子的材質、顏色與造型(S)\n__看電梯、餐廳、廁所在哪，掌握空間配置(N)\n";
    question[3] = "4. 哪個敘述比較接近你的穿衣哲學？\n注重飾品、顏色與整體搭配(S)\n依照每天心情決定要穿什麼(S)\n不想動腦，同款的衣服好幾件(N)\n衣服長怎樣不重要，乾淨就好(N)\n";
    question[4] = "5. 到新環境的第一天，你會______\n默默做自己的事情，不太好意思跟人講話(I)\n主動找人搭話，很快開始認識新朋友(E)\n";
    question[5] = "6. 跟朋友一起出去玩，你通常______\n完全跟上所有活動，全程樂在其中(E)\n到了某個時間點，會突然開始放空(I)\n";
    question[6] = "7. 到大賣場進行例行採購，你傾向______\n直接朝預設目標前進，速戰速決(J)\n還是會從頭開始閒逛，東看西看(P)\n";
    question[7] = "8. 你覺得跟哪種人相處比較自在？\n有點善變，但處處替人著想的人(F)\n不近人情，但做事公平公正的人(T)\n";
    question[8] = "9. 工作上發生很煩人的事，你會傾向怎麼處理？\n自己找個地方靜一靜，把情緒消化掉就沒事了(I)\n立刻找朋友大聊特聊，把情緒發洩掉就沒事了(E)\n";
    question[9] = "10. 哪一個是你比較理想的生活節奏？\n把工作與休息完全切開，休息時完全關機(J)\n想工作就工作、想休息就休息，隨心所欲(P)\n";
    question[10] = "11. 抬頭看向天空，有兩隻鳥飛過一片雲朵中間，這時你會想______\n哇，這個畫面真美，心情好好(F)\n那兩隻是什麼鳥啊？(T)\n喔，天色已經這麼晚了！(T)\n真想像牠們一樣自由自在(F)\n";
    question[11] = "12. 你對於「自律的人，才能擁有自由」這句話的想法比較接近 ______\n認同並努力執行(J)\n光聽就壓力山大(P)\n";
    //建立16種角色的MBTI、形狀、人格類別、人格、人格描述
    Role[0].MBTI = "INTJ",Role[0].shape = "三角形",Role[0].category = "分析家",Role[0].personality = "建築師",Role[0].describe = "富有想像力和戰略性的思想家，一切皆在計劃之中。";
    Role[1].MBTI = "INTP",Role[1].shape = "五邊形",Role[1].category = "分析家",Role[1].personality = "邏輯學家",Role[1].describe = "具有創造力的發明家，對知識有著止不住的渴望。";
    Role[2].MBTI = "ENTJ",Role[2].shape = "正方形",Role[2].category = "分析家",Role[2].personality = "指揮官",Role[2].describe = "大膽，富有想像力且意志強大的領導者，總能找到或創造解決方法。";
    Role[3].MBTI = "ENTP",Role[3].shape = "箏型",Role[3].category = "分析家",Role[3].personality = "辯論家",Role[3].describe = "聰明好奇的思想者，不會放棄任何智力上的挑戰。";
    Role[4].MBTI = "INFJ",Role[4].shape = "Scutoid",Role[4].category = "外交家",Role[4].personality = "提倡者",Role[4].describe = "安靜而神秘，同時鼓舞人心且不知疲倦的理想主義者。";
    Role[5].MBTI = "INFP",Role[5].shape = "九邊形",Role[5].category = "外交家",Role[5].personality = "調停者",Role[5].describe = "詩意，善良的利他主義者，總是熱情地為正當理由提供幫助。";
    Role[6].MBTI = "ENFJ",Role[6].shape = "方圓形",Role[6].category = "外交家",Role[6].personality = "主角",Role[6].describe = "富有魅力鼓舞人心的領導者，有使聽眾著迷的能力。";
    Role[7].MBTI = "ENFP",Role[7].shape = "十二角星",Role[7].category = "外交家",Role[7].personality = "競選者",Role[7].describe = "熱情，有創造力愛社交的自由自在的人，總能找到理由微笑。";
    Role[8].MBTI = "ISTJ",Role[8].shape = "八邊形",Role[8].category = "守護者",Role[8].personality = "物流師",Role[8].describe = "實際且注重事實的個人，可靠性不容懷疑。";
    Role[9].MBTI = "ISFJ",Role[9].shape = "無形",Role[9].category = "守護者",Role[9].personality = "守衛者",Role[9].describe = "非常專注而溫暖的守護者，時刻準備著保護愛著的人們。";
    Role[10].MBTI = "ESTJ",Role[10].shape = "正1000邊形",Role[10].category = "守護者",Role[10].personality = "總經理",Role[10].describe = "出色的管理者，在管理事情或人的方面無與倫比。";
    Role[11].MBTI = "ESFJ",Role[11].shape = "六邊形",Role[11].category = "守護者",Role[11].personality = "執政官",Role[11].describe = "極有同情心，愛交往受歡迎的人們，總是熱心提供幫助。";
    Role[12].MBTI = "ISTP",Role[12].shape = "四角星星",Role[12].category = "探險家",Role[12].personality = "鑑賞家",Role[12].describe = "大膽而實際的實驗家，擅長使用任何形式的工具。";
    Role[13].MBTI = "ISFP",Role[13].shape = "六角星星",Role[13].category = "探險家",Role[13].personality = "探險家",Role[13].describe = "靈活有魅力的藝術家，時刻準備著探索和體驗新鮮事物。";
    Role[14].MBTI = "ESTP",Role[14].shape = "八角星星",Role[14].category = "探險家",Role[14].personality = "企業家",Role[14].describe = "聰明，精力充沛善於感知的人們，真心享受生活在邊緣。";
    Role[15].MBTI = "ESFP",Role[15].shape = "貓咪型",Role[15].category = "探險家",Role[15].personality = "表演者",Role[15].describe = "自發的，精力充沛而熱情的表演者－生活在他們周圍永不無聊。";
    //記錄MBTI測驗各個答案的數量與初始化值
    int count[128] = {0};
    for(int i = 0;i < 128;i++){
        count[i] = 100;
    }
    char student_id[10];
    while(printf("請輸入學號(格式：英文字母+7位數字)：") && scanf("%s",student_id) != EOF){
        if(check(student_id)){
            //輸出進入系統橫幅
            banner(check(student_id));
            printf("此為真實學號，歡迎使用此服務\n");
            //輸入身高、體重、性別、年齡
            int height,weight,gender,age;
            printf("請輸入身高(cm)：");
            scanf("%d", &height);
            printf("請輸入體重(kg)：");
            scanf("%d", &weight);
            printf("請輸入性別(男1 女0)：");
            scanf("%d", &gender);
            printf("請輸入年齡：");
            scanf("%d", &age);
            //透過funtion計算BMI,BMR
            double BMI = cal_BMI(height,weight), BMR = cal_BMR(height,weight,gender,age);
            printf("您的BMI：%.1f\n您的BMR：%.1f\n%s\n歡迎繼續做心理測驗喔！\n",BMI,BMR,body_advice(BMI));
            ask_answer_question(count);
            int MBTI_index = search_MBTI(count);
            printf("您的心理測驗結果：\nMBTI 16型人格：%s\n形狀：%s\n人格類別：%s\n人格：%s\n人格描述：%s\n",Role[MBTI_index].MBTI,Role[MBTI_index].shape,Role[MBTI_index].category,Role[MBTI_index].personality,Role[MBTI_index].describe);
            search_sport(MBTI_index);
        }else{
            //輸出橫幅、學號不存在
            banner(check(student_id));
            printf("此學號不存在，請重新輸入\n");
        }
    }
    return 0;
}