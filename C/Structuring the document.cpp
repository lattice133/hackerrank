#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

struct split_result{
	char ** split_data;
	int count;
};

struct split_result string_split(char* text, char seperation){
    assert(text);

    char* token = strtok(text,&seperation);

	struct split_result result;
	result.split_data = (char **)malloc(sizeof(char*));

    int indicator_token = 0;
    

    while(token!= NULL){
        result.split_data = (char **)realloc(result.split_data,(indicator_token+1)*sizeof(char*));
        result.split_data[indicator_token] = token;
        token= strtok(NULL,&seperation);
        indicator_token++;        
    }


    result.count = indicator_token;

    return result;
}

struct document get_document(char* text) {
	
	assert(text);
	text = strcat(text,"\n");
	struct split_result paragraphs = string_split(text, '\n');
	
	struct document doc;
	doc.paragraph_count = paragraphs.count;
	doc.data = (struct paragraph *)malloc(sizeof(struct paragraph)*paragraphs.count);
	
	int i = 0;
	for(i =0; i< paragraphs.count; i++){
		struct split_result sentences = string_split(paragraphs.split_data[i], '.');
		
		doc.data[i].data = (struct sentence *) malloc((sentences.count)* sizeof(struct sentence));
		doc.data[i].sentence_count = sentences.count;
		int j = 0;
		for(j =0; j< sentences.count; j++){
			struct split_result words;
			words = string_split(sentences.split_data[j], ' ');
			doc.data[i].data[j].data = (struct word *) malloc((words.count)*sizeof(struct word));
			doc.data[i].data[j].word_count = words.count;
			int k =0;
			for (k =0; k< words.count; k++){

				int length_temp = strlen(words.split_data[k]);
				doc.data[i].data[j].data[k].data = (char *)malloc((length_temp+1)*sizeof(char));
			    strcpy(doc.data[i].data[j].data[k].data, words.split_data[k]);
			}
			
		}

	}
	return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {

	return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 

	return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
	
	return Doc.data[k-1];
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
