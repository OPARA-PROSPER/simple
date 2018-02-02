
/* 
	Copyright (c) 2017-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
	MIT License Copyright (c) 2017 simple 

*/

/* 
 * File:   simple.h
 * Author: thecarisma
 *
 * Created on July 10, 2017, 1:10 PM
 */


#ifndef simple_vm_h
#define simple_vm_h
/*
**  Data 
**  Stack Size 
*/
#define SIMPLE_VM_STACK_SIZE 256
#define SIMPLE_VM_STACK_CHECKOVERFLOW 253
#define SIMPLE_VM_FREE_STACK_IN_CLASS_REGION_AFTER 100
#define SIMPLE_VM_BC_ITEMS_COUNT 24
typedef struct ByteCode {
	Item *aData[SIMPLE_VM_BC_ITEMS_COUNT]  ;
	char nSize  ;
	List *pList  ;
} ByteCode ;
typedef struct VM {
	int nPC  ;
	List *pCode  ;
	List *pFunctionsMap  ;
	List *pClassesMap  ;
	List *pPackagesMap  ;
	int nOPCode  ;
	Item aStack[SIMPLE_VM_STACK_SIZE]  ;
	unsigned char nSP  ;
	List *pMem  ;
	List *pActiveMem  ;
	List *pTempMem  ;
	ByteCode *pByteCode  ;
	ByteCode *pByteCodeIR  ;
	char *cFileName  ;
	int nLineNumber  ;
	int nListStart  ;
	List *pNestedLists  ;
	int nBlockFlag  ;
	List *aPCBlockFlag  ;
	List *pFuncCallList  ;
	int nFuncSP  ;
	int nFuncExecute  ;
	List *pCFunctionsList  ;
	List *pExitMark  ;
	List *pLoopMark  ;
	int nCallMainFunction  ;
	List *pTry  ;
	List *aScopeNewObj  ;
	char nCallMethod  ;
	List *pObjState  ;
	List *pBraceObject  ;
	List *aBraceObjects  ;
	int nVarScope  ;
	int nScopeID  ;
	List *aScopeID  ;
	int nActiveScopeID  ;
	int nActiveCatch  ;
	char nInsideBraceFlag  ;
	char nInClassRegion  ;
	List *aActivePackage  ;
	char nPrivateFlag  ;
	char nGetSetProperty  ;
	void *pGetSetObject  ;
	char nGetSetObjType  ;
	List *aSetProperty  ;
	void *pAssignment  ;
	List *aCPointers  ;
	List *aForStep  ;
	char nFirstAddress  ;
	char nBeforeEqual  ;
	char nNOAssignment  ;
	RingState *pRingState  ;
	List *aLoadAddressScope  ;
	List *aBeforeObjState  ;
	List *pLoadAddressScope  ;
	int nFuncExecute2  ;
	List *aNewByteCodeItems  ;
	char nEvalCalledFromRingCode  ;
	char nDecimals  ;
	char nEvalReallocationFlag  ;
	int nEvalReallocationSize  ;
	int nCFuncParaCount  ;
	char nIgnoreNULL  ;
	int nEvalReturnPC  ;
	char nRetItemRef  ;
	void (*pFuncMutexDestroy)(void *) ;
	void (*pFuncMutexLock)(void *) ;
	void (*pFuncMutexUnlock)(void *) ;
	void *pMutex  ;
	char nIgnoreCPointerTypeCheck  ;
	char nCallClassInit  ;
	char nRetEvalDontDelete  ;
	char *cPrevFileName  ;
	char nRunCode  ;
	char nActiveError  ;
	List *aDynamicSelfItems  ;
	String *pPackageName  ;
	char lTrace  ;
	String *pTrace  ;
	char lTraceActive  ;
	char nTraceEvent  ;
	List *pTraceData  ;
	char nEvalInScope  ;
	char lPassError  ;
	char lHideErrorMsg  ;
	List *aGlobalScopes  ;
	List *aActiveGlobalScopes  ;
	int nCurrentGlobalScope  ;
	char *cFileNameInClassRegion  ;
} VM ;
/*
**  Functions 
**  Main 
*/

VM * simple_vm_new ( RingState *pRingState ) ;

VM * simple_vm_delete ( VM *pVM ) ;

SIMPLE_API void simple_vm_loadcode ( VM *pVM ) ;

void simple_vm_start ( RingState *pRingState,VM *pVM ) ;

void simple_vm_fetch ( VM *pVM ) ;

void simple_vm_fetch2 ( VM *pVM ) ;

void simple_vm_execute ( VM *pVM ) ;

SIMPLE_API void simple_vm_error ( VM *pVM,const char *cStr ) ;

