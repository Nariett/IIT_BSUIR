//------------------------------------------------------
//	����:		BMPVIEW.H
//	��������:	������������� ������ � ��������
//------------------------------------------------------


#define TIMER_ID	1
#define TIMER_RATE	500

const wchar_t* szClassName = L"BMP_Window";
const wchar_t* szAppName = L"BMP Application";

// ����������� ��������� Windows
BOOL BMP_OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
void BMP_OnDestroy(HWND hwnd);
void BMP_OnTimer(HWND hwnd, UINT id);
void BMP_OnKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags);
void BMP_OnIdle(HWND hwnd);

//������� ���������
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//��������������� �������
BOOL LoadBMP(HDC hdc, LPCTSTR szFileName);
void ShowText(void);
