#include <stdio.h>
#include <stdlib.h>

char ****get_document(char *text) {
        /* **********************************************
         * To find the number of paragraph in text      *
         * we start with no_of_para as 1 because        *
         * default newLine is always ends with          *
         * the last word os text.                       *
         * *********************************************/
        int no_of_para = 1;

        for (int i = 0; text[i] != '\0'; i++) {
                if (text[i] == '\n') {
                        no_of_para = no_of_para + 1;
                }
        }

        char ****document = (char****)malloc(no_of_para * sizeof(char***));

        int start_pos = 0;
        int cur_pos = 0;

        for (int i = 0; i < no_of_para; i++) {
                int no_of_sentence = 0;
                cur_pos = start_pos;
                while (text[cur_pos] != '\0' && text[cur_pos] != '\n') {
                        if (text[cur_pos] == '.') {
                                no_of_sentence = no_of_sentence + 1;
                        }
                        cur_pos = cur_pos + 1;
                }
                *(document + i) = (char***)malloc(no_of_sentence * sizeof(char**));

                cur_pos = start_pos;

                for (int j = 0; j < no_of_sentence; j++) {
                        int no_of_words = 1;
                        int sentence_start = cur_pos;
                        while (text[cur_pos] != '.') {
                                if (text[cur_pos] == ' ') {
                                        no_of_words = no_of_words + 1;
                                }
                                cur_pos = cur_pos + 1;
                        }
                        cur_pos = cur_pos + 1;
                        *(*(document + i) + j) = (char**)malloc(no_of_words * sizeof(char*));

                        int word_start = sentence_start;

                        for (int k = 0; k < no_of_words; k++) {
                                int no_of_characters = 0;
                                int word_cur = word_start;
                                while (text[word_cur] != ' ' && text[word_cur] != '.') {
                                        no_of_characters = no_of_characters + 1;
                                        word_cur = word_cur + 1;
                                }

                                *(*(*(document + i) + j) + k) = (char*)malloc((no_of_characters + 1) * sizeof(char));

                                for (int ch = 0; ch < no_of_characters; ch++) {
                                        *(*(*(*(document + i) + j) + k) + ch) = text[word_start + ch];
                                }

                                *(*(*(*(document + i) + j) + k) + no_of_characters) = '\0';

                                if (text[word_cur] == ' ') {
                                        word_cur = word_cur + 1;
                                }
                                word_start = word_cur;
                        }
                }

                if (text[cur_pos] == '\n') {
                        cur_pos = cur_pos + 1;
                }
                start_pos = cur_pos;
        }
        return document;
}

char*** kth_paragraph(char**** document, int k) {
        return *(document + (k - 1));
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
        return *(*(document + (m - 1)) + (k - 1));
}

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
        return *(*(*(document + (n - 1)) + (m - 1)) + (k - 1));
}

int main() {
        // Ready for copy-pasting directly into HackerRank!
        return 0;
}
