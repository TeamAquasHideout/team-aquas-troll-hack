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
	setflag FLAG_SYS_B_DASH
	setflag FLAG_EXPLOSION_BALL_TRIGGERED
	givemon SPECIES_MUDKIP, 30, ITEM_MYSTIC_WATER
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
	goto_if_set FLAG_EXPLOSION_BALL_TRIGGERED, AquaHideout_B1F_BallIfNotPrimed
	msgbox AquaHideout_B1F_Explosion, MSGBOX_AUTOCLOSE
	removeobject 30
	dofieldeffect(FLDEFF_EXPLOSION)
    waitfieldeffect(FLDEFF_EXPLOSION)
	special DoSoftReset
	release
	end

AquaHideout_B1F_Explosion:
	.string "A little Present from the Trick Room…$"

AquaHideout_B1F_BallIfNotPrimed::
	msgbox AquaHideout_B1F_BallIfNotPrimed_Text, MSGBOX_AUTOCLOSE
	release
	end

AquaHideout_B1F_BallIfNotPrimed_Text:
	.string "A plain Pokeball…$"

AquaHideout_BF1_ArchieAtDesk::
	faceplayer
	setflag FLAG_HIDEOUT_BLOCK_EXIT
	msgbox AquaHideout_B1F_Text_ArchieAtDesk, MSGBOX_AUTOCLOSE
	setvar VAR_TROLL_HACK_STATE, 2
	call AquaHideout_BF1_ExplosionBallSparkle
	clearflag FLAG_EXPLOSION_BALL_TRIGGERED
	release
	end

AquaHideout_B1F_Text_ArchieAtDesk::
	.string "WHAT are you doing standing there?!\n"
	.string "GET OUT! \p"
	.string "And take that Item Ball with you!!!$"

AquaHideout_BF1_ExplosionBallSparkle::
	setvar VAR_0x8006, 0
	dofieldeffectsparkle 21, 9, VAR_0x8006
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_TROLL_HACK_STATE, 3
	delay 10
	return


AquaHideout_B1F_EventScript_GruntBlockExit::
	faceplayer
	msgbox AquaHideout_B1F_GruntBlockExit, MSGBOX_AUTOCLOSE
	release
	end

AquaHideout_B1F_GruntBlockExit:
	.string "Gotta talk to the Boss to be let out…$"


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
