Route2_ViridianForest_NorthEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_DexNavOn
	.byte 0

ViridianForest_DexNavOn::
	setflag FLAG_SYS_DEXNAV_GET
	end

Route2_ViridianForest_NorthEntrance_EventScript_Youngster::
	msgbox Route2_ViridianForest_NorthEntrance_Text_ManyMonsOnlyInForests, MSGBOX_NPC
	end

Route2_ViridianForest_NorthEntrance_EventScript_OldMan::
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCutSkinnyTrees, MSGBOX_NPC
	end

Route2_ViridianForest_NorthEntrance_EventScript_CooltrainerF::
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCancelEvolution, MSGBOX_NPC
	end
