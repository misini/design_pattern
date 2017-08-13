
CROSS?=

ifeq ($(origin CROSS), undefined)
export CROSS=
endif


GCC =  $(CROSS)gcc
GPP =  $(CROSS)g++
AR    = $(CROSS)ar

ROOT_DIR              = .

INC_DIR                 :=  -I$(ROOT_DIR)/include
SRC_DIR                 :=  $(ROOT_DIR)/srcs
OBJ_DIR                  :=  $(ROOT_DIR)/objs
TEST_DIR             :=  $(ROOT_DIR)/test
#***?????*********************
SRCS                 :=  $(shell find $(SRC_DIR) -name '*.cpp')
SRCS                 :=  $(sort $(SRCS))

TEST                 :=  $(shell find $(TEST_DIR) -name '*.cpp')
TEST                 :=  $(sort $(TEST))
#***????*********************
OBJS                 :=  $(addprefix $(OBJ_DIR)/,$(notdir $(patsubst %.c,%.o,$(SRCS))))
LIBTARGET             :=  $(LIB_TAG_DIR)/libMAKE.a
LIBTARGET_S             :=  $(LIB_TAG_DIR)/libMAKE.so
TEST_TAG                 :=  $(TEST_DIR)/example
#***???*********************
LDFLAGS              := 
# Compiler flags, -g for debug, -c to make an object file
#
CFLAGS      = -c -g
CFLAGS_T =    -g
# Ar settings to build the library
ARFLAGS = -rcv

COMPILE =  $(GCC)  $(CFLAGS) "$<" -o $@  $(LDFLAGS) $(LIB_DIR) $(INC_DIR) $(LIB_INC_DIR)

all: prepare
    @chmod 777 * -R

$(OBJS):$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
    @echo "$< = $@"
    $(GCC)  "$<" -o "$@"  $(INC_DIR) $(LIB_INC_DIR) $(CFLAGS)
    

clean:
    @echo "rm -f $(OBJS) $(LIBTARGET) $(LIBTARGET_S) $(TEST_TAG)"
    @rm -f $(OBJS) $(LIBTARGET) $(LIBTARGET) $(TEST_TAG)
	
prepare:
	echo "aa"
	if [ ! -e $(INC_DIR) ] && mkdir $(INC_DIR)
 