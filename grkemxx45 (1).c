#include<stdio.h>
#include<conio.h>
void initializeMatrix(char tus[12][4]){				//TUSLARIN HARF KARSILIKLARININ DIZIYE ATILMASI
	int i, j;
	char harf = 'A';								//A TUSUNDAN BASLAYARAK BIR BIR ARTACAK DEGISKEN
	for(i = 2; i <= 9; ++i){						//2 DEN BASLAYIP 9 TUSUNA KADAR DIZIDE DONEN DONGU
		for(j = 0; j < 3; ++j){						//HER RAKAMA 3 HARF VERIYORUZ
			tus[i][j] = harf;						//MATRISTE ATADIKTAN SONRA
			harf = harf + 1;						//HARFI ALFABEDE 1 ARTTIRIYORUZ
		}
		if(i == 7 || i == 9){						//EGER RAKAMLAR 7 VEYA 9 ISE 3 HARF DEGIL 4 HARF OLDUGU ICIN 4. HARFI ATIYORUZ
			tus[i][j] = harf;
			harf = harf + 1;
		}
	}
}

void displayCombinations(char matrix[12][4], int *numberArray, int count, int index, char word[]){
	int i;
	
	if(index == count){							//EGER DIZIDEKI INDEXIMI SAYI DIZISININ BOYUTUNA ULASTIYSA
		word[index] = '\0';
		printf("%s\n",word);					//OLUSAN KOMBINASYONU EKRANA YAZDIRIYORUZ
		return;
	}
		
	
	for(i = 0; i < 4; ++i){								//RAKAMLARDA 4 HARF DE OLABILDIGI ICIN 4 KERE DONEN DONGU
		if(matrix[ numberArray[index] ][i] != 0){					//MATRIKSIMIZDEKI INDEX SATIRINDAKI I. SUTUNDAKI HARF 0 DEGIL ISE
			word[index] = matrix[ numberArray[index] ][i];		 	//HARFI WORD DIZISINE ATIYORUZ
			displayCombinations(matrix, numberArray, count, index + 1, word);			//VE RECURSIVE OLARAK INDEX + 1 OLARAK FONKSIYONU TEKRAR CAGIRIYORUZ
		}
	}
	
}

int main(){
	
	char tus[12][4] = {0};							//TUSLARA KARSI HARFLERI TUTAN MATRIX
	int i;
	int count, number;
	
	printf("Sayi Dizisinin Boyutunu Giriniz: ");					
	scanf("%d", &count);								//GIRILECEK SAYI DIZISININ BOYUTUNU GIRIYORUZ
	
	int numberArray[count];								//NUMBER DIZISI ACIYORUZ
	char word[count + 1];								//GIRILECEK SAYI BOYUTU KADAR WORD DIZISI ACIYORUZ
	
	for(i = 0; i < count; ++i){										
		printf("Sayi Dizisinin %d. Sayisini Giriniz: ", i + 1);
		scanf("%d", &number);													//SAYI DIZISINE SAYI ELEMANLARINI INPUT OLARAK ALIYORUZ
		
		if(number >= 0 && number <= 9){											//EGER GIRILEN DEGER 0'DAN 9'A KADAR RAKAM DEGIL ISE TEKRAR GIRMESINI ISTIYORUZ
			numberArray[i] = number;
		}
		else{
			printf("Girilen deger 1-9 arasinda olmalidir. Lutfen tekrar deneyin.\n");
			i--;
		}
	}
	
	initializeMatrix(tus);											//FONKSIYON CAGRIMI
	
	displayCombinations(tus, numberArray, count, 0, word);				//RECURSIVE FONKSIYON CAGRIMI
	
	getch();
	return 0;
}
