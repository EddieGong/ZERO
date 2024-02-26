
#include "WindowsPlatformIncludes.h"
import std;
#include "DEMO.h"

using namespace ZERO;

namespace
{
    std::unique_ptr<DEMO> gDEMO;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR lpCmdLine, _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    gDEMO = std::make_unique<DEMO>();

    const wchar_t CLASS_NAME[] = L"ZERO DEMO Window";

    WNDCLASSEXW wcex = { };
    wcex.cbSize        = sizeof(WNDCLASSEX);
    wcex.style         = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc   = WndProc;
    wcex.hInstance     = hInstance;
    wcex.lpszClassName = CLASS_NAME;
    wcex.hIcon         = LoadIconW(hInstance, L"IDI_ICON");
    wcex.hCursor       = LoadCursorW(nullptr, IDC_ARROW);
    wcex.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);

    if (!RegisterClassEx(&wcex))
        return 1;

    RECT rc = { 0, 0, static_cast<LONG>(DEMO::DefualtConfig::width), static_cast<LONG>(DEMO::DefualtConfig::height) };
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);


    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"ZERO DEMO",                   // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        CW_USEDEFAULT, CW_USEDEFAULT,   // Size and position
        rc.right  - rc.left, 
        rc.bottom - rc.top,

        nullptr,                        // Parent window    
        nullptr,                        // Menu
        hInstance,                      // Instance handle
        gDEMO.get()                     // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = { };
    while (WM_QUIT != msg.message)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            // Run DEMO code
        }
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    DEMO* demo = reinterpret_cast<DEMO*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));\

    std::ignore = demo;

    switch (message)
    {
    case WM_CREATE:
        if (lParam)
        {
            auto params = reinterpret_cast<LPCREATESTRUCTW>(lParam);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(params->lpCreateParams));
        }
        break;

    case WM_SIZE:
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            std::ignore = BeginPaint(hwnd, &ps);
            EndPaint(hwnd, &ps);
        }
        break;
    }

    // DefWindowProc handles all other messages including WM_CLOSE
    return DefWindowProc(hwnd, message, wParam, lParam);
}