#pragma once
#ifndef CS2ASSIST_GAME_SYSTEM_MGR_H
#define CS2ASSIST_GAME_SYSTEM_MGR_H

#include <string>
#include <vector>
#include <Windows.h>
namespace CS2Assist {

    // 游戏状态枚举
    enum class GameState {
        InGame,     // 游戏中
        Loading,    // 加载中
        Lobby,      // 大厅中
        Unknown     // 未知状态
    };

    // 烟雾弹实体（基础属性）
    struct SmokeEntity {
        float x, y, z;  // 位置坐标
        float duration; // 持续时间（秒）
    };

    // 闪光弹实体（基础属性）
    struct FlashEntity {
        float x, y, z;  // 位置坐标
        float explodeTime; // 爆炸时间（秒）
    };

    // 枪支实体（基础属性）
    struct WeaponEntity {
        std::string type; // 枪支类型（如 "AK47"）
        int ammo;         // 弹药数量
    };

    class GameSystemMgr {
    public:
        GameSystemMgr(HANDLE processHandle, HMODULE clientModule);
        ~GameSystemMgr();

        // 获取游戏灵敏度
        float GetSensitivity() const;
        // 获取屏幕宽度
        int GetScreenWidth() const;
        // 获取屏幕高度
        int GetScreenHeight() const;
        // 获取游戏状态
        GameState GetGameState() const;
        // 获取对局比分（队伍1得分, 队伍2得分）
        std::pair<int, int> GetScore() const;
        // 获取游戏地图名
        std::string GetMapName() const;

        // 获取烟雾弹列表
        std::vector<SmokeEntity> GetSmokeEntities() const;
        // 获取闪光弹列表
        std::vector<FlashEntity> GetFlashEntities() const;
        // 获取枪支列表
        std::vector<WeaponEntity> GetWeaponEntities() const;

        // 更新游戏系统数据
        void Update();

    private:
        HANDLE hProcess;            // 进程句柄
        uint64_t ClientModuleAddress; // 客户端模块基址
        // 可根据需要添加其他成员变量
    };

} // namespace CS2Assist

#endif // CS2ASSIST_GAME_SYSTEM_MGR_H