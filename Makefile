NAME = wolf3d
CC = gcc
FLG = -Wall -Wextra -Werror
CFLAGS = -g
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))
LIBFT = dependencies/libft/libft.a
SDL2 = dependencies/SDL2/build/libSDL2.a
SDL2_IMAGE = dependencies/SDL2_image/.libs/libSDL2_image.a

LIBS = $(SDL2) $(SDL2_IMAGE)
INCLUDES = -I dependencies/libft/include -I dependencies/SDL2/include -I dependencies/SDL2_image/

ifeq ($(shell uname), Darwin)
SYSTEM_LIBS = -framework CoreFoundation -framework AppKit -framework CoreAudio \
							-framework CoreVideo -framework ForceFeedback -framework IOKit \
							-framework Metal -framework Carbon -framework AudioToolbox -liconv -L /usr/X11/lib/ -lfreetype
endif
ifeq ($(shell uname), Linux)
SYSTEM_LIBS = -lX11 -lXext -lasound -lpthread -ldl -lm -lsndio -lcairo -lwayland-server -lwayland-client -lwayland-cursor \
						-lwayland-egl -lpulse -lXcursor -lXi -lXrandr -lXxf86vm -lXinerama -lXss -lxkbcommon -lfreetype
endif

all: $(NAME)

$(NAME): folders dependencies $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) $(SYSTEM_LIBS) $(LIBFT) -o $(NAME)

dependencies : $(SDL2) $(SDL2_IMAGE) $(LIBFT)

folders:
	-@mkdir obj

$(LIBFT):
	-@cd dependencies/libft && make

$(SDL2):
	-@cd dependencies/SDL2 && mkdir build
	-@cd dependencies/SDL2/build && cmake .. && make

$(SDL2_IMAGE):
	-@cd dependencies/SDL2_image && sh autogen.sh && ./configure && make

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm -rf obj
	rm -f $(NAME)
	make -C dependencies/libft/ clean

fclean:
	-@rm -f $(NAME)
	-@rm -rf obj
	-@cd dependencies/libft && make fclean

re: clean $(NAME)

.PHONY: dependencies all folders obj clean fclean re