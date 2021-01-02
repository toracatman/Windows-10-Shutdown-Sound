// MyApplicationTrayWnd.cpp : �����t�@�C��
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

	// SetForgroundWindow��PostMessage���K�v�ȗ��R�́A
	// Knowledge Base (Q135788)�Q�Ƃ̂���
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

	// SetForgroundWindow��PostMessage���K�v�ȗ��R�́A
	// Knowledge Base (Q135788)�Q�Ƃ̂���
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



// CMyApplicationTrayWnd ���b�Z�[�W �n���h��

void CMyApplicationTrayWnd::OnAppExit()
{
	// TODO: �����ɃR�}���h �n���h�� �R�[�h��ǉ����܂��B
	PostMessage( WM_CLOSE );
}

void CMyApplicationTrayWnd::OnAppAbout()
{
	// TODO: �����ɃR�}���h �n���h�� �R�[�h��ǉ����܂��B
	CAboutDlg dlg;
	dlg.DoModal();
}

int CMyApplicationTrayWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTrayWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �����ɓ���ȍ쐬�R�[�h��ǉ����Ă��������B
	m_hIcon_main = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	NotifyIcon( NIM_ADD, m_hIcon_main, _T("Windows 10 Shutdown Sound") );

	return 0;
}

void CMyApplicationTrayWnd::OnDestroy()
{
	CTrayWnd::OnDestroy();

	// TODO: �����Ƀ��b�Z�[�W �n���h�� �R�[�h��ǉ����܂��B
	NotifyIcon( NIM_DELETE, NULL );	
}
