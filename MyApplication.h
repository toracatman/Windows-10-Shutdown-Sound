// MyApplication.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CMyApplicationApp:
// このクラスの実装については、MyApplication.cpp を参照してください。
//

class CMyApplicationApp : public CWinApp
{
public:
	CMyApplicationApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMyApplicationApp theApp;