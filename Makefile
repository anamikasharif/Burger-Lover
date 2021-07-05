GBALIB_OBJS = $(wildcard $(GBALIB_DIR)/build/*.o)
PROJ_DIR = .
BUILD_DIR = $(PROJ_DIR)/build

# Game files
GAME_OBJS = $(BUILD_DIR)/game.o

# Name of output targets.
NAME = game.tmp
TARGET = game.gba

include $(GBALIB_DIR)/Sprites.mak
include $(GBALIB_DIR)/Backgrounds.mak
include $(GBALIB_DIR)/Sounds.mak
include $(GBALIB_DIR)/GBALib.mak

$(BUILD_DIR)/game.o: game.c
	$(CC) $(DEFAULT) $(INCLUDES) $(CFLAGS) -c $< -o $@

.PHONY : build_dir
build_dir:
	@mkdir -p $(BUILD_DIR)

.PHONY : gba
gba: | build_dir sprite_map background_map sound_map $(TARGET) 

.PHONY : game
game:
	@$(MAKE) gba > /dev/null
	@$(MAKE) clean > /dev/null

.PHONY : debug
debug: gba

.PHONY : clean
clean:
	rm -r $(BUILD_DIR)
