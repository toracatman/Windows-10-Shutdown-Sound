// MyApplicationTrayWnd.cpp : 実装ファイル
//

#include "stdafx.h"
#include "MyApplication.h"
#include "MyApplicationTrayWnd.h"

#include "AboutDlg.h"

// CMyApplicationTrayWnd

IMPLEMENT_DYNAMIC(CMyApplicationTrayWnd, CTrayWnd)

CMyApplicationTrayWnd::CMyApplicationTrayWnd() :
	m_hIcon_main(NULL)
{

}

CMyApplicationTrayWnd::~CMyApplicationTrayWnd()
{
}

void CMyApplicationTrayWnd::DoLButtonClick()
{
	POINT pt;
	GetCursorPos( &pt );

	CMenu menu;
	menu.LoadMenu( IDM_TRAY_L );

	CMenu*	pPopup = menu.GetSubMenu(0);

	// SetForgroundWindowとPostMessageが必要な理由は、
	// Knowledge Base (Q135788)参照のこと
	SetForegroundWindow();
	pPopup->TrackPopupMenu( TPM_RIGHTBUTTON, pt.x, pt.y, this );
	PostMessage( WM_NULL );
}

void CMyApplicationTrayWnd::DoRButtonClick()
{
	POINT pt;
	GetCursorPos( &pt );

	CMenu menu;
	menu.LoadMenu( IDM_TRAY_R );

	CMenu*	pPopup = menu.GetSubMenu(0);

	// SetForgroundWindowとPostMessageが必要な理由は、
	// Knowledge Base (Q135788)参照のこと
	SetForegroundWindow();
	pPopup->TrackPopupMenu( TPM_RIGHTBUTTON, pt.x, pt.y, this );
	PostMessage( WM_NULL );
}

void CMyApplicationTrayWnd::DoLButtonDoubleClick()
{
	SendMessage( WM_COMMAND, ID_APP_ABOUT );
}

BEGIN_MESSAGE_MAP(CMyApplicationTrayWnd, CTrayWnd)
	ON_COMMAND(ID_APP_EXIT, &CMyApplicationTrayWnd::OnAppExit)
	ON_COMMAND(ID_APP_ABOUT, &CMyApplicationTrayWnd::OnAppAbout)
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()



// CMyApplicationTrayWnd メッセージ ハンドラ

void CMyApplicationTrayWnd::OnAppExit()
{
	// TODO: ここにコマンド ハンドラ コードを追加します。
	PostMessage( WM_CLOSE );
}

void CMyApplicationTrayWnd::OnAppAbout()
{
	// TODO: ここにコマンド ハンドラ コードを追加します。
	CAboutDlg dlg;
	dlg.DoModal();
}

int CMyApplicationTrayWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTrayWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ここに特定な作成コードを追加してください。
	m_hIcon_main = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	NotifyIcon( NIM_ADD, m_hIcon_main, _T("Windows 10 Shutdown Sound") );

	return 0;
}

void CMyApplicationTrayWnd::OnDestroy()
{
	CTrayWnd::OnDestroy();

	// TODO: ここにメッセージ ハンドラ コードを追加します。
	NotifyIcon( NIM_DELETE, NULL );	
}
