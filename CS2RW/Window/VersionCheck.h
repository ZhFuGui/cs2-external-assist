#pragma once
#include <Windows.h>
#include <fstream>
#include <string>

struct Version {
	std::string VersionDate="Sep 10 2024";
	std::string VersionTime="15:25:31";
}IniVersion;

BOOL VersionCheckFun(std::string GameFile) {
	size_t index = GameFile.find("game");
	std::string InfFile = GameFile.substr(0, index) + "game\\csgo\\steam.inf";
	std::ifstream inputFile(InfFile);
	if (!inputFile.is_open()) {
		MessageBoxA(0,"找不到更新文件，无法确定版本信息。\n避免未知行为损坏磁盘，将结束辅助进程！", "版本警告", 0);
		return FALSE;
	}
	std::string line; 
	BOOL 是否配置节点头 = 0; size_t equals_pos; std::string Key = ""; std::string Value = "";
	while (std::getline(inputFile, line)) {

		equals_pos = line.find('=');

		if (equals_pos != std::string::npos) { Key = line.substr(0, equals_pos); Value = line.substr(equals_pos + 1, line.length());}else { Key = ""; Value = ""; continue; }; if (Key == "" || Value == "") { continue; };

		if (Key == "VersionDate"&& Value!= IniVersion.VersionDate) {
			inputFile.close();
			return FALSE;
		}
		else if (Key == "VersionTime" && Value != IniVersion.VersionTime) {
			inputFile.close();
			return FALSE;
		}
	};
	inputFile.close();
	return TRUE;
}