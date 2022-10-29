char * longestPalindrome(char * s){
    int arr_size = 2 * strlen(s) - 1;
    int max_len = 1;
    char temp_ans[strlen(s)];
    temp_ans[0] = s[0];
    
    for(int i = 0; i < arr_size; i++){
        int front, end, len;
        if(i%2 == 0){
            front = i-2;
            end = i+2;
            len = 1;
        }else{
            front = i-1;
            end = i+1;
            len = 0;
        }
        
        while(front>=0 && end<=arr_size){
            if(s[front/2] == s[end/2])
                len += 2;
            else
                break;
            front -= 2;
            end += 2;
        }
        
        if(len > max_len){
            max_len = len;
            int idx = 0;
            for(int j = front+2; j <= end-2; j += 2){
                temp_ans[idx] = s[j/2];
                idx++;
            }
        }
    }
    char sub_ans[max_len+1];
    
    memset(sub_ans, '\0', sizeof(sub_ans));
    strncpy(sub_ans, temp_ans, max_len);

    char * ans = sub_ans;
    for(int i = 0; i<max_len; ++i){
        printf("%c", ans[i]);
    }
    return ans;
    
    char *sub_ans = (char *) calloc(max_len + 1, sizeof(char));
    strncpy(sub_ans, temp_ans, max_len);
    return sub_ans;

}