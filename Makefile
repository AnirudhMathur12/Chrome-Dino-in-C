SRC = src/main.c src/Utils.c 
APP = game
INC = -I/Library/Frameworks/SDL2.framework/Versions/A/Headers -I/Library/Frameworks/SDL2_image.framework/Versions/A/Headers

build:
	gcc $(SRC) -o $(APP) $(INC) -lm -F/Library/Frameworks/ -framework SDL2 -framework SDL2_image

run:
	make build
	./$(APP)
