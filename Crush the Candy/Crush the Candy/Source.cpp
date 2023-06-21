
#include <Windows.h>
#include "resource.h"

LRESULT CALLBACK cases(HWND VENTANA, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CLOSE:            //CASO APRIETE LA X, CIERRE LA VENTANA
		DestroyWindow(VENTANA);
		break;
	case WM_DESTROY:        //CASO CIERRE LA VENTANA, CIERRE EL PROGRAMA
		PostQuitMessage(117);
		break;
	default:
		return DefWindowProc(VENTANA, msg, wparam, lparam);
		break;
	}
	return FALSE;
}

HWND window;
MSG msg;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, PSTR cmdLine, int cShow)
{
	window = CreateDialog(hInst, MAKEINTRESOURCE(Ventana), HWND_DESKTOP, cases);  //PROGRAMA PARA INCLUIR LA VENTANA Y SUS ATRIBUTOS
	ShowWindow(window, cShow);

	MSG msg; 							//ESTABLECER UNA VARIABLE PARA ELCOMANDO DEL USUSARIO
	ZeroMemory(&msg, sizeof(MSG));		//LIMPIAR LA MEMORIA POR SI QUEDA BASURA 

	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
