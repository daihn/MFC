#include "mfc.h"

MyApp app;		// ȫ�ֱ��������ҽ���һ��

MyApp::MyApp()
{
	MessageBox(NULL,TEXT("��һ��С����"),TEXT("��һ��С����ʼ��"),MB_OK);
}

BOOL MyApp::InitInstance()
{
	// ��������
	MyFrame *frame = new MyFrame;

	// ��ʾ����
	/************************************************************************/
	/* ԭ�ͣ�  BOOL CWnd::ShowWindow( int nCmdShow );
	/* ����ֵ���������ԭ���ɼ����򷵻ط���ֵ�����CWndԭ�������صģ��򷵻�0��
	/* ������  
nCmdShow ָ����CWndӦ��α���ʾ��������������ֵ֮һ�� 
			SW_HIDE ���ش��ڲ����״̬���ݸ��������ڡ�  
			SW_MINIMIZE ��С�����ڲ�����ϵͳ�б��еĶ��㴰�ڡ�  
			SW_RESTORE �����ʾ���ڡ������������С������󻯵ģ�Windows�ָ���ԭ���Ĵ�С��λ�á�  
			SW_SHOW ����ڲ����䵱ǰ�Ĵ�С��λ����ʾ��  
			SW_SHOWMAXIMIZED ����ڲ���ʾΪ��󻯴��ڡ�  
			SW_SHOWMINIMIZED ����ڲ���ʾΪͼ�ꡣ  
			SW_SHOWMINNOACTIVE ��������ʾΪͼ�ꡣ��ǰ��Ĵ��ڽ����ֻ״̬��  
			SW_SHOWNA ���յ�ǰ״̬��ʾ���ڡ���ǰ��Ĵ��ڽ����ֻ״̬��  
			SW_SHOWNOACTIVATE ����������Ĵ�С��λ����ʾ����ǰ��Ĵ��ڽ����ֻ״̬��  
			SW_SHOWNORMAL �����ʾ���ڡ������������С������󻯵ģ���Windows�ָ���ԭ���Ĵ�С��λ�á�  

/*˵����
	����������ô��ڵĿ���״̬��
	ÿ��Ӧ�ó���ֻӦ��CWinApp::m_nCmdShowΪ�����ڵ���һ��ShowWindow���Ժ����ShowWindowӦ���������г���ֵ������CWinApp::m_nCmdShowָ����ֵ��*/
	/************************************************************************/
	frame->ShowWindow(SW_SHOWNA);
	
	/************************************************************************/
	/*ԭ�ͣ� void CWnd::UpdateWindow();										*/
	/*������ bShow ָ��ӵ�еĴ�����ʾ�����ء�									*/
	/*˵���� �����������Ϊ�գ�����һ��WM_PAINT��Ϣ�Ը��¿ͻ�����		*/
	/*		 UpdateWindow��Ա����ֱ�ӷ���һ��WM_PAINT��Ϣ��Խ��Ӧ�ó�����С�	*/
	/*		 �����������Ϊ�գ���WM_PAINT���ᱻ���͡�							*/
	/************************************************************************/
	frame->UpdateWindow();

	m_pMainWnd = frame;

	return TRUE;
}

// �ֽ��
BEGIN_MESSAGE_MAP(MyFrame,CFrameWnd )
	ON_WM_LBUTTONDOWN()	// �����
	ON_WM_CHAR()		// ����
	ON_WM_PAINT()		// ��ͼ
END_MESSAGE_MAP()



MyFrame::MyFrame()
{
/************************************************************************/
/*	����˵����

ԭ�ͣ�
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

����ֵ�������ʼ���ɹ����򷵻ط���ֵ������Ϊ0��

������ lpszClassName ָ��һ����������Windows����Կ���ֹ���ַ�����
	�����������κ���AfxRegisterJWndClassȫ�ֺ����Ǽǻ�RegisterClassWindows�����Ǽǵ�����
	���ΪNULL��ʹ��Ԥ�����ȱʡCFrameWnd���ԡ�  

	lpszWindowName ָ������������Կ���ֹ���ַ������������������ı���  
	dwStyle ָ�����ڷ�����ԡ������������Զ���ʾ���ڴ�����ĵ�������Ӧ����FWS_ADDTOTITLE���  
	rect ���崰�ڴ�С��λ�á�rectDefaultֵʹWindowsΪһ���´���ָ����С��λ�á�  
	pParentWnd ָ����ܴ��ڵĸ����ڣ�����߲��ܴ�����˵ӦΪNULL��  
	lpszMenuName ָ���봰��һ��ʹ�õĲ˵���Դ��������˵���һ������ID�������ַ���ID����ʹMAKEINTRESOURCE���˲�����ΪNULL��  
	dwExStyle ָ��������չ�ķ�����ԡ�  
	pContext ָ��CCreateContext�ṹ��ָ�롣��ΪNULL��  

˵����
	����������һ��CFrameWnd�������ȵ��ù��캯��������CFrameWnd����Ȼ�����Create������Windows��ܴ��ڲ��������Ӹ�CFrameWnd����Create��ʼ�����ڵ����������������Ǽ����ķ�񡢸����ں���ز˵���ȱʡֵ��
	ʹ��LoadFrame������Create������Դ������ָ�����������һ����ܴ��ڡ�	*/
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
	str.Format(TEXT("%c����������"),key);

	MessageBox(str);
}

void MyFrame::OnPaint()
{
	CPaintDC dc(this);
	dc.Ellipse(100 + 240,100 + 0,400 + 240,400 + 0);
	dc.TextOutW(230 + 240,250 + 0,TEXT("FUCK"));
}