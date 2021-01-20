void execInst(int *ptrArr[], char inst, int param1, int param2){
    if(inst=='P'){
        ptrArr[param1]=ptrArr[param2];
        return;
    }
    else{
        *ptrArr[param1]=param2;
        return;
    }
}
