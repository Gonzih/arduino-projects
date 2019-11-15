BOARD_TAG    = uno
ARDUINO_PORT = /dev/ttyACM0

ARDUINO_DIR = $(shell nix-build '<nixpkgs>' --no-build-output -A arduino)/share/arduino
ARDMK_FILE = $(shell nix-build '<nixpkgs>' --no-build-output -A arduino-mk)/Arduino.mk

include $(ARDMK_FILE)
