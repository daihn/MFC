#include "mfc.h"

MyApp app;		// 全局变量，有且仅有一个

MyApp::MyApp()
{
	MessageBox(NULL,TEXT("第一个小程序"),TEXT("第一个小程序开始了"),MB_OK);
}

BOOL MyApp::InitInstance()
{
	// 创建窗口
	MyFrame *frame = new MyFrame;

	// 显示窗口
	/************************************************************************/
	/* 原型：  BOOL CWnd::ShowWindow( int nCmdShow );
	/* 返回值：如果窗口原来可见，则返回非零值；如果CWnd原来是隐藏的，则返回0。
	/* 参数：  
nCmdShow 指定了CWnd应如何被显示。它必须是下列值之一： 
			SW_HIDE 隐藏窗口并将活动状态传递给其它窗口。  
			SW_MINIMIZE 最小化窗口并激活系统列表中的顶层窗口。  
			SW_RESTORE 激活并显示窗口。如果窗口是最小化或最大化的，Windows恢复其原来的大小和位置。  
			SW_SHOW 激活窗口并以其当前的大小和位置显示。  
			SW_SHOWMAXIMIZED 激活窗口并显示为最大化窗口。  
			SW_SHOWMINIMIZED 激活窗口并显示为图标。  
			SW_SHOWMINNOACTIVE 将窗口显示为图标。当前活动的窗口将保持活动状态。  
			SW_SHOWNA 按照当前状态显示窗口。当前活动的窗口将保持活动状态。  
			SW_SHOWNOACTIVATE 按窗口最近的大小和位置显示。当前活动的窗口将保持活动状态。  
			SW_SHOWNORMAL 激活并显示窗口。如果窗口是最小化或最大化的，则Windows恢复它原来的大小和位置。  

/*说明：
	这个函数设置窗口的可视状态。
	每个应用程序只应用CWinApp::m_nCmdShow为主窗口调用一次ShowWindow。以后调用ShowWindow应该用上面列出的值来代替CWinApp::m_nCmdShow指定的值。*/
	/************************************************************************/
	frame->ShowWindow(SW_SHOWNA);
	
	/************************************************************************/
	/*原型： void CWnd::UpdateWindow();										*/
	/*参数： bShow 指定拥有的窗口显示或隐藏。									*/
	/*说明： 如果更新区域不为空，则发送一条WM_PAINT消息以更新客户区域。		*/
	/*		 UpdateWindow成员函数直接发送一条WM_PAINT消息，越过应用程序队列。	*/
	/*		 如果更新区域为空，则WM_PAINT不会被发送。							*/
	/************************************************************************/
	frame->UpdateWindow();

	m_pMainWnd = frame;

	return TRUE;
}

// 分界宏
BEGIN_MESSAGE_MAP(MyFrame,CFrameWnd )
	ON_WM_LBUTTONDOWN()	// 鼠标点击
	ON_WM_CHAR()		// 键盘
	ON_WM_PAINT()		// 绘图
END_MESSAGE_MAP()



MyFrame::MyFrame()
{
/************************************************************************/
/*	函数说明：

原型：
	BOOL Create(
	LPCTSTR lpszClassName,
	LPCTSTR lpszWindowName,
	DWORD dwStyle = WS_OVERLAPPEDWINDOW,
	const RECT &rect = rectDefault,
	CWnd* pParentWnd = NULL,
	LPCTSTR lpszMenuName = NULL,
	DWORD dwExStyle = 0,
	CCreateContext* pContext = NULL
	);

返回值：如果初始化成功，则返回非零值，否则为0。

参数： lpszClassName 指向一个用于命名Windows类的以空终止的字符串。
	类名可以是任何以AfxRegisterJWndClass全局函数登记或RegisterClassWindows函数登记的名。
	如果为NULL，使用预定义的缺省CFrameWnd属性。  

	lpszWindowName 指向代表窗口名的以空终止的字符串，用作标题条的文本。  
	dwStyle 指定窗口风格属性。如果想标题条自动显示窗口代表的文档名，则应包含FWS_ADDTOTITLE风格。  
	rect 定义窗口大小和位置。rectDefault值使Windows为一个新窗口指定大小和位置。  
	pParentWnd 指定框架窗口的父窗口，对最高层框架窗口来说应为NULL。  
	lpszMenuName 指定与窗口一起使用的菜单资源名。如果菜单有一个整数ID而不是字符串ID，则使MAKEINTRESOURCE。此参数可为NULL。  
	dwExStyle 指定窗口扩展的风格属性。  
	pContext 指向CCreateContext结构的指针。可为NULL。  

说明：
	分两步构造一个CFrameWnd对象。首先调用构造函数来构造CFrameWnd对象，然后调用Create来构造Windows框架窗口并把它附加给CFrameWnd对象，Create初始化窗口的类名、窗口名，登记它的风格、父窗口和相关菜单的缺省值。
	使用LoadFrame而不用Create来从资源而不是指定其参数加载一个框架窗口。	*/
/************************************************************************/
	Create(NULL, TEXT("MFC"));
}

void MyFrame::OnLButtonDown( UINT, CPoint point)
{
	TCHAR buf[1024];

	wsprintf(buf,TEXT("x == %d, y = %d"), point.x, point.y);
	
	MessageBox(buf);
}

void MyFrame::OnChar(UINT key, UINT,UINT )
{
	CString str;
	str.Format(TEXT("%c键被按下了"),key);

	MessageBox(str);
}

void MyFrame::OnPaint()
{
	CPaintDC dc(this);
	dc.Ellipse(100 + 240,100 + 0,400 + 240,400 + 0);
	dc.TextOutW(230 + 240,250 + 0,TEXT("FUCK"));
}