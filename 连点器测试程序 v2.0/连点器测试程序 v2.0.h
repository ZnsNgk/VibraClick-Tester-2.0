
// ���������Գ��� v2.0.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C���������Գ���v20App: 
// �йش����ʵ�֣������ ���������Գ��� v2.0.cpp
//

class C���������Գ���v20App : public CWinApp
{
public:
	C���������Գ���v20App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C���������Գ���v20App theApp;