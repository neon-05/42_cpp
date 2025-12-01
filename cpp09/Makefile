define NL


endef

EXS = $(addprefix ex0, $(shell seq 0 1))

all: target
	$(foreach ex, $(EXS), cp $(ex)/$$($(MAKE) $@ -C $(ex) -s) ./; $(NL))

$(EXS):
	cp $@/$$($(MAKE) -C $@ -s) ./

ffclean: fclean
	$(foreach ex, $(EXS), rm -f $$($(MAKE) target -C $(ex) -s); $(NL))

%:
	$(foreach ex, $(EXS), $(MAKE) $@ -C $(ex) -s; $(NL))

.PHONY: $(EXS) ffclean