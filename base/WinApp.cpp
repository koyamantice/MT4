#include "WinApp.h"
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WinApp::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{

	if (ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam)) {
		return 1;
	}

	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wparam, lparam);
}


void WinApp::Initialize() {

	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;//�E�B���h�E�v���V�[�W����ݒ�
	w.lpszClassName = L"DirectXGame";//�E�B���h�E�N���X��
	w.hInstance = GetModuleHandle(nullptr);//�E�B���h�E�n���h��
	w.hCursor = LoadCursor(NULL, IDC_ARROW);//�J�[�\���w��

	//�E�B���h�E�N���X��OS�ɓo�^
	RegisterClassEx(&w);
	//�E�B���h�E�T�C�Y{X���W Y���W�@�����@�c��}
	RECT wrc = { 0,0,window_width,window_height };
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);//�����ŃT�C�Y�␳

	//�E�B���h�E�I�u�W�F�N�g�̐���
	/*HWND*/ hwnd = CreateWindow(w.lpszClassName,//�N���X��
		L"LE2B_13_�R���}�J�C�g",//�^�C�g���o�[�̕���
		WS_OVERLAPPED | WS_SYSMENU,//�W���I�ȃE�B���h�E�X�^�C��
		//WS_OVERLAPPEDWINDOW,//��Œ�ȃE�B���h�E�X�^�C��
		CW_USEDEFAULT,//�\��X���W(OS�ɔC����)
		CW_USEDEFAULT,//�\��Y���W(OS�ɔC����)
		(wrc.right - wrc.left),//�E�B���h�E����
		(wrc.bottom - wrc.top),//�E�B���h�E�c��
		nullptr,//�e�E�B���h�E�n���h��
		nullptr,//���j���[�n���h��
		w.hInstance,//�Ăяo���A�v���P�[�V�����n���h��
		nullptr);//�I�v�V����

	//SetWinCenter();//�E�B���h�E��^�񒆂Ɏ����Ă���
	ShowWindow(hwnd, SW_SHOW);
}

void WinApp::Update() {
}

bool WinApp::ProcessMessage() {

	MSG msg{};//���b�Z�[�W
			//���b�Z�[�W������?
	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);//�L�[���̓��b�Z�[�W�̏���
		DispatchMessage(&msg);//�v���V�[�W���Ƀ��b�Z�[�W�𑗂�
	}
	//x�{�^���ŏI�����b�Z�[�W��������Q�[�����[�v�𔲂���
	if (msg.message == WM_QUIT) {
		return true;
	}

	return false;
}

void WinApp::Finalize() {
	UnregisterClass(w.lpszClassName, w.hInstance);

}
int  WinApp::SetWinCenter() {
	HWND hDeskWnd;
	RECT deskrc, rc;
	int x, y;

	hDeskWnd = GetDesktopWindow();
	GetWindowRect(hDeskWnd, (LPRECT)&deskrc);
	GetWindowRect(hwnd, (LPRECT)&rc);
	x = (deskrc.right - (rc.right - rc.left)) / 2;
	y = (deskrc.bottom - (rc.bottom - rc.top)) / 2;
	SetWindowPos(hwnd, HWND_TOPMOST, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_SHOWWINDOW);
	return 0;
}