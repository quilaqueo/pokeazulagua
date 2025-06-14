.set LOCALID_SCIENTIST1, 1
.set LOCALID_OLD_AMBER,  4

PewterCity_Museum_1F_MapScripts::
	.byte 0

PewterCity_Museum_1F_EventScript_Scientist1::
	lock
	faceplayer
	goto_if_eq VAR_FACING, DIR_WEST, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	goto_if_eq VAR_FACING, DIR_SOUTH, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	goto_if_eq VAR_FACING, DIR_NORTH, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox PewterCity_Museum_1F_Text_PleaseEnjoyYourself MSGBOX_NPC
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_EventScript_Scientist1BehindCounter::
	faceplayer
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox PewterCity_Museum_1F_Text_PleaseEnjoyYourself MSGBOX_NPC
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter::
	msgbox PewterCity_Museum_1F_Text_AmberContainsGeneticMatter
	applymovement LOCALID_SCIENTIST1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_Museum_1F_EventScript_ExplainAmber::
	msgbox PewterCity_Museum_1F_Text_AmberIsFossilizedSap
	applymovement LOCALID_SCIENTIST1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTrigger::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	showmoneybox 0, 0
	msgbox PewterCity_Museum_1F_Text_Its50YForChildsTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_TryPayForTicket
	msgbox PewterCity_Museum_1F_Text_ComeAgain
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_EventScript_TryPayForTicket::
	checkmoney 100
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NotEnoughMoney
	closemessage
	call_if_eq VAR_TEMP_1, 0, PewterCity_Museum_1F_EventScript_PlayerApproachCounterLeft
	call_if_eq VAR_TEMP_1, 1, PewterCity_Museum_1F_EventScript_PlayerApproachCounterMid
	call_if_eq VAR_TEMP_1, 2, PewterCity_Museum_1F_EventScript_PlayerApproachCounterRight
	playse SE_SHOP
	removemoney 100
	updatemoneybox
	waitse
	msgbox PewterCity_Museum_1F_Text_Right50YThankYou
	setvar VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F, 1
	hidemoneybox
	releaseall
	end

PewterCity_Museum_1F_EventScript_PlayerApproachCounterLeft::
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterLeft
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_PlayerApproachCounterMid::
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterMid
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_PlayerApproachCounterRight::
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterRight
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_NotEnoughMoney::
	msgbox PewterCity_Museum_1F_Text_DontHaveEnoughMoney
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_Movement_ForcePlayerExit::
	walk_down
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterLeft::
	walk_right
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterMid::
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterRight::
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_Scientist2::
	msgbox PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_OldMan::
	msgbox PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_OldAmberScientist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_AMBER, PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber
	msgbox PewterCity_Museum_1F_Text_WantYouToGetAmberExamined
	checkitemspace ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NoRoomForOldAmber
	setflag FLAG_GOT_OLD_AMBER
	removeobject LOCALID_OLD_AMBER
	giveitem_msg PewterCity_Museum_1F_Text_ReceivedOldAmberFromMan, ITEM_OLD_AMBER, 1, MUS_OBTAIN_KEY_ITEM
	release
	end

PewterCity_Museum_1F_EventScript_NoRoomForOldAmber::
	msgbox PewterCity_Museum_1F_Text_DontHaveSpaceForThis
	release
	end

PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber::
	msgbox PewterCity_Museum_1F_Text_GetOldAmberChecked
	release
	end

PewterCity_Museum_1F_EventScript_OldAmber::
	msgbox PewterCity_Museum_1F_Text_BeautifulPieceOfAmber, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_AerodactylFossil::
	lockall
	setvar VAR_0x8004, SPECIES_AERODACTYL
	setvar VAR_0x8005, 10
	setvar VAR_0x8006, 3
	special OpenMuseumFossilPic
	signmsg
	msgbox PewterCity_Museum_1F_Text_AerodactylFossil
	normalmsg
	waitmessage
	special CloseMuseumFossilPic
	releaseall
	end

PewterCity_Museum_1F_EventScript_KabutopsFossil::
	lockall
	setvar VAR_0x8004, SPECIES_KABUTOPS
	setvar VAR_0x8005, 10
	setvar VAR_0x8006, 3
	special OpenMuseumFossilPic
	msgbox PewterCity_Museum_1F_Text_KabutopsFossil
	special CloseMuseumFossilPic
	releaseall
	end

PewterCity_Museum_1F_EventScript_Montanero::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox PewterCity_Museum_1F_Text_Montanero
	releaseall
	end

