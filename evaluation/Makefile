LIBS = -lcryptosec
INCLUDES = -I./$(GTEST_DIR) -I$(INCLUDE_DIR)  -I/usr/local/ssl/include
CC = g++
CPPFLAGS = -DGTEST_HAS_PTHREAD=0
CXXFLAGS = -g -std=c++11
EXECUTABLE = test.out

INCLUDE_DIR = ../include/
GTEST_DIR = gtest
SRC_DIR = src
MILESTONES_DIR = ../src/milestones
UTILS_DIR = ../src/utils

LIBCRYPTOSEC = /usr/lib/libcryptosec.so

TEST_SRCS += $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRCS += $(wildcard $(MILESTONES_DIR)/*.cpp)
TEST_SRCS += $(wildcard $(UTILS_DIR)/*.cpp)
OBJS += $(TEST_SRCS:.cpp=.o)

FIRST_TARGET = 	$(UTILS_DIR)/FileIo.o\
		$(UTILS_DIR)/paths.o\
		$(MILESTONES_DIR)/FirstMilestone.o\
		src/FirstMilestoneEvaluation.o\
		src/Main.o

SECOND_TARGET = $(UTILS_DIR)/FileIo.o\
		$(UTILS_DIR)/paths.o\
		$(MILESTONES_DIR)/SecondMilestone.o\
		src/SecondMilestoneEvaluation.o\
		src/Main.o

THIRD_TARGET = 	$(UTILS_DIR)/FileIo.o\
		$(UTILS_DIR)/paths.o\
		$(MILESTONES_DIR)/ThirdMilestone.o\
		src/ThirdMilestoneEvaluation.o\
		src/Main.o

FOURTH_TARGET =	$(UTILS_DIR)/FileIo.o\
		$(UTILS_DIR)/paths.o\
		$(MILESTONES_DIR)/FourthMilestone.o\
		src/FourthMilestoneEvaluation.o\
		src/Main.o

FIFTH_TARGET =	$(UTILS_DIR)/FileIo.o\
		$(UTILS_DIR)/paths.o\
		$(MILESTONES_DIR)/FifthMilestone.o\
		src/FifthMilestoneEvaluation.o\
		src/Main.o

SIXTH_TARGET =	$(UTILS_DIR)/FileIo.o\
		$(UTILS_DIR)/paths.o\
		$(MILESTONES_DIR)/SixthMilestone.o\
		src/SixthMilestoneEvaluation.o\
		src/Main.o

%.o: %.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	$(CC) $(CPPFLAGS) $(CXXFLAGS) $(INCLUDES) -O0 -Wall -c -o "$@" "$<" $(LIBS)
	@echo 'Finished building: $<'
	@echo ' '

all:	check-lib gtest $(OBJS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJS) ./$(GTEST_DIR)/gtest-all.o $(LIBS)
	@echo 'Build complete!'
	@echo ' '

check-lib:
	@test -s $(LIBCRYPTOSEC) || { echo "You should install libcryptosec first!"; exit 1; }

gtest: ./$(GTEST_DIR)/gtest-all.o

test:	all
	@echo 'Executing tests...'
	./$(EXECUTABLE)
	@echo 'Done!'

clean:
	rm -rf ./$(SRC_DIR)/*.o $(MILESTONES_DIR)/*.o $(UTILS_DIR)/*.o $(EXECUTABLE)

cleanassets:
	rm -rf ../assets/keys/*.der ../assets/certificates/*.pem ../assets/pkcs12/*.p12

veryclean: clean cleanassets
	rm -rf ./$(GTEST_DIR)/*.o

first:	check-lib gtest $(FIRST_TARGET)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -o $(EXECUTABLE) $(FIRST_TARGET) ./$(GTEST_DIR)/gtest-all.o $(LIBS)
	@echo 'Executing FIRST MILESTONE'
	./$(EXECUTABLE)
	@echo ' '

second:	check-lib gtest $(SECOND_TARGET)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -o $(EXECUTABLE) $(SECOND_TARGET) ./$(GTEST_DIR)/gtest-all.o $(LIBS)
	@echo 'Executing SECOND MILESTONE'
	./$(EXECUTABLE)
	@echo ' '

third:	check-lib gtest $(THIRD_TARGET)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -o $(EXECUTABLE) $(THIRD_TARGET) ./$(GTEST_DIR)/gtest-all.o $(LIBS)
	@echo 'Executing THIRD MILESTONE'
	./$(EXECUTABLE)
	@echo ' '

fourth:	check-lib gtest $(FOURTH_TARGET)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -o $(EXECUTABLE) $(FOURTH_TARGET) ./$(GTEST_DIR)/gtest-all.o $(LIBS)
	@echo 'Executing FOURTH MILESTONE'
	./$(EXECUTABLE)
	@echo ' '

fifth:	check-lib gtest $(FIFTH_TARGET)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -o $(EXECUTABLE) $(FIFTH_TARGET) ./$(GTEST_DIR)/gtest-all.o $(LIBS)
	@echo 'Executing FIFTH MILESTONE'
	./$(EXECUTABLE)
	@echo ' '

sixth:	check-lib gtest $(SIXTH_TARGET)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -o $(EXECUTABLE) $(SIXTH_TARGET) ./$(GTEST_DIR)/gtest-all.o $(LIBS)
	@echo 'Executing SIXTH MILESTONE'
	./$(EXECUTABLE)
	@echo ' '

evaluate: clean cleanassets all first second third fourth fifth sixth
