EXS = ex00

all:
	$(foreach ex, $(EXS), $(MAKE) $@ -C $(ex);)

$(EXS):
	$(MAKE) -C $@

%:
	$(foreach ex, $(EXS), $(MAKE) $@ -C $(ex);)

.PHONY: $(EXS)