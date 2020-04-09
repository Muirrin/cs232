char password[8] = "secret";
int main() {
    char input[8];
    printf("please enter your password\n");
    scanf("%s", input);

    if(strcmp(input, password)==0) {
        return 0;
    } else {
        return -1;
    }

}


char password[8] = "secret";
int main() {
    char input[8];
    int k=0;
    printf("please enter your password\n");
    scanf("%s", input);

    start:
    if(8>k){
        if(65<=input[k] && 90>=input[k]){
          input[k]=input[k]+32;
        }
        k++;
        goto start;
    }
    if(strcmp(password, input)==0){
        return 0;
    }
    else{
    return -1;
  }
}
