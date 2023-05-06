#pragma once
#include "stdafx.h"

namespace handle {
	int Start() {
		std::cout << XorStr("Waiting for CS:GO!") << std::endl;

		while (!FindWindow(NULL, XorStr("Counter-Strike: Global Offensive - Direct3D 9")))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		}

		try {
			pMemoryManage = new MemoryManage(XorStr("csgo.exe"));

		}
		catch (...) {
			std::cout << XorStr("CS:GO not found!") << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			return 0;
		}

		std::cout << XorStr("CS:GO Found!") << std::endl;


		std::cout << XorStr("Waiting for modules!") << std::endl;

		while (!pMemoryManage->GrabModule(XorStr("client.dll")) || !pMemoryManage->GrabModule(XorStr("engine.dll"))) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		}

		std::cout << XorStr("Modules Found") << std::endl;


		for (auto& m : pMemoryManage->GetModules())
		{
			if (!strcmp(m.szModule, XorStr("client.dll")))
			{
				bClient = reinterpret_cast<DWORD>(m.modBaseAddr);
				break;
			}
		}

		for (auto& m : pMemoryManage->GetModules())
		{
			if (!strcmp(m.szModule, XorStr("engine.dll")))
			{
				bEngine = reinterpret_cast<DWORD>(m.modBaseAddr);
				break;
			}
		}
		std::cout << XorStr("SLNKYHOOK started!") << std::endl;
		Beep(1000, 200);
	}

};