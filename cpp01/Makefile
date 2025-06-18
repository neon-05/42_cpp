define NL


endef

EXS = $(addprefix ex0, $(shell seq 0 5))

all:
	$(foreach ex, $(EXS), cp $(ex)/$$($(MAKE) $@ -C $(ex) -s) ./; $(NL))

$(EXS):
	$(MAKE) -C $@

ffclean: fclean
	$(foreach ex, $(EXS), rm -f $$($(MAKE) target -C $(ex) -s); $(NL))

%:
	$(foreach ex, $(EXS), $(MAKE) $@ -C $(ex) -s; $(NL))

.PHONY: $(EXS) ffclean