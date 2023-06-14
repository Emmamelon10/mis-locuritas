#include <Windows.h>
#include "resource.h" //PROGRAMA DE RECURSOS

BOOL CALLBACK fVentana1(HWND, UINT, WPARAM, LPARAM);   //ESTABLECER LAS PROPIEDADES DE LA VENTANA

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, PSTR cmdLine, int cShow)
{
	HWND hVentana1 = CreateDialog(hInst, MAKEINTRESOURCE(DLG_1), NULL, fVentana1);  //PROGRAMA PARA INCLUIR LA VENTANA Y SUS ATRIBUTOS
	ShowWindow(hVentana1, cShow);

	MSG msg; 							//ESTABLECER UNA VARIABLE PARA ELCOMANDO DEL USUSARIO
	ZeroMemory(&msg, sizeof(MSG));		//LIMPIAR LA MEMORIA POR SI QUEDA BASURA 

	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}


BOOL CALLBACK fVentana1(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) //ESTABLECER EL CUERPO DE LA VENTANA
{
	switch (msg) 
	{
	case WM_COMMAND:
		{
			//HIWORD/*QUE*/   LOWORD/*QUIEN*/
			if(LOWORD(wparam) == BTN_2 && HIWORD(wparam) == BN_CLICKED) //SI LA ORDEN RECIBIDA EN EL BOTON 1 ES "APRETADO"
			{
				MessageBox(NULL,"*Una ventanita aparece amistosamente a tu pantalla* :D","Ventanita :)",MB_OK);
			}
			if(LOWORD(wparam) == BTN_1 && HIWORD(wparam) == BN_CLICKED)
			{
				MessageBox(hwnd,"AHHHHH NOO AHORA ME VOY A MORIR D:","Bruh",MB_OK);
				MessageBox(hwnd,"    x_x *SE MUERE*","*Muerte dramatica*",MB_OK);
				DestroyWindow(hwnd);
			}
		}
		
		break;
	case WM_CLOSE:            //CASO APRIETE LA X, CIERRE LA VENTANA
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:        //CASO CIERRE LA VENTANA, CIERRE EL PROGRAMA
		PostQuitMessage(117);
		break;
	}
	return FALSE;
}
