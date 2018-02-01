/* Copyright (c) 2013-2018 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef simple_api_h
#define simple_api_h
/*
**  Functions 
**  Support for C Functions 
*/

SIMPLE_API void simple_vm_funcregister2 ( RingState *pRingState,const char *cStr, void (*pFunc)(void *) ) ;

SIMPLE_API void simple_vm_loadcfunctions ( RingState *pRingState ) ;

SIMPLE_API List * simple_vm_api_getlist ( void *pPointer,int x ) ;

int simple_vm_api_islist ( void *pPointer,int x ) ;

SIMPLE_API void simple_vm_api_retlist ( void *pPointer,List *pList ) ;

SIMPLE_API List * simple_vm_api_newlist ( VM *pVM ) ;

SIMPLE_API void simple_vm_api_retcpointer ( void *pPointer,void *pGeneral,const char *cType ) ;

SIMPLE_API void * simple_vm_api_getcpointer ( void *pPointer,int x,const char *cType ) ;

SIMPLE_API void simple_vm_api_setcpointernull ( void *pPointer,int x ) ;

void simple_vm_extension ( RingState *pRingState ) ;

SIMPLE_API void * simple_vm_api_varptr ( void *pPointer,const char  *cStr,const char *cStr2 ) ;

SIMPLE_API void simple_vm_api_intvalue ( void *pPointer,const char  *cStr ) ;

SIMPLE_API void simple_list_addcpointer ( List *pList,void *pGeneral,const char *cType ) ;

SIMPLE_API int simple_vm_api_iscpointerlist ( List *pList ) ;

SIMPLE_API int simple_vm_api_iscpointer ( void *pPointer,int x ) ;

SIMPLE_API int simple_vm_api_isobject ( void *pPointer,int x ) ;

SIMPLE_API int simple_vm_api_cpointercmp ( List *pList,List *pList2 ) ;

SIMPLE_API int simple_vm_api_ispointer ( void *pPointer,int x ) ;

SIMPLE_API void * simple_vm_api_getcpointer2pointer ( void *pPointer,int x,const char *cType ) ;

SIMPLE_API void simple_list_addcpointer_gc ( void *pState,List *pList,void *pGeneral,const char *cType ) ;
/*
**  Library 
**  General 
*/

void simple_vmlib_len ( void *pPointer ) ;

void simple_vmlib_add ( void *pPointer ) ;

void simple_vmlib_del ( void *pPointer ) ;

void simple_vmlib_get ( void *pPointer ) ;

void simple_vmlib_clock ( void *pPointer ) ;

void simple_vmlib_lower ( void *pPointer ) ;

void simple_vmlib_upper ( void *pPointer ) ;

void simple_vmlib_input ( void *pPointer ) ;

void simple_vmlib_ascii ( void *pPointer ) ;

void simple_vmlib_char ( void *pPointer ) ;

void simple_vmlib_date ( void *pPointer ) ;

void simple_vmlib_time ( void *pPointer ) ;

void simple_vmlib_filename ( void *pPointer ) ;

void simple_vmlib_getchar ( void *pPointer ) ;

void simple_vmlib_system ( void *pPointer ) ;

void simple_vmlib_random ( void *pPointer ) ;

void simple_vmlib_timelist ( void *pPointer ) ;

void simple_vmlib_adddays ( void *pPointer ) ;

void simple_vmlib_diffdays ( void *pPointer ) ;

void simple_vmlib_version ( void *pPointer ) ;

void simple_vmlib_clockspersecond ( void *pPointer ) ;

void simple_vmlib_prevfilename ( void *pPointer ) ;

int simple_vmlib_adddays_isleapyear ( int nYear ) ;

void simple_vmlib_swap ( void *pPointer ) ;

void simple_vmlib_shutdown ( void *pPointer ) ;
/* Check Data Type */

void simple_vmlib_isstsimple ( void *pPointer ) ;

void simple_vmlib_isnumber ( void *pPointer ) ;

void simple_vmlib_islist ( void *pPointer ) ;

void simple_vmlib_type ( void *pPointer ) ;

void simple_vmlib_isnull ( void *pPointer ) ;

void simple_vmlib_isobject ( void *pPointer ) ;
/* Conversion */

void simple_vmlib_hex ( void *pPointer ) ;

void simple_vmlib_dec ( void *pPointer ) ;

void simple_vmlib_number ( void *pPointer ) ;

void simple_vmlib_stsimple ( void *pPointer ) ;

void simple_vmlib_str2hex ( void *pPointer ) ;

void simple_vmlib_hex2str ( void *pPointer ) ;

void simple_vmlib_str2list ( void *pPointer ) ;

void simple_vmlib_list2str ( void *pPointer ) ;