int simple_vm_eval ( VM *pVM,const char *cStr ) ;

void simple_vm_tobytecode ( VM *pVM,int x ) ;

void simple_vm_error2 ( VM *pVM,const char *cStr,const char *cStr2 ) ;

void simple_vm_newbytecodeitem ( VM *pVM,int x ) ;

void simple_vm_mainloop ( VM *pVM ) ;

SIMPLE_API void simple_vm_runcode ( VM *pVM,const char *cStr ) ;

void simple_vm_init ( RingState *pRingState ) ;

void simple_vm_printstack ( VM *pVM ) ;

SIMPLE_API void simple_vm_showerrormessage ( VM *pVM,const char *cStr ) ;

void simple_vm_addglobalvariables ( VM *pVM ) ;
/* Stack and Variables */

void simple_vm_pushv ( VM *pVM ) ;

void simple_vm_loadaddress ( VM *pVM ) ;

void simple_vm_assignment ( VM *pVM ) ;

void simple_vm_inc ( VM *pVM ) ;

void simple_vm_loadapushv ( VM *pVM ) ;

void simple_vm_newline ( VM *pVM ) ;

void simple_vm_freestack ( VM *pVM ) ;

void simple_vm_setreference ( VM *pVM ) ;

void simple_vm_list_copy ( VM *pVM,List *pNewList, List *pList ) ;

void simple_vm_list_simpointercopy ( VM *pVM,List *pList ) ;

void simple_vm_beforeequallist ( VM *pVM,List *pVar,double nNum1 ) ;

void simple_vm_beforeequalitem ( VM *pVM,Item *pItem,double nNum1 ) ;

void simple_vm_assignmentpointer ( VM *pVM ) ;

void simple_vm_freeloadaddressscope ( VM *pVM ) ;

void simple_vm_setfilename ( VM *pVM ) ;

void simple_vm_loadaddressfirst ( VM *pVM ) ;

void simple_vm_endfuncexec ( VM *pVM ) ;
/* Compare */

void simple_vm_equal ( VM *pVM ) ;

void simple_vm_lessequal ( VM *pVM ) ;

void simple_vm_less ( VM *pVM ) ;

void simple_vm_greater ( VM *pVM ) ;

void simple_vm_greaterequal ( VM *pVM ) ;

void simple_vm_notequal ( VM *pVM ) ;
/* Math */

void simple_vm_sum ( VM *pVM ) ;

void simple_vm_sub ( VM *pVM ) ;

void simple_vm_mul ( VM *pVM ) ;

void simple_vm_div ( VM *pVM ) ;

void simple_vm_mod ( VM *pVM ) ;

void simple_vm_neg ( VM *pVM ) ;

char * simple_vm_numtostring ( VM *pVM,double nNum1,char *cStr ) ;

double simple_vm_stringtonum ( VM *pVM,const char *cStr ) ;

void simple_vm_expr_ppoo ( VM *pVM,const char *cStr ) ;

void simple_vm_expr_npoo ( VM *pVM,const char *cStr,double nNum1 ) ;

void simple_vm_expr_spoo ( VM *pVM,const char *cStr,const char *cStr2,int nSize ) ;

void simple_vm_plusplus ( VM *pVM ) ;

void simple_vm_minusminus ( VM *pVM ) ;

void simple_vm_addlisttolist ( VM *pVM,List *pList,List *pList2 ) ;
/* Logic */

void simple_vm_and ( VM *pVM ) ;

void simple_vm_or ( VM *pVM ) ;

void simple_vm_not ( VM *pVM ) ;
/* Variables */

void simple_vm_newscope ( VM *pVM ) ;

int simple_vm_findvar ( VM *pVM,const char *cStr ) ;

int simple_vm_findvar2 ( VM *pVM,int x,List *pList2,const char *cStr ) ;

void simple_vm_newvar ( VM *pVM,const char *cStr ) ;

List * simple_vm_newvar2 ( VM *pVM,const char *cStr,List *pParent ) ;

void simple_vm_addnewnumbervar ( VM *pVM,const char *cStr,double x ) ;

void simple_vm_addnewstringvar ( VM *pVM,const char *cStr,const char *cStr2 ) ;

void simple_vm_deletescope ( VM *pVM ) ;

void simple_vm_addnewpointervar ( VM *pVM,const char *cStr,void *x,int y ) ;

void simple_vm_newtempvar ( VM *pVM,const char *cStr, List *TempList ) ;

void simple_vm_addnewstringvar2 ( VM *pVM,const char *cStr,const char *cStr2,int nStrSize ) ;

List * simple_vm_newtempvar2 ( VM *pVM,const char *cStr,List *pList3 ) ;

