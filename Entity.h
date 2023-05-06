#include "stdafx.h"
#include "offsets.h"
namespace Entity {

	std::uintptr_t Localplayer;
	std::uintptr_t LocalplayerID;
	std::uintptr_t Entitys;
	std::uintptr_t Clientstate;
	std::uintptr_t BoneMatrix;
	std::uintptr_t PlayerinLocalCross;
	std::uintptr_t TeaminLocalCross;
	std::uintptr_t TeamNum;
	std::uintptr_t InfoTable;
	std::uintptr_t Items;
	std::uint32_t PlayerRessource;
	std::uint32_t EntityAddr;
	std::uint32_t EntityTeamNum;
	std::uint32_t Health;
	std::uint32_t Crosshair;
	std::uint32_t Flashduration;
	std::uint32_t GlowIndex;
	std::uint32_t GlowObject;
	std::uint32_t ShotsFired;
	std::uint32_t myWeapons;
	std::uintptr_t waffe;
	std::uint32_t waffepaint;
	std::uintptr_t iwas;
	std::uint8_t ranks;
	std::uint16_t wins;
	std::uintptr_t asd;
	Vector::Vector3 mVecOrigin;
	Vector::Vector3 mVecViewOffset;
	Vector::Vector3 VecVelocity;
	Vector::Vector3 Viewangles;
	Vector::Vector3 Aimpunch;

	BYTE fFlags;
	bool Dormant;
	bool SpottedByMask;
	uint32_t ShouldUpdate;


	std::uintptr_t getLocalplayer() {
		Localplayer = pMemoryManage->ReadN<std::uintptr_t>(bClient + hazedumper::signatures::dwLocalPlayer);
		return Localplayer;
	}

	BYTE getfFlags() {
		fFlags = pMemoryManage->ReadN<std::uintptr_t>(Entity::getLocalplayer() + hazedumper::netvars::m_fFlags);
		return fFlags;
	}

	std::uintptr_t getMyTeamNum() {
		TeamNum = pMemoryManage->ReadN<std::uintptr_t>(Entity::getLocalplayer() + hazedumper::netvars::m_iTeamNum);
		return TeamNum;
	}

	Vector::Vector3 getmVecOrigin() {
		mVecOrigin = pMemoryManage->ReadN<Vector::Vector3>(Entity::getLocalplayer() + hazedumper::netvars::m_vecOrigin);
		return mVecOrigin;
	}

	Vector::Vector3 getmVecViewOffset() {
		mVecViewOffset = pMemoryManage->ReadN<Vector::Vector3>(Entity::getLocalplayer() + hazedumper::netvars::m_vecViewOffset);
		return mVecViewOffset;
	}

	std::uintptr_t getClientstate() { //AKA Enginepointer
		Clientstate = pMemoryManage->ReadN<std::uintptr_t>(bEngine + hazedumper::signatures::dwClientState);
		return Clientstate;
	}

	std::uintptr_t getLocalplayerID() {
		LocalplayerID = pMemoryManage->ReadN<std::uintptr_t>(Entity::getClientstate() + hazedumper::signatures::dwClientState_GetLocalPlayer);
		return LocalplayerID;
	}

	Vector::Vector3 getViewangles() {
		Viewangles = pMemoryManage->ReadN<Vector::Vector3>(Entity::getClientstate() + hazedumper::signatures::dwClientState_ViewAngles);
		return Viewangles;
	}


	Vector::Vector3 getAimpunch() {
		Aimpunch = pMemoryManage->ReadN<Vector::Vector3>(Entity::getLocalplayer() + hazedumper::netvars::m_aimPunchAngle);
		return Aimpunch;
	}

	std::uintptr_t getEntitys(auto i) {
				Entitys = pMemoryManage->ReadN<std::uintptr_t>(bClient + hazedumper::signatures::dwEntityList + i * 0x10);
				return Entitys;
	}

	std::uint32_t getEntityTeamNum(auto i) {
			EntityTeamNum = pMemoryManage->ReadN<std::uint32_t>(Entity::getEntitys(i) + hazedumper::netvars::m_iTeamNum);
			return EntityTeamNum;
	}

	bool getDormant(auto i) {
		Dormant = pMemoryManage->ReadN<bool>(Entity::getEntitys(i) + hazedumper::signatures::m_bDormant);
		return Dormant;
	}

	std::uint32_t getHealth(auto i) {
		Health = pMemoryManage->ReadN<std::uint32_t>(Entity::getEntitys(i) + hazedumper::netvars::m_iHealth);
		return Health;
	}

