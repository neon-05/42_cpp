EXS = ex00 ex01 ex02 ex03

all:
	$(foreach ex, $(EXS), $(MAKE) $@ -C $(ex);)

$(EXS):
	$(MAKE) -C $@

%:
	$(foreach ex, $(EXS), $(MAKE) $@ -C $(ex);)

.PHONY: $(EXS)