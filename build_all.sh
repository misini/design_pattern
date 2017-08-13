#!/bin/bash
#$1 ????

#????
for param in $@
do
    case "$param" in
        "CMAKE" )
        CMAKE=1
        echo "CMAKE=$CMAKE"
        ;;
        
        "MAKE" )
        MAKE=1
        echo "MAKE=$MAKE"
        ;;
        
        * )
        echo "unknown $param"
        ;;
    esac
done
#***************************************************************************
#cmake ??
###########################################################################

#***************************************************************************
#??Makefile??
###########################################################################
fill_makefile()
{

echo "
CROSS?= arm-hisiv100nptl-linux-

ifeq (\$(origin CROSS), undefined)
export CROSS=
endif


GCC =  \$(CROSS)gcc
GPP =  \$(CROSS)g++
AR    = \$(CROSS)ar

ROOT_DIR              = .
LIB_DIR                 :=  -L\$(ROOT_DIR)/../lib
LIB_INC_DIR             :=  -I\$(ROOT_DIR)/../include
INC_DIR                 :=  -I\$(ROOT_DIR)/include
SRC_DIR                 :=  \$(ROOT_DIR)/srcs
OBJ_DIR                  :=  \$(ROOT_DIR)/objs
LIB_TAG_DIR             :=  \$(ROOT_DIR)/libs
TEST_DIR             :=  \$(ROOT_DIR)/test
#***?????*********************
SRCS                 :=  \$(shell find \$(SRC_DIR) -name '*.c')
SRCS                 :=  \$(sort \$(SRCS))

TEST                 :=  \$(shell find \$(TEST_DIR) -name '*.c')
TEST                 :=  \$(sort \$(TEST))
#***????*********************
OBJS                 :=  \$(addprefix \$(OBJ_DIR)/,\$(notdir \$(patsubst %.c,%.o,\$(SRCS))))
LIBTARGET             :=  \$(LIB_TAG_DIR)/lib$2.a
LIBTARGET_S             :=  \$(LIB_TAG_DIR)/lib$2.so
TEST_TAG                 :=  \$(TEST_DIR)/example
#***???*********************
LDFLAGS              := -lcurl
# Compiler flags, -g for debug, -c to make an object file
#
CFLAGS      = -c -g
CFLAGS_T =    -g
# Ar settings to build the library
ARFLAGS = -rcv

COMPILE =  \$(GCC)  \$(CFLAGS) \"\$<\" -o \$@  \$(LDFLAGS) \$(LIB_DIR) \$(INC_DIR) \$(LIB_INC_DIR)

all:\$(OBJS)
    \$(AR) \$(ARFLAGS) -o \$(LIBTARGET) \$(OBJS)
    \$(GCC) \$(OBJS) -fpic -shared -o \$(LIBTARGET_S)
    @echo \"COMPILE all ok!\"
    \$(GCC)  -o \$(TEST_TAG) \$(TEST) \$(INC_DIR) \$(LIB_INC_DIR)  -L\$(LIB_TAG_DIR) \$(LDFLAGS) \$(LIB_DIR) \$(CFLAGS_T) \$(LIBTARGET)
    @chmod 777 * -R

\$(OBJS):\$(OBJ_DIR)/%.o : \$(SRC_DIR)/%.c
    @echo \"\$< = \$@\"
    \$(GCC)  \"\$<\" -o \"\$@\"  \$(INC_DIR) \$(LIB_INC_DIR) \$(CFLAGS)
    

clean:
    @echo \"rm -f \$(OBJS) \$(LIBTARGET) \$(LIBTARGET_S) \$(TEST_TAG)\"
    @rm -f \$(OBJS) \$(LIBTARGET) \$(LIBTARGET) \$(TEST_TAG)

" > $1
}
#***************************************************************************
#??????
###########################################################################
PWD=`pwd`
`mkdir $1`
PWD=$PWD/$1
echo "$PWD"
if [ $CMAKE ] ;then
  `mkdir $PWD/build`
  `touch $PWD/CMakeLists.txt`
fi

`mkdir $PWD/srcs`
if [ $CMAKE ] ; then
  `touch $PWD/srcs/CMakeLists.txt`
fi

`mkdir $PWD/objs`

`mkdir $PWD/libs`

`mkdir $PWD/test`

`mkdir $PWD/include`

`mkdir $PWD/bin`

if [ $MAKE ] ; then
  `touch $PWD/Makefile`
  fill_makefile $PWD/Makefile $1
fi
