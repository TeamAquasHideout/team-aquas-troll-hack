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

AquaHideout_IntroSequence::
	setvar VAR_TROLL_HACK_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, AquaHideout_IntroPlayerFaceLeft
	waitmovement 0
	lockall
	msgbox AquaHideout_IntroSpeech, MSGBOX_DEFAULT
	release
	end

AquaHideout_IntroSpeech:
	.string "Team Aqua is under threat.\n"
	.string "We are being attacked on all fronts\p"
	.string "The Trick Room guy has declared war,\n"
	.string "We must DESTROY him… NOW!\l"
	.string "You are dismissed.$"

AquaHideout_IntroPlayerFaceLeft:
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

AquaHideout_B1F_OnTransition:
	end

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
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	release
	end

AquaHideout_B1F_EventScript_Grunt3Defeated::
	faceplayer
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt5::
	faceplayer
	msgbox AquaHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	release
	end

AquaHideout_B1F_EventScript_Grunt7::
	faceplayer
	msgbox AquaHideout_B1F_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	release
	end

AquaHideout_B1F_Text_Grunt2Intro:
	.string "If you want to know the secret about\n"
	.string "our HIDEOUT, you have me to beat!$"

AquaHideout_B1F_Text_Grunt2Defeat:
	.string "I can't win at all…$"

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

AquaHideout_B1F_Text_Grunt3Defeat:
	.string "I took a serious licking!$"

AquaHideout_B1F_Text_Grunt3PostBattle:
	.string "Humph!\n"
	.string "This was supposed to happen!\p"
	.string "My mission was to just hold you up!$"

AquaHideout_B1F_Text_Grunt5Intro:
	.string "Yawn… Keeping watch over the\n"
	.string "HIDEOUT bores me. I'll take you on.$"

AquaHideout_B1F_Text_Grunt5Defeat:
	.string "Yawn…\n"
	.string "Oh, I lost…$"

AquaHideout_B1F_Text_Grunt5PostBattle:
	.string "If you scurry too much, other TEAM\n"
	.string "AQUA members might get you.$"

AquaHideout_B1F_Text_Grunt7Intro:
	.string "Hey!\n"
	.string "You there!\p"
	.string "Which do you think is cooler?\n"
	.string "TEAM AQUA's uniform or TEAM MAGMA's?$"

AquaHideout_B1F_Text_Grunt7Defeat:
	.string "I lost in a cool way…$"

AquaHideout_B1F_Text_Grunt7PostBattle::
	.string "If you have a cool uniform, you look\n"
	.string "good even in a loss, don't you think?$"
