rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

NAME := libmcseedcpp
DBGD := libmcjavacpp
INCD := include
BIND := build
SRCD := src
DEPD := dep
OBJD := obj
STSD := test
DTSD := testdep
OTSD := testobj

STST := $(call rwildcard,$(STSD)/,*.cpp)
OTST := $(patsubst $(STSD)/%.cpp,$(OTSD)/%.o,$(STST))
DTST := $(patsubst $(STSD)/%.cpp,$(DTSD)/%.d,$(STST))
SRCS := $(call rwildcard,$(SRCD)/,*.cpp)
OBJS := $(patsubst $(SRCD)/%.cpp,$(OBJD)/%.o,$(SRCS))
DEPS := $(patsubst $(SRCD)/%.cpp,$(DEPD)/%.d,$(SRCS))

CXX := g++
CXXFLAGS := -Wall -g -I$(INCD) -I$(DBGD)/include
.PRECIOUS: $(DEPD)/%.d $(DTSD)/%.d

$(NAME): $(OBJS)
	@echo "compiling $@"
	@mkdir -p $(BIND)
	@$(CXX) $(CXXFLAGS) $(OBJS) -shared -o $(BIND)/$(NAME).so

test: $(NAME) $(OTST)
	@echo "compiling $@"
	@mkdir -p $(BIND)
	@$(CXX) $(CXXFLAGS) -L$(BIND) -L$(DBGD)/build -lmcjavacpp -lmcseedcpp $(OTST) -o $(BIND)/test

$(DTSD)/%.d: $(STSD)/%.cpp
	@echo "listing dependencies for $<"
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -I$(STSD) -M -c $< -o $@

$(OTSD)/%.o: $(STSD)/%.cpp $(DTSD)/%.d
	@echo "building object $@"
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -I$(STSD) -c $< -o $@

$(DEPD)/%.d: $(SRCD)/%.cpp
	@echo "listing dependencies for $<"
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -M -c $< -o $@

$(OBJD)/%.o: $(SRCD)/%.cpp $(DEPD)/%.d
	@echo "building object $@"
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

clean:
	@echo "cleaning workspace"
	@rm -rf $(BIND)
	@rm -rf $(OTSD)
	@rm -rf $(DTSD)
	@rm -rf $(OBJD)
	@rm -rf $(DEPD)
