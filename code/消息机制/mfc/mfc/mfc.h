#include <afxwin.h>

// 应用程序类
class MyApp:public CWinApp
{
public:
	MyApp();
	// MFC入口函数
	virtual BOOL InitInstance();
};

class MyFrame:public CFrameWnd
{
public:
	MyFrame();		// 构造函数
	DECLARE_MESSAGE_MAP()
	
	afx_msg void OnLButtonDown( UINT, CPoint ); 
	afx_msg void OnChar( UINT, UINT,UINT );
	afx_msg void OnPaint();
};
