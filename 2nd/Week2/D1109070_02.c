#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char rna[200][40][20];
	char tbl[30] = "FLIMVSPTAYHQNKDECWRGZ";
	char *s = "UUUUUCUUAUUGCUUCUCCUACUGAUUAUCAUAAUGGUUGUCGUAGUGUCUUCCUCAUCGAGUAGCCCUCCCCCACCGACUACCACAACGGCUGCCGCAGCGUAUUACCAUCACCAACAGAAUAACAAAAAGGAUGACGAAGAGUGUUGCUGGCGUCGCCGACGGAGAAGGGGUGGCGGAGGGUAAUAGUGA";
	int len[128];
	len['F'] = 2;
	len['L'] = 6;
	len['I'] = 3;
	len['M'] = 1;
	len['V'] = 4;
	len['S'] = 6;
	len['P'] = 4;
	len['T'] = 4;
	len['A'] = 4;
	len['Y'] = 2;
	len['H'] = 2;
	len['Q'] = 2;
	len['N'] = 2;
	len['K'] = 2;
	len['D'] = 2;
	len['E'] = 2;
	len['C'] = 2;
	len['W'] = 1;
	len['R'] = 6;
	len['G'] = 4;
	len['Z'] = 3;
	char r[1000];
	long long t;
	scanf("%lld",&t);
	getchar();
	while(t--){
		char *ans = "",cnt[3];
		scanf("%s",r);
		int check = 1;
		for(int i = 0;i < strlen(r) && check;i += 3){
			for(int j = 0;j < 3;j++){
				cnt[j] = r[i + j];
			}
			char cmp[3] = "";
			int f = 1;
			for(int j = 0,index = 0;j < strlen(tbl) && f && check;j++){
				for(int k = 0;k < len[tbl[j]] && f && check;k++){
					for(int l = 0;l < 3;l++){
						cmp[l] = s[index];
						index++;
					}
					if(strncmp(cmp,cnt,3) == 0){
						if(tbl[j] == 'Z'){
							check = 0;
							f = 0;
							break;
						}else{
							printf("%c",tbl[j]);
							f = 0;
						}
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}