
// MFCApplication2_LPT_4B.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'pch.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CMFCApplication2LPT4BApp:
// Consulte MFCApplication2_LPT_4B.cpp para obtener información sobre la implementación de esta clase
//

class CMFCApplication2LPT4BApp : public CWinApp
{
public:
	CMFCApplication2LPT4BApp();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication2LPT4BApp theApp;
