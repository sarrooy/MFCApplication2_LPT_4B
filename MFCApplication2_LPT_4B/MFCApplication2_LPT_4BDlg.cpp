
// MFCApplication2_LPT_4BDlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication2_LPT_4B.h"
#include "MFCApplication2_LPT_4BDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CMFCApplication2LPT4BDlg



CMFCApplication2LPT4BDlg::CMFCApplication2LPT4BDlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_LPT_4B_DIALOG, pParent)
	, m_data(0)
	, m_read(0)
	, m_PortAddress(0)
	, m_address(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2LPT4BDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DATA_EDIT, m_data);
	DDX_Text(pDX, IDC_READ_STATIC, m_read);
	DDX_Text(pDX, IDC_PORT_ADRS_EDIT, m_PortAddress);
	DDX_Text(pDX, IDC_EDIT3, m_address);
}

BEGIN_MESSAGE_MAP(CMFCApplication2LPT4BDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ON_BUTTON, &CMFCApplication2LPT4BDlg::OnBnClickedOnButton)
	ON_BN_CLICKED(IDC_OFF_BUTTON, &CMFCApplication2LPT4BDlg::OnBnClickedOffButton)
	ON_BN_CLICKED(IDC_SEND_BUTTON, &CMFCApplication2LPT4BDlg::OnBnClickedSendButton)
	ON_BN_CLICKED(IDC_READ_BUTTON, &CMFCApplication2LPT4BDlg::OnBnClickedReadButton)
END_MESSAGE_MAP()


// Controladores de mensajes de CMFCApplication2LPT4BDlg

BOOL CMFCApplication2LPT4BDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional

	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CMFCApplication2LPT4BDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CMFCApplication2LPT4BDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CMFCApplication2LPT4BDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/* declaracion de funciones prototipo
*/
void _stdcall Out32(short direccion_De_Puerto, short Dato);
short _stdcall Inp32(short direccion_de_puerto);

void CMFCApplication2LPT4BDlg::OnBnClickedOnButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	Out32(0x300, 0xff);
}


void CMFCApplication2LPT4BDlg::OnBnClickedOffButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	Out32(0x300, 0x00);
}


void CMFCApplication2LPT4BDlg::OnBnClickedSendButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	Out32(m_address, m_data);
}


void CMFCApplication2LPT4BDlg::OnBnClickedReadButton()
{
	// TODO: Agregue aquí su código de controlador de notificación de control
	UpdateData(TRUE);
	m_read = Inp32(m_PortAddress);
	UpdateData(FALSE);
}
