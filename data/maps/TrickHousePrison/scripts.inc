TrickHousePrison_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrickRoomPrison_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrickRoomPrison_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, TrickRoomPrison_OnTransition
	.byte 0

TrickRoomPrison_OnFrame:
	map_script_2 VAR_TRICK_ROOM_PRISON, 0, TrickRoomPrison_IntroSequence
	.2byte 0

TrickRoomPrison_OnResume::
	end

TrickRoomPrison_OnTransition:
	end

TrickRoomPrison_IntroSequence::
	lockall
	setvar VAR_TRICK_ROOM_PRISON, 1
	special SaveGame
	waitstate
	releaseall
	end

TrickRoomPrison_Scroll::
	lockall
	msgbox TrickRoomPrison_Scroll_Text, MSGBOX_AUTOCLOSE
	release
	end

TrickRoomPrison_Scroll_Text:
	.string "Hehe, nothing is safe…\n"
	.string "You are not prepared for the \l"
	.string "Tricks I am going to play on you!$"
