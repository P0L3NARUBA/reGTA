#pragma once

#include "common.h"

// TODO: move some of this into Vehicle.h

enum tComponent
{
	COMPONENT_DEFAULT,
	COMPONENT_WHEEL_FRONT_LEFT,
	COMPONENT_WHEEL_FRONT_RIGHT,
	COMPONENT_WHEEL_REAR_LEFT,
	COMPONENT_WHEEL_REAR_RIGHT,
	COMPONENT_DOOR_BONNET,
	COMPONENT_DOOR_BOOT,
	COMPONENT_DOOR_FRONT_LEFT,
	COMPONENT_DOOR_FRONT_RIGHT,
	COMPONENT_DOOR_REAR_LEFT,
	COMPONENT_DOOR_REAR_RIGHT,
	COMPONENT_PANEL_FRONT_LEFT,
	COMPONENT_PANEL_FRONT_RIGHT,
	COMPONENT_PANEL_REAR_LEFT,
	COMPONENT_PANEL_REAR_RIGHT,
	COMPONENT_PANEL_WINDSCREEN,
	COMPONENT_BUMPER_FRONT,
	COMPONENT_BUMPER_REAR,
};

enum tComponentGroup
{
	COMPGROUP_BUMPER,
	COMPGROUP_WHEEL,
	COMPGROUP_DOOR,
	COMPGROUP_BONNET,
	COMPGROUP_BOOT,
	COMPGROUP_PANEL,
	COMPGROUP_DEFAULT,
};

enum eLights
{
	VEHLIGHT_FRONT_LEFT,
	VEHLIGHT_FRONT_RIGHT,
	VEHLIGHT_REAR_LEFT,
	VEHLIGHT_REAR_RIGHT,
};

enum {
	VEHDOOR_BONNET = 0,
	VEHDOOR_BOOT,
	VEHDOOR_FRONT_LEFT,
	VEHDOOR_FRONT_RIGHT,
	VEHDOOR_REAR_LEFT,
	VEHDOOR_REAR_RIGHT
};

enum {
	VEHPANEL_FRONT_LEFT,
	VEHPANEL_FRONT_RIGHT,
	VEHPANEL_REAR_LEFT,
	VEHPANEL_REAR_RIGHT,
	VEHPANEL_WINDSCREEN,
	VEHBUMPER_FRONT,
	VEHBUMPER_REAR,
};

class CDamageManager
{
public:

	float field_0;
	uint8 m_engineStatus;
	uint8 m_wheelStatus[4];
	uint8 m_doorStatus[6];
	uint32 m_lightStatus;
	uint32 m_panelStatus;
	uint32 field_24;

	void ResetDamageStatus(void);
	void FuckCarCompletely(void);
	bool ApplyDamage(tComponent component, float damage, float unused);
	bool GetComponentGroup(tComponent component, tComponentGroup *componentGroup, uint8 *foo);

	void SetDoorStatus(int32 door, uint32 status);
	int32 GetDoorStatus(int32 door);
	bool ProgressDoorDamage(uint8 door);
	void SetPanelStatus(int32 panel, uint32 status);
	int32 GetPanelStatus(int32 panel);
	bool ProgressPanelDamage(uint8 panel);
	// needed for CReplay
	static int32 GetPanelStatus(uint32 panelstatus, int32 panel) { return ldb(panel*4, 4, panelstatus); }
	void SetLightStatus(eLights light, uint32 status);
	int32 GetLightStatus(eLights light);
	void SetWheelStatus(int32 wheel, uint32 status);
	int32 GetWheelStatus(int32 wheel);
	bool ProgressWheelDamage(uint8 wheel);
	void SetEngineStatus(uint32 status);
	int32 GetEngineStatus(void);
	bool ProgressEngineDamage(void);
};
VALIDATE_SIZE(CDamageManager, 0x1C);