void simple_vm_addnewcpointervar ( VM *pVM,const char *cStr,void *pPointer,const char *cStr2 ) ;
/* Jump */

void simple_vm_jump ( VM *pVM ) ;

void simple_vm_jumpzero ( VM *pVM ) ;

void simple_vm_jumpfor ( VM *pVM ) ;

void simple_vm_jumpone ( VM *pVM ) ;

void simple_vm_jumpzero2 ( VM *pVM ) ;

void simple_vm_jumpone2 ( VM *pVM ) ;
/* Lists */

void simple_vm_liststart ( VM *pVM ) ;

void simple_vm_listitem ( VM *pVM ) ;

void simple_vm_listend ( VM *pVM ) ;

void simple_vm_loadindexaddress ( VM *pVM ) ;

void simple_vm_listpushv ( VM *pVM ) ;

void simple_vm_listassignment ( VM *pVM ) ;

void simple_vm_listgetvalue ( VM *pVM,List *pVar,const char *cStr ) ;

int simple_vm_strcmpnotcasesensitive ( const char *cStr1,const char *cStr2 ) ;
/* Functions */

int simple_vm_loadfunc ( VM *pVM ) ;

int simple_vm_loadfunc2 ( VM *pVM,const char *cStr,int nPerformance ) ;

void simple_vm_call ( VM *pVM ) ;

void simple_vm_call2 ( VM *pVM ) ;

void simple_vm_return ( VM *pVM ) ;

void simple_vm_returnnull ( VM *pVM ) ;

void simple_vm_returneval ( VM *pVM ) ;

void simple_vm_newfunc ( VM *pVM ) ;

void simple_vm_blockflag ( VM *pVM ) ;

void simple_vm_blockflag2 ( VM *pVM,int x ) ;

void simple_vm_removeblockflag ( VM *pVM ) ;

void simple_vm_movetoprevscope ( VM *pVM ) ;

void simple_vm_createtemplist ( VM *pVM ) ;

void simple_vm_saveloadaddressscope ( VM *pVM ) ;

void simple_vm_restoreloadaddressscope ( VM *pVM ) ;

void simple_vm_anonymous ( VM *pVM ) ;

int simple_vm_isstackpointertoobjstate ( VM *pVM ) ;

void simple_vm_retitemref ( VM *pVM ) ;

void simple_vm_callclassinit ( VM *pVM ) ;
/* User Interface */

void simple_vm_see ( VM *pVM ) ;

void simple_vm_give ( VM *pVM ) ;
/* String As Array */

void simple_vm_stsimple_pushv ( VM *pVM ) ;

void simple_vm_stsimple_assignment ( VM *pVM ) ;

void simple_vm_stsimple_index ( VM *pVM , String *pString , double x ) ;
/* Try Catch Done */

void simple_vm_try ( VM *pVM ) ;

void simple_vm_catch ( VM *pVM,const char *cError ) ;

void simple_vm_done ( VM *pVM ) ;
/* Duplicate and Range */

void simple_vm_dup ( VM *pVM ) ;

void simple_vm_range ( VM *pVM ) ;

List * simple_vm_range_newlist ( VM *pVM ) ;
/* OOP */

void simple_vm_oop_newobj ( VM *pVM ) ;

void simple_vm_oop_property ( VM *pVM ) ;

int simple_vm_oop_isobject ( List *pList ) ;

List * simple_vm_oop_getobj ( VM *pVM ) ;

void simple_vm_oop_loadmethod ( VM *pVM ) ;

void simple_vm_oop_aftercallmethod ( VM *pVM ) ;

void simple_vm_oop_setscope ( VM *pVM ) ;

void simple_vm_oop_printobj ( VM *pVM,List *pList ) ;

void simple_vm_oop_parentinit ( VM *pVM,List *pList ) ;

void simple_vm_oop_parentmethods ( VM *pVM,List *pList ) ;

void simple_vm_oop_newclass ( VM *pVM ) ;

void simple_vm_oop_setbraceobj ( VM *pVM,List *pList ) ;

void simple_vm_oop_bracestart ( VM *pVM ) ;

void simple_vm_oop_braceend ( VM *pVM ) ;

void simple_vm_oop_bracestack ( VM *pVM ) ;

void simple_vm_oop_newsuperobj ( VM *pVM,List *pState,List *pClass ) ;

List * simple_vm_oop_getsuperobj ( VM *pVM ) ;

void simple_vm_oop_loadsuperobjmethod ( VM *pVM,List *pSuper ) ;

void simple_vm_oop_import ( VM *pVM ) ;