void simple_vmlib_str2hexcstyle ( void *pPointer ) ;
/* Stsimple */

void simple_vmlib_left ( void *pPointer ) ;

void simple_vmlib_right ( void *pPointer ) ;

void simple_vmlib_trim ( void *pPointer ) ;

void simple_vmlib_copy ( void *pPointer ) ;

void simple_vmlib_substr ( void *pPointer ) ;

void simple_vmlib_lines ( void *pPointer ) ;

void simple_vmlib_strcmp ( void *pPointer ) ;
/* Functional */

void simple_vmlib_eval ( void *pPointer ) ;
/* Error Handling */

void simple_vmlib_raise ( void *pPointer ) ;

void simple_vmlib_assert ( void *pPointer ) ;
/* Check Characters */

void simple_vmlib_isfunc ( void *pPointer,int (*pFunc)(int) ) ;

void simple_vmlib_isalnum ( void *pPointer ) ;

void simple_vmlib_isalpha ( void *pPointer ) ;

void simple_vmlib_iscntrl ( void *pPointer ) ;

void simple_vmlib_isdigit ( void *pPointer ) ;

void simple_vmlib_isgraph ( void *pPointer ) ;

void simple_vmlib_islower ( void *pPointer ) ;

void simple_vmlib_isprint ( void *pPointer ) ;

void simple_vmlib_ispunct ( void *pPointer ) ;

void simple_vmlib_isspace ( void *pPointer ) ;

void simple_vmlib_isupper ( void *pPointer ) ;

void simple_vmlib_isxdigit ( void *pPointer ) ;
/* Garbage Collector & Variable Pointer */

void simple_vmlib_callgc ( void *pPointer ) ;

void simple_vmlib_varptr ( void *pPointer ) ;

void simple_vmlib_intvalue ( void *pPointer ) ;

void simple_vmlib_object2pointer ( void *pPointer ) ;

void simple_vmlib_pointer2object ( void *pPointer ) ;

void simple_vmlib_nullpointer ( void *pPointer ) ;

void simple_vmlib_space ( void *pPointer ) ;

void simple_vmlib_ptrcmp ( void *pPointer ) ;
/* Ring State */

void simple_vmlib_state_init ( void *pPointer ) ;

void simple_vmlib_state_runcode ( void *pPointer ) ;

void simple_vmlib_state_delete ( void *pPointer ) ;

void simple_vmlib_state_runfile ( void *pPointer ) ;

void simple_vmlib_state_findvar ( void *pPointer ) ;

void simple_vmlib_state_newvar ( void *pPointer ) ;

void simple_vmlib_state_runobjectfile ( void *pPointer ) ;

void simple_vmlib_state_main ( void *pPointer ) ;

void simple_vmlib_state_setvar ( void *pPointer ) ;

void simple_vmlib_state_new ( void *pPointer ) ;

void simple_vmlib_state_mainfile ( void *pPointer ) ;
/* Ring See and Give */

void simple_vmlib_see ( void *pPointer ) ;

