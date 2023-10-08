
LRL_WEB_BINDEST ?= $(HOME)/public_html/cgi-bin/

COMMANDS  =  \
	CheckInput \
	CmdCmplx \
	CmdDelone \
	CmdDists \
	CmdLM \
	CmdNiggli \
	CmdPath \
	CmdPerturb \
	CmdS6Refl \
	CmdSella  \
	CmdToB4 \
	CmdToC3 \
	CmdToCell \
	CmdToD13 \
	CmdToDC \
	CmdToG6 \
	CmdToS6 \
	CmdToU \
	CmdVolume

BIN	= $(PWD)/bin

all:	$(BIN) $(COMMANDS) $(LRL_WEB_BINDEST)
	cp $(BIN)/* $(LRL_WEB_BINDEST)

$(BIN):
	mkdir -p $(BIN)

$(LRL_WEB_BINDEST):
	mkdir -p $(LRL_WEB_BINDEST)

$(COMMANDS):  $(BIN)/$@
	(cd $@; make all; cp $@ $(BIN))
