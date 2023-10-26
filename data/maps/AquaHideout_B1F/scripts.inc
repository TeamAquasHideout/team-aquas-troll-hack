AquaHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AquaHideout_B1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_OnTransition
	.byte 0

AquaHideout_B1F_OnFrame:
	map_script_2 VAR_TROLL_HACK_STATE, 0, AquaHideout_IntroSequence
	.2byte 0

AquaHideout_B1F_OnResume::
	end

AquaHideout_B1F_OnTransition:
	end


AquaHideout_IntroSequence::
	lockall
	setvar VAR_TROLL_HACK_STATE, 1
	msgbox AquaHideout_IntroSpeech0, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, AquaHideout_IntroPlayerFaceLeft
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, AquaHideout_IntroCameraMove
	waitmovement 0
	msgbox AquaHideout_IntroSpeech1, MSGBOX_DEFAULT
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDEOUT_GRUNTS_SECOND_POSITION
	special RemoveCameraObject
	warpsilent MAP_AQUA_HIDEOUT_B1F, 20, 20
	waitstate
	releaseall
	end

AquaHideout_IntroSpeech0:
	.string "ALL GRUNTS TO THE MAIN FLOOR! STAT!\p"
	.string "THAT MEANS NOW!!!$"

AquaHideout_IntroSpeech1:
	.string "RED ALERT! Team Aqua is under threat.\p"
	.string "We are being attacked on all fronts\n"
	.string "The Trick Room guy has declared war.\l"
	.string "We must DESTROY him… NOW!\p"
	.string "You are dismissed.$"

AquaHideout_IntroPlayerFaceLeft:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	face_left
	step_end

AquaHideout_IntroCameraMove:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end


AquaHideoutExplosionBall::
	msgbox AquaHideout_B1F_Explosion, MSGBOX_DEFAULT
	special DoSoftReset
	release
	end

AquaHideout_B1F_Explosion:
	.string "A little Present from the Trick Room…$"


AquaHideout_BF1_ArchieAtDesk::
	faceplayer
	msgbox AquaHideout_B1F_Text_ArchieAtDesk, MSGBOX_AUTOCLOSE
	release
	end

AquaHideout_B1F_Text_ArchieAtDesk::
	.string "WHAT are you doing standing there?!\n"
	.string "GET OUT! \p"
	.string "And take that Item Ball with you!!!$"


AquaHideout_B1F_EventScript_Grunt2::
	faceplayer
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	release
	end

AquaHideout_B1F_EventScript_Grunt2Defeated::
	faceplayer
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt3::
	faceplayer
	msgbox AquaHideout_B1F_Text_Grunt3Intro, MSGBOX_AUTOCLOSE
	release
	end

AquaHideout_B1F_EventScript_Grunt3Defeated::
	faceplayer
	msgbox AquaHideout_B1F_Text_Grunt3Intro, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt5::
	faceplayer
	msgbox AquaHideout_B1F_Text_Grunt7Intro, MSGBOX_AUTOCLOSE
	release
	end

AquaHideout_B1F_EventScript_Grunt7::
	faceplayer
	msgbox AquaHideout_B1F_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	release
	end


AquaHideout_B1F_Text_Grunt2PostBattle:
	.string "Our HIDEOUT's secret?\p"
	.string "Well, let's just say…\n"
	.string "There's a submarine at the far end!\p"
	.string "But, by now…\n"
	.string "Kekekeke…$"

AquaHideout_B1F_Text_Grunt3Intro:
	.string "Fuel supply loaded A-OK!\n"
	.string "In-cruise snacks loaded A-OK!\p"
	.string "Nothing left to do but KO a pesky\n"
	.string "meddler!$"

AquaHideout_B1F_Text_Grunt7Intro:
	.string "Hey!\n"
	.string "You there!\p"
	.string "Which do you think is cooler?\n"
	.string "TEAM AQUA's uniform or TEAM MAGMA's?$"

AquaHideout_B1F_Text_Grunt7PostBattle::
	.string "If you have a cool uniform, you look\n"
	.string "good even in a loss, don't you think?$"
