#include <afxwin.h>

// Ӧ�ó�����
class MyApp:public CWinApp
{
public:
	MyApp();
	// MFC��ں���
	virtual BOOL InitInstance();
};

class MyFrame:public CFrameWnd
{
public:
	MyFrame();		// ���캯��
	DECLARE_MESSAGE_MAP()
	
	afx_msg void OnLButtonDown( UINT, CPoint ); 
	afx_msg void OnChar( UINT, UINT,UINT );
	afx_msg void OnPaint();
};
