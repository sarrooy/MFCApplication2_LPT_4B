
// MFCApplication2_LPT_4BDlg.h: archivo de encabezado
//

#pragma once


// Cuadro de diálogo de CMFCApplication2LPT4BDlg
class CMFCApplication2LPT4BDlg : public CDialogEx
{
// Construcción
public:
	CMFCApplication2LPT4BDlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_LPT_4B_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOnButton();
	afx_msg void OnBnClickedOffButton();
	afx_msg void OnBnClickedSendButton();
	short m_data;
	short m_read;
	afx_msg void OnBnClickedReadButton();
	short m_PortAddress;
	short m_address;
};
