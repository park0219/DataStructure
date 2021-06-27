// 헤더파일은 사용할 프로그램의 "선언" 해야하는 요소를
// 전부 작성해두는 파일입니다.
// 초기화나 정의 관련된 내용은 "소스파일"에서, 실행관련
// 내용은 "메인파일" 에서 담당하기 때문에 소스코드를
// 관리하기 편해집니다.
// 헤더파일은 먼저 #ifndef와 #define을 상단에 정의해야
// 사용할 수 있습니다.
// #ifndef __파일명_H__ 작성, #define에도 동일하게 작성합니다.
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
//////////////////////////////////////////////////////////////
#include "Point.h"   //Point.h 내부의 구조체를 타겟자료로 삼으므로
//////////////////////////////////////////////////////////////
#define   TRUE   1
#define   FALSE   0

/*** ArrayList의 정의 ***/
#define   LIST_LEN   100
typedef int LData;///////////////////////
//typedef Point * LData;   //LData를 Point 자료형으로 변경
//////////////////////////////////////////
typedef struct __ArrayList {
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;

/*** ArrayList와 관련된 연산들 ***/
typedef ArrayList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);
//마지막줄에는 #endif를 작성하며 #ifndef와 짝을 이룬다,
#endif
//ArrayList.h