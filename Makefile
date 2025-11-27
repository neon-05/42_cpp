define NL


endef

CPPS = $(addprefix cpp0, $(shell seq 0 9))

all: $(CPPS) target

$(CPPS):
	cp $$($(MAKE) -C $@ -s | sed -e 's#^#$@/#') ./

ffclean: fclean
	$(foreach cpp, $(CPPS), rm -f $$($(MAKE) ffclean target -C $(cpp) -s); $(NL))

%:
	$(foreach cpp, $(CPPS), $(MAKE) $@ -C $(cpp) -s; $(NL))

.PHONY: $(CPPS) ffclean