	bool getSpottedByMask(auto i) {
		SpottedByMask = pMemoryManage->ReadN<bool>(Entity::getEntitys(i) + hazedumper::netvars::m_bSpottedByMask);
		return SpottedByMask;
	}

	std::uintptr_t getBoneMatrix(auto i) {
		BoneMatrix = pMemoryManage->ReadN<std::uintptr_t>(Entity::getEntitys(i) + hazedumper::netvars::m_dwBoneMatrix);
		return BoneMatrix;
	}

	Vector::Vector3 getVecVelocity() {
		VecVelocity = pMemoryManage->ReadN<Vector::Vector3>(Entity::getLocalplayer() + hazedumper::netvars::m_vecVelocity);
		return VecVelocity;
	}

	std::uintptr_t getLocalCrosshair() {
		Crosshair = pMemoryManage->ReadN<std::uint32_t>(Entity::getLocalplayer() + hazedumper::netvars::m_iCrosshairId);
		return Crosshair;
	}

	std::uintptr_t getPlayerinLocalCross() {
		PlayerinLocalCross = pMemoryManage->ReadN<std::uintptr_t>(bClient + hazedumper::signatures::dwEntityList + (Entity::getLocalCrosshair() - 1) * 0x10);
		return PlayerinLocalCross;
	}

	std::uintptr_t getTeaminLocalCross() {
		TeaminLocalCross = pMemoryManage->ReadN<std::uintptr_t>(Entity::getPlayerinLocalCross() + hazedumper::netvars::m_iTeamNum);
		return TeaminLocalCross;
	}

	std::uint32_t getFlashduration() {
		Flashduration = pMemoryManage->ReadN<std::uint32_t>(Entity::getLocalplayer() + hazedumper::netvars::m_flFlashDuration);
		return Flashduration;
	}

	std::uint32_t getGlowindex(auto i) {
		GlowIndex = pMemoryManage->ReadN<std::uint32_t>(Entity::getEntitys(i) + hazedumper::netvars::m_iGlowIndex);
		return GlowIndex;
	}

	std::uint32_t getGlowObject() {
		GlowObject = pMemoryManage->ReadN<std::uint32_t>(bClient + hazedumper::signatures::dwGlowObjectManager);
		return GlowObject;
	}

	std::uint32_t getShotsFired() {
		ShotsFired = pMemoryManage->ReadN<std::uint32_t>(Entity::getLocalplayer() + hazedumper::netvars::m_iShotsFired);
		return ShotsFired;
	}

	std::uintptr_t getWeaponIndex(auto i) {
		myWeapons = pMemoryManage->ReadN<std::uintptr_t>((Entity::getLocalplayer() + hazedumper::netvars::m_hMyWeapons + i * 0x4) & 0xFFFF);
		return myWeapons;
	}

	std::uintptr_t getwaffe(auto i) {
		waffe = pMemoryManage->ReadN<std::uintptr_t>(bClient + hazedumper::signatures::dwEntityList + (Entity::getWeaponIndex(i) - 1) * 0x10);
		return waffe;
	}

	std::uintptr_t getInfoTable() {
		InfoTable = pMemoryManage->ReadN<std::uintptr_t>(Entity::getClientstate() + hazedumper::signatures::dwClientState_PlayerInfo);
		return InfoTable;
	}

	std::uintptr_t getItems() {
		Items = pMemoryManage->ReadN<std::uintptr_t>((Entity::getInfoTable() + 0x40) + 0xC);
		return Items;
	}

	std::uint32_t getPlayerRessource() {
		PlayerRessource = pMemoryManage->ReadN<std::uint32_t>(bClient + hazedumper::signatures::dwPlayerResource);
		return PlayerRessource;
	}

	std::uint32_t getEntityAddr(auto i) {
		EntityAddr = pMemoryManage->ReadN<std::uint32_t>(bClient + hazedumper::signatures::dwEntityList + i * 0x10);
		return EntityAddr;
	}

	std::uint8_t getRanks(auto i) {
		ranks = pMemoryManage->ReadN<std::uint8_t>(Entity::getPlayerRessource() + hazedumper::netvars::m_iCompetitiveRanking + (i * 0x04));
		return ranks;
	}

	std::uint16_t getWins(auto i) {
		wins = pMemoryManage->ReadN<std::uint16_t>(Entity::getPlayerRessource() + hazedumper::netvars::m_iCompetitiveRanking + (i * 0x04));
		return wins;
	}

	std::uintptr_t getasd(auto i) {
		asd = pMemoryManage->ReadN<std::uintptr_t>(Entity::getItems()  + 0x28 + i * 0x34);
		return asd;
	}
}; 