List * simple_vm_oop_checkpointertoclassinpackage ( VM *pVM,List *pList ) ;

void simple_vm_oop_import2 ( VM *pVM,const char *cPackage ) ;

void simple_vm_oop_import3 ( VM *pVM,List *pList ) ;

int simple_vm_oop_visibleclassescount ( VM *pVM ) ;

List * simple_vm_oop_visibleclassitem ( VM *pVM,int x ) ;

void simple_vm_oop_pushclasspackage ( VM *pVM,List *pList ) ;

void simple_vm_oop_popclasspackage ( VM *pVM ) ;

void simple_vm_oop_deletepackagesafter ( VM *pVM,int x ) ;

int simple_vm_oop_callmethodinsideclass ( VM *pVM ) ;

void simple_vm_oop_setget ( VM *pVM,List *pVar ) ;

void simple_vm_oop_setproperty ( VM *pVM ) ;

void simple_vm_oop_operatoroverloading ( VM *pVM,List *pObj,const char *cStr1,int nType,const char *cStr2,double nNum1,void *pPointer,int nPointerType ) ;

List * simple_vm_oop_objvarfromobjlist ( List *pList ) ;

int simple_vm_oop_objtypefromobjlist ( List *pList ) ;

Item * simple_vm_oop_objitemfromobjlist ( List *pList ) ;

void simple_vm_oop_callmethodfrombrace ( VM *pVM ) ;

int simple_vm_oop_ismethod ( VM *pVM,List *pList,const char *cStr ) ;

void simple_vm_oop_updateselfpointer ( VM *pVM,List *pObj,int nType,void *pContainer ) ;

void simple_vm_oop_movetobeforeobjstate ( VM *pVM ) ;

void simple_vm_oop_setthethisvariable ( VM *pVM ) ;

void simple_vm_oop_updateselfpointer2 ( VM *pVM,List *pObj ) ;
/* For Better Performance */

void simple_vm_pushp ( VM *pVM ) ;

void simple_vm_incp ( VM *pVM ) ;

void simple_vm_pushpv ( VM *pVM ) ;

void simple_vm_incjump ( VM *pVM ) ;

void simple_vm_incpjump ( VM *pVM ) ;

void simple_vm_jumpvarlenum ( VM *pVM ) ;

void simple_vm_jumpvarplenum ( VM *pVM ) ;

void simple_vm_loadfuncp ( VM *pVM ) ;

void simple_vm_pushplocal ( VM *pVM ) ;

void simple_vm_inclpjump ( VM *pVM ) ;

void simple_vm_jumpvarlplenum ( VM *pVM ) ;

void simple_vm_incpjumpstep1 ( VM *pVM ) ;

void simple_vm_jumpvarplenumstep1 ( VM *pVM ) ;
/* End Program / Exit from Loop / Loop (Continue) */

void simple_vm_bye ( VM *pVM ) ;

void simple_vm_exitmark ( VM *pVM ) ;

void simple_vm_popexitmark ( VM *pVM ) ;

void simple_vm_exit ( VM *pVM,int nType ) ;
/* State */

void simple_vm_savestate ( VM *pVM,List *pList ) ;

void simple_vm_restorestate ( VM *pVM,List *pList,int nPos,int nFlag ) ;

void simple_vm_backstate ( VM *pVM,int x,List *pList ) ;

void simple_vm_savestate2 ( VM *pVM,List *pList ) ;

void simple_vm_restorestate2 ( VM *pVM,List *pList,int x ) ;

List * simple_vm_savestack ( VM *pVM ) ;

void simple_vm_restorestack ( VM *pVM,List *pList ) ;
/* Bitwise */

void simple_vm_bitand ( VM *pVM ) ;

void simple_vm_bitor ( VM *pVM ) ;

void simple_vm_bitxor ( VM *pVM ) ;

void simple_vm_bitnot ( VM *pVM ) ;

void simple_vm_bitshl ( VM *pVM ) ;

void simple_vm_bitshr ( VM *pVM ) ;
/* Step Number */

void simple_vm_stepnumber ( VM *pVM ) ;

void simple_vm_popstep ( VM *pVM ) ;
/* Threads */

SIMPLE_API void simple_vm_mutexfunctions ( VM *pVM,void *(*pFunc)(void),void (*pFuncLock)(void *),void (*pFuncUnlock)(void *),void (*pFuncDestroy)(void *) ) ;

SIMPLE_API void simple_vm_mutexlock ( VM *pVM ) ;

SIMPLE_API void simple_vm_mutexunlock ( VM *pVM ) ;

SIMPLE_API void simple_vm_mutexdestroy ( VM *pVM ) ;

SIMPLE_API void simple_vm_runcodefromthread ( VM *pVM,const char *cStr ) ;
/* Trace */

void simple_vm_traceevent ( VM *pVM,char nEvent ) ;
/* Fast Function Call for Extensions (Without Eval) */

SIMPLE_API void simple_vm_callfunction ( VM *pVM,char *cFuncName ) ;
/* Custom Global Scope */

void simple_vm_newglobalscope ( VM *pVM ) ;

void simple_vm_endglobalscope ( VM *pVM ) ;

void simple_vm_setglobalscope ( VM *pVM ) ;

List * simple_vm_getglobalscope ( VM *pVM ) ;
/*
**  Macro 
**  Stack 
**  Add 
*/
#define SIMPLE_VM_STACK_PUSHC pVM->nSP++ ; simple_itemarray_setstring2(pVM->aStack, pVM->nSP, simple_stsimple_get(pVM->pByteCodeIR->aData[1]->data.pString), simple_stsimple_size(pVM->pByteCodeIR->aData[1]->data.pString))
#define SIMPLE_VM_STACK_PUSHN pVM->nSP++ ; simple_itemarray_setdouble(pVM->aStack, pVM->nSP , pVM->pByteCodeIR->aData[1]->data.dNumber)
#define SIMPLE_VM_STACK_PUSHP pVM->nSP++ ; simple_itemarray_setpointer(pVM->aStack, pVM->nSP , pVM->pByteCodeIR->aData[1]->data.pPointer )
/* Note, use SIMPLE_VM_STACK_OBJTYPE to read/write the pointer type */
#define SIMPLE_VM_STACK_TRUE simple_itemarray_setdouble(pVM->aStack,pVM->nSP, 1)
#define SIMPLE_VM_STACK_FALSE simple_itemarray_setdouble(pVM->aStack,pVM->nSP, 0)
#define SIMPLE_VM_STACK_PUSHCVAR simple_itemarray_setstring2(pVM->aStack,pVM->nSP,simple_list_getstring(pVar,3),simple_list_getstringsize(pVar,3))
#define SIMPLE_VM_STACK_PUSHNVAR simple_itemarray_setdouble(pVM->aStack,pVM->nSP,simple_list_getdouble(pVar,3))
#define SIMPLE_VM_STACK_PUSHPVALUE(x) pVM->nSP++ ; simple_itemarray_setpointer(pVM->aStack, pVM->nSP , x )
#define SIMPLE_VM_STACK_PUSHCVALUE(x) pVM->nSP++ ; simple_itemarray_setstring(pVM->aStack, pVM->nSP, x)
#define SIMPLE_VM_STACK_PUSHNVALUE(x) pVM->nSP++ ; simple_itemarray_setdouble(pVM->aStack, pVM->nSP , x)
#define SIMPLE_VM_STACK_SETCVALUE(x) simple_itemarray_setstring(pVM->aStack, pVM->nSP, x)
#define SIMPLE_VM_STACK_SETNVALUE(x) simple_itemarray_setdouble(pVM->aStack, pVM->nSP , x)
#define SIMPLE_VM_STACK_SETPVALUE(x) simple_itemarray_setpointer(pVM->aStack, pVM->nSP , x )
#define SIMPLE_VM_STACK_SETCVALUE2(x,y) simple_itemarray_setstring2(pVM->aStack, pVM->nSP, x,y)
/* Check */
#define SIMPLE_VM_STACK_ISSTRING simple_itemarray_isstring(pVM->aStack,pVM->nSP)
#define SIMPLE_VM_STACK_ISNUMBER simple_itemarray_isnumber(pVM->aStack,pVM->nSP)
#define SIMPLE_VM_STACK_ISPOINTER simple_itemarray_ispointer(pVM->aStack,pVM->nSP)
#define SIMPLE_VM_STACK_ISPOINTERVALUE(x) simple_itemarray_ispointer(pVM->aStack,x)
/* Read */
#define SIMPLE_VM_STACK_READC simple_itemarray_getstring(pVM->aStack,pVM->nSP)
#define SIMPLE_VM_STACK_STRINGSIZE simple_itemarray_getstringsize(pVM->aStack,pVM->nSP)
#define SIMPLE_VM_STACK_READN simple_itemarray_getdouble(pVM->aStack,pVM->nSP)
#define SIMPLE_VM_STACK_READP simple_itemarray_getpointer(pVM->aStack,pVM->nSP)
#define SIMPLE_VM_STACK_OBJTYPE pVM->aStack[pVM->nSP].nObjectType
#define SIMPLE_VM_STACK_PREVOBJTYPE pVM->aStack[pVM->nSP-1].nObjectType
/* Delete */
#define SIMPLE_VM_STACK_POP pVM->nSP--
/* Objects/Pointer  - Type */
#define SIMPLE_OBJTYPE_VARIABLE 1
#define SIMPLE_OBJTYPE_LISTITEM 2
#define SIMPLE_OBJTYPE_SUBSTRING 3
/* Variable Structure */
#define SIMPLE_VAR_NAME 1
#define SIMPLE_VAR_TYPE 2
#define SIMPLE_VAR_VALUE 3
#define SIMPLE_VAR_PVALUETYPE 4
#define SIMPLE_VAR_PRIVATEFLAG 5
/* Number of global variables defined by the VM like True, False, cErrorMsg */
#define SIMPLE_VM_INTERNALGLOBALSCOUNT 14
#define SIMPLE_VAR_LISTSIZE 5
/* Variable Type */
#define SIMPLE_VM_NULL 0
#define SIMPLE_VM_STRING 1
#define SIMPLE_VM_NUMBER 2
#define SIMPLE_VM_LIST 3
#define SIMPLE_VM_POINTER 4
/* IR (Instruction Register) */
#define SIMPLE_VM_JUMP pVM->nPC = pVM->pByteCodeIR->aData[1]->data.iNumber
#define SIMPLE_VM_IR_READC simple_stsimple_get(pVM->pByteCodeIR->aData[1]->data.pString)
#define SIMPLE_VM_IR_READCVALUE(x) simple_stsimple_get(pVM->pByteCodeIR->aData[x]->data.pString)
#define SIMPLE_VM_IR_READP pVM->pByteCodeIR->aData[1]->data.pPointer
#define SIMPLE_VM_IR_READPVALUE(x) pVM->pByteCodeIR->aData[x]->data.pPointer
#define SIMPLE_VM_IR_READI pVM->pByteCodeIR->aData[1]->data.iNumber
#define SIMPLE_VM_IR_READIVALUE(x) pVM->pByteCodeIR->aData[x]->data.iNumber
#define SIMPLE_VM_IR_READD pVM->pByteCodeIR->aData[1]->data.dNumber
#define SIMPLE_VM_IR_READDVALUE(x) pVM->pByteCodeIR->aData[x]->data.dNumber
#define SIMPLE_VM_IR_PARACOUNT pVM->pByteCodeIR->nSize
#define SIMPLE_VM_IR_OPCODE pVM->pByteCodeIR->aData[0]->data.iNumber
#define SIMPLE_VM_IR_SETCVALUE(x,y) simple_stsimple_set_gc(pVM->pRingState,pVM->pByteCodeIR->aData[x]->data.pString,y)
#define SIMPLE_VM_IR_ITEM(x) pVM->pByteCodeIR->aData[x]
#define SIMPLE_VM_IR_LIST pVM->pByteCodeIR->pList
#define SIMPLE_VM_IR_LOAD pVM->pByteCodeIR = pVM->pByteCode + pVM->nPC - 1
#define SIMPLE_VM_IR_UNLOAD pVM->pByteCodeIR = pVM->pByteCode + pVM->nPC - 2
/*
**  Calling Functions 
**  Note : When you insert items check performance functions for update too! 
**  pFuncCallList ( Type, Func Name , Position(PC) , Stack Pointer , TempMem, ... 
**  Types 
*/
#define SIMPLE_FUNCTYPE_SCRIPT 1
#define SIMPLE_FUNCTYPE_C 2
#define SIMPLE_FUNCCL_TYPE 1
#define SIMPLE_FUNCCL_NAME 2
#define SIMPLE_FUNCCL_PC 3
#define SIMPLE_FUNCCL_SP 4
#define SIMPLE_FUNCCL_TEMPMEM 5
#define SIMPLE_FUNCCL_FILENAME 6
#define SIMPLE_FUNCCL_NEWFILENAME 6
#define SIMPLE_FUNCCL_METHODORFUNC 8
#define SIMPLE_FUNCCL_LINENUMBER 9
#define SIMPLE_FUNCCL_CALLERPC 10
#define SIMPLE_FUNCCL_FUNCEXE 11
#define SIMPLE_FUNCCL_LISTSTART 12
#define SIMPLE_FUNCCL_NESTEDLISTS 13
#define SIMPLE_FUNCCL_STATE 14
/* pFunctionsMap ( Func Name , Position , File Name, Private Flag) */
#define SIMPLE_FUNCMAP_NAME 1
#define SIMPLE_FUNCMAP_PC 2
#define SIMPLE_FUNCMAP_FILENAME 3
#define SIMPLE_FUNCMAP_PRIVATEFLAG 4
/* FunctionMap List Size */
#define SIMPLE_FUNCMAP_NORMALSIZE 4
/* Variable Scope */
#define SIMPLE_VARSCOPE_NOTHING 0
#define SIMPLE_VARSCOPE_LOCAL 1
#define SIMPLE_VARSCOPE_OBJSTATE 2
#define SIMPLE_VARSCOPE_GLOBAL 3
#define SIMPLE_VARSCOPE_NEWOBJSTATE 4
/*
**  OOP 
**  pClassesMap 
*/
#define SIMPLE_CLASSMAP_CLASSNAME 1
#define SIMPLE_CLASSMAP_PC 2
#define SIMPLE_CLASSMAP_PARENTCLASS 3
#define SIMPLE_CLASSMAP_METHODSLIST 4
#define SIMPLE_CLASSMAP_FLAGISPARENTCLASSINFCOLLECTED 5
#define SIMPLE_CLASSMAP_POINTERTOPACKAGE 6
#define SIMPLE_CLASSMAP_POINTERTOLISTOFCLASSINSIDEPACKAGE 2
#define SIMPLE_CLASSMAP_POINTERTOFILENAME 3
#define SIMPLE_CLASSMAP_IMPORTEDCLASSSIZE 3
/* Packages */
#define SIMPLE_PACKAGENAME 1
#define SIMPLE_CLASSESLIST 2
/* Object */
#define SIMPLE_OBJECT_CLASSPOINTER 1
#define SIMPLE_OBJECT_OBJECTDATA 2
/* pObjState */
#define SIMPLE_OBJSTATE_SCOPE 1
#define SIMPLE_OBJSTATE_METHODS 2
#define SIMPLE_OBJSTATE_CLASS 3
/* Operator Overloading */
#define SIMPLE_OOPARA_STRING 1
#define SIMPLE_OOPARA_NUMBER 2
#define SIMPLE_OOPARA_POINTER 3
/* aBraceObjects */
#define SIMPLE_ABRACEOBJECTS_BRACEOBJECT 1
/* aScopeNewObj */
#define SIMPLE_ASCOPENEWOBJ_PREVSCOPE 1
#define SIMPLE_ASCOPENEWOBJ_LISTSTART 2
#define SIMPLE_ASCOPENEWOBJ_NESTEDLISTS 3
#define SIMPLE_ASCOPENEWOBJ_SP 4
#define SIMPLE_ASCOPENEWOBJ_FUNCSP 10
/* State */
#define SIMPLE_STATE_TRYCATCH 1
#define SIMPLE_STATE_EXIT 2
#define SIMPLE_STATE_RETURN 3
/* Memory */
#define SIMPLE_MEMORY_GLOBALSCOPE 1
/* List as Hash */
#define SIMPLE_LISTHASH_KEY 1
#define SIMPLE_LISTHASH_VALUE 2
#define SIMPLE_LISTHASH_SIZE 2
/* C Pointer List (inside Variable Value) */
#define SIMPLE_CPOINTER_POINTER 1
#define SIMPLE_CPOINTER_TYPE 2
#define SIMPLE_CPOINTER_STATUS 3
#define SIMPLE_CPOINTER_LISTSIZE 3
/* C Pointer Status */
#define SIMPLE_CPOINTERSTATUS_NOTCOPIED 0
#define SIMPLE_CPOINTERSTATUS_COPIED 1
#define SIMPLE_CPOINTERSTATUS_NOTASSIGNED 2
/* Temp Object */
#define SIMPLE_TEMP_OBJECT "simple_temp_object"
#define SIMPLE_TEMP_VARIABLE "simple_sys_temp"
/* Trace */
#define SIMPLE_VM_TRACEEVENT_NEWLINE 1
#define SIMPLE_VM_TRACEEVENT_NEWFUNC 2
#define SIMPLE_VM_TRACEEVENT_RETURN 3
#define SIMPLE_VM_TRACEEVENT_ERROR 4
#define SIMPLE_VM_TRACEEVENT_BEFORECFUNC 5
#define SIMPLE_VM_TRACEEVENT_AFTERCFUNC 6
/* Runtime Error Messages */
#define SIMPLE_VM_ERROR_DIVIDEBYZERO "Error (R1) : Cann't divide by zero !"
#define SIMPLE_VM_ERROR_INDEXOUTOFRANGE "Error (R2) : Array Access (Index out of range) !"
#define SIMPLE_VM_ERROR_FUNCNOTFOUND "Error (R3) : Calling Function without definition !"
#define SIMPLE_VM_ERROR_STACKOVERFLOW "Error (R4) : Stack Overflow !"
#define SIMPLE_VM_ERROR_OBJECTISNOTLIST "Error (R5) : Can't access the list item, Object is not list !"
#define SIMPLE_VM_ERROR_NOTVARIABLE "Error (R6) : Variable is required"
#define SIMPLE_VM_ERROR_VALUEMORETHANONECHAR "Error (R7) : Can't assign to a string letter more than one character"
#define SIMPLE_VM_ERROR_VARISNOTSTRING "Error (R8) : Variable is not a string "
#define SIMPLE_VM_ERROR_EXITWITHOUTLOOP "Error (R9) : Using exit command outside loops "
#define SIMPLE_VM_ERROR_EXITNUMBEROUTSIDERANGE "Error (R10) : Using exit command with number outside the range "
#define SIMPLE_VM_ERROR_CLASSNOTFOUND "Error (R11) : error in class name, class not found! "
#define SIMPLE_VM_ERROR_PROPERTYNOTFOUND "Error (R12) : error in property name, property not found! "
#define SIMPLE_VM_ERROR_NOTOBJECT "Error (R13) : Object is required"
#define SIMPLE_VM_ERROR_METHODNOTFOUND "Error (R14) : Calling Method without definition !"
#define SIMPLE_VM_ERROR_PARENTCLASSNOTFOUND "Error (R15) : error in parent class name, class not found! "
#define SIMPLE_VM_ERROR_BRACEWITHOUTOBJECT "Error (R16) : Using braces to access unknown object ! "
#define SIMPLE_VM_ERROR_SUPERCLASSNOTFOUND "Error (R17) : error, using 'Super' without parent class! "
#define SIMPLE_VM_ERROR_NUMERICOVERFLOW "Error (R18) : Numeric Overflow! "
#define SIMPLE_VM_ERROR_LESSPARAMETERSCOUNT "Error (R19) : Calling function with less number of parameters!"
#define SIMPLE_VM_ERROR_EXTRAPARAMETERSCOUNT "Error (R20) : Calling function with extra number of parameters!"
#define SIMPLE_VM_ERROR_BADVALUES "Error (R21) : Using operator with values of incorrect type"
#define SIMPLE_VM_ERROR_LOOPWITHOUTLOOP "Error (R22) : Using loop command outside loops "
#define SIMPLE_VM_ERROR_LOOPNUMBEROUTSIDERANGE "Error (R23) : Using loop command with number outside the range "
#define SIMPLE_VM_ERROR_USINGNULLVARIABLE "RUNTIME ERROR 24 : Using uninitialized variable "
#define SIMPLE_VM_ERROR_PACKAGENOTFOUND "Error (R25) : Error in package name, Package not found! "
#define SIMPLE_VM_ERROR_CALLINGPRIVATEMETHOD "Error (R26) : Calling private method from outside the class "
#define SIMPLE_VM_ERROR_USINGPRIVATEATTRIBUTE "Error (R27) : Using private attribute from outside the class "
#define SIMPLE_VM_ERROR_FORSTEPDATATYPE "Error (R28) : Using bad data type as step value"
#define SIMPLE_VM_ERROR_FORLOOPDATATYPE "Error (R29) : Using bad data type in for loop"
#define SIMPLE_VM_ERROR_PARENTCLASSLIKESUBCLASS "Error (R30) : parent class name is identical to child class name "
#define SIMPLE_VM_ERROR_TRYINGTOMODIFYTHESELFPOINTER "Error (R31) : Trying to destory the object using the self reference "
#define SIMPLE_VM_ERROR_BADCALLPARA "Error (R32) : The CALL command expect a variable contains string!"
#define SIMPLE_VM_ERROR_BADDECIMALNUMBER "Error (R33) : Bad decimals number (correct range >= 0 and <=14) !"
#define SIMPLE_VM_ERROR_ASSIGNNOTVARIABLE "Error (R34) : Variable is required for the assignment operation"
#define SIMPLE_VM_ERROR_CANTOPENFILE "Error (R35) : Can't create/open the file!"
#define SIMPLE_VM_ERROR_BADCOLUMNNUMBER "Error (R36) : The column number is not correct! It's greater than the number of columns in the list"
#define SIMPLE_VM_ERROR_BADCOMMAND "Error (R37) : Sorry, The command is not supported in this context"
#define SIMPLE_VM_ERROR_LIBLOADERROR "Error (R38) : Runtime Error in loading the dynamic library!"
#define SIMPLE_VM_ERROR_TEMPFILENAME "Error (R39) : Error occurred creating unique filename."
/* Extra Size (for codeExecution) */
#define SIMPLE_VM_EXTRASIZE 2
/* Variables Location */
#define SIMPLE_VM_STATICVAR_THIS 12
#endif
