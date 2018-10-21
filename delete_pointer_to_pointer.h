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

// #define ShowPtoP(pp, BaseType)\
// {\
//     if(pp)\
//     {\
//         int index =0;\
//         do\
//         {\
//             BaseType* p = pp[index++];\
//             if(!p) break;\
//             printf("index:%d(%d,%d)\n", index, p[0],p[1]);\
//         }while(1);\
//     }\
// }

int GetPtoPLength(void** pp);



#endif//__DELETE_POINTER_TO_POINTER_H_