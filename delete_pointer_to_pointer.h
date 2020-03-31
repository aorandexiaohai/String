#ifndef __DELETE_POINTER_TO_POINTER_H_
#define __DELETE_POINTER_TO_POINTER_H_
#define DeletePtoP(pp, BaseType)\
{\
    if(pp)\
    {\
        int index =0;\
        do\
        {\
            BaseType* p = pp[index++];\
            if(!p) break;\
            free(p);\
        }while(1);\
        free(pp);\
    }\
}

int GetPtoPLengthInt(int** pp);
int GetPtoPLengthChar(char** pp);



#endif//__DELETE_POINTER_TO_POINTER_H_