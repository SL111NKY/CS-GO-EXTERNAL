#include "stdafx.h"
#include "Offsets.h"
#include "Entity.h"
#include "quickmaths.h"
#include "handle.h"
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
// 2023-02-16 10:15:15.147903900 UTC
// 
//INACTIVE
class skinchanger {
private:
	bool isSkinchanger;
	bool isRunning;
public:
	skinchanger(bool isSkinchanger = false) {
		this->isSkinchanger = isSkinchanger;
	}

	void Start() {
		this->isRunning = true;
		
		while (this->isRunning) {
			//	const bool sollupdaten = Entity::getShouldUpdate(waffe);



			//if (!Entity::getwaffe()){}
			//	if (GetWeaponPaint() = 490) {}

		//	for (int i = 0; i < 3; ++i) {

				//pMemoryManage->WriteN<int>(Entity::getwaffe(i) + hazedumper::netvars::m_iItemIDHigh, -1);
				//uintptr_t CurrentWeaponID = Entity::getWeaponIndex(i) + hazedumper::netvars::m_iItemDefinitionIndex;
				//pMemoryManage->WriteN<uintptr_t>(Entity::getwaffe(i) + hazedumper::netvars::m_nFallbackPaintKit, 490);
				//pMemoryManage->WriteN<uintptr_t>(Entity::getwaffe() + hazedumper::netvars::m_nFallbackPaintKit, 490);
				//pMemoryManage->WriteN<float>(Entity::getwaffe(i) + hazedumper::netvars::m_flFallbackWear, 0.1f);

				//	pMemoryManage->WriteN<int>(Entity::getwaffe() + hazedumper::netvars::m_nFallbackPaintKit, 962);
				//	pMemoryManage->WriteN<int>(Entity::getClientstate() + hazedumper::signatures::clientstate_delta_ticks, -1);
			//	std::cout << XorStr("Paint!") << std::endl;
			//}

		}
	}
};
class rankwinrevealer {

private:
	bool isrankwinrevealer;
	bool isRunning;
public:


	struct TPlayerInfo {
		__int64         unknown;            //0x0000 
		union
		{
			__int64       steamID64;          //0x0008 - SteamID64
			struct
			{
				__int32     xuid_low;
				__int32     xuid_high;
			};
		};
		char            szName[128];        //0x0010 - Player Name
		int             userId;             //0x0090 - Unique Server Identifier
		char            szSteamID[20];      //0x0094 - STEAM_X:Y:Z
		char            pad_0x00A8[0x10];   //0x00A8
		unsigned long   iSteamID;           //0x00B8 - SteamID 
		char            szFriendsName[128];
		bool            fakeplayer;
		bool            ishltv;
		unsigned int    customfiles[4];
		unsigned char   filesdownloaded;
	};
	rankwinrevealer(bool isrankwinrevealer = false) {
		this->isrankwinrevealer = isrankwinrevealer;
	}
	void MouseMove(float x, float y)
	{
		INPUT Input = { 0 };
		Input.type = INPUT_MOUSE;
		Input.mi.dx = (LONG)x;
		Input.mi.dy = (LONG)y;
		Input.mi.dwFlags = MOUSEEVENTF_MOVE;
		SendInput(1, &Input, sizeof(INPUT));
	}
	void Start() {

		this->isRunning = true;
		while (this->isRunning) {

			/*
			for (int i = 0; i <= 32; i++) {
				DWORD clientState = pMemoryManage->ReadN<DWORD>(bEngine + hazedumper::signatures::dwClientState);
				DWORD userInfoTable = pMemoryManage->ReadN<DWORD>(clientState + 0x5240);
				DWORD items = pMemoryManage->ReadN<DWORD>(pMemoryManage->ReadN<DWORD>(userInfoTable + 0x40) + 0xC);
				TPlayerInfo var = pMemoryManage->ReadN<TPlayerInfo>(pMemoryManage->ReadN<DWORD>(items + 0x28 + ((i - 1) * 0x34)));
				std::string s = var.szName;
				std::cout << i << ": " << s << std::endl;
				//return var.szName;

				const char* ranks[] = { "Unranked", "Silver I", "Silver II", "Silver III", "Silver IV", "Silver Elite", "Silver Elite Master", "Gold Nova I", "Gold Nova II", "Gold Nova III", "Gold Nova Elite", "Master Guardian I", "Master Guardian II", "Master Guardian Elite", "Distinguished Master Guardian", "Legendary Eagle", "Legendary Eagle Master", "Supreme Master First Class", "The Global Elite" };
				unsigned a = Entity::getRanks(i);
				if (Entity::getRanks(i) > sizeof(ranks) / sizeof(ranks[0])) {
					//return NULL;
				return ranks;
				}
		*/
			if (GetKeyState(int('Z')) && 0x800) {
		//	SetCursorPos (3, 3);
			HWND window = FindWindow("Valve001", "Counter-Strike: Global Offensive - Direct3D 9");
			if (window)
			{
				RECT rect = { 0 };
				GetWindowRect(window, &rect);

				SetForegroundWindow(window);
				SetActiveWindow(window);
				SetFocus(window);
			//	Sleep(300);
				//SetCursorPos(rect.right - 200, rect.bottom - 200);
				std::cout << XorStr("gefunden") << std::endl;
				//mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 1,3, 0, 0);
				MouseMove(200, 200);

			}
			else {
				std::cout << XorStr("nix") << std::endl;
			}
			}
	}
	}
};