void simple_vmlib_give ( void *pPointer ) ;
/* API For C Functions */
#define SIMPLE_API_PARALIST (((VM *) pPointer)->pActiveMem)
#define SIMPLE_API_PARACOUNT (((VM *) pPointer)->nCFuncParaCount)
#define SIMPLE_API_GETSTSIMPLE(x) (simple_list_getstsimple(simple_list_getlist(SIMPLE_API_PARALIST,x),3))
#define SIMPLE_API_GETNUMBER(x) (simple_list_getdouble(simple_list_getlist(SIMPLE_API_PARALIST,x),3))
#define SIMPLE_API_GETPOINTER(x) (simple_list_getpointer(simple_list_getlist(SIMPLE_API_PARALIST,x),3))
#define SIMPLE_API_ISSTSIMPLE(x) (simple_list_isstsimple(simple_list_getlist(SIMPLE_API_PARALIST,x),3))
#define SIMPLE_API_ISNUMBER(x) (simple_list_isnumber(simple_list_getlist(SIMPLE_API_PARALIST,x),3))
#define SIMPLE_API_ISPOINTER(x) (simple_vm_api_ispointer((VM *) pPointer,x))
#define SIMPLE_API_GETPOINTERTYPE(x) (simple_list_getint(simple_list_getlist(SIMPLE_API_PARALIST,x),4))
#define SIMPLE_API_ERROR(x) (simple_vm_error((VM *) pPointer,x))
#define SIMPLE_API_ISLIST(x) (simple_vm_api_islist((VM *) pPointer,x))
#define SIMPLE_API_GETLIST(x) (simple_vm_api_getlist((VM *) pPointer,x))
#define SIMPLE_API_RETNUMBER(x) ((VM *) pPointer)->nSP++ ; simple_itemarray_setdouble(((VM *) pPointer)->aStack, ((VM *) pPointer)->nSP , x)
#define SIMPLE_API_RETSTSIMPLE(x) ((VM *) pPointer)->nSP++ ; simple_itemarray_setstsimple(((VM *) pPointer)->aStack, ((VM *) pPointer)->nSP, x)
#define SIMPLE_API_RETSTSIMPLE2(x,y) ((VM *) pPointer)->nSP++ ; simple_itemarray_setstsimple2(((VM *) pPointer)->aStack, ((VM *) pPointer)->nSP, x,y)
#define SIMPLE_API_RETLIST(x) simple_vm_api_retlist((VM *) pPointer,x)
#define SIMPLE_API_NEWLIST simple_vm_api_newlist((VM *) pPointer)
#define SIMPLE_API_RETCPOINTER(x,y) (simple_vm_api_retcpointer((VM *) pPointer,(void *) x,y))
#define SIMPLE_API_GETCPOINTER(x,y) (simple_vm_api_getcpointer((VM *) pPointer,x,y))
#define SIMPLE_API_PUSHPVALUE(x) ((VM *) pPointer)->nSP++ ; simple_itemarray_setpointer(((VM *) pPointer)->aStack, ((VM *) pPointer)->nSP , x )
#define SIMPLE_API_OBJTYPE ((VM *) pPointer)->aStack[((VM *) pPointer)->nSP].nObjectType
#define SIMPLE_FUNC(x) void x(void *pPointer)
#define SIMPLE_API_GETSTSIMPLESIZE(x) (simple_list_getstsimplesize(simple_list_getlist(SIMPLE_API_PARALIST,x),3))
#define SIMPLE_API_SETNULLPOINTER(x) (simple_vm_api_setcpointernull((VM *) pPointer,x))
#define SIMPLE_API_GETCPOINTERSTATUS(x) simple_list_getint(SIMPLE_API_GETLIST(x),SIMPLE_CPOINTER_STATUS)
#define SIMPLE_API_ISCPOINTERNOTASSIGNED(x) (SIMPLE_API_GETCPOINTERSTATUS(x) == SIMPLE_CPOINTERSTATUS_NOTASSIGNED)
#define SIMPLE_API_VARPOINTER(x,y) (simple_vm_api_varptr(pPointer,x,y))
#define SIMPLE_API_INTVALUE(x) (simple_vm_api_intvalue(pPointer,x))
#define SIMPLE_API_GETINTPOINTER(x) (int *) SIMPLE_API_VARPOINTER(SIMPLE_API_GETSTSIMPLE(x),"int")
#define SIMPLE_API_ACCEPTINTVALUE(x) SIMPLE_API_INTVALUE(SIMPLE_API_GETSTSIMPLE(x))
#define SIMPLE_API_GETDOUBLEPOINTER(x) SIMPLE_API_VARPOINTER(SIMPLE_API_GETSTSIMPLE(x),"double")
#define SIMPLE_API_IGNORECPOINTERTYPE ((VM *) pPointer)->nIgnoreCPointerTypeCheck = 1
#define SIMPLE_API_ISCPOINTER(x) simple_vm_api_iscpointer(pPointer,x)
#define SIMPLE_API_ISOBJECT(x) simple_vm_api_isobject(pPointer,x)
#define SIMPLE_API_GETCPOINTER2POINTER(x,y) (simple_vm_api_getcpointer2pointer((VM *) pPointer,x,y))
/* Constants/MACRO */
#define SIMPLE_API_MISS1PARA "Bad parameters count, the function expect one parameter"
#define SIMPLE_API_MISS2PARA "Bad parameters count, the function expect two parameters"
#define SIMPLE_API_MISS3PARA "Bad parameters count, the function expect three parameters"
#define SIMPLE_API_MISS4PARA "Bad parameters count, the function expect four parameters"
#define SIMPLE_API_BADPARATYPE "Bad parameter type!"
#define SIMPLE_API_BADPARACOUNT "Bad parameters count!"
#define SIMPLE_API_BADPARARANGE "Bad parameters value, error in range!"
#define SIMPLE_API_NOTPOINTER "Error in parameter, not pointer!"
#define SIMPLE_API_NULLPOINTER "Error in parameter, NULL pointer!"
#define SIMPLE_API_EMPTYLIST "Bad parameter, empty list!"
#define simple_vm_funcregister(x,y) simple_vm_funcregister2(pRingState,x,y)
/*
**  Note : The C Function Get Lists as pointers because of (List Pass by Reference) 
**  The List Maybe a Variable/ListItem or may represent Object or C Pointer inside a List 
**  C Pointer List , [ Pointer Value , Type Stsimple , Status Number 0=Not Copied 1=Copied 2= Not Assigned Yet] 
*/
#endif
