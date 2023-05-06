#pragma once
#include "stdafx.h"
class MemoryManage
{
private:
	HANDLE m_hProcess;
	DWORD m_dwProcessId;
	std::vector<MODULEENTRY32> m_Modules;
public:
	bool Attach(const std::string& strProcessName);

	bool GrabModule(const std::string& strModuleName);
	/*
	MemoryManage()
	{
		m_hProcess = INVALID_HANDLE_VALUE;
		m_dwProcessId = 0;
		m_Modules.clear();
	}
	*/
	MemoryManage(const std::string& strProcessName = "csgo.exe")
	{
		m_hProcess = INVALID_HANDLE_VALUE;
		m_dwProcessId = 0;
		m_Modules.clear();
		if (!Attach(strProcessName))
			throw;
	}

	template <class T>
	inline bool Read(std::uintptr_t dwAddress, T& Value)
	{
		return ReadProcessMemory(m_hProcess, reinterpret_cast<LPVOID>(dwAddress), reinterpret_cast<LPVOID>(&Value), sizeof(T), NULL);
	}

	template <class T>
	inline bool Write(std::uintptr_t dwAddress, const T& Value)
	{
		return WriteProcessMemory(m_hProcess, reinterpret_cast<LPVOID>(dwAddress), reinterpret_cast<LPCVOID>(&Value), sizeof(T), NULL);
	}

	template <class T> 
	constexpr const T ReadN(const std::uintptr_t& dwAddress) const noexcept {
			T value = { };
			 ReadProcessMemory(m_hProcess, reinterpret_cast<const void*>(dwAddress), &value, sizeof(T), NULL);
			 return value;
		}

	template <class T>
	constexpr void WriteN(const std::uintptr_t& dwAddress, const T& value) const noexcept {
		WriteProcessMemory(m_hProcess, reinterpret_cast<void*>(dwAddress), &value, sizeof(T), NULL);
	}
		
	 

	// Getters
	HANDLE GetHandle() { return m_hProcess; }
	DWORD GetProcId() { return m_dwProcessId; }
	std::vector<MODULEENTRY32> GetModules() { return m_Modules; }
};