// WriteProcessMemory durch Angle Berechnung XY/ Mouse/ Keyboardevents ersetzen :)
class rcs {
private:
	bool isRCS;
	bool isRunning;

public:
	float flSpeed;

	Vector::Vector3 aimPunch;
	Vector::Vector3 ViewAngle;
	Vector::Vector3 OldAimPunch;
	Vector::Vector3 fixedAngle;

	rcs(bool isRCS = false) {
		this->isRCS = isRCS;
	}
	void Start() {
		this->isRunning = true;
		while (this->isRunning) {

			if (Entity::getShotsFired() > 2) {

				aimPunch = Entity::getAimpunch() *2.f;

				ViewAngle = (Entity::getViewangles() + OldAimPunch) - aimPunch;

				OldAimPunch = aimPunch;

				fixedAngle = quickmaths::ClampIt(ViewAngle);
				fixedAngle = quickmaths::NormalizeIt(fixedAngle);

				if (quickmaths::ClampAngles(fixedAngle)) {
					pMemoryManage->WriteN<Vector::Vector3>(Entity::getClientstate() + hazedumper::signatures::dwClientState_ViewAngles, fixedAngle);
				}

			}
			else {
				OldAimPunch.x = OldAimPunch.y = 0.f;
			}

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}

	}
}; 
class ESP {
private:

public:
	bool isESP;
	bool isRunning;
	struct Color
	{
		constexpr Color(const float r, const float g, const float b, const float a = 1.f) noexcept :
			r(r), g(g), b(b), a(a) { }

		float r, g, b, a;
	};

	ESP(bool isESP = false) {
		this->isESP = isESP;

	}

	void Start() {
		this->isRunning = true;

		while (this->isRunning = true) {
			for (auto i = 1; i <= 64; ++i) {
				Color color = Color{ 1.f, 0.f, 1.f };   //weitere Checks für Teammates, Leben (Anpassung Farbe (Health /100))
				pMemoryManage->Write<Color>(Entity::getGlowObject() + (Entity::getGlowindex(i) * 0x38) + 0x8, color);
				pMemoryManage->Write<bool>(Entity::getGlowObject() + (Entity::getGlowindex(i) * 0x38) + 0x28, true);
				pMemoryManage->Write<bool>(Entity::getGlowObject() + (Entity::getGlowindex(i) * 0x38) + 0x29, false);
			}
		}
	}
	void Stop() {
		this->isRunning = false;
	}
};
class Noflash {
private:


public:
	bool isRunning;
	bool isNoflash;

	Noflash(bool isNoflash = false) {
		this->isNoflash = isNoflash;
	}
	void Start() {
		this->isRunning = true;

		while (this->isRunning) {
			if (Entity::getFlashduration() > 0) {
				//pMemoryManage->Write<int>(Entity::getLocalplayer() + hazedumper::netvars::m_flFlashDuration, 0);
			}
		}


	}
	void Stop() {
		this->isRunning = false;
	}
};
class radar {
private:


public:
	bool isRadar;
	bool isRunning;
	radar(bool isRadar = false) {
		this->isRadar = isRadar;
	}
	void Start() {
		this->isRunning = true;
		while (this->isRunning) {
			if (GetAsyncKeyState((int)XorStr('H'))) {
				for (auto i = 1; i <= 64; ++i) {
					pMemoryManage->Write(Entity::getEntitys(i) + hazedumper::netvars::m_bSpotted, 1); //teamcheck fehlend
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
		}
	}
	void Stop() {
		this->isRunning = false;
	}
};
class TriggerBot {
private:
	bool isTriggerBot = true;
	bool isRunning;
public:
	TriggerBot(bool isTriggerBot = false) {
		this->isTriggerBot = isTriggerBot;
	}

	void Start() {
		this->isRunning = true;

		while (this->isRunning) {
			if (GetAsyncKeyState((int)XorStr('F')) & 0x8000)
			{
				if (Entity::getLocalCrosshair() > 0 && Entity::getLocalCrosshair() <= 64)
				{
					if (Entity::getTeaminLocalCross() != Entity::getMyTeamNum() && !Entity::getDormant(Entity::getLocalCrosshair())) { // if enemy
						pMemoryManage->Write(bClient + hazedumper::signatures::dwForceAttack, 1);
						std::this_thread::sleep_for(std::chrono::milliseconds(1));
						pMemoryManage->Write(bClient + hazedumper::signatures::dwForceAttack, 0);
					}
				}
			}
		}
	}

	void Stop() {
		this->isRunning = false;
	}
};
class aimbot {

private:
	bool isAimbot;

public:
	BOOL SetCursorPos(int X,int Y);
	bool isRunning;
	aimbot(bool isAimbot = false) {
		this->isAimbot = isAimbot;
	}
	constexpr const Vector::Vector3 calcangle(
		const Vector::Vector3& localPosition,
		const Vector::Vector3& enemyPosition,
		const Vector::Vector3& viewAngles) noexcept
	{
		return ((enemyPosition - localPosition).ToAngle() - viewAngles);
	};

	Vector::Vector3 eyepos;
	Vector::Vector3 viewangless;
	Vector::Vector3 aimpunchh;
	Vector::Vector3 bestAngle;

	Vector::Vector3 angle;
	Vector::Vector3 both;
	Vector::Vector3 playerheadpos;

	Vector::Vector3 clampAngles(Vector::Vector3 angle) { //again same as rcs clamp em angles not to get untrusted mid game
		Vector::Vector3 clampedVector = angle;
		if (clampedVector.x > 89.0f && clampedVector.x <= 180.0f) {
			clampedVector.x = 89.0f;
		}
		while (clampedVector.x > 180.f) {
			clampedVector.x -= 360.f;
		}
		while (clampedVector.x < -89.0f) {
			clampedVector.x = -89.0f;
		}
		while (clampedVector.y > 180.f) {
			clampedVector.y -= 360.f;
		}
		while (clampedVector.y < -180.f) {
			clampedVector.y += 360.f;
		}
		return clampedVector;
	}
	bool angle_normalize(Vector::Vector3& angles)
	{
		if (isfinite(angles.x) &&
			isfinite(angles.y) &&
			isfinite(angles.z))
		{
			angles.x = remainder(angles.x, 360.0f);
			angles.y = remainder(angles.y, 360.0f);
			return true;
		}

		return false;
	}

	void Start() {

		this->isRunning = true;
		while (this->isRunning) {
			eyepos = Entity::getmVecOrigin() + Entity::getmVecViewOffset();
			for (auto i = 1; i <= 64; ++i) {

				if (Entity::getEntityTeamNum(i) == Entity::getMyTeamNum()) {
					continue;
				}
				if (Entity::getDormant(i)) {
					continue;
				}
				if (!Entity::getHealth(i)) {
					continue;
				}

				if (Entity::getSpottedByMask(i) && (1 << Entity::getLocalplayerID())) {
					
					playerheadpos = Vector::Vector3{
					pMemoryManage->ReadN<float>(Entity::getBoneMatrix(i) + 0x30 * 8 + 0x0C),
					pMemoryManage->ReadN<float>(Entity::getBoneMatrix(i) + 0x30 * 8 + 0x1C),
					pMemoryManage->ReadN<float>(Entity::getBoneMatrix(i) + 0x30 * 8 + 0x2C)
					};

					angle = calcangle(
						eyepos,
						playerheadpos,
						Entity::getViewangles() // +Entity::getAimpunch() for Spraydown
					);
					bestAngle = clampAngles(angle);
					both = (Entity::getViewangles() + bestAngle);
					
				//	if (!bestAngle.IsZero()) {
						
					if (GetKeyState(VK_RBUTTON) & 0x80) {
						pMemoryManage->WriteN<Vector::Vector3>(Entity::getClientstate() + hazedumper::signatures::dwClientState_ViewAngles, both);
						if (Entity::getHealth(i)) {
						//	if (GetKeyState(int('J')) & 0x80) {
							//	continue;
							//}
							break;
						}
						else 
						{
							continue;
						}
					}
			//		}
					
				};
			};
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
				
	/* another one

	radar_base = mem.read_int(Offsets.game_module + Offsets.dwRadarBase)
		c_hud_radar = mem.read_int(radar_base + 0x74)
		name = mem.read_string(c_hud_radar + 0x300 + (0x174 * (self.id - 1)))
		return name


		and another one
	for (int i = 0; i < maxPlayers; i++) {
		DWORD radarBase;
		ReadProcessMemory(processHandle, (LPCVOID)(clientDll.modBaseAddr + Offsets::signatures::dwRadarBase), &radarBase, sizeof(DWORD), NULL);
		DWORD radarPointer;
		ReadProcessMemory(processHandle, (LPCVOID)(radarBase + 0x6C), &radarPointer, sizeof(DWORD), NULL);
		char name[128];
		ReadProcessMemory(processHandle, (LPCVOID)(radarPointer + ((0x168 * (i + 1)) + 0x180)), &name, sizeof(name), NULL);
	}

	another one
	char GetPlayerName(int i)
{
int RadarBase = RPM<int>(BASE_Client + RadarBaseOffset);
int RadarPtr = RPM<int>(RadarBase + 0x74);
int p = i+1;
char Name[23] = RPM<char>(RadarPtr + p * 0x184 + 0x18);
return Name;
}

another one
class player_info_t
{
private:
	char __pad[0x10];
public:
	char name[32];
};

uintptr_t dwClientState = Memory.Read< uintptr_t >(Engine() + Offsets.m_dwClientState);
uintptr_t UserInfoTable = Memory.Read< uintptr_t >(dwClientState + Offsets.dwClientState_PlayerInfo);
uintptr_t x = Memory.Read< std::uintptr_t >(Memory.Read< uintptr_t >(UserInfoTable + 0x40) + 0xC);
player_info_t p = Memory.Read< player_info_t >(Memory.Read< uintptr_t >(x + 0x28 + 0x34 * i));

printf("\n%s", p.name);



another one

		struct player_info
		{
			__int64         unknown;            //0x0000
			union
			{
				__int64       steamID64;          //0x0008 - SteamID64
				struct
				{
					__int32     xuid_low;
					__int32     xuid_high;
				};
			};
			char            szName[128];        //0x0010 - Player Name
			int             userId;             //0x0090 - Unique Server Identifier
			char            szSteamID[20];      //0x0094 - STEAM_X:Y:Z
			char            pad_0x00A8[0x10];   //0x00A8
			unsigned long   iSteamID;           //0x00B8 - SteamID
			char            szFriendsName[128];
			bool            fakeplayer;
			bool            ishltv;
			unsigned int    customfiles[4];
			unsigned char   filesdownloaded;
		} var;

		//memset(&var, 0, sizeof(var));
		DWORD clientState = Hacks::mem.Read<DWORD>(dwEngine + dwClientState);
		DWORD userInfoTable = Hacks::mem.Read<DWORD>(clientState + dwClientState_PlayerInfo);
		DWORD items = Hacks::mem.Read<DWORD>(Hacks::mem.Read<DWORD>(userInfoTable + 0x40) + 0xC);
				var = Hacks::mem.Read<player_info>(Hacks::mem.Read<DWORD>(items + 0x28 + ((i - 1) * 0x34)));
				std::string name = var.szName*/

}; 
class BHOP {
private:
	bool isBhop;
	bool isRunning;
public:
	BHOP(bool isBhop = false) {
		this->isBhop = isBhop;
	}

	void Start() {
		this->isRunning = true;
		while (this->isRunning) {
			while (GetAsyncKeyState(VK_SPACE))
			{
				/*

								Vector velocity;
								pMemoryManage->Read<Vector>(LocalBase + hazedumper::netvars::m_vecVelocity, velocity);
								BYTE mouseEnable = 0;
								pMemoryManage->Read<BYTE>(bClient + hazedumper::signatures::dwMouseEnable, mouseEnable);
								if (mouseEnable == 72)
									continue;

								if (sqrtf(velocity.x * velocity.x + velocity.y * velocity.y) < 0.1f)
									continue;


								DWORD movetype = 0;
								pMemoryManage->Read<DWORD>(LocalBase + hazedumper::netvars::m_MoveType, movetype);

								if (movetype == 8 || movetype == 9) // MOVETYPE_NOCLIP OR MOVETYPE_LADDER
									continue;
				*/
				if (Entity::getfFlags() & (1 << 0)) // Check for FL_ONGROUND, Enums auflisten in Enums.H
					pMemoryManage->Write(bClient + hazedumper::signatures::dwForceJump, 6); // Will force jump for 1 tick only
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
	void Stop() {
		this->isRunning = false;
	}
};
class menu {
public:
	bool isRunning;
	bool isMenu;
	menu(bool isMenu = false) {
		this->isMenu = isMenu;
	}

	void Start() {
	}

};
	





int main()
{
	title = XorStr("SLNKYHOOK");

	SetConsoleTitleA(title.c_str());

	handle::Start();

	Noflash noflash(true);
	//skinchanger Skinchanger(true);
	radar Radar(true);
	rankwinrevealer Rankwinrevealer(true);
	TriggerBot triggerbot(true);
	rcs RCS(true);
	aimbot Aimbot(true);
	BHOP bHOP(true);
	menu Menu(true);
	ESP esp(true);
	std::thread TRankwinrevealer(&rankwinrevealer::Start, &Rankwinrevealer);
	std::thread tesp(&ESP::Start, &esp);
	//std::thread tskinchanger(&skinchanger::Start, &Skinchanger);
	std::thread taimbot(&aimbot::Start, &Aimbot);
	std::thread tnoflash(&Noflash::Start, &noflash);
	std::thread tRCS(&rcs::Start, &RCS);
	std::thread tradar(&radar::Start, &Radar);
	std::thread tBhop(&BHOP::Start, &bHOP);
	std::thread tTriggerBot(&TriggerBot::Start, &triggerbot);
	std::thread tMENU(&menu::Start, &Menu);


	while (true)
	{
		if (GetAsyncKeyState(VK_DELETE) & 0x8000)
		{
			std::cout << XorStr("Closing SLNKY.exe!") << std::endl;
			Beep(500, 200);

			//	Bhop.Stop();
				//Triggerbot.Stop();


				//tBhop.join();
				//tTriggerBot.join();

			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
			break;
		}

		if (GetAsyncKeyState(VK_OEM_PERIOD) & 1) {
			std::cout << "dot pressed" << std::endl;
		}


		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	return 0;
};