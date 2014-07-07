BOARD_TAG = leonardo
ARDUINO_PORT = /dev/ttyACM0
ARDUINO_LIBS =
ARDUINO_DIR = /home/dek/arduino-1.5.6-r2
BOARDS_TXT=$(ARDUINO_DIR)/hardware/arduino/avr/boards.txt
ARDUINO_CORE_PATH=$(ARDUINO_DIR)/hardware/arduino/avr/cores/arduino
ARDUINO_VAR_PATH=$(ARDUINO_DIR)/hardware/arduino/avr/variants

include /usr/share/arduino/Arduino.mk
