
# markstos: enable media keys
EXTRAKEY_ENABLE = yes

# markstos: smaller file size, little down-side
LTO_ENABLE = yes

#Follow these instructions to have working overlapping combos
#https://precondition.github.io/home-row-mods#using-mod-taps-in-combos
COMBO_ENABLE = yes

NKRO_ENABLE = yes
#WPM_ENABLE = yes
#AUTO_SHIFT_ENABLE = yes

MOUSEKEY_ENABLE    = no   # Mouse keys(+4700)
BOOTMAGIC_ENABLE   = no   # Virtual DIP switch configuration(+1000)
CONSOLE_ENABLE     = no   # Console for debug(+400)
COMMAND_ENABLE     = no   # Commands for debug and configuration
BACKLIGHT_ENABLE   = no   # Enable keyboard backlight functionality
MIDI_ENABLE        = no   # MIDI controls
AUDIO_ENABLE       = no   # Audio output on port C6
UNICODE_ENABLE     = no   # Unicode
BLUETOOTH_ENABLE   = no   # Enable Bluetooth with the Adafruit EZ-Key HID
SWAP_HANDS_ENABLE  = no   # Enable one-hand typing
STENO_ENABLE	   = no
TERMINAL_ENABLE    = no
GRAVE_ESC_ENABLE   = no
MAGIC_ENABLE       = no
SPACE_CADET_ENABLE = no
VELOCIKEY_ENABLE   = no
ENCODER_ENABLE     = no
BACKLIGHT_ENABLE   = no  # Enable keyboard backlight functionality
RGB_MATRIX_ENABLE  = no

RGBLIGHT_ENABLE    = yes
RGBLIGHT_SPLIT     = yes
RGBLIGHT_DISABLE_KEYCODES = yes
RGBLIGHT_SLEEP     = yes
RGBLIGHT_ANIMATIONS = no

OLED_DRIVER_ENABLE  = yes



SRC += keycodes.c
SRC += combos.c
SRC += features/casemodes.c
SRC += features/functions.c

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
	SRC += style/oled.c
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	SRC += style/rgb.c
endif
