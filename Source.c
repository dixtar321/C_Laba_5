#include <stdio.h>


void copy_word(char* dst, char* scr, int start, int end) { // копирует из строки scr в dst символы с позиции start до end
	int i = 0, j = 0;
	for (i = start; i < end; i++) {
		dst[j] = scr[i];
		j++;
	}dst[j] = 0;
}

void my_strcmp(char* s1, int k) { // сравнивает строки
	int i = 0;
	char* v1 = s1;

	while((v1[i] != '\0')&&(v1[i]) != '\n')
		i++;
	if (i == k) {
		for (i = 0; i < k; i++)
			printf("%c", v1[i]);
		printf(" ");
	}
}

int my_letters(char* s1, int k) { // считает кол-во букв в слове
	int i = 0;
	char* v1 = s1;
	while ((v1[i] != '\0')&&(v1[i] != ' ')&&(v1[i] != '\n')) {
		i++;
	}
	k = i;
	return k;
}

char* get_string(int* len) { //неограниченный ввод символов через malloc -> realloc
	*len = 0;
	int capacity = 1;
	char* tmp;
	char* s = (char*)malloc(sizeof(char));
	char c = getchar();
	while (c != '\n' && s != NULL) {
		s[(*len)++] = c;
		if (s != NULL && *len >= capacity) {
			capacity *= 2;
			tmp = (char*)realloc(s, capacity * sizeof(char));
			if (tmp != NULL)
				s = tmp;
		}
		c = getchar();
	}
	s[(*len)++] = '\0';
	return s;
}


int main() { // Ввести строку и слово. Вывести количество слов в строке, имеющих длину, равную длине введенного слова.
	
	int i = 0, start_w = 0, end_w = 0, in_word = 0, word_count = 0, k = 0, p = 0, j = 0, l = 0;
	
	printf("Enter your string: ");
	char* s = get_string(&p);

	printf("\nEnter your word: ");
	char* word = get_string(&p);

	while (s[j]) {
		if (s[j] == ' ')
			word_count++;
		j++;
	}word_count++;

	char** words = (char**)malloc(word_count * sizeof(char*));

while (s[i]) {
		if (s[i] != ' ') {
			if (in_word == 0) start_w = i;
			in_word = 1;
		}
		else {
			if (in_word == 1) {
				end_w = i;
				words[l] = (char*)malloc((end_w - start_w + 1) * sizeof(char*));
				copy_word(words[l], s, start_w, end_w, l);
				l++;
			}
			in_word = 0;
		}
		i++;
	}
	if (in_word == 1) {
		end_w = i;
		words[l] = (char**)malloc((end_w - start_w + 1) * sizeof(char**));
		copy_word(words[l], s, start_w, end_w, l);
	}
	k = my_letters(word, k);

	printf("\nResult: ");
	for (i = 0; i < word_count; i++) 
		my_strcmp(words[i], k);
	printf("\n");

	for (i = 0; i < word_count; i++) {
		free(words[i]);
	}
	free(words);
	return 0;
}

/*1) Ввести строку, ввести слово
2) Функция: Посчитать кол-во букв в слове
3) Функция: Разделить строку на слова в двухмерный массив
4) Функция: Сравнивать каждое слово двухмерного массива по нужному кол-ву букв. Если совпадает, то printf или в другой массив
5) free malloc


функция: передаёт указатель на массив указателей words и s. Также передаёт длинну слова (start_w и end_w).
В функции происходит malloc (если слово не первое, то за malloc следует realloc). После realloc следует обмен через tmp.


*/
