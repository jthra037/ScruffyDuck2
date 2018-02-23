#include "Engine.h"
#include <cassert>
#include <Windows.h>
#include <direct.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <stdexcept>

bool IsOnlyInstance(LPCTSTR gameTitle);
bool CheckStorage(const DWORDLONG diskSpaceNeeded);
bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
std::string ReadArchitectureType();

Engine::GameState Engine::_gameState = Engine::Playing;
ObjectManager* Engine::_objectManager;
sf::RenderWindow* Engine::_mainWindow;

void Engine::Start()
{
	if (_gameState == Uninitialized)
		return;

	_gameState = Engine::Playing;
	_objectManager = new ObjectManager();

	Object* obj0 = new Object();
	Object* obj1 = new Object();
	Object* obj2 = new Object(obj1);

	printf("Obj0 address: %p \n", obj0);
	printf("Obj1 address: %p \n", obj1);
	printf("Obj2 address: %p \n", obj2);
	printf("Obj2 parent's address: %p \n", obj2->GetParent());
	printf("Obj1 child's address: %p \n", obj1->GetChildren()->front());


	//Component* comp1 = new Component();
	//obj1->AttachComponent(comp1);
	//obj1->AttachComponent(new Component());
	//obj2->AttachComponent(new Component());

	_objectManager->AddObject(obj0);
	_objectManager->AddObject(obj1);
	_objectManager->AddObject(obj2);
	_objectManager->AddObject(new Object(new Object()));

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow->close();
}

void Engine::Initialize()
{
	_mainWindow = new sf::RenderWindow();
	_mainWindow->create(sf::VideoMode(1024, 768, 32), "Galaga");
	sf::Texture splashTex;
	if (splashTex.loadFromFile("Assets/Textures/splash.png"))
	{
		sf::Sprite splash;
		splash.setTexture(splashTex);

		_mainWindow->clear();
		_mainWindow->draw(splash);
		_mainWindow->display();
	}
	else
	{
		std::cout << "Failed to load splash screen." << std::endl << std::endl;
	}

	std::cout << "Is this the only instance of the game?" << std::endl;
	if (IsOnlyInstance("Galaga"))
	{
		std::cout << "... Yes. Proceed." << std::endl;
	}
	else
	{
		std::cout << "It is not. Do not proceed." << std::endl;
		return;
	}

	std::cout << std::endl << "Checking storage..." << std::endl;
	if (CheckStorage(300000000))		//300mb
	{
		std::cout << "... Storage is sufficient." << std::endl;
	}
	else
	{
		return;
	}

	std::cout << std::endl << "Checking Memory..." << std::endl;
	if (CheckMemory(8000000000, 4000000000))	//8gb, 4gb
	{
		std::cout << "... Memory is sufficient." << std::endl;
	}
	else
	{
		return;
	}

	std::cout << std::endl << "CPU Speed: " << ReadArchitectureType() << std::endl << std::endl;

	_gameState = Engine::Playing;
	Engine::Start();
}

bool Engine::IsExiting()
{
	return _gameState == GameState::Exiting;
}

void Engine::GameLoop()
{
	sf::Event event;
	while (_mainWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_gameState = GameState::Exiting;
		}
	}

	_objectManager->Update();
	_mainWindow->clear();
	_mainWindow->display();
}

#pragma region Initialization Functions

bool IsOnlyInstance(LPCTSTR gameTitle)
{
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS)
	{
		HWND hWnd = FindWindow(gameTitle, NULL);
		/*
		if (hWnd)
		{
		// An instance of your game is already running.
		ShowWindow(hWnd, SW_SHOWNORMAL);
		SetFocus(hWnd);
		SetForegroundWindow(hWnd);
		SetActiveWindow(hWnd);
		return false;
		}
		*/
		return false;
	}
	return true;
}

bool CheckStorage(const DWORDLONG diskSpaceNeeded)
{
	//Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters = diskSpaceNeeded /
		(diskfree.sectors_per_cluster*diskfree.bytes_per_sector);
	if (diskfree.avail_clusters < neededClusters)
	{
		//If you get here you don’t have enough disk space!
		std::cout << ("CheckStorage Failure : Not enough physical storage.") << std::endl;
		return false;
	}
	return true;
}

bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded)
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);

	std::cout << std::setprecision(4);
	std::cout << "... Total physical memory: " << (status.ullTotalPhys / 1000000000.0f) << " GB." << std::endl;
	std::cout << "... Available physical memory: " << status.ullAvailPhys / 1000000000.0f << " GB." << std::endl;
	if (status.ullTotalPhys < physicalRAMNeeded)
	{
		//You don’t have enough physical memory. Tell the player to go get a real computer and give this one to his mother.
		std::cout << ("CheckMemory Failure : Not enough physical memory.") << std::endl;
		return false;
	}

	//Check for enough free memory.
	std::cout << "... Total virtual memory: " << status.ullTotalVirtual / 1000000000.0f << " GB." << std::endl;
	std::cout << "... Available virtual memory: " << status.ullAvailVirtual / 1000000000.0f << " GB." << std::endl;
	if (status.ullAvailVirtual < virtualRAMNeeded)
	{
		//You don’t have enough virtual memory available. Tell the player to shut down the copy of Visual Studio running in the background.
		std::cout << ("CheckMemory Failure : Not enough virtual memory.") << std::endl;
		return false;
	}

	char *buff = new char[virtualRAMNeeded];
	if (buff)
		delete[] buff;
	else
	{
		//Even though there is enough memory, it isn’t available in one block, which can be critical for games that manage their own memory.
		std::cout << ("CheckMemory Failure : Not enough contiguousmemory.") << std::endl;
		return false;
	}
}

std::string ReadArchitectureType()
{
	DWORD BufSize = 1024;
	DWORD type = REG_SZ;
	HKEY hKey;
	char procname[1024];
	//Open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);
	if (lError == ERROR_SUCCESS)
	{
		//Query the key:
		RegQueryValueEx(hKey, "ProcessorNameString", NULL, NULL, (LPBYTE)&procname, &BufSize);
	}

	return std::string(procname);
}

#pragma endregion
