#include "mfc.h"
#include <iostream>
using namespace std;
MyApp app;

BEGIN_MESSAGE_MAP(MyFrame,CFrameWnd)
	ON_WM_PAINT( )
END_MESSAGE_MAP()

BOOL MyApp::InitInstance()
{
	MyFrame *frame = new MyFrame;
	frame->ShowWindow(SW_NORMAL);
	frame->UpdateWindow();

	m_pMainWnd = frame;
	return TRUE;
}

MyFrame::MyFrame()
{
	Create(NULL,TEXT("MFC Window"));
}

void MyFrame::OnPaint()
{
	

	CPaintDC dc(this);

	// 字符集相关代码
	// TEXT 自适应编码转换
	// TCHAR 自适应编码转换
//	MessageBox(L"Hello world");

	// 统计字符长度
	char *p0 = "aaa";
	int num = strlen(p0);

	// 宽字节长度统计
	wchar_t *pp00 = L"bbbbbb";
	num = wcslen(pp00);

	// CString char* String之间转换 char*是桥梁
	// 1.CString->char *
	CString str = L"1.CString->char *";  
	wchar_t *pWChar = str.GetBuffer(); //获取str的宽字符用数组保存  
	str.ReleaseBuffer();  

	int nLen = str.GetLength(); //获取str的字符数  
	char *pChar = new char[nLen * 2 + 1];   
	memset(pChar, 0, nLen * 2 + 1);  
	int rtnVal = (int)wcstombs(pChar, pWChar, nLen * 2 + 1); //宽字符转换为多字节字符  
	dc.TextOutW( 100, 100, pChar);

	// 2.char *->string
	char *ch002 = "2.char *->string";
	std::string str002 = std::string(ch002);
	dc.TextOutW( 400, 100, str002.c_str());

	// 3.string->char *
	std::string str003 = "3.string->char *";
	char *ch003 = new char[100];
	memset(ch003, 0, 100);
	strcpy(ch003, str003.c_str());
	dc.TextOutW( 700, 100, ch003);

	// 4.char *->CString
	char  *ch004 = "4.char *->CString";
	CString cstr004 = CString(ch004);
	dc.TextOutW( 100, 300, cstr004);

	// 5.string->CString
	std::string str005="5.string->CString";
	CString cstr005(str005.c_str());//或者CString cstr(str.data());初始化时才行
	dc.TextOutW( 400, 300, cstr005);

	// 6.CString->string
	CString cstr006 = L"6.CString->char *";  
	wchar_t *wch006 = cstr006.GetBuffer(); //获取str的宽字符用数组保存  
	cstr006.ReleaseBuffer();  

	int nLen006 = cstr006.GetLength(); //获取str的字符数  
	char *ch006 = new char[nLen006 * 2 + 1];   
	memset(ch006, 0, nLen006 * 2 + 1);  
	int rtnVal006 = (int)wcstombs(ch006, wch006, nLen006 * 2 + 1); //宽字符转换为多字节字符

	std::string str006 = std::string(ch006);
	
	dc.TextOutW( 700, 300, str006.c_str());
}