@NPC CLASE
PewterCity_Museum_1F_EventScript_NPC01::
	faceplayer
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox PewterCity_Museum_1F_Text_NPC01 MSGBOX_NPC
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_EventScript_NPC02::
	faceplayer
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox PewterCity_Museum_1F_Text_NPC02 MSGBOX_NPC
	applymovement 6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_EventScript_NPC03::
	faceplayer
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox PewterCity_Museum_1F_Text_NPC03 MSGBOX_NPC
	applymovement 12, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_EventScript_NPC04::
	faceplayer
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox PewterCity_Museum_1F_Text_NPC04 MSGBOX_NPC
	applymovement 13, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_EventScript_NPC05::
	faceplayer
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox PewterCity_Museum_1F_Text_NPC05 MSGBOX_NPC
	applymovement 11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

@cientifico npc
PewterCity_Museum_1F_EventScript_NPC06::
	faceplayer
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox PewterCity_Museum_1F_Text_NPC06 MSGBOX_NPC
	applymovement 9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end


PewterCity_Museum_1F_EventScript_Brock::
	setvar VAR_0x408F,2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, PewterCity_Museum_1F_Move_Camara1
	waitmovement 0
	special RemoveCameraObject
	msgbox PewterCity_Museum_1F_Text_Brock1
	applymovement 10, PewterCity_Museum_1F_Move_Brock
	waitmovement 0
	msgbox PewterCity_Museum_1F_Text_Brock2
	applymovement 2, PewterCity_Museum_1F_Move_Publico2
	applymovement 6, PewterCity_Museum_1F_Move_Publico1
	applymovement 11, PewterCity_Museum_1F_Move_Publico1
	applymovement 12, PewterCity_Museum_1F_Move_Publico2
	applymovement 13, PewterCity_Museum_1F_Move_Publico1
	waitmovement 0
	msgbox PewterCity_Museum_1F_Text_Brock3
	applymovement 2, PalletTown_ProfessorOaksLab_Movement_Player8
	applymovement 6, PalletTown_ProfessorOaksLab_Movement_Player8
	applymovement 11, PalletTown_ProfessorOaksLab_Movement_Player8
	applymovement 12, PalletTown_ProfessorOaksLab_Movement_Player8
	applymovement 13, PalletTown_ProfessorOaksLab_Movement_Player8
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, PewterCity_Museum_1F_Move_Camara3
	waitmovement 0
	special RemoveCameraObject
	setflag FLAG_0x0B4 @desaparece brock y publico
	releaseall
	end

PewterCity_Museum_1F_EventScript_BrockNoTeVayas::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	setvar VAR_0x408F,2
	msgbox PewterCity_Museum_1F_Text_BrockNoTeVayas1
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Move_Player1
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_Move_Player1::
	walk_up
	step_end

PewterCity_Museum_1F_Move_Camara1::
	walk_up
	walk_up
	walk_up
	step_end

PewterCity_Museum_1F_Move_Camara3::
	walk_down
	walk_down
	walk_down	
	step_end

PewterCity_Museum_1F_Move_Brock::
	emote_exclamation_mark
	walk_in_place_down
	step_end

PewterCity_Museum_1F_Move_Publico1::
	face_down
	step_end

PewterCity_Museum_1F_Move_Publico2::
	emote_question_mark
	face_down
	step_end

PewterCity_Museum_1F_EventScript_Fosil1::
	lock
	goto_if_set FLAG_0x0B7, PewterCity_Museum_1F_EventScript_BrockFosilFinal2
	setflag FLAG_0x0B5
	special SetSeenMon
	setvar VAR_0x8004, SPECIES_KABUTO
	showmonpic SPECIES_KABUTO, 10, 3
	signmsg
	msgbox PewterCity_Museum_1F_Text_Fosil1
	normalmsg
	waitmessage
	hidemonpic
	goto_if_set FLAG_0x0B6, PewterCity_Museum_1F_EventScript_FosilCheckFosil2
	release
	end

PewterCity_Museum_1F_EventScript_Fosil2::
	lock
	goto_if_set FLAG_0x0B7, PewterCity_Museum_1F_EventScript_BrockFosilFinal1
	setflag FLAG_0x0B6
	special SetSeenMon
	setvar VAR_0x8004, SPECIES_OMANYTE
	showmonpic SPECIES_OMANYTE, 10, 3
	signmsg
	msgbox PewterCity_Museum_1F_Text_Fosil2
	normalmsg
	hidemonpic
	waitmessage
	goto_if_set FLAG_0x0B5, PewterCity_Museum_1F_EventScript_FosilCheckFosil1
	release
	end




PewterCity_Museum_1F_EventScript_FosilCheckFosil2::
	lockall
	goto_if_set FLAG_0x0B5, PewterCity_Museum_1F_EventScript_BrockTerminaFosil1
	releaseall
	end

