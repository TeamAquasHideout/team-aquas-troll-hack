AquaWarpHouse1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AquaHouseNumberOne_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AquaHouseNumberOne_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHouseNumberOne_OnTransition
	.byte 0

AquaHouseNumberOne_OnFrame:
	map_script_2 VAR_TEMP_4, 0, AquaHouseNumberOne_Begin
	map_script_2 VAR_TROLL_HACK_STATE, 4, AquaHouseNumberOne_End
	.2byte 0

AquaHouseNumberOne_OnResume::
	end

AquaHouseNumberOne_OnTransition:
	end

AquaHouseNumberOne_Begin::
	lockall
	setvar VAR_TEMP_4, 1
	goto_if_ne VAR_TROLL_HACK_STATE, 3, EndTheScript
	applymovement 3, AquaHouseOne_Movement2
	waitmovement 0
	msgbox AquaHouseNumberOne_Scroll_Text, MSGBOX_AUTOCLOSE
	releaseall
	end

EndTheScript::
	releaseall
	end

AquaHouseNumberOne_End::
	lockall
	setvar VAR_TROLL_HACK_STATE, 5
	applymovement 3, AquaHouseOne_Movement
	waitmovement 0
	msgbox AquaHouseNumberOne_Scroll_Text2, MSGBOX_AUTOCLOSE
	releaseall
	end

AquaHouseOne_Movement::
	face_down
	step_end

AquaHouseOne_Movement2::
	face_left
	step_end

AquaHouseNumberOne_Scroll_Text:
	.string "Hey, are you here to help?\n"
	.string "Route 116 was blocked off with\l"
	.string "trees, we need to clear it.$"

AquaHouseNumberOne_Scroll_Text2:
	.string "You found an Axe, thats\n"
	.string "perfect.\p"
	.string "First, you should probably \n"
	.string "clear the tree in the Hideout.$"
