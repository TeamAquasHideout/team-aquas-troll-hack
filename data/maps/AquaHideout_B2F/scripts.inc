.set LOCALID_MATT, 1
.set LOCALID_SUBMARINE, 4

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AquaHideout_B2F_OnFrame
	.byte 0

AquaHideout_B2F_OnFrame:
	map_script_2 VAR_AQUA_HIDEOUT_B2F_STATE, 0, AquaHideout_B2F_InitiateB2FCutscene
	map_script_2 VAR_TROLL_HACK_STATE, 5, AquaHideout_B2F_FinishTrollOneCutscene
	.2byte 0

AquaHideout_B2F_OnTransition:
	setrespawn HEAL_LOCATION_AQUA_HIDEOUT
	end

AquaHideout_B2F_InitiateB2FCutscene::
	lockall
	setvar VAR_AQUA_HIDEOUT_B2F_STATE, 1
	applymovement 1, ScientistGreetYouMovement
	waitmovement 1
	setobjectxyperm 1, 17, 4
	lockall
	msgbox ScientistGreetYouMovement_Text, MSGBOX_AUTOCLOSE
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, AquaHideout_ScientistGreetYouMovementCameraMove
	waitmovement 0
	msgbox ScientistGreetYouMovement_Text2, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_CAMERA, AquaHideout_ScientistGreetYouMovementCameraMove2
	waitmovement 0
	special RemoveCameraObject
	msgbox ScientistGreetYouMovement_Text3, MSGBOX_AUTOCLOSE
	setflag FLAG_HIDEOUT_B2F_EXPOSITION_SWAP_ONE
	clearflag FLAG_HIDEOUT_B2F_EXPOSITION_SWAP_TWO
	removeobject 1
	addobject 13
	releaseall
	return

ScientistGreetYouMovement_Text:
	.string "Hey, new recruit?\n"
	.string "We need you to help us out$"

ScientistGreetYouMovement_Text2:
	.string "The warps to our mini-bases\n"
	.string "around Hoenn have been sealed off.\l"
	.string "We need help opening them.$"

ScientistGreetYouMovement_Text3:
	.string "You can take a look around, but\n"
	.string "we need you down the first warp\l"
	.string "ASAP to help with the effort.$"

ScientistGreetYouMovement:
	emote_exclamation_mark
	walk_up
	step_end

AquaHideout_ScientistGreetYouMovementCameraMove:
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_ScientistGreetYouMovementCameraMove2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	step_end

AquaHideout_B2F_FinishTrollOneCutscene::
	lockall
	setvar VAR_TROLL_HACK_STATE, 6
	setflag FLAG_FORCE_SAVE
	special SaveGame
	waitstate
	clearflag FLAG_FORCE_SAVE
	releaseall
	end