PewterCity_Museum_1F_EventScript_BrockFosilFinal1::
	lock
	special SetSeenMon
	setvar VAR_0x8004, SPECIES_OMANYTE
	showmonpic SPECIES_OMANYTE, 10, 3
	signmsg
	msgbox PewterCity_Museum_1F_Text_Fosil2
	normalmsg
	hidemonpic
	waitmessage
	release
	end

PewterCity_Museum_1F_EventScript_BrockFosilFinal2::
	lock
	special SetSeenMon
	setvar VAR_0x8004, SPECIES_KABUTO
	showmonpic SPECIES_KABUTO, 10, 3
	signmsg
	msgbox PewterCity_Museum_1F_Text_Fosil2
	normalmsg
	waitmessage
	hidemonpic
	release
	end


PewterCity_Museum_1F_EventScript_FosilCheckFosil1::
	lockall
	goto_if_set FLAG_0x0B6, PewterCity_Museum_1F_EventScript_BrockTerminaFosil2
	releaseall
	end

PewterCity_Museum_1F_EventScript_BrockTerminaFosil1::
	lockall
	setflag FLAG_0x0B7
	normalmsg
	textcolor NPC_TEXT_COLOR_NEUTRAL
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Move_BrockTermina1 
	waitmovement 0

	@MUSICA CLASES

	msgbox PewterCity_Museum_1F_Text_BrockTermina1 MSGBOX_DEFAULT
	waitmessage          
	fadescreen FADE_TO_BLACK
	setobjectxy 2,13,13
	setobjectxy 6,13,13
	setobjectxy 11,13,13
	setobjectxy 12,13,13
	setobjectxy 13,13,13
	fadescreen FADE_FROM_BLACK
	
	@MUSICA DESAFIO

	applymovement 10, PewterCity_Museum_1F_Move_BrockTermina2
	waitmovement 0	
	msgbox PewterCity_Museum_1F_Text_BrockTermina2 MSGBOX_DEFAULT
	waitmessage
	applymovement 10, PewterCity_Museum_1F_Move_BrockTermina3
	waitmovement 0	
	msgbox PewterCity_Museum_1F_Text_BrockTermina3
	waitmessage
	applymovement 10, PewterCity_Museum_1F_Move_BrockTermina4
	waitmovement 0	
	setvar VAR_0x408F,3
	setobjectxy 10,13,13

	@MUSICA MUSEO

	releaseall
	end

PewterCity_Museum_1F_Move_BrockTermina1::
	emote_exclamation_mark
	face_right
	step_end

PewterCity_Museum_1F_Move_BrockTermina1v2::
	emote_exclamation_mark
	face_left
	step_end

PewterCity_Museum_1F_Move_BrockTermina2::
	face_left
	delay_16
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_Museum_1F_Move_BrockTermina2v2::
	face_right
	delay_16
	delay_16
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_Museum_1F_Move_BrockTermina3::
	face_right
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	step_end

PewterCity_Museum_1F_Move_BrockTermina3v2::
	face_left
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	step_end

PewterCity_Museum_1F_Move_BrockTermina4::
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PewterCity_Museum_1F_Move_BrockTermina4v2::
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PewterCity_Museum_1F_EventScript_BrockTerminaFosil2::
	lockall
	setflag FLAG_0x0B7
	normalmsg
	textcolor NPC_TEXT_COLOR_NEUTRAL
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Move_BrockTermina1v2 
	waitmovement 0

	@MUSICA CLASES

	msgbox PewterCity_Museum_1F_Text_BrockTermina1 MSGBOX_DEFAULT
	waitmessage
	fadescreen FADE_TO_BLACK
	setobjectxy 2,13,13
	setobjectxy 6,13,13
	setobjectxy 11,13,13
	setobjectxy 12,13,13
	setobjectxy 13,13,13
	fadescreen FADE_FROM_BLACK
	
	@MUSICA DESAFIO

	applymovement 10, PewterCity_Museum_1F_Move_BrockTermina2v2
	waitmovement 0	
	msgbox PewterCity_Museum_1F_Text_BrockTermina2 MSGBOX_DEFAULT
	waitmessage
	applymovement 10, PewterCity_Museum_1F_Move_BrockTermina3v2
	waitmovement 0	
	msgbox PewterCity_Museum_1F_Text_BrockTermina3
	waitmessage
	applymovement 10, PewterCity_Museum_1F_Move_BrockTermina4v2
	waitmovement 0	
	setvar VAR_0x408F,3
	setobjectxy 10,13,13

	@MUSICA MUSEO

	releaseall
	end