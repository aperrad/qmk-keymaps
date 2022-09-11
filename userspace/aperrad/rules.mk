VPATH += keyboards/gboards

COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes

EXTRAFLAGS += -flto

CASEMODES_ENABLE = yes       # ENables case modes
CUSTOM_LEADER_ENABLE = no       # ENables custom leader function
CUSTOM_LEADER_TO_DL = no       # makes leader key activate default layer
CUSTOM_ONE_SHOT_ENABLE = yes  # ENables custom one shot modifiers function
CUSTOM_WORD_LINE_SELECTION_ENABLE = yes  # ENables custom one shot modifiers function
EOS_ENABLE = yes #end of sentence

CASEMODES_ENABLE ?= yes       # ENables case modes
ifeq ($(strip $(CASEMODES_ENABLE)), yes)
	OPT_DEFS += -DCASEMODES_ENABLE
	SRC += features/casemodes.c
endif
CUSTOM_LEADER_ENABLE ?= yes       # ENables custom leader function
ifeq ($(strip $(CUSTOM_LEADER_ENABLE)), yes)
	OPT_DEFS += -DCUSTOM_LEADER_ENABLE
	OPT_DEFS += -DCUSTOM_LEADER_TO_DL
	SRC += features/leader.c
	SRC += features/leaderfuncs.c
endif
CUSTOM_ONE_SHOT_ENABLE ?= yes       # ENables custom one shot function
ifeq ($(strip $(CUSTOM_ONE_SHOT_ENABLE)), yes)
	OPT_DEFS += -DCUSTOM_ONE_SHOT_ENABLE
	SRC += features/oneshot.c
endif
EOS_ENABLE ?= yes       # ENables custom one shot function
ifeq ($(strip $(EOS_ENABLE)), yes)
	OPT_DEFS += -DEOS_ENABLE
	SRC += features/eos_util.c
endif

CUSTOM_WORD_LINE_SELECTION_ENABLE ?= yes       # ENables power brackets
ifeq ($(strip $(CUSTOM_WORD_LINE_SELECTION_ENABLE)), yes)
	OPT_DEFS += -DCUSTOM_WORD_LINE_SELECTION_ENABLE
	SRC += features/word_line_selection.c
